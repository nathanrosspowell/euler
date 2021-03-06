// The following iterative sequence is defined for the set of positive integers
//
//      n -> n/2 (n is even
//      n -> 3n+1 (n is odd)
//
// Which starting number, under one million, produces the longes chain?
#include <iostream>
#include <vector>

typedef unsigned long long BigInt;

int sequence( BigInt num, int chain = 0 )
{
    if ( num <= 1 )
    {
        return chain;
    }
    else if ( num % 2 == 0 )
    {
        return sequence( num / 2, ++chain );        
    }
    return sequence( 3 * num + 1, ++chain );
}

int main()
{
    const int limit = 1000000;
    int biggestChain = 0;
    int biggestChainNum = 0;
    for ( BigInt i = 1; i < limit; ++i )
    {
        int chain = sequence( i ); 
        if ( chain > biggestChain )
        { 
            biggestChain = chain;
            biggestChainNum = i;
        }
    }
    std::cout << biggestChainNum << std::endl;
    return 0;
}
