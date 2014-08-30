##!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# execute. Authored by Nathan Ross Powell.
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Imports.
import os
import sys
import commands
from time import time

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Main class
class Execute:
    # Bash format.
    bashFormat = "bash %s.bash %s"
    answer = "%.4d.txt"
    cleanUp = "bash %s/cleanup.bash %s"
    success = "\033[92m"
    warn = "\033[93m"
    fail = "\033[91m"
    end = "\033[0m"
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    def __init__( self, folders, language, problemNumber, problemPath, answer ):
        self.folders = folders
        self.language = language
        self.problemNumber = problemNumber
        self.problemPath = problemPath
        self.answer = answer
        self.cmd = ""
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    def printCol( self, colour, form, args ):
        print "%s%s%s" % (
            colour,
            form % args,
            self.end
        )
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    def run( self ):
        spaces = 30 
        printLine = "[%s][%s][%.4d]" % ( self.language.upper(), self.version.upper(), self.problemNumber, )
        print "%s%s| " % ( printLine, " " * ( spaces - len( printLine ) ) ),
        sys.stdout.flush()
        self.createCmd()
        startTime = time()
        status, output = commands.getstatusoutput( self.cmd )
        endTime = time()
        if status == 0 and output.strip() == self.answer:
            timer = endTime - startTime
            if timer > 60.0:
                colour = self.warn
                warn = " Should be under 60.00."
            else:
                colour = self.success
                warn = ""
            self.printCol( colour, "~%.2f seconds.%s", ( timer, warn ) )
        elif output.strip().find( "404!" ) != -1:
            colour = self.warn
            warn = "Implementation not complete."
            self.printCol( colour, "%s", ( warn ) )
        else:
            self.printCol( self.fail,
                """Error!
    Status: %s
    Output: %s""",
                ( status, output, )
        )
        args = "%s %s" %  os.path.split( self.problemPath )
        os.system( self.cleanUp % ( self.folders.bashPath, args ) )

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteGcc( Execute ):
    version = "gcc"
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    def createCmd( self ):
        folder, fileName = os.path.split( self.problemPath )
        args = "%s %s" % ( folder, self.problemPath )
        bash = os.path.join( self.folders.bashPath, self.version)
        self.cmd = self.bashFormat % ( bash, args )

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecutePython( ExecuteGcc ):
    version = "cpython"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteClang( ExecuteGcc ):
    version = "clang"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteGo( ExecuteGcc ):
    version = "go"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteJavascript( ExecuteGcc ):
    version = "javascript"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteGdc( ExecuteGcc ):
    version = "gdc"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteRust( ExecuteGcc ):
    version = "rust"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteHaskell( Execute ):
    version = "glasgow"
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    def createCmd( self ):
        folder, fileName = os.path.split( self.problemPath )
        args = "%s %s %.4d.o" % ( folder, self.problemPath, self.problemNumber )
        bash = os.path.join( self.folders.bashPath, self.version )
        self.cmd = self.bashFormat % ( bash, args )

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class ExecuteErlang( Execute ):
    version = "erlang"
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    def createCmd( self ):
        folder, fileName = os.path.split( self.problemPath )
        args = "%s %s/pe%.4d.erl pe%.4d" % ( folder, folder, self.problemNumber, self.problemNumber )
        bash = os.path.join( self.folders.bashPath, self.version )
        self.cmd = self.bashFormat % ( bash, args )
