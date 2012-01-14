import runall
import sys

if __name__ == "__main__":
    if len( sys.argv ) == 1:
        print "Script usage:\npython runspecific.py <language/s> <problem/s>"
        sys.exit( 1 )
    filterLanguages = []
    filterProblems = []
    for arg in sys.argv[ 1: ]:
        try:
            filterProblems.append( int( arg ) )
        except:
            filterLanguages.append( arg )
    runall.main( filterLanguages, filterProblems )
    


