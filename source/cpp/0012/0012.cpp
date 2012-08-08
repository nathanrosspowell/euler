// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>

typedef std::map< int, int > Map;

class GenPrimes
{
public:
    GenPrimes()
    {
        primes.clear();
        primes.push_back( 2 );
    };

    bool isPrime( int test )
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
        return true;
    }

    int getPrime( int nthPrime )
    {
        int primeCount = primes.size();
        if ( nthPrime < primeCount )
        {
            return primes[ nthPrime ];
        }
        else
        {
            int count = primes.back();
            while ( true )
            {
                if ( isPrime( count ) )
                {
                    primes.push_back( count );
                    ++primeCount;
                    if ( primeCount > nthPrime )
                    {
                        return primes[ nthPrime ]; 
                    }
                }
                ++count;
            }
        }
    }
private:
    std::vector< int > primes;
};

int main()
{
    int errorValue = 0;
    int triangleNumber = 1;
    int counter = 2;
    int factors = 0;
    GenPrimes primes;
    while ( factors <= 500 )
    {
        factors = 1;
        triangleNumber += counter++;
        std::vector< int > node;
        int triCopy = triangleNumber;
        while( triCopy != 1 )
        {
            for ( int i = 0, prime = 0; ( prime = primes.getPrime( i ) ); ++i )
            {
                if ( triCopy % prime == 0 )
                {
                    triCopy /= prime;
                    node.push_back( prime );
                    break;
                }
            }
        }
        Map counts;
        for ( std::vector< int >::iterator iter = node.begin();
              iter != node.end();
              ++iter )
        {
            int factor = (*iter);
            if ( counts.find( factor ) == counts.end() )
            {
                counts[ factor ] = 1;
            }
            else
            {
                counts[ factor ] = counts[ factor ] + 1;
            }
        }
        for ( Map::iterator iter = counts.begin(); iter != counts.end(); ++iter )
        {
            factors *= ( (*iter).second + 1 );
        }   
        if ( factors > 500 )
        {
            std::cout << triangleNumber << std::endl;
        } 
    }
    return errorValue;
}
