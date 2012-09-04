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
#include <numeric>

typedef int uint;
typedef std::vector< uint > List;


uint sum( uint number )
{   
    uint total = 0;
    for ( unsigned int i = 1; i < number; ++i )
    {
        if ( number % i == 0 )
        {
            total += i;
        }
    }
    return total;
}

int main()
{
    //const uint limit = 20161;
    const uint limit = 28123;
    List abundant;
    for ( uint num = 1; num < limit; ++num )
    {
        if ( sum( num ) > num )
        {
            abundant.push_back( num );
        }
    }
    std::vector< bool > fromPair( limit );
    for ( int i = 0; i < fromPair.size(); ++i )
    {
        fromPair[ i ] = false;
    }
    for ( int i = 0; i < abundant.size(); ++i )
    {
        for ( int j = 0; j < abundant.size(); ++j )
        {
            uint pair = abundant[ i ] + abundant[ j ];
            if ( pair < limit )
            {
                fromPair[ pair ] = true;
            }
            else
            {
                break;
            }
        }
    }
    uint totalSum = 0; 
    for ( uint i = 0; i < limit; ++i )
    {
        if ( !fromPair[ i ] )
        {
            totalSum += i;
        }
    }
    std::cout << totalSum << std::endl;
    return 0;
}

