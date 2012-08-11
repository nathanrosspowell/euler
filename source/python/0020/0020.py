# n! means n  (n  1)  ...  3x2x1
#
# For example, 10! = 10x9x...x3x2x1 = 3628800,
# and the sum of the digits in the number 10! is
# 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
#
# Find the sum of the digits in the number 100!
import operator
print reduce(lambda x,y:int(x)+int(y),str(reduce(operator.mul,xrange(2,101))))
