import sys
import ROOT
import time
import numpy as np
from array import array


elif sys.argv[1]== 'All':
    name_extension = "All"
    file_name = 'NTuple_X2RHNuGm_all_files_plots.root'

elif sys.argv[1]== 'Test':
    name_extension = "Test"
    file_name = 'NTuple_X2RHNuGm_all_files_plots_test.root'

print "\n\nRunning over ", file_name, "\n"

tfile = ROOT.TFile(file_name)

#ROOT.gROOT.ProcessLine('.L lhcbStyle.C')
#ROOT.gROOT.ProcessLine('lhcbStyle()')

c1 = ROOT.TCanvas('c1','c1',650,450)

def PNN_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)
    cv.SetLogx(0)
    cv.SetLogy(0)
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def M1D_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)

    cv.SetLogx()
    cv.SetLogy()
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def M1D_regions_plot(cv, plots_keys):
    name = '{}_{}_regions.png'.format(name_extension, plots_keys[0])
    print "Plotting ", name
    M = tfile.Get(plots_keys[0])
    M.SetStats(False)
    M.SetLineColor(ROOT.kBlack)
    cv.SetLogx()
    cv.SetLogy()
    M.Draw()
    color_list = [ROOT.kRed, ROOT.kBlue, ROOT.kGreen, ROOT.kCyan]
    for plot_i, plots_key in enumerate(plots_keys[1:]):
        M = tfile.Get(plots_key)
        M.SetLineColor(ROOT.kBlack)
        M.SetFillColor(color_list[plot_i])
        M.Draw('same')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def M2D_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)
    M.Rebin2D(10,10)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx()
    #cv.SetLogy()
    cv.SetLogz()
    M.GetXaxis().SetRange(200,500000);
    M.Draw('colz')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def M1M2_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(1)
    cv.SetLogy(1)
    #cv.SetLogz()
    M.GetXaxis().SetRangeUser(200,100000);
    M.GetYaxis().SetRangeUser(200,100000);
    M.Draw('colz')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def Mdmat_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(1)
    cv.SetLogy(0)
    #cv.SetLogz()
    M.GetXaxis().SetRangeUser(200,100000);
    #M.GetYaxis().SetRangeUser(200,100000);
    M.Draw('colz')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def M_il_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(1)
    cv.SetLogy(0)
    #cv.SetLogz()
    M.GetXaxis().SetRangeUser(200,100000);
    #M.GetYaxis().SetRangeUser(200,100000);
    M.Draw('colz')
    cv.SaveAs('plots/'+name)
    cv.Clear()

def Q_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    M.SetStats(False)

    cv.SetLogx(0)
    cv.SetLogy(0)
    M.Draw('hist')
    cv.SaveAs('plots/'+name)
    cv.Clear()


def d2_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    #M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(0)
    cv.SetLogy(0)
    #cv.SetLogz()
    #M.GetXaxis().SetRangeUser(0.,1.);
    #M.GetYaxis().SetRangeUser(0.,1.);
    M.Draw()
    cv.SaveAs('plots/'+name)
    cv.Clear()

def xxx_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    #M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(0)
    cv.SetLogy(0)
    #cv.SetLogz()
    #M.GetXaxis().SetRangeUser(0.,1.);
    #M.GetYaxis().SetRangeUser(0.,1.);
    M.Draw()
    cv.SaveAs('plots/'+name)
    cv.Clear()

def dmat_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    #M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(0)
    cv.SetLogy(1)
    #cv.SetLogz()
    M.GetXaxis().SetRangeUser(0.,4.);
    #M.GetYaxis().SetRangeUser(0.,1.);
    M.Draw()
    cv.SaveAs('plots/'+name)
    cv.Clear()

def fd_r_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    #M.Rebin2D(25,25)
    print "M.GetNbinsX : ", M.GetNbinsX()
    cv.SetLogx(0)
    cv.SetLogy(1)
    #cv.SetLogz()
    #M.GetXaxis().SetRangeUser(0.,4.);
    #M.GetYaxis().SetRangeUser(0.,1.);
    M.Draw()
    cv.SaveAs('plots/'+name)
    cv.Clear()

def Bsmumu_plot(cv, plots_key):
    name = '{}_{}.png'.format(name_extension, plots_key)
    print "Plotting ", name
    M = tfile.Get(plots_key)
    print '\n', M
    M.SetStats(False)
    #M.Rebin2D(25,25)
    #print "M.GetNbinsX : ", M.GetNbinsX()
    #cv.SetLogx()
    #cv.SetLogy()
    #cv.SetLogz()
    M.GetXaxis().SetRangeUser(-1.,1.);
    M.Draw()
    cv.SaveAs('plots/'+name)
    cv.Clear()

