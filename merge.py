

def merge(urls,outfile):

    '''
    Merge root files given by a list of access urls.
    '''

    from subprocess import check_output
    print('MERGING')
    check_output(['hadd','-f',outfile]+urls)

import sys

mode = sys.argv[1]


njob = sys.argv[2]

file = open('urlList{}.txt'.format(njob))
urls = file.read().splitlines()
file.close()

if ((len(sys.argv) == 4) and (sys.argv[3] != sys.argv[2])):
     njob2 = sys.argv[3]
     file2 = open('urlList{}.txt'.format(njob2))
     urls += file2.read().splitlines()
     file2.close()
     merge(urls, 'NTuple_X2ApGm_all_files_{}_{}_{}.root'.format(mode, njob, njob2))
else:
    #print "urls : ", urls
    merge(urls, 'NTuple_X2ApGm_all_files_{}_{}.root'.format(mode, njob))

assert(-1==1), "Executed right, but now using the file NTuple_X2ApGm_all_files_{0}_{1}.root rather than NTuple_X2ApGm_all_files_{0}.root ".format(mode,njob)
