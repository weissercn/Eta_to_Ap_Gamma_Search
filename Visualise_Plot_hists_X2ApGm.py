import sys
import ROOT
import time
import numpy as np
from array import array
import datetime

SLEEP = False

PRECISE_TIME = False
date_today = datetime.date.today().isoformat()
if PRECISE_TIME:
    date_today = datetime.datetime.today().isoformat()[:-7]

if sys.argv[1]== 'prmpt_and_displ':
    name_extension = "Prmpt_and_Displ_X2ApGm"
    file_name1 = 'NTuple_X2ApGm_all_files_plots_displ.root'
    file_name2 = 'NTuple_X2ApGm_all_files_plots_prmpt.root'
    if len(sys.argv) > 2:
        file_name2 = 'NTuple_X2ApGm_all_files_plots_prmpt_{}.root'.format(sys.arv[2])
        if len(sys.argv) > 3:
            file_name1 = 'NTuple_X2ApGm_all_files_plots_displ_{}.root'.format(sys.arv[3])

    print "\n\nRunning over ", file_name2, "\t", file_name1, "\n"

    tfile1 = ROOT.TFile(file_name1)
    tfile2 = ROOT.TFile(file_name2)

else:
    if sys.argv[1]== 'prmpt':
        name_extension = "Prmpt_X2ApGm"
        file_name = 'NTuple_X2ApGm_all_files_plots_prmpt.root'
        if len(sys.argv) > 2:
            file_name = 'NTuple_X2ApGm_all_files_plots_prmpt_{}.root'.format(sys.argv[2])

    if sys.argv[1]== 'displ':
        name_extension = "Displ_X2ApGm"
        file_name = 'NTuple_X2ApGm_all_files_plots_displ.root'
        if len(sys.argv) > 2:
            file_name = 'NTuple_X2ApGm_all_files_plots_displ_{}.root'.format(sys.argv[2])

    elif sys.argv[1]== 'Test':
        name_extension = "Test_X2ApGm"
        file_name = 'NTuple_X2ApGm_all_files_plots_test.root'

    print "\n\nRunning over ", file_name, "\n"

    tfile = ROOT.TFile(file_name)

    try:tfile2 = ROOT.TFile('mumucal_angles.root')
    except: print "Cannot use mumucal_angles.root"

#ROOT.gROOT.ProcessLine('.L lhcbStyle.C')
#ROOT.gROOT.ProcessLine('lhcbStyle()')

M1D_list, Angle_list, Angle_prmpt_displ_list, dalitz_name_type_list, simple_plot_list, scatter_name_type_list = [], [], [], [], [], []

if sys.argv[1]== 'prmpt_and_displ':
    Angle_list += ['angle_calo_mu0', 'angle_calo_mu1', 'Dphi_calo_mu0', 'Dphi_calo_mu1', 'Deta_calo_mu0', 'Deta_calo_mu1', 'DR_calo_mu0', 'DR_calo_mu1', 'calo_cl']
    Angle_list += ['ecal_calo_pull', 'ecal_calo_dist']
    #Angle_prmpt_displ_list += ['angle_calo_mu0', 'angle_calo_mu1'] # TOM
elif sys.argv[1]== 'prmpt':
    pass

elif sys.argv[1]== 'displ':
    pass
elif sys.argv[1]== 'Test':
    pass



