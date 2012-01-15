/*

Problem 4
16 November 2001

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

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
    for ( int half = testString.size() / 2; start < half; ++start, --end )
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

bool isPalendrone2( int number )
{
    std::stringstream ss ( std::stringstream::in | std::stringstream::out );
    ss << number;
    std::string testString = ss.str();
    int digits = 0;
    int numberCopy = number;
    while( numberCopy > 0 ) 
    {
        ++digits;
        numberCopy = static_cast<int>( numberCopy * 0.1 );
    }
    
    int start = 0;
    int end = digits-1;
    
    bool palindrome = true;
    for ( int half = digits / 2; start < half; ++start, --end )
    {
        int first = int( number / pow( 10.0, start ) ) % 10;
        int last = int ( number / pow( 10.0, end ) ) % 10;
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
    
    std::cout << "The largest palondromic number is " << palindromic << std::endl;

    return errorValue;
}
