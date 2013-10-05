# The fraction 49/98 is a curious fraction, as an inexperienced 
# mathematician in attempting to simplify it may incorrectly believe 
# that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
#
# We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
#
# There are exactly four non-trivial examples of this type of fraction,
# less than  one in value, and containing two digits in the numerator 
# and denominator.

# If the product of these four fractions is given in its lowest common 
# terms, find the value of the denominator.
def divide( x, y ):
    return ( x * 1.0 ) / ( y * 1.0 )
def lowestCommonDenominator( numerator, denominator ):
    return 1.0
def getVariations( num ):
    for i in xrange( 1, num ):
        for j in xrange( 1, num ):
            yield ( i*10 + num, num*10 + j ), ( i, j )
numerator = 1
denominator =1
for i in range( 1, 10 ):
    for calc, test in getVariations( i ):
        #print "Test:",calc, test
        result = divide( *calc )
        if result == divide( *test ):
            numerator *= test[ 0 ]
            denominator *= test[ 1 ]
print denominator / lowestCommonDenominator( numerator, denominator )
