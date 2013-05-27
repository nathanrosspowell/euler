// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

typedef unsigned long long BigInt;

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

struct FactorNode
{
    FactorNode* nextNode;
    int factor;
};

int main()
{
    int errorValue = 0;
    BigInt topNumber = 600851475143LL;
    FactorNode node;
    FactorNode* currentNode = &node;
    BigInt factorise = topNumber;
    bool work = true;
    GenPrimes primes;
    while( factorise != 1 && work )
    {
        BigInt lastFactorise = factorise;
        for ( int i = 0, prime = 0; ( prime = primes.getPrime( i ) ); ++i )
        {
            if ( factorise % prime == 0 )
            {
                factorise = factorise / prime;
                currentNode->factor = prime;
                currentNode->nextNode = new FactorNode();
                currentNode = currentNode->nextNode;
                break;
            }
        }
    }
    std::vector<int> factors;
    currentNode = &node; 
    while ( currentNode )
    {
        int factor = currentNode->factor;
        if ( std::find( factors.begin(), factors.end(), factor ) == factors.end() )
        {
            factors.push_back( factor );
        }
        currentNode = currentNode->nextNode;
    }
    std::vector<int>::iterator max = std::max_element( factors.begin(), factors.end() );
    if ( max != factors.end() )
    {
        std::cout <<  *max << std::endl;
    }
    else
    {
        errorValue = 1;
    }
    return errorValue;
}
