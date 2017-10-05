import sys
import ROOT
import time
import numpy as np
from array import array


if sys.argv[1]== 'prmpt':
    name_extension = "Prmpt_X2ApGm"
    file_name = 'NTuple_X2ApGm_all_files_plots_prmpt.root'

if sys.argv[1]== 'displ':
    name_extension = "Displ_X2ApGm"
    file_name = 'NTuple_X2ApGm_all_files_plots_displ.root'

elif sys.argv[1]== 'Test':
    name_extension = "Test_X2ApGm"
    file_name = 'NTuple_X2ApGm_all_files_plots_test.root'

print "\n\nRunning over ", file_name, "\n"

tfile = ROOT.TFile(file_name)

try:tfile2 = ROOT.TFile('mumucal_angles.root')
except: print "Cannot use mumucal_angles.root"

ROOT.gROOT.ProcessLine('.L lhcbStyle.C')
ROOT.gROOT.ProcessLine('lhcbStyle()')

c1 = ROOT.TCanvas('c1','c1',650,450)



def M1D_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)
    #M.GetXaxis().SetRangeUser(200,10000);
    cv.SetLogx()
    cv.SetLogy()
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def M1D_plot_lin(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
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

def Angle_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
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

def Angle_prmpt_displ_plot(cv, plots_key):
    name = '{}_{}_prmpt_displ.png'.format(name_extension, plots_key)
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


def Dalitz(cv, data,name_extension, name_type):
    #print "data.shape : ", data.shape
    data = np.atleast_2d(data)
    #print "data.shape : ", data.shape

    x_scatter, y_scatter, z_scatter = array ( 'd' ), array ( 'd' ), array ( 'd' )
    length = data.shape[0]


    for j in range(length):
        x_scatter.append(data[j,0]) # mu0 mu1
        y_scatter.append(data[j,1]) # calo mu0
        z_scatter.append(data[j,2]) # calo mu1

    #dummy = ROOT.TH2F("dummy","dummy",30,0,800,30,0,1500);
    dummy = ROOT.TH2F("dummy","dummy",30,0,1500,30,0,1100);
    dummy.SetStats(False)
    dummy.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
    #dummy.GetXaxis().SetRangeUser(-30,30);
    dummy.GetXaxis().SetTitle("m (mu0 mu1) [mm]");
    #dummy.GetYaxis().SetRangeUser(-30,30);
    dummy.GetYaxis().SetTitle("m (gamma mu0) [mm]");
    dummy.Draw();

    gyx = ROOT.TGraph(length,x_scatter,y_scatter);
    #gyx.SetMarkerColor(1);
    gyx.SetMarkerStyle(19);
    gyx.SetMarkerStyle(8);
    #gyx.SetMarkerSize(0.000001);
    gyx.SetMarkerSize(0.4);
    #gyx.SetTitle("Dalitz Plot");
    gyx.Draw("PSame");
    cv.SaveAs("plots/{}_dalitz_mu0{}.png".format(name_extension, name_type));

    #cv.Clear()

    #dummy = ROOT.TH2F("dummy","dummy",30,0,800,30,0,1500);
    dummy = ROOT.TH2F("dummy","dummy",30,0,1500,30,0,1100);
    dummy.SetStats(False)
    dummy.SetTitle("Dalitz plot {} region{}".format(name_extension, name_type));
    #dummy.GetXaxis().SetRangeUser(-30,30);
    dummy.GetXaxis().SetTitle("m (mu0 mu1) [mm]");
    #dummy.GetYaxis().SetRangeUser(-30,30);
    dummy.GetYaxis().SetTitle("m (gamma mu1) [mm]");
    dummy.Draw();

    gyx = ROOT.TGraph(length,x_scatter,z_scatter);
    #gyx.SetMarkerColor(1);
    gyx.SetMarkerStyle(19);
    gyx.SetMarkerStyle(8);
    #gyx.SetMarkerSize(0.000001);
    gyx.SetMarkerSize(0.4);
    #gyx.SetTitle("Dalitz Plot");
    gyx.Draw("PSame");
    cv.SaveAs("plots/{}_dalitz_mu1{}.png".format(name_extension, name_type));



M1D_list = []
#M1D_list += ['M', 'M_l0_p', 'M_hlt1_p', 'M_hlt2_p', 'M_strip_p', 'M_kin_p', 'M_data_consistency_p', 'M_patho_p', 'M_material_p' ]
#M1D_list += ['M_require_calo', 'M_require_calo_at_m_eta', 'M_require_calo_at_m_eta_no_brem']
#M1D_list += ['M_require_calo_at_m_eta', 'M_tag_calo', 'M_calo_mu0', 'M_calo_mu1']
#M1D_list = []

for plots_key in M1D_list:
    M1D_plot_lin(c1,plots_key)
    time.sleep(2.8)

# The plot with colored regions
#M1D_regions_plot(c1, ['M_pid_p', 'M_pid_I_p', 'M_pid_II_p', 'M_pid_III_p'])
#time.sleep(2.8)


Angle_list = []
#Angle_list += ['angle_calo_mu0', 'angle_calo_mu1', 'Dphi_calo_mu0', 'Dphi_calo_mu1', 'Deta_calo_mu0', 'Deta_calo_mu1', 'DR_calo_mu0', 'DR_calo_mu1']
#Angle_list += ['angle_calo_mu0_m_eta', 'angle_calo_mu1_m_eta', 'Dphi_calo_mu0_m_eta', 'Dphi_calo_mu1_m_eta', 'Deta_calo_mu0_m_eta', 'Deta_calo_mu1_m_eta', 'DR_calo_mu0_m_eta', 'DR_calo_mu1_m_eta']
#Angle_list += ['angle_calo_mu0_not_m_eta', 'angle_calo_mu1_not_m_eta', 'Dphi_calo_mu0_not_m_eta', 'Dphi_calo_mu1_not_m_eta', 'Deta_calo_mu0_not_m_eta', 'Deta_calo_mu1_not_m_eta', 'DR_calo_mu0_not_m_eta', 'DR_calo_mu1_not_m_eta']
#Angle_list = []

for plots_key in Angle_list:
    Angle_plot(c1, plots_key)
    time.sleep(2.8)

Angle_prmpt_displ_list = ['angle_calo_mu0', 'angle_calo_mu1']

for plots_key in Angle_prmpt_displ_list:
    Angle_prmpt_displ_plot(c1, plots_key)
    time.sleep(2.8)


c8 = ROOT.TCanvas('c8','c8',6500,4500)
c8.Clear()
dalitz_name_type_list = []
#dalitz_name_type_list += ['', '_m_eta', '_not_m_eta']
#dalitz_name_type_list = []

for scatter_name_type in dalitz_name_type_list:
    data = np.loadtxt("plots/{}_dalitz{}.csv".format(name_extension,scatter_name_type), delimiter=",")
    Dalitz(c8, data, name_extension, scatter_name_type)
    time.sleep(2.8)


from shutil import copyfile


copyfile(file_name, file_name.replace('.root', '_backup.root'))