def Scatter_old(data,name_extension, name_type):
    plt.plot(data[:,1], data[:,0])
    plt.save("{}_gyx{}.png".format(name_extension,name_type))
    plt.plot(data[:,2], data[:,0])
    plt.save("{}_gzx{}.png".format(name_extension,name_type))

def Scatter(cv, data,name_extension, name_type):
    #print "data.shape : ", data.shape
    data = np.atleast_2d(data)
    #print "data.shape : ", data.shape

    x_scatter, y_scatter, z_scatter = array ( 'd' ), array ( 'd' ), array ( 'd' )
    length = data.shape[0]


    for j in range(length):
        x_scatter.append(data[j,0])
        y_scatter.append(data[j,1])
        z_scatter.append(data[j,2])

    dummy = ROOT.TH2F("dummy","dummy",10,-30,30,10,-30,30);
    dummy.SetStats(False)
    dummy.SetTitle("gyx {} region{}".format(name_extension, name_type));
    dummy.GetXaxis().SetRangeUser(-30,30);
    dummy.GetXaxis().SetTitle("y [mm]");
    dummy.GetYaxis().SetRangeUser(-30,30);
    dummy.GetYaxis().SetTitle("x [mm]");
    dummy.Draw();

    gyx = ROOT.TGraph(length,y_scatter,x_scatter);
    gyx.SetMarkerColor(1);
    #gyx.SetMarkerStyle(19);
    gyx.SetMarkerStyle(8);
    gyx.SetMarkerSize(0.0000001);
    gyx.SetTitle("gyx All cuts");
    gyx.Draw("PSame");
    cv.SaveAs("plots/{}_gyx{}.png".format(name_extension, name_type));

    #cv.Clear()

    dummy = ROOT.TH2F("dummy2","dummy2",10,-200,500,10,-30,30);
    dummy.SetStats(False)
    dummy.SetTitle("gzx {} {}".format(name_extension, name_type));
    dummy.GetXaxis().SetRangeUser(-200,500);
    dummy.GetXaxis().SetTitle("z [mm]");
    dummy.GetYaxis().SetRangeUser(-30,30);
    dummy.GetYaxis().SetTitle("x [mm]");
    dummy.Draw();

    gzx = ROOT.TGraph(length,z_scatter,x_scatter);
    gzx.SetMarkerColor(1);
    #gzx.SetMarkerStyle(19);
    gzx.SetMarkerStyle(8);
    gzx.SetMarkerSize(0.0000001);
    gzx.Draw("PSame");
    cv.SaveAs("plots/{}_gzx{}.png".format(name_extension, name_type));

    #cv.Clear()


#M1D_list = ['M', 'M_l0_p', 'M_l0_f', 'M_hlt1_p', 'M_hlt1_f', 'M_hlt2_p', 'M_hlt2_f', 'M_strip_p', 'M_strip_f', 'M_kin_p', 'M_data_consistency_p', 'M_data_consistency_f', 'M_kin_f', 'M_patho_p', 'M_patho_f', 'M_material_p', 'M_material_f', 'M_hf_p', 'M_hf_f', 'M_pid_p', 'M_pid_f']
#M1D_list = ['M_strip_p', 'M_kin_p', 'M_data_consistency_p', 'M_patho_p', 'M_material_p', 'M_hf_p', 'M_fd_r_p', 'M_pid_p']
#M1D_list = ['M']
#M1D_list = ['M_hf_p', 'M_fd_r_p', 'M_pid_p']
M1D_list = ['M_strip_p', 'M_trigger_cuts', 'M_necessary_cuts', 'M_necessary_and_hf_cuts', 'M_necessary_and_material_cuts', 'M_necessary_and_hf_and_material_cuts', 'M_pid_p']
#M1D_list = ['M_l0_p']
M1D_list = []

for plots_key in M1D_list:
    M1D_plot(c1,plots_key)
    time.sleep(2.8)

# The plot with colored regions
#M1D_regions_plot(c1, ['M_pid_p', 'M_pid_I_p', 'M_pid_II_p', 'M_pid_III_p'])
#time.sleep(2.8)





