# Eta_to_Ap_Gamma_Search
LHCb search for eta decaying to a photon and a dark photon (A'), which itself decays into two muons

Run over displaced DiMuon sample:
Look for dimuons whose mass is < 1.2 GeV
Add all neutrals and photons that when added to the dimuons give a mass of < 1.2 GeV (i.e. m_(mu+mu+gamma) < 1.2 GeV)

We are running over the same 2016 EW stripping28 as for the RHNu

For testing
lb-run DaVinci/Latest python MakeNTuple_X2ApGm_prompt.py
lb-run DaVinci/Latest python MakeNTuple_X2ApGm_displaced.py


MAYBE ONLY LOOKED AT MAGDOWN


lhcb-proxy-init
ganga submit_MakeTuple_X2ApGm.py



ganga getOutputManual.py 21
ganga getOutputManual.py 62
lb-run DaVinci/Latest python merge.py prmpt 21 22   // right now we only look at 21
lb-run DaVinci/Latest python merge.py displ 61 62   // right now we only look at 61
lb-run DaVinci/Latest python merge.py noip 44   



lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"prmpt 2016 31\")"    # This creates a root file containing histograms for file with all X2ApGm. Prompt 2016
lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"prmpt 2017 ?\")"    # This creates a root file containing histograms for file with all X2ApGm. Prompt 2017
lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"displ 2016 29\")"    # This creates a root file containing histograms for file with all X2ApGm. Displ 2016
lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"displ 2017 40\")"    # This creates a root file containing histograms for file with all X2ApGm. Displ 2017
lb-run ROOT root -l -q "Plot_hists_X2ApGm_deploy.cxx(\"Test\")"    # This creates a root file containing histograms for file with all X2ApGm, but only a fraction of events.


lb-run ROOT python Visualise_Plot_hists_X2ApGm.py prmpt_and_displ_2016
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py prmpt_and_displ_2017
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py prmpt_2016      # Take ROOT file with histograms and plot them
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py prmpt_2017      # Take ROOT file with histograms and plot them
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py displ_2016      # Take ROOT file with histograms and plot them
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py displ_2017      # Take ROOT file with histograms and plot them
lb-run ROOT python Visualise_Plot_hists_X2ApGm.py Test      # Take ROOT file with histograms and plot them





//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////        J O B S        //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// jobs 61 and 62 for magdown and magup, but with hlt always returning default (0).
// job 64 with magdown hlt_updated, but when making dimuons applied prompt not displaced cuts..., issues with monitoring, deleted gangadir
// job 0 restart
// job 3 test run, with running over unincluded input file problems. with bremsadded info and material added automatically
// job 4 test run, os.system with DISPLAY problems. with bremsadded info and material added automatically
// job 5 test run, os.popen, failed because of HE16.1_pars.root upload
// job 6 test run, subprocess popen, failed because of display and HE16.1_pars.root upload
// job 7 test run, subprocess call, failed because of display and HE16.1_pars.root upload
// job 8 test run, subprocess popen not saving HE16.1_pars.root, root -b, succeeded (but only saw output later)
// job 9 test run, subprocess popen not saving HE16.1_pars.root, root -b, DISPLAY=localhost, 2k events ??? maybe code was taken from job 10 (sadly this happened), failed because of display, failed
// job 10 test run, os.popen not saving HE16.1_pars.root, 2k events, failed because of display
// job 11 test run, os.popen, DISPLAY=localhost, 2k events
// job 12 test run, os.popen, root -b DISPLAY=localhost, 2k events ??? maybe code was taken from job 13 (sadly this happened)
// job 13 test run, subprocess popen, root -b, 2k events, also redirecting stderr

// job 14 full run, subprocess popen, root -b, good. THIS WAS USED FOR THE DISPLACED CASE


// job 20 prompt run, but forgot to set run_ganga = True
// job 21 prompt run, good. THIS WAS USED FOR THE PROMPT CASE

// job 22 displ calo_pos_added, but run_ganga False
// job 23 displ calo_pos_added, but job resubmitted completed jobs
// job 24 displ calo_pos_added, but job not fully submitted
// job 25 displ calo_pos_added, but job not fully submitted
// job 26 displ calo_pos_added, but job not fully submitted
// job 27 displ calo_pos_added, but job resubmitted completed jobs
// job 28 displ calo_pos_added with autoresubmit turned off, but job not fully submitted
// job 29 displ calo_pos_added with autoresubmit turned off

// job 30 empty

// job 31 prompt run calo_pos_added with autoresubmit turned off
// job 32 prompt isolation exception no longer stops code, but exception condition handled wrongly
// job 33 prompt isolation exception no longer stops code

// job 40 2017 displ 20% of magdown
// job 41, 42  crashed
// job 43 2017 displ 100% of magdown
// job 44 2017 NoIP  100% of MagDown
// job 46 2017 NoIPSS  100% of MagDown


//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////        H I S T O R I C A L        ////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

# add material veto branches to tree
lb-run ROOT root -l -q "Add_material_deploy.cxx(\"All\")"        # This updates NTuple_X2ApGm_all_files_with_materials.root
lb-run ROOT root -l -q "Add_material_deploy.cxx(\"Test\")"        # This updates NTuple_X2ApGm_all_files_with_materials.root
