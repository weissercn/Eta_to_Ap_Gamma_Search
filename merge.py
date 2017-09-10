

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

#print "urls : ", urls
merge(urls, 'NTuple_X2RHNuGm_all_files.root')
