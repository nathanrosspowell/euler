/*

Problem XXX
30 November 2001

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include <iostream>

int main()
{
    int errorValue = 0;
    int divide = 20;
    int result = -1;
    int current = divide;
    while ( result == -1 )
    {
        bool divisable = true;
        for ( int i = divide - 1; i > 1; --i )
        {
            if ( current % i != 0 )
            {
                divisable = false;
                break;
            }
        }
        
        if ( divisable )
        {
            result = current;
        } 
        else
        {
            current += divide;
        }
        
    }
    
    std::cout << "Smallest number " << result << std::endl;

    return errorValue;
}
