// A perfect numebr is a number for which the sum of it's proper devisors 
// is exactly equal to the number.
// For example, the sum of the proper divisors of 28 would be
// 1 + 2 + 3 + 4 + 6 +14 = 28. which means 28 is a perfect number.
//
// A number N is called deficient if the sum of it's proper divisors is less 
// than N and it is called abundant if the sum exceeds N.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
// number that can be written as the sum of two abundant numbers is 24. By
// mathematical analysis, it can be shown that all integers greater than
// 28123 can be writen as the sum of two abundant numbers. However, this 
// upper limit cannot be reduced any further by analysis even though it is
// known that the geatest number than cannot be expressed as the sum of two
// abundant numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the 
// sum of two abundant numbers.
#include <iostream>
#include <vector>
#include <algorithm>

typedef uint uint;
typedef std::vector< uint > List;

int main()
{
    int limit = 28123;
    List abundant;
    for ( int i = 1; i < limit; ++i )
    {
        uint total = 0;
        for ( uint j = 1; j < i; ++j )
        {
            if ( i % j == 0 )
            {
                total += j;
            }
        }
        if ( total > i )
        {
            abundant.push_back( i );
        }
    }
    uint totalSum = 0; 
    for ( int i = 1; i < limit; ++i )
    {
        List::iterator end = abundant.end();
        uint halfLimit = ( i / 2 ) + 1;
        for ( uint j = 1; j < halfLimit; ++j )
        {
            int a = j;
            int b = i - j;
            bool foundA = false, foundB = false;
            List::iterator it = abundant.begin();
            while ( it != end )
            {
                uint& val = *it;

                if ( val == a ) 
                {
                    foundA = true;
                }
                if ( val == b )
                {
                    foundB = true;
                }

                if ( foundA && foundB )
                {
                    break;
                }
                else if ( val > halfLimit )
                {
                    end = it;
                    break;
                }
                else
                {
                    ++it;
                }
            } 
            if ( foundA && foundB )
            {
                totalSum += i;
            }
        }
    }
    std::cout << totalSum << std::endl;
    return 0;
}

