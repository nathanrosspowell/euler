# Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
# 
# 1634 = 1^4 + 6^4 + 3^4 + 4^4
# 8208 = 8^4 + 2^4 + 0^4 + 8^4
# 10474 = 10^4 + 4^4 + 7^4 + 4^4
# As 1 = 14 is not a sum it is not included.
# 
# The sum of these numbers is 1634 + 8208 + 10474 = 110316.
# 
# Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
print sum(x for x in xrange(1000000)if x==sum(map(lambda x:int(x)**5,str(x))))-1
