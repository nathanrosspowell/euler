# The sequence of triangle numbers is generated by adding the natural numbers.
# So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
# The first ten terms would be:
#   1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
# Let us list the factors of the first seven triangle numbers:
#   1: 1
#   3: 1,3
#   6: 1,2,3,6
#  10: 1,2,5,10
#  15: 1,3,5,15
#  21: 1,3,7,21
#  28: 1,2,4,7,14,28
# We can see that 28 is the first triangle number to have over five divisors.
# What is the value of the first triangle number to have over five hundred divisors?
class Prime:
    def __init__( self ):
        self.primes = [ 2, ]
    def isPrime( self, test ):
        for prime in self.primes:
            if  test is prime or test % prime == 0:
                return False;
        return True;
    def getPrime( self, i ):
        primeCount = len( self.primes )
        if i < primeCount:
            return self.primes[ i ];
        else:
            count = self.primes[ -1 ]
            while True:
                if self.isPrime( count ):
                    self.primes.append( count )
                    primeCount += 1
                    if primeCount > i:
                        return self.primes[ i ]; 
                count += 1
triangleNumber = 0
counter = 1
totalFactors = 0
primes = Prime()
while True: 
    totalFactors = 0
    triangleNumber += counter
    counter += 1
    factorList = []
    primeFactors = []
    primeCount = 0
    while True:
        prime = primes.getPrime( primeCount )
        primeCount += 1
        if prime > triangleNumber:
            break;
        elif triangleNumber % prime == 0:
            primeFactors.append( prime )
    for factor in primeFactors:
        multiple = 1
        while True:
            factor = prime * multiple
            multiple += 1 
            if factor <= triangleNumber:
                factorList.append( factor )
            else:
                break
    num = len( set( factorList ) )
    if num >= 500:
        break
    else:
        print "Fail %d factors %s" % ( triangleNumber, num )
print triangleNumber
