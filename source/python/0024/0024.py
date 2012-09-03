# A permutation is an ordered arrangement of objects. For Example
# 3124 is one of the possible permutations of the digits 1, 2, 3 and 4.
# If all of the permutations are listed numerically or alphabetically, we 
# cal it lexographic order. 
# The lexographic permutations of 0, 1 and 2 are:
#
#    012 021, 102, 201, 210
#
# What is the millionth lexogrphic permutation of the digits
# 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9?
import itertools
for i, nums in enumerate( itertools.permutations( "0123456789" ) ):
    if i + 1 == 1000000:
        print "".join( n for n in nums )
        break
