#! /usr/bin/python

import os
import commands
from time import time

class Folders:
    problems = "problems"
    # Language options.
    langC = "c"
    langCpp = "cpp"
    langPython = "python"
    langHaskell = "haskell"
    langScala = "scala"
    # Extensinon map.
    extensions = {
        langC : "c",
        langCpp : ".cpp",
        langPython : ".py",
        langHaskell : ".hs",
        langScala : ".scala"
    }
    # Problem fomats.
    folderFormat = "%.4d"
    sourceFile = "%.4d%s"

    def __init__( self, path ):
        self.path = path
        self.projectPath, folder = os.path.split( path )
        self.sourcePath = os.path.join( self.projectPath, "source" )
        self.answerPath = os.path.join( self.path, "answers" )

    def getPath( self, folder ):
        return os.path.join( self.sourcePath, folder )

    def getSourceFile( self, folder, problem ):
        subPath = os.path.join( self.folderFormat % ( problem, ),
            self.sourceFile % ( problem, self.extensions[ folder ] )
        )
        return os.path.join( self.getPath( folder), subPath )
    
    def yieldPrograms( self, languageFilter = None, problemFilter = None ):
        for file in os.listdir( self.answerPath ):
            answerFile = os.path.join( self.answerPath, file )
            if not os.path.exists( answerFile ) or os.path.isdir( answerFile ):
                continue
            number = os.path.splitext( file )[ 0 ] 
            problemNumber = int( number )
            if problemFilter and problemNumber not in problemFilter:
                continue
            with open( answerFile, 'r' ) as encodedAnswer:
                rawAnswer = encodedAnswer.read()
            answer = rawAnswer.strip().decode( 'bz2' )
            print "Answer:", answer
            for language, ext in self.extensions.items():
                if languageFilter and language not in languageFilter:
                    continue
                folderPath = self.getPath( language )
                if not os.path.exists( folderPath ):
                    continue
                for problem in os.listdir( folderPath ):            
                    problemInt = int( problem )
                    if problemInt is not problemNumber:
                        continue
                    problemFolder = os.path.join( folderPath, problem )
                    if not os.path.exists( problemFolder ) or not os.path.isdir( problemFolder ):
                        continue
                    problemPath = os.path.join( problemFolder, self.sourceFile % ( problemInt, ext ) )
                    yield {
                        "language" : language,
                        "problemNumber" : problemNumber,
                        "problemPath" : problemPath,
                        "answer" : answer,
                    }
                        
class Execute:
    # Bash format.
    bashFormat = "bash %s.bash %s"
    answer = "%.4d.txt"

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
        if status == 0 and output == self.answer:
            print "Complete:", endTime - startTime
        else:
            print "Error", status, output, self.answer, self.language, self.problemNumber

class ExecuteCpp( Execute ):
    def createCmd( self ):
        folder, fileName = os.path.split( self.problemPath )
        args = "%s %s" % ( folder, self.problemPath )
        bash = os.path.join( self.folders.path, self.language )
        self.cmd = self.bashFormat % ( bash, args )

def createExecInstance( folders, **kwargs ):
    className = eval( "Execute%s" % ( kwargs[ "language" ].title(), ) )
    return className( folders, **kwargs )

def main( filterLanguages = None, filterProblems = None ):
    filePath = os.path.realpath( __file__ )
    path, file  = os.path.split( filePath )
    folders = Folders( path )
    for program in folders.yieldPrograms( filterLanguages, filterProblems ):
        createExecInstance( folders, **program ).run()

if __name__ == "__main__":
    main()
