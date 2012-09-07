// Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
// 
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 10474 = 10^4 + 4^4 + 7^4 + 4^4
// As 1 = 14 is not a sum it is not included.
// 
// The sum of these numbers is 1634 + 8208 + 10474 = 110316.
// 
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
#include <iostream>

int pow( int num )
{
    return num * num * num * num * num;
}

int main()
{
    int total = -1;
    for ( int hth = 0; hth < 10; ++hth )
    {
        for ( int tth = 0; tth < 10; ++tth )
        {
            for ( int tho = 0; tho < 10; ++tho )
            {
                for ( int hun = 0; hun < 10; ++hun )
                {
                    for ( int ten = 0; ten < 10; ++ten)
                    {
                        for ( int unit = 0; unit < 10; ++unit )
                        {
                            int number = ( hth * 100000 )
                                       + ( tth * 10000 )
                                       + ( tho * 1000 )
                                       + ( hun * 100 )
                                       + ( ten * 10 )
                                       + unit;
                            int power = pow( hth)
                                      + pow( tth )
                                      + pow( tho ) 
                                      + pow( hun ) 
                                      + pow( ten ) 
                                      + pow( unit );
                            if ( number == power )
                            {
                                total += number;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << total << std::endl;
    return 0;
}


