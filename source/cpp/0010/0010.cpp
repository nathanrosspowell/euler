// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

#include <iostream>
#include <vector>
#include <math.h>

typedef long long BigInt;

int isPrime( int test )
{
    float sqRoot = sqrt( static_cast< float >( test ) );
    int sqRootInt = static_cast< int >( sqRoot ) + 1;
    for ( int i = 2; i < sqRootInt; ++i )
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
    const int limit = 2000000;
    BigInt total = 0;
    for ( int i = 2; i < limit; ++i )
    {
        total += isPrime( i );
    }
    std::cout << total << std::endl;
    return 0; 
}
