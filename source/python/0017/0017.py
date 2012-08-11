# If the numbers 1 to 5 are written out in words: one, two, three, four,
# five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were 
# written out in words, how many letters would be used?
#
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred 
# and forty-two) contains 23 letters and 115 (one hundred and fifteen) 
# contains 20 letters. The use of "and" when writing out numbers is in 
# compliance with British usage.

units = (
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
)
tens = (
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
)
hundred = "hundred"
thousand = "thousand"

def getWord( number):
    strnum = str( number )[ :: -1 ]
    #print "NUMMM", strnum
    word = ""
    usedAnd = False
    for i in reversed( range(  len( strnum ) ) ):
        n = int( strnum[ i ] )
        #print "Loop i:", i, n, strnum[ i ]
        if n == 0:
            continue
        if i == 3:
            word += " %s %s" % ( units[ n ], thousand )
            #print "Tho", word
        elif i == 2:
            word += " %s %s" % ( units[ n ], hundred )
            #print "Hun", word
        elif i == 1:
            if len( word ) > 0 and not usedAnd: 
                word += " and"
                usedAnd = True 
                #print "AND"
            if n > 1:
                word += " %s" % ( tens[ n ], )
                #print "Tens", word
            else:
                n2 = int( strnum[ :2 ][ :: -1 ] )
                word += " %s" % ( units[ n2 ], )
                #print "Units2", word, n2
                break
        else:
            if len( strnum ) > 2 and not usedAnd: 
                word += " and"
                usedAnd = True 
            word += " %s" % ( units[ n ], )
            #print "Units", word
    return word

if __name__ == "__main__":
    total = 0
    for i in xrange( 1, 1001 ): 
        total += len( getWord( i ).strip().replace( " ", "") )
    print total