if (sys.argv[1]== 'displ') or (sys.argv[1]== 'prmpt'):

    #M1D_list += ['M', 'M_l0_p', 'M_hlt1_p', 'M_hlt2_p', 'M_strip_p', 'M_kin_p', 'M_data_consistency_p', 'M_patho_p', 'M_material_p' ]
    #M1D_list += ['M_require_calo_at_m_eta_no_brem']
    M1D_list += ['M_require_calo', 'M_require_calo_at_m_eta', 'M_tag_calo', 'M_calo_mu0', 'M_calo_mu1']
    #M1D_list += ['M_require_calo_at_m_eta_no_brem']


    #Angle_list += ['angle_calo_mu0_m_eta', 'angle_calo_mu1_m_eta', 'Dphi_calo_mu0_m_eta', 'Dphi_calo_mu1_m_eta', 'Deta_calo_mu0_m_eta', 'Deta_calo_mu1_m_eta', 'DR_calo_mu0_m_eta', 'DR_calo_mu1_m_eta']
    #Angle_list += ['angle_calo_mu0_not_m_eta', 'angle_calo_mu1_not_m_eta', 'Dphi_calo_mu0_not_m_eta', 'Dphi_calo_mu1_not_m_eta', 'Deta_calo_mu0_not_m_eta', 'Deta_calo_mu1_not_m_eta', 'DR_calo_mu0_not_m_eta', 'DR_calo_mu1_not_m_eta']

    dalitz_name_type_list += ['', '_m_eta']
    #dalitz_name_type_list += ['_not_m_eta']
    #dalitz_name_type_list += ['_m_eta_m_mu0_mu1_0_200', '_m_eta_m_mu0_mu1_200_300', '_m_eta_m_mu0_mu1_300_400', '_m_eta_m_mu0_mu1_400_500', '_m_eta_m_mu0_mu1_500_600']

    #simple_plot_list += ['calo_cl']

    #scatter_name_type_list += ['_ecal_calo_dist', '_ecal_calo_dist_m_eta']



#M1D_list = []
#Angle_list = []
#Angle_prmpt_displ_list = []
#dalitz_name_type_list = []
#simple_plot_list = []
#scatter_name_type_list = []






#############################################################################################################################################
#############################################################################################################################################
#                                     I M P L E M E N T A T I O N
#############################################################################################################################################
#############################################################################################################################################



def simple_plot(cv, plots_key):
    name = '{}_{}_{}.png'.format(name_extension, plots_key, date_today)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)
    #M.GetXaxis().SetRangeUser(200,10000);
    #cv.SetLogx()
    #cv.SetLogy()
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()
    if SLEEP: time.sleep(2.8)


def M1D_plot(cv, plots_key):
    name = '{}_{}_{}.png'.format(name_extension, plots_key, date_today)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)
    #M.GetXaxis().SetRangeUser(200,10000);
    cv.SetLogx()
    cv.SetLogy()
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()
    if SLEEP: time.sleep(2.8)

def M1D_plot_lin(cv, plots_key):
    name = '{}_{}_{}.png'.format(name_extension, plots_key, date_today)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)
    M.GetXaxis().SetRangeUser(200,2000);
    #M.GetXaxis().SetRangeUser(770,785);
    #cv.SetLogx()
    cv.SetLogy()
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()
    if SLEEP: time.sleep(2.8)

def Angle_plot(cv, plots_key):
    name = '{}_{}_{}.png'.format(name_extension, plots_key, date_today)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print M
    M.SetStats(False)
    #M.GetXaxis().SetRangeUser(0,3.2);
    #cv.SetLogx()
    #cv.SetLogy()
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()
    if SLEEP: time.sleep(2.8)

def Angle_prmpt_and_displ_plot(cv, plots_key):
    name = '{}_{}_{}.png'.format(name_extension, plots_key, date_today)
    print "Plotting ", name
    M1 = tfile1.Get(plots_key+'_m_eta') #displ
    M2 = tfile2.Get(plots_key+'_m_eta_backgr_subtr') #prompt
    M3 = tfile2.Get(plots_key+'_sideband') #prompt
    M4 = tfile2.Get(plots_key+'_m_eta') #prompt
    print M1
    M1.SetStats(False)
    M1.Scale(1./M1.Integral());
    M2.Scale(1./M2.Integral());
    M3.Scale(1./M3.Integral());
    M4.Scale(1./M4.Integral());
    M1.SetLineColor(ROOT.kRed)
    M2.SetLineColor(ROOT.kCyan)
    M3.SetLineColor(ROOT.kBlack)
    M4.SetLineColor(ROOT.kBlue)
    M1.GetYaxis().SetTitle("Fraction / bin width");

    #M.GetXaxis().SetRangeUser(0,3.2);
    #cv.SetLogx()
    #cv.SetLogy()
    maximum = 1.1*max(M1.GetMaximum(), M2.GetMaximum(), M3.GetMaximum(), M4.GetMaximum())
    print 'maximum : ', maximum
    M1.SetMaximum(maximum)

    M1.Draw('hist')
    M2.Draw('histsame')
    M3.Draw('histsame')
    M4.Draw('histsame')

    if plots_key == "calo_cl":  leg = ROOT.TLegend(0.1,0.55,0.3,0.9);
    else:    leg = ROOT.TLegend(0.7,0.55,0.9,0.9);
    leg.AddEntry(M1,"displ eta mass", "l");
    leg.AddEntry(M4,"prmpt eta mass","l");
    leg.AddEntry(M2,"#splitline{prmpt eta mass}{bckgnd sbtrctd}","l");
    leg.AddEntry(M3,"prmpt sideband","l");
    leg.Draw("same");
    cv.SaveAs('plots/'+name)
    cv.Clear()
    if SLEEP: time.sleep(2.8)

