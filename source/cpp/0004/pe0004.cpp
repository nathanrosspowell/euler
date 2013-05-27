// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

bool isPalendrone( int number )
{
    std::stringstream ss ( std::stringstream::in | std::stringstream::out );
    ss << number;
    std::string testString = ss.str();
    int start = 0;
    int end = testString.size() - 1;
    bool palindrome = true;
    for ( int half = testString.size() * 0.5; start < half; ++start, --end )
    {
        int first = testString[ start ];
        int last = testString[ end ];
        if ( first != last )
        {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

int main()
{
    int errorValue = 0;
    int palindromic = -1;
    for ( int num1 = 999; num1 > 0; --num1 )
    {
        for ( int num2 = 999; num2 > 0; --num2 )
        {
            int test = num1 * num2;
            if ( isPalendrone( test ) && test > palindromic )
            {
                palindromic = test;
            }
                       
        }
    }
    if ( palindromic != -1 )
    {    
        std::cout << palindromic << std::endl;
    }
    else
    {
        errorValue = 1;
    }
    return errorValue;
}
