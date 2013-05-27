// Starting with the number 1 and moving to the right in a clockwise direction a 
// 5 by 5 spiral is formed as follows:
// 
// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13
// 
// It can be verified that the sum of the numbers on the diagonals is 101.
// 
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral 
// formed in the same way?
#include <iostream>

typedef unsigned int uint;
typedef unsigned long long int BigInt;

int main()
{
    uint width = 1001;
    uint start = width * width;
    BigInt total = 1 + start;
    while ( true )
    {
        for ( int i = 0; i < 3; ++i )
        {
            start -= width - 1;
            total += start;
        }
        if ( width - 2 > 1 )
        { 
            start -= width - 2;
            width -= 2;
            start -= 1;
            total += start;
        }
        else
        {
            break;
        }
    }
    std::cout << total << std::endl;
    return 0;
}
