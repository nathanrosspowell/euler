// Let d(n) be defined as the sum of proper divisiors of 
// n(numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a where a =/= b, then a and b are an impicable pair
// and each of a and b are called amiciable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44 
// and 110; therefore d(220) - 284.
// The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under limit.
#include <iostream>

unsigned int sum( unsigned int number )
{   
    unsigned int total = 0;
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
    const unsigned int limit = 10000;
    unsigned int totalSum = 0; 
    unsigned int sums[ limit ] = {};
    for ( unsigned int i = 0; i < limit; ++i )
    {
        sums[ i ] = sum( i );
    }
    for ( unsigned int i = 0; i < limit; ++i )
    {
        unsigned int number = sums[ i ];
        if ( number < limit && sums[ number ] == i && number != i )
        {
            totalSum += number;
        }
    }
    std::cout << totalSum << std::endl;
    return 0;
}