def Angle_prmpt_and_displ_plot_Tom(cv, plots_key):
    name = '{}_{}_prmpt_displ_{}.png'.format(name_extension, plots_key, date_today)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print M
    if plots_key == 'angle_calo_mu0': M2 = tfile2.Get('mumucal_theta1')
    elif plots_key == 'angle_calo_mu1': M2 = tfile2.Get('mumucal_theta2')
    else: M2 = tfile2.Get(plots_key)
    M.SetStats(False)
    M.Scale(1./M.Integral());
    M2.Scale(1./M2.Integral());
    M.SetLineColor(ROOT.kRed)
    M2.SetLineColor(ROOT.kBlue)
    M.GetYaxis().SetRangeUser(0,0.04);
    M.GetYaxis().SetTitle("Fraction / 0.001 rad");

    M.Draw('hist')
    M2.Draw('histsame')

    leg = ROOT.TLegend(0.7,0.7,0.9,0.9);
    leg.AddEntry(M,"displ", "l");
    leg.AddEntry(M2,"prmpt","l");
    leg.Draw("same");

    cv.SaveAs('plots/'+name)
    cv.Clear()
    if SLEEP: time.sleep(2.8)

def Scatter(cv, data,name_extension, name_type):
    #print "data.shape : ", data.shape
    data = np.atleast_2d(data)
    #print "data.shape : ", data.shape

    scatter_bool = True
    colz_bool = True

    x_scatter, y_scatter = array ( 'd' ), array ( 'd' )
    length = data.shape[0]


    for j in range(length):
        x_scatter.append(data[j,0]) # dist
        y_scatter.append(data[j,1]) # pull

    if scatter_bool:
        #dummy = ROOT.TH2F("dummy","dummy",30,0,800,30,0,1500);
        #dummy = ROOT.TH2F("dummy","dummy",30,min(x_scatter),max(x_scatter),30,min(y_scatter),max(y_scatter));
        dummy = ROOT.TH2F("dummy","dummy",30,0, 2000,30, 0,70);
        dummy.SetStats(False)
        dummy.SetTitle("Distance calo mu {} {}".format(name_extension, name_type));
        #dummy.GetXaxis().SetRangeUser(-30,30);
        dummy.GetXaxis().SetTitle("min distance calo mu [mm]");
        #dummy.GetYaxis().SetRangeUser(-30,30);
        dummy.GetYaxis().SetTitle("pull calo mu");
        dummy.Draw();


        gyx = ROOT.TGraph(length,x_scatter,y_scatter);
        #gyx.SetMarkerColor(1);
        gyx.SetMarkerStyle(19);
        gyx.SetMarkerStyle(8);
        #gyx.SetMarkerSize(0.000001);
        gyx.SetMarkerSize(0.4);
        #gyx.SetTitle("Dalitz Plot");
        gyx.Draw("PSame");
        cv.SaveAs("plots/{}{}_{}.png".format(name_extension, name_type, date_today));
        del dummy

    if colz_bool:
        hist  = ROOT.TH2F("Dalitz_mu0_colz","dummy",30,0, 2000,30, 0,70);
        hist.SetStats(False)
        hist.SetTitle("Distance calo mu {} {}".format(name_extension, name_type));
        #hist.GetXaxis().SetRangeUser(-30,30);
        hist.GetXaxis().SetTitle("min distance calo mu [mm]");
        #hist.GetYaxis().SetRangeUser(-30,30);
        hist.GetYaxis().SetTitle("pull calo mu");
        for j in range(length):   hist.Fill(x_scatter[j], y_scatter[j])
        hist.Draw("colz");
        cv.SaveAs("plots/{}{}_colz_{}.png".format(name_extension, name_type, date_today));


