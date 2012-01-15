/*

Problem 10
08 February 2002

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include <iostream>
#include <vector>
#include <math.h>

typedef long long BigInt;

int isPrime( int test )
{
    int sqroot = static_cast< int >( sqrt( static_cast< double >( test ) ) ) + 1;
    for ( int i = 2; i < sqroot; ++i )
    {
        if ( test % i == 0 )
        {
            return 0;
        }
    }
    return test;
}

int main()
{
    int errorValue = 0;
    const int limit = 2000000;
    BigInt total = 0;
    for ( int i = 2; i < limit; ++i )
    {
        total += isPrime( i );
    }
    std::cout << total << std::endl;
    return errorValue;
}
