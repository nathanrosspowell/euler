# The following iterative sequence is defined for the set of positive integers
#
#      n -> n/2 (n is even
#      n -> 3n+1 (n is odd)
#
# Which starting number, under one million, produces the longes chain?
store = {}
def sequence( num ):
    if num <= 1:
        return 1 
    elif num % 2 == 0:
        num = num / 2
    else:
        num = 3 * num + 1
    if not store.has_key( num ):
        store[ num ] = sequence( num )
    return 1 + store[ num ] 
chain = 0
chainNum = 0
for i in xrange( 1000000 ):
    result = sequence( i )
    if result > chain:
        chain = result
        chainNum = i
print chainNum
