/*

Problem 1
05 October 2001

If we list all the natural numbers below 10 that are multiples 
of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

*/


#include <iostream>

int main()
{
    int errorValue = 0;

    // Problem constants.
    const int topNumber = 1000;
    const int multiples[] = { 3, 5 };
    const int numMultiples = sizeof( multiples )/sizeof( *multiples );
    // Final value.
    int sum = 0;

    for ( int number = 1; number < topNumber; ++number )
    {
        for ( int multiple = 0; multiple < numMultiples; ++multiple )
        {
            // Use modulus operator to see if the number is a multiple.
            const int leftOver = number % multiples[ multiple ];
            if ( leftOver == 0 )
            {
                // Add the number, then break to the next one.
                sum += number;
                break;
            }
        }
    }

    // Print our calculation.
    std::cout << sum << std::endl;

    return errorValue;
} 
