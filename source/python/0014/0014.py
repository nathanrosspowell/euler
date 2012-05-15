# The following iterative sequence is defined for the set of positive integers
#
#      n -> n/2 (n is even
#      n -> 3n+1 (n is odd)
#
# Which starting number, under one million, produces the longes chain?

def sequence( num ):
    count = 0
    while num > 1:
        count += 1
        if num % 2 == 0:
            num = num / 2
        else:
            num = 3 * num + 1
    return count

biggestChain = 0
biggestChainNum = 0
for i in xrange( 1000000 ):
    if i % 2:
        chain = sequence( i )
        if chain > biggestChain:
            biggestChain = chain
            biggestChainNum = i
print biggestChainNum
