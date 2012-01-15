// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

typedef unsigned long long BigInt;

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

struct FactorNode
{
    FactorNode* nextNode;
    int factor;
};

int main()
{
    int errorValue = 0;

    // Problem constants.
    BigInt topNumber = 600851475143LL;
    
    std::vector< int > primes;
    getPrimes( 1000, primes );
    
    //std::cout << "Number of primes" << primes.size() << std::endl;
    
   /* for ( std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it )
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    */
    
    FactorNode node;
    FactorNode* currentNode = &node;
    BigInt factorise = topNumber;
    bool work = true;
    while( factorise != 1 && work )
    {
        BigInt lastFactorise = factorise;
        for ( std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it )
        {
            int prime = *it;
            if ( factorise % prime == 0 )
            {
                factorise = factorise / prime;
                //std::cout << "Factor of " << prime << ". Working on " << factorise << std::endl;
                currentNode->factor = prime;
                currentNode->nextNode = new FactorNode();
                currentNode = currentNode->nextNode;
                break;
            }
        }
        
        if ( lastFactorise == factorise )
        {
            //std::cout << "Not enough primes? Issue with " << factorise << std::endl;
            work = false;
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

    //std::cout << "Number of factors" << factors.size() << std::endl;

    //std::cout << "Factors of  " << topNumber << " are ";
  
    for ( std::vector<int>::iterator it = factors.begin(); it != factors.end(); ++it )
    {
        //std::cout << *it << " ";
    }

    std::cout << std::endl;    
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
