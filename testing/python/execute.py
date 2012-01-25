import os
import sys
import commands
from time import time

class Execute:
    # Bash format.
    bashFormat = "bash %s.bash %s"
    answer = "%.4d.txt"
    cleanUp = "bash %s/cleanup.bash %s"

    def __init__( self, folders, language, problemNumber, problemPath, answer ):
        self.folders = folders
        self.language = language
        self.problemNumber = problemNumber
        self.problemPath = problemPath
        self.answer = answer
        self.cmd = ""

    def run( self ):
        self.createCmd()
        startTime = time()
        status, output = commands.getstatusoutput( self.cmd )
        endTime = time()
        print "Problem:", self.problemNumber, "",
        if status == 0 and output.strip() == self.answer:
            print "Complete:", endTime - startTime
        else:
            print "Error", status, output, self.answer, self.language
        args = "%s %s" %  os.path.split( self.problemPath )
        os.system( self.cleanUp % ( self.folders.bashPath, args ) )
        
class ExecuteCpp( Execute ):
    def createCmd( self ):
        folder, fileName = os.path.split( self.problemPath )
        args = "%s %s" % ( folder, self.problemPath )
        bash = os.path.join( self.folders.bashPath, self.language )
        self.cmd = self.bashFormat % ( bash, args )

ExecutePython = ExecuteCpp

class ExecuteHaskell( Execute ):
    def createCmd( self ):
        folder, fileName = os.path.split( self.problemPath )
        args = "%s %s %.4d.o" % ( folder, self.problemPath, self.problemNumber )
        bash = os.path.join( self.folders.bashPath, self.language )
        self.cmd = self.bashFormat % ( bash, args )