def Dalitz(cv, data,name_extension, name_type):
    #print "data.shape : ", data.shape
    data = np.atleast_2d(data)
    #print "data.shape : ", data.shape

    scatter_bool = True
    colz_bool = True

    x_scatter, y_scatter, z_scatter = array ( 'd' ), array ( 'd' ), array ( 'd' )
    length = data.shape[0]


    for j in range(length):
        x_scatter.append(data[j,0]) # mu0 mu1
        y_scatter.append(data[j,1]) # calo mu0
        z_scatter.append(data[j,2]) # calo mu1

    if scatter_bool:
        #dummy = ROOT.TH2F("dummy","dummy",30,0,800,30,0,1500);
        dummy = ROOT.TH2F("dummy","dummy",30,0,1200,30,0,1200);
        dummy.SetStats(False)
        dummy.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
        #dummy.GetXaxis().SetRangeUser(-30,30);
        dummy.GetXaxis().SetTitle("m (mu0 mu1) [MeV]");
        #dummy.GetYaxis().SetRangeUser(-30,30);
        dummy.GetYaxis().SetTitle("m (gamma mu0) [MeV]");
        dummy.Draw();


        gyx = ROOT.TGraph(length,x_scatter,y_scatter);
        #gyx.SetMarkerColor(1);
        gyx.SetMarkerStyle(19);
        gyx.SetMarkerStyle(8);
        #gyx.SetMarkerSize(0.000001);
        gyx.SetMarkerSize(0.4);
        #gyx.SetTitle("Dalitz Plot");
        gyx.Draw("PSame");
        cv.SaveAs("plots/{}_dalitz_mu0{}_{}.png".format(name_extension, name_type, date_today));
        del dummy

    if colz_bool:
        hist  = ROOT.TH2F("Dalitz_mu0_colz","dummy",60,0,1200,60,0,1200);
        hist.SetStats(False)
        hist.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
        #hist.GetXaxis().SetRangeUser(-30,30);
        hist.GetXaxis().SetTitle("m (mu0 mu1) [MeV]");
        #hist.GetYaxis().SetRangeUser(-30,30);
        hist.GetYaxis().SetTitle("m (gamma mu0) [MeV]");
        for j in range(length):   hist.Fill(x_scatter[j], y_scatter[j])
        hist.Draw("colz");

        annotation = ROOT.TText()
        annotation.SetNDC()
        annotation.DrawText(0.5, 0.85, "Requiring no associable brem photons");


        cv.SaveAs("plots/{}_dalitz_mu0{}_colz_{}.png".format(name_extension, name_type, date_today));

    #cv.Clear()


    if scatter_bool:
        #dummy = ROOT.TH2F("dummy","dummy",30,0,800,30,0,1500);
        dummy = ROOT.TH2F("dummy","dummy",30,0,1200,30,0,1200);
        dummy.SetStats(False)
        dummy.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
        #dummy.GetXaxis().SetRangeUser(-30,30);
        dummy.GetXaxis().SetTitle("m (mu0 mu1) [MeV]");
        #dummy.GetYaxis().SetRangeUser(-30,30);
        dummy.GetYaxis().SetTitle("m (gamma mu1) [MeV]");
        dummy.Draw();

        gyx = ROOT.TGraph(length,x_scatter,z_scatter);
        #gyx.SetMarkerColor(1);
        gyx.SetMarkerStyle(19);
        gyx.SetMarkerStyle(8);
        #gyx.SetMarkerSize(0.000001);
        gyx.SetMarkerSize(0.4);
        #gyx.SetTitle("Dalitz Plot");
        gyx.Draw("PSame");
        #cv.SaveAs("plots/{}_dalitz_mu1{}_{}.png".format(name_extension, name_type, date_today));
        del dummy

    if colz_bool:
        hist  = ROOT.TH2F("Dalitz_mu1_colz","dummy",60,0,1200,60,0,1200);
        hist.SetStats(False)
        hist.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
        #hist.GetXaxis().SetRangeUser(-30,30);
        hist.GetXaxis().SetTitle("m (mu0 mu1) [MeV]");
        #hist.GetYaxis().SetRangeUser(-30,30);
        hist.GetYaxis().SetTitle("m (gamma mu1) [MeV]");
        for j in range(length):   hist.Fill(x_scatter[j], z_scatter[j])
        #hist.Draw("colz");
        #cv.SaveAs("plots/{}_dalitz_mu1{}_colz_{}.png".format(name_extension, name_type, date_today));

    #cv.Clear()


    if scatter_bool:
        #dummy = ROOT.TH2F("dummy","dummy",30,0,800,30,0,1500);
        dummy = ROOT.TH2F("dummy","dummy",30,0,1200,30,0,1200);
        dummy.SetStats(False)
        dummy.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
        #dummy.GetXaxis().SetRangeUser(-30,30);
        dummy.GetXaxis().SetTitle("m (gamma mu0) [MeV]");
        #dummy.GetYaxis().SetRangeUser(-30,30);
        dummy.GetYaxis().SetTitle("m (gamma mu1) [MeV]");
        dummy.Draw();

        gyx = ROOT.TGraph(length,y_scatter,z_scatter);
        #gyx.SetMarkerColor(1);
        gyx.SetMarkerStyle(19);
        gyx.SetMarkerStyle(8);
        #gyx.SetMarkerSize(0.000001);
        gyx.SetMarkerSize(0.4);
        #gyx.SetTitle("Dalitz Plot");
        gyx.Draw("PSame");
        cv.SaveAs("plots/{}_dalitz_gamma{}_{}.png".format(name_extension, name_type, date_today));
        del dummy

    if colz_bool:
        hist  = ROOT.TH2F("Dalitz_gamma_colz","dummy",60,0,1200,60,0,1200);
        hist.SetStats(False)
        hist.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
        #hist.GetXaxis().SetRangeUser(-30,30);
        hist.GetXaxis().SetTitle("m (gamma mu0) [MeV]");
        #hist.GetYaxis().SetRangeUser(-30,30);
        hist.GetYaxis().SetTitle("m (gamma mu1) [MeV]");
        for j in range(length):   hist.Fill(y_scatter[j], z_scatter[j])
        hist.Draw("colz");

        annotation = ROOT.TText()
        annotation.SetNDC()
        annotation.DrawText(0.5, 0.85, "Requiring no associable brem photons");

        cv.SaveAs("plots/{}_dalitz_gamma{}_colz_{}.png".format(name_extension, name_type, date_today));



    if SLEEP: time.sleep(2.8)







