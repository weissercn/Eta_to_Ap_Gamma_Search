from __future__ import print_function

# Get an access url for a given LFN at a specified SE
def getAccessURL(lfn, SEs=['CERN-USER']):
    from subprocess import check_output

    opts = '--SEs='+','.join(SEs)
    cmd = 'dirac-dms-lfn-accessURL'
    version = 'v8r6p2'
    app = 'LHCbDirac/'+version
    pro = '--Protocol=xroot,root'
    urls = check_output(['lb-run',app,cmd,lfn,opts,pro])
    url = urls.split(' : ')[-1].strip()
    return url

# Create a text file with access urls for job output
def getJobURLs(njob, fname, SE='CERN-USER'):

    f = open('urlList{}.txt'.format(njob),'w')

    for sj in jobs(njob).subjobs:
        print("Operating on subjob {0}".format(sj.id))
        for fn in sj.backend.getOutputDataLFNs():
            if fname in fn.lfn:
                #df = DiracFile(lfn=fn)

                try:
                    # I like my output files to be at CERN user
                    if SE not in fn.locations:
                        try: fn.replicate(SE)
                        except: continue

                    url = getAccessURL(fn.lfn,[SE])
                    if url:
                        print(url)
                        print(url,file=f)
                except:
                    print("Could not get Access URL")


def getJobURLs_nsubjobs(njob, nsubjob, fname, SE='CERN-USER'):

    f = open('urlList{}.txt'.format(njob),'w')

    for sj in jobs(njob).subjobs.select(id=nsubjob):
        print("Operating on subjob {0}".format(sj.id))
        for fn in sj.backend.getOutputDataLFNs():
            if fname in fn.lfn:
                #df = DiracFile(lfn=fn)

                try:
                    # I like my output files to be at CERN user
                    if SE not in fn.locations:
                        try: fn.replicate(SE)
                        except: continue

                    url = getAccessURL(fn.lfn,[SE])
                    if url:
                        print(url)
                        print(url,file=f)
                except:
                    print("Could not get Access URL")

import sys

#getJobURLs_nsubjobs(14, 367, 'outfile.root')

njob = sys.argv[1]
#outfile = 'outfile.root'
outfile = 'NTuple_X2ApGm_all_files_with_materials_test.root'
getJobURLs(njob,outfile)
