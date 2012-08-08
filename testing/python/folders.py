import os
from python.execute import *

class Folders:
    problems = "problems"
    # Language options.
    langC = "c"
    langCpp = "cpp"
    langPython = "python"
    langHaskell = "haskell"
    langScala = "scala"
    # Keys.
    ext = "etx"
    exe = "exe"
    # Map of settings.
    language = {
        langC : {
            ext : ".c",
            exe : ( None, ),
        },
        langCpp : {
            ext : ".cpp",
            exe : ( ExecuteGcc, ExecuteClang ),
        },
        langPython : {
            ext : ".py",
            exe : ( ExecutePython, ),
        },
        langHaskell : {
            ext : ".hs",
            exe : ( ExecuteHaskell, ),
        },
        langScala : {
            ext : ".scala",
            exe : ( None, ),
        },
    }
    # Problem fomats.
    folderFormat = "%.4d"
    sourceFile = "%.4d%s"

    def __init__( self, path ):
        self.path = path
        self.projectPath, folder = os.path.split( path )
        self.sourcePath = os.path.join( self.projectPath, "source" )
        self.answerPath = os.path.join( self.path, "answers" )
        self.bashPath = os.path.join( self.path, "bash" )

    def getPath( self, folder ):
        return os.path.join( self.sourcePath, folder )

    def getSourceFile( self, folder, problem ):
        subPath = os.path.join( self.folderFormat % ( problem, ),
            self.sourceFile % ( problem, self.extensions[ folder ] )
        )
        return os.path.join( self.getPath( folder), subPath )
    
    def yieldPrograms( self, languageFilter = None, problemFilter = None ):
        for file in sorted( os.listdir( self.answerPath ) ):
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
            for language, data in self.language.items():
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
                    problemPath = os.path.join( problemFolder, self.sourceFile % ( problemInt, data[ self.ext ] ) )
                    yield {
                        "language" : language,
                        "problemNumber" : problemNumber,
                        "problemPath" : problemPath,
                        "answer" : answer,
                    }
