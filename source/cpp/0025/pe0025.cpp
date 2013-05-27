//
#include <iostream>

typedef long double BigNum;

int numDigits( BigNum num )
{
    int digits = 1;
    while ( num > 10.0 )
    {
        num *= 0.1f; 
        ++digits;
    }
    return digits;
}

int main()
{
    BigNum last = 1;
    BigNum current = 1;
    int term = 2;
    bool error = false;
    int n = 0;
    while ( n < 1000 )
    {
        n = 1;
        BigNum fib = last + current;
        BigNum num = fib;
        while ( num > 10.0 )
        {
            num *= 0.1f; 
            ++n;
        }
        last = current;
        current = fib;
        ++term;
    }
    std::cout << term << std::endl;
    return 0;
}
