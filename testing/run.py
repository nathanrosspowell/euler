#! /usr/bin/python
import os
import sys
from python.folders import Folders

def createExecInstance( folders, **kwargs ):
    for execute in folders.language[ kwargs[ "language" ] ][ Folders.exe ]:
        yield execute( folders, **kwargs )

def main( filterLanguages = None, filterProblems = None ):
    filePath = os.path.realpath( __file__ )
    path, file  = os.path.split( filePath )
    folders = Folders( path )
    spacer = "---------------------------------------------------------------"
    print spacer
    print "Project Euler."
    print spacer
    for program in folders.yieldPrograms( filterLanguages, filterProblems ):
        for execInst in createExecInstance( folders, **program ):
            execInst.run()
            print spacer

if __name__ == "__main__":
    if len( sys.argv ) > 1:
        filterLanguages = []
        filterProblems = []
        for arg in sys.argv[ 1: ]:
            try:
                filterProblems.append( int( arg ) )
            except:
                filterLanguages.append( arg )
        main( filterLanguages, filterProblems )
    else:
        main()
