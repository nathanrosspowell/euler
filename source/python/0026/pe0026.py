def pattern( digits ):
    if len( digits ) < 2:
        return 0, []  
    neg = -len( digits )
    for x in xrange( -1, neg, -1 ):
        y = x + x 
        z = y + x
        ##print "x", x, "y", y, "z"
        ##print digits[ x :  ], digits[ y : x ], digits[ z : y ]
        if digits[ x :  ] == digits[ y : x ] == digits[ z : y ]:
            return len( digits[ x : ] ), digits
    return 0, []

def fraction( den ):
    digits = []
    num = 1
    while True:
        remain = num % den
        div = ( num - remain ) / den
        if div > 0:
            digits.append( div )
        if remain == 0:
            break
        num = remain * 10
        pat = pattern( digits )
        if pat[0] > 0 :
            return pat
    return 0,[] 
length = 0
number = 0
for i in xrange( 2, 1001 ):
    iLength, digits = fraction( i )
    #print i, iLength
    if iLength > length:
        length = iLength
        number = i
print number


