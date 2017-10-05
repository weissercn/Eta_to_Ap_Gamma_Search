#========================================================================
# Dictionary of info for submitting ganga jobs and setting up DaVinci
#========================================================================

JobInfo = {
    #====================
    # Info for MC jobs
    #====================
    'MC.2015.6500.pp.b2jpsik': {'Input' : '/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09a/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/12143001/ALLSTREAMS.DST',
                                'CondDBTag' : 'sim-20160606-vc-md100',
                                'DDDBTag' : 'dddb-20150724',
                                'Type' : 'MC', # for Phil's pi0 efficiency code
                                'NFiles' : 1},

    'MC.2015.6500.pp.b2jpsikst': {'Input' : '/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09a/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/12143401/ALLSTREAMS.DST',
                                  'CondDBTag' : 'sim-20160606-vc-md100',
                                  'DDDBTag' : 'dddb-20150724',
                                  'Type' : 'MC', # for Phil's pi0 efficiency code
                                  'NFiles' : 1},

    'MC.2015.2510.pp'   : { 'Input' : '/MC/Dev/Beam2510GeV-Nov2015-MagDown-Nu1.5-25ns-Pythia8/Sim09Dev03/Trig0x4115014e/Reco15/Turbo01aEM/Stripping22NoPrescalingFlagged/30000000/ALLSTREAMS.DST',
                            'CondDBTag' : 'sim-20150813-vc-md100',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2015',
                            'NFiles' : 1},

    'MC.2015.6500.pp' : { 'Input' : '/MC/2015/Beam6500GeV-Jun2015-MagDown-Nu1.6-Pythia8/Sim09b/Trig0x40f9014e/Reco15em/Turbo01aEM/30000000/DST',
                          'CondDBTag' : 'sim-20161124-2015early-vc-md100',
                          'DDDBTag' : 'dddb-20150703',
                          'Type' : '2015',
                          'NFiles' : 1},

    'MC.2015.6500.pp.b2phigamma' : { 'Input' : '/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09a/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/13102202/ALLSTREAMS.DST',
                                     'CondDBTag' : 'sim-20160606-vc-md100',
                                     'DDDBTag' : 'dddb-20150724',
                                     'Type' : '2015',
                                     'NFiles' : 1 },

    'MC.2013.4000.pPb'  : { 'Input' : '/MC/2013/Beam4000GeV-2013-MagDown-Nu9-Pythia8/Sim08e/Digi13/Trig0x406e004a/Reco14r1/30000000/DST',
                            'CondDBTag' : '',
                            'DDDBTag' : '',
                            'Type' : '2013',
                            'NFiles' : 1},

    'MC.2015.6500.pp.Gms.1.5' : { 'Input' : '/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09a/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/49000225/ALLSTREAMS.DST',
                                  'CondDBTag' : 'sim-20160606-vc-md100',
                                  'DDDBTag' : 'dddb-20150724',
                                  'Type' : '2015',
                                  'NFiles' : 1 },

    'MC.2015.6500.pp.Gms.5.10' : { 'Input' : '/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09a/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/49000220/ALLSTREAMS.DST',
                                   'CondDBTag' : 'sim-20160606-vc-md100',
                                   'DDDBTag' : 'dddb-20150724',
                                   'Type' : '2015',
                                   'NFiles' : 1 },

    'MC.2015.6500.pp.Gms.10.15' : { 'Input' : '/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09a/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/49000221/ALLSTREAMS.DST',
                                    'CondDBTag' : 'sim-20160606-vc-md100',
                                    'DDDBTag' : 'dddb-20150724',
                                    'Type' : '2015',
                                    'NFiles' : 1 },

    #====================
    # Info for data jobs
    #====================
    'Data.2015.6500.pp' : { 'Input' : '/LHCb/Collision15em/Beam6500GeV-VeloClosed-MagDown/Real Data/Reco15em/96000000/FULL.DST',
                            'CondDBTag' : 'cond-20150828',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2015',
                            'NFiles' : 5},

    'Data.2016.6500.pp.Turbo.Leptons' : { 'Input' : '/LHCb/Collision16/Beam6500GeV-VeloClosed-MagDown/Real Data/Turbo03/94000000/LEPTONS.MDST',
                                          'CondDBTag' : 'cond-20160522',
                                          'DDDBTag' : 'dddb-20150724',
                                          'Type' : 'Turbo03', # for Phil's pi0 efficiency code
                                          'NFiles' : 25
                                          },

    'Data.2013.4000.pPb' : { 'Input' : '/LHCb/Protonion13/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14r1/Stripping20r3/90000000/ALL.DST',
                             'CondDBTag' : 'cond-20130404',
                             'DDDBTag' : 'dddb-20120831',
                             'Type' : '2013',
                             'NFiles' : 50},

    'Data.2013.4000.Pbp' : { 'Input' : '/LHCb/Ionproton13/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14r1/Stripping20r3/90000000/ALL.DST',
                             'CondDBTag' : 'cond-20130404',
                             'DDDBTag' : 'dddb-20120831',
                             'Type' : '2013',
                             'NFiles' : 50},

    'Data.2015.2510.pp' : { 'Input' : '/LHCb/Collision15/Beam2510GeV-VeloClosed-MagDown/Real Data/Reco15a/Stripping22b/90000000/ALL.DST',
                            'CondDBTag' : 'cond-20150828',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2015',
                            'NFiles' : 50},

    'Data.2016.6500.RHNu' : { 'Input' : '/LHCb/Collision16/Beam6500GeV-VeloClosed-MagDown/Real Data/Reco16/Stripping28/90000000/EW.DST',
                            'CondDBTag' : 'cond-20161004',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2016',
                            'NFiles' : 30},

    'Data.2016.6500.X2ApGm_displ.MagDown' : { 'Input' : '/LHCb/Collision16/Beam6500GeV-VeloClosed-MagDown/Real Data/Reco16/Stripping28/90000000/EW.DST',
                            'CondDBTag' : 'cond-20161004',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2016',
                            'NFiles' : 30},

    'Data.2016.6500.X2ApGm_displ.MagUp' : { 'Input' : '/LHCb/Collision16/Beam6500GeV-VeloClosed-MagUp/Real Data/Reco16/Stripping28/90000000/EW.DST',
                            'CondDBTag' : 'cond-20161004',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2016',
                            'NFiles' : 30},

    'Data.2016.6500.X2ApGm.MagDown' : { 'Input' : '/LHCb/Collision16/Beam6500GeV-VeloClosed-MagDown/Real Data/Turbo03/94000000/LEPTONS.MDST',
                            'CondDBTag' : 'cond-20161004',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2016',
                            'NFiles' : 30},

    'Data.2016.6500.X2ApGm.MagUp' : { 'Input' : '/LHCb/Collision16/Beam6500GeV-VeloClosed-MagUp/Real Data/Turbo03/94000000/LEPTONS.MDST',
                            'CondDBTag' : 'cond-20161004',
                            'DDDBTag' : 'dddb-20150724',
                            'Type' : '2016',
                            'NFiles' : 30}

    }