#M2D_list = ['MT', 'MT_l0_p', 'MT_l0_f', 'MT_hlt1_p', 'MT_hlt1_f', 'MT_hlt2_p', 'MT_hlt2_f', 'MT_strip_p', 'MT_strip_f', 'MT_kin_p', 'MT_kin_f', 'MT_data_consistency_p', 'MT_data_consistency_f','MT_patho_p', 'MT_patho_f', 'MT_material_p', 'MT_material_f', 'MT_hf_p', 'MT_hf_f', 'MT_pid_p', 'MT_pid_f']
M2D_list = ['MT_strip_p', 'MT_kin_p', 'MT_data_consistency_p', 'MT_patho_p', 'MT_material_p', 'MT_hf_p', 'MT_fd_r_p', 'MT_pid_p']
#M2D_list = ['MT']
M2D_list = []

for plots_key in M2D_list:
    M2D_plot(c1,plots_key)
    time.sleep(2.8)





PNN_list = ['mu_pnnmu', 'h_pnnk', 'h_pnnpi']
#PNN_list = ['mu_isMuon', 'h_isMuon']
PNN_list = []

for plots_key in PNN_list:
    PNN_plot(c1,plots_key)
    time.sleep(2.)




M1M2_list = ['M1M2', 'M1M2_tau_1to2', 'M1M2_tau_2to5', 'M1M2_tau_5to10', 'M1M2_dtf_chi2_0to2', 'M1M2_dtf_chi2_2to5', 'M1M2_dtf_chi2_5to8']
#M1M2_list += ['M2nMavg']
M1M2_list += ['M1M2_strip', 'M1M2_kin', 'M1M2_data_consistency', 'M1M2_patho', 'M1M2_material', 'M1M2_hf', 'M1M2_fd_r', 'M1M2_pid']
#M1M2_list = ['M1M2']
M1M2_list = ['M1M2_hf', 'M1M2_fd_r', 'M1M2_pid']
M1M2_list = ['M1M2_trigger_cuts', 'M1M2_necessary_cuts', 'M1M2_necessary_and_hf_cuts', 'M1M2_necessary_and_material_cuts', 'M1M2_necessary_and_hf_and_material_cuts']
M1M2_list = []

for plots_key in M1M2_list:
    M1M2_plot(c1,plots_key)
    time.sleep(2.8)

Q_list = ['Q']
Q_list = []

for plots_key in Q_list:
    Q_plot(c1,plots_key)
    time.sleep(2.8)


d2_list = ['d2']
d2_list = []

for plots_key in d2_list:
    d2_plot(c1,plots_key)
    time.sleep(2.8)

xxx_list = ['xxx']
xxx_list = []

for plots_key in xxx_list:
    xxx_plot(c1,plots_key)
    time.sleep(2.8)



dmat_list = ['dmat', 'dmat_rescaled', 'dmat_rescaled_I', 'dmat_rescaled_II', 'dmat_rescaled_III']
dmat_list = []

for plots_key in dmat_list:
    dmat_plot(c1,plots_key)
    time.sleep(2.8)




fd_r_list = ['fd_r', 'fd_r_I', 'fd_r_II', 'fd_r_III']
fd_r_list = []

for plots_key in fd_r_list:
    fd_r_plot(c1,plots_key)
    time.sleep(2.8)



Bsmumu_list = ['iv_hf', 'iv_sig', 'il_hf', 'il_sig']
Bsmumu_list = []

for plots_key in Bsmumu_list:
    Bsmumu_plot(c1,plots_key)
    time.sleep(2.8)


Mdmat_list = ['Mdmat_necessary_cuts', 'Mdmat_rescaled_necessary_cuts', 'Mdmat_necessary_cuts_diRHNu', 'Mdmat_rescaled_necessary_cuts_diRHNu']
#Mdmat_list = []

for plots_key in Mdmat_list:
    Mdmat_plot(c1,plots_key)
    time.sleep(2.8)

M_il_list = ['M_il_necessary_cuts', 'M_iv_necessary_cuts', 'M_il_necessary_cuts_diRHNu', 'M_iv_necessary_cuts_diRHNu']
#M_il_list = []

for plots_key in M_il_list:
    M_il_plot(c1,plots_key)
    time.sleep(2.8)



c8 = ROOT.TCanvas('c8','c8',6500,4500)
c8.Clear()
scatter_name_type_list = ['', '_I', '_II', '_III']
scatter_name_type_list = []

for scatter_name_type in scatter_name_type_list:
    data = np.loadtxt("plots/{}_scatter{}.csv".format(name_extension,scatter_name_type), delimiter=",")
    Scatter(c8, data, name_extension, scatter_name_type)
    time.sleep(2.8)


#c8.Close()
