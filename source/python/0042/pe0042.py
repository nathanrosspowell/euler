# The nth term of the sequence of triangle numbers is given by, tn = 1/2n(n+1);
# so the first ten triangle numbers are:
# 
# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
# 
# By converting each letter in a word to a number corresponding to its 
# alphabetical position and adding these values we form a word value. 
# For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. 
# If the word value is a triangle number then we shall call the word 
# a triangle word.
# 
# Using words.txt, a 16K text file containing nearly two-thousand common 
# English words, how many are triangle words?
def wordList():
    with open( "words.txt", 'r' ) as file:
        for line in file.read().split( ","):
            yield line.replace( '"', '' ).strip().lower()

def num( word ):
    return sum( map( lambda letter: ord( letter ) - 96, word ) )

def getTri( n ):
    return int( ( n / 2.0 ) * ( n + 1 ) )

def isTriangle( num, tris = [ 1 ] ):
    if num == tris[ -1 ]:
        return True
    elif num < tris[ -1 ]:
        return num in tris
    else:
        tris.append( getTri( len( tris ) + 1 ) )
        return isTriangle( num )

print sum( isTriangle( num( word ) ) for word in wordList() )