c1 = ROOT.TCanvas('c1','c1',650,450)

for plots_key in M1D_list:
    M1D_plot_lin(c1,plots_key)

for plots_key in Angle_list:
    if sys.argv[1]== 'prmpt_and_displ': Angle_prmpt_and_displ_plot(c1, plots_key)
    else: Angle_plot(c1, plots_key)

for plots_key in Angle_prmpt_displ_list:
    Angle_prmpt_and_displ_plot_Tom(c1, plots_key)

c8 = ROOT.TCanvas('c8','c8',6500,4500)
c8.Clear()

for scatter_name_type in dalitz_name_type_list:
    name = "csvs/{}_dalitz{}.csv".format(name_extension,scatter_name_type)
    print "Plotting ", name
    data = np.loadtxt(name, delimiter=",")
    print "data.shape", data.shape
    if data.shape[0]!=0: Dalitz(c8, data, name_extension, scatter_name_type)
    else: print "No events for ", name


for scatter_name_type in scatter_name_type_list:
    name = "csvs/{}_scatter{}.csv".format(name_extension,scatter_name_type)
    print "Plotting ", name
    data = np.loadtxt(name, delimiter=",")
    print "data.shape", data.shape
    if data.shape[0]!=0: Scatter(c8, data, name_extension, scatter_name_type)
    else: print "No events for ", name

for plots_key in simple_plot_list:
    simple_plot(c1, plots_key)



from shutil import copyfile

if sys.argv[1]== 'prmpt_and_displ':
    copyfile(file_name1, file_name1.replace('.root', '_backup.root'))
    copyfile(file_name2, file_name2.replace('.root', '_backup.root'))
else: copyfile(file_name, file_name.replace('.root', '_backup.root'))
