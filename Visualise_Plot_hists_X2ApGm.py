import sys
import ROOT
import time
import numpy as np
from array import array


if sys.argv[1]== 'All':
    name_extension = "All_X2ApGm"
    file_name = 'NTuple_X2ApGm_all_files_plots.root'

elif sys.argv[1]== 'Test':
    name_extension = "Test_X2ApGm"
    file_name = 'NTuple_X2ApGm_all_files_plots_test.root'

print "\n\nRunning over ", file_name, "\n"

tfile = ROOT.TFile(file_name)

#ROOT.gROOT.ProcessLine('.L lhcbStyle.C')
#ROOT.gROOT.ProcessLine('lhcbStyle()')

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



M1D_list = ['M', 'M_l0_p', 'M_hlt1_p', 'M_hlt2_p', 'M_strip_p', 'M_kin_p', 'M_data_consistency_p', 'M_patho_p', 'M_material_p' ]
M1D_list += ['M_require_calo', 'M_require_calo_at_m_eta', 'M_tag_calo']
#M1D_list = []

for plots_key in M1D_list:
    M1D_plot_lin(c1,plots_key)
    time.sleep(2.8)

# The plot with colored regions
#M1D_regions_plot(c1, ['M_pid_p', 'M_pid_I_p', 'M_pid_II_p', 'M_pid_III_p'])
#time.sleep(2.8)
