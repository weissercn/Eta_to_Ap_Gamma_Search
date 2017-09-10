import GaudiPython, ROOT, array
from math import sqrt, log, pi, sin, cos, acos
from GaudiPython import gbl
class IsoBdt:
    def __init__(self, dst, xmls = ['IsoBdtVelo.xml', 'IsoBdtLong.xml']):
        """
        Initialize the tool.
        dst:  distance calculation tool.
        xmls: four XML files for BDT weights.
        """
        self.dst  = dst
        self.vals = [array.array('f', [0]) for i in range(0, 9)]
        self.mvas = [None]*len(xmls)
        vnms = ['log(trk_ips)', 'trk_pvdis1', 'trk_svdis1', 'log(trk_doca1)',
                'trk_angle1', 'trk_fc1', 'trk_dphi1',
                'abs(trk_deta1)', 'trk_pt']
        vids = [range(0, 6), range(0, 9)]
        for mva, xml in enumerate(xmls):
            self.mvas[mva] = ROOT.TMVA.Reader('!Color:Silent')
            for vid in vids[mva]:
                self.mvas[mva].AddVariable(vnms[vid], self.vals[vid])
            self.mvas[mva].BookMVA('BDT', xml)
    def key(self, trk):
        """
        Determine the unique VELO key for a track.
        trk: track to find the key.
        """
        key = float(1)
        for lid in trk.lhcbIDs():
            if lid.isVelo(): key *= float(lid.veloID().channelID()/1000000.0)
        return key
    def dot(self, v0, v1):
        """
        Calculate Gaudi::XYZ* dot-products as this functionality has
        been removed in ROOT 6.
        """
        return v0.x()*v1.x() + v0.y()*v1.y() + v0.z()*v1.z()
    def logIpChiMin(self, prt, pvrs):
        """
        Calculate the log of the minimum IP chi with the primary
        vertices. In the BsMuMu code this is log(calcIPToAnyPV).
        prt:  particle to calculate ipChiMin.
        pvrs: primary vertices used in calculation.
        """
        ip, ipChi2, ipChi2Min = ROOT.Double(0), ROOT.Double(0), float('inf')
        for pvr in pvrs:
            self.dst.distance(prt, pvr, ip, ipChi2)
            if ipChi2 < ipChi2Min: ipChi2Min = float(ipChi2)
        try: return log(sqrt(ipChi2Min))
        except: return float('-inf')
    def vertex(self, prtX, prtP, dtrX, dtrP):
        """
        Vertex a displaced track with a daughter particle. In the
        BsMuMu code this is getPerpFeet which provides the same result
        as closest_point.
        prt[X,P]: particle origin point and momentum vector.
        dtr[X,P]: daughter origin point and momentum vector.
        """
        difX, prtN, dtrN = prtX - dtrX, prtP.unit(), dtrP.unit()
        difPrt = self.dot(difX, prtN)
        difDtr = self.dot(difX, dtrN)
        dtrPrt = self.dot(dtrN, prtN)
        num, den = difPrt*dtrPrt - difDtr, dtrPrt*dtrPrt - 1
        if den > 1e-27: return (
            gbl.Gaudi.XYZVector(), gbl.Gaudi.XYZVector(), gbl.Gaudi.XYZVector())
        prtPrp = prtX + prtN*(num/den*dtrPrt - difPrt)
        dtrPrp = dtrX + dtrN*num/den
        return prtPrp, dtrPrp, prtPrp + (dtrPrp - prtPrp)*0.5
    def distance(self, vrt, svr):
        """
        Calculate the distance between a daughter and vertex. In the
        BsMuMu code this is calcVertexDist.
        vrt: daughter vertex with track.
        svr: vertex of the decay.
        """
        return (vrt.z() - svr.z())/abs(vrt.z() - svr.z())*(vrt - svr).R()
    def angle(self, prtP, dtrP):
        """
        Calculate the angle between a particle and daughter. In the
        BsMuMu code this is enclosedAngle.
        prtP: momentum vector of the particle.
        dtrP: momentum vector of the daughter.
        """
        cs  = self.dot(prtP, dtrP)/(prtP.R()*dtrP.R())
        acs = acos(abs(cs))
        return pi - acs if cs < 0 else acs
    def fc(self, prtP, dtrP, vrt, pvr):
        """
        Calculate the f_c variable. In the BsMuMu code this is calcFC.
        prtP: momentum vector of the particle.
        dtrP: momentum vector of the daughter.
        vrt:  daughter vertex with track.
        pvr:  associated primary vertex.
        """
        sumP, difX = prtP + dtrP, vrt - pvr
        sn = sin(self.angle(sumP, difX))
        num, den = sumP.R()*sn, sumP.R()*sn + prtP.Rho() + dtrP.Rho()
        return num/den if den else -1
    def isolation(self, mom, pvr, l_gdtr_prt_for_smooth_iso, pvrs, prts, mva = 1):
        """
        Calculate the isolation for the daughters of a particle.
        mom:  mother particle.
        pvr:  associated primary vertex of the mother.
        l_gdtr_prt_for_smooth_iso: List of tracks to ignore when calculating the isolation for the heavy flavour veto. This turns an isolation to a smooth isolation
        pvrs: primary vertices of the event.
        prts: displaced particles, protos, or tracks for vertexing.
        mva:  multi-variate method to use: 0 is VELO and 1 is LONG.
        """
        svr, dtrs, isos = mom.endVertex(), mom.daughtersVector(), []
        other_dtrs = l_gdtr_prt_for_smooth_iso
        dtrKeys = [self.key(dtr.proto().track()) for dtr in dtrs]
        other_dtrKeys = [self.key(other_dtr.proto().track()) for other_dtr in other_dtrs]
        for dtr in dtrs:
            dtrTrk = dtr.proto().track()
            isos += [float('-inf')]
            for prt in prts:
                try: prtPro = prt.proto()
                except: prtPro = prt
                try: prtTrk = prtPro.track()
                except: prtTrk = prt
                if self.key(prtTrk) in dtrKeys: continue
                if self.key(prtTrk) in other_dtrKeys: continue
                if mva == 0 and prtTrk.type() != 1: continue
                if mva == 1 and prtTrk.type() != 3: continue
                prtP, prtX = prtTrk.momentum(), prtTrk.position()
                dtrP, dtrX = dtrTrk.momentum(), dtrTrk.position()
                if mva == 0: dtrP *= 0.4/dtrP.Rho()
                prtPrp, dtrPrp, vrt = self.vertex(prtX, prtP, dtrX, dtrP)
                try:
                    self.vals[0][0] = self.logIpChiMin(prt, pvrs)
                    self.vals[1][0] = self.distance(vrt, pvr.position())
                    self.vals[2][0] = self.distance(vrt, svr.position())
                    self.vals[3][0] = log((prtPrp - dtrPrp).R())
                    self.vals[4][0] = self.angle(prtP, dtrP)
                    self.vals[5][0] = self.fc(prtP, dtrP, vrt, pvr.position())
                    self.vals[6][0] = abs(prtP.Phi() - dtrP.Phi())
                    self.vals[7][0] = abs(prtP.Eta() - dtrP.Eta())
                    self.vals[8][0] = prtTrk.pt()
                    iso = self.mvas[mva].EvaluateMVA('BDT')
                except: iso = float('-inf')
                if iso > isos[-1]: isos[-1] = iso
        return isos
