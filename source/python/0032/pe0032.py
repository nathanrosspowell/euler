# We shall say that an n-digit number is pandigital if it makes use of all the
# digits 1 to n exactly once; for example, the 5-digit number, 15234, 
# is 1 through 5 pandigital.
#
# The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing 
# multiplicand, multiplier, and product is 1 through 9 pandigital.
#
# Find the sum of all products whose multiplicand/multiplier/product 
# identity can be written as a 1 through 9 pandigital.
#
# HINT: Some products can be obtained in more than one way so be sure to only
# include it once in your sum.
import itertools
def isPandigital( x, y, z ):
    if x * y == z:
        return z
def getCombinations( range ):
    for perm in itertools.permutations( range ):
        yield perm
def getSplits( nums ):
    size = len( nums )
    for i in xrange( 1, size - 1 ):
        for j in xrange( i+1, size ):
            yield nums[ :i ], nums[ i:j ], nums[ j: ]
def tupleToNumber( nums ):
    num = 0
    for i, digit in enumerate( reversed( nums ) ):
        num += digit * ( 10**i )
    return num
pandigital = []
for com in getCombinations( xrange( 1, 10 ) ):
    for split in getSplits( com ):
        args =  map( tupleToNumber, split )
        product = isPandigital( *args )
        if product is not None:
            pandigital.append( product )
print sum( set( pandigital ) )
