

def merge(urls,outfile):

    '''
    Merge root files given by a list of access urls.
    '''

    from subprocess import check_output
    print('MERGING')
    check_output(['hadd','-f',outfile]+urls)

import sys

njob = sys.argv[1]

file = open('urlList{}.txt'.format(njob))
urls = file.read().splitlines()

if ((len(sys.argv) == 3) and (sys.argv[2] != sys.argv[1])):
     njob2 = sys.argv[2]
     file2 = open('urlList{}.txt'.format(njob2))
     urls += file2.read().splitlines()


#print "urls : ", urls
merge(urls, 'NTuple_X2ApGm_all_files.root')
