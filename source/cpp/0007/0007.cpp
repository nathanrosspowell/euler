/*

Problem 7
28 December 2001

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can 
see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <iostream>
#include <vector>

bool isPrime( int test, std::vector<int>& primes )
{
    std::vector<int>::iterator it;
    for ( it = primes.begin(); it != primes.end(); ++it )
    {
        int prime = *it;
        if ( test == prime || test % prime == 0 )
        {
            return false;
        }
    }
    primes.push_back( test );
    return true;
}


void getPrimes( int limit, std::vector<int>& primes)
{
    primes.clear();
    primes.push_back( 2 );
    int count = 2;
    int primeCount = 0;
    while ( true )
    {
        if ( isPrime( count, primes ) )
        {
            ++primeCount;
        }
        if ( primeCount >= limit)
        {
            return;
        }
        ++count;
    }
}

int main()
{
    int errorValue = 0;
    int target = 10001;
    std::vector<int> primes;
    getPrimes( target, primes );
    std::cout << "The " << target << " prime is " << primes[ target -1 ];
    return errorValue;
}
