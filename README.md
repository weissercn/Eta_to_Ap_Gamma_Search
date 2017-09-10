# Eta_to_Ap_Gamma_Search
LHCb search for eta decaying to a photon and a dark photon (A'), which itself decays into two muons

Run over displaced DiMuon sample:
Look for dimuons whose mass is < 1.2 GeV
Add all neutrals and photons that when added to the dimuons give a mass of < 1.2 GeV (i.e. m_(mu+mu+gamma) < 1.2 GeV)

We are running over the same 2016 EW stripping28 as for the RHNu


MAYBE ONLY LOOKED AT MAGDOWN


lb-run LHCbDirac $SHELL
lhcb-proxy-init
ganga submit_MakeTuple_X2ApGm.py

// job 999??? did what

ganga getOutputManual.py 999
lb-run DaVinci/Latest python merge.py 999

# add material veto branches to tree

lb-run ROOT root -l -q "Add_material_deploy.cxx(\"DiAll\")"        # This updates NTuple_X2ApGm_all_files_with_materials.root
lb-run ROOT root -l -q "Add_material_deploy.cxx(\"Test\")"        # This updates NTuple_X2ApGm_all_files_with_materials.root


lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"All\")"    # This creates a root file containing histograms for file with all X2ApGm.
lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"Test\")"    # This creates a root file containing histograms for file with all X2ApGm, but only a fraction of events.


lb-run ROOT python Visualise_Plot_hists_X2ApGm.py All      # Take ROOT file with histograms and plot them
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py Test      # Take ROOT file with histograms and plot them
