#! /usr/bin/python
import os
import sys
from python.folders import Folders

def createExecInstance( folders, **kwargs ):
    className = folders.language[ kwargs[ "language" ] ][ Folders.exe ] 
    return className( folders, **kwargs )

def main( filterLanguages = None, filterProblems = None ):
    filePath = os.path.realpath( __file__ )
    path, file  = os.path.split( filePath )
    folders = Folders( path )
    spacer = "---------------------------------------------------------------"
    print spacer
    print "Project Euler."
    print spacer
    for program in folders.yieldPrograms( filterLanguages, filterProblems ):
        createExecInstance( folders, **program ).run()
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
