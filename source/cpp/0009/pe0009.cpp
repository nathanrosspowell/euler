// A Pythagorean triplet is a set of three natural numbers, a  b  c, for
// which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <cmath>

int main()
{
    int errorValue = 0;
    int goal = 1000;
    int loop = 1000;
    int a = 1;
    int b = 1;
    int c = 0;
    bool done = false;
    for ( ; a < loop; ++a )
    {
        b = 0;
        for ( ; b < loop; ++b )
        {
            if ( a > b )
            {
                continue;
            }
            int a2 = a * a;
            int b2 = b * b;
            int c2 = a2 + b2;
            for ( int ci = 0; ci < c2 && !done; ++ci )
            {
                int testC2 = ci * ci;
                if ( testC2 > c2)
                {
                    break;
                }
                else if ( testC2 == c2 )
                {
                    c = ci;
                    if ( (a + b + c) == goal )
                    {
                        if ( b < c )
                        {
                            done = true;
                            break;
                        }
                    }
                }
            }
            if ( done )
            {
                break;
            }
        }
        if ( done )
        {
            break;
        }
    }
    if ( done )
    {
        std::cout << a*b*c << std::endl;
    }
    else
    {
        std::cout << "DOH a:" << a << " b:" << b << " c:" << c << " abc:" << a*b*c << std::endl;
        errorValue = 1;
    }
    return errorValue;
}
