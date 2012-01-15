/*

Problem 6
14 December 2001

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten
natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one
hundred natural numbers and the square of the sum.

*/

#include <iostream>

int main()
{
    int errorValue = 0;
    int limit = 100; 
    int squaredCount = 0;
    int count = 0;
    
    for ( int i = 1; i <= limit; ++i )
    {
        count += i;
        squaredCount += i * i;
    }
    count *= count;
    
    std::cout << count - squaredCount << std::endl;;
    
    return errorValue;
}
