// Starting in the top left corner of a 22 grid, there are 6 routes (without
// backtracking) to the bottom right corner.
//
// How many routes are there through a 2020 grid?
#include <iostream>
#include <cmath>

const int gridsize = 20 + 1; // Corners.
typedef unsigned long long BigInt;

BigInt calculate( BigInt grid[][ gridsize ], int y )
{
    if ( y >= gridsize )
    {
        const int oneoff = gridsize - 1; 
        return grid[ oneoff ][ oneoff ];
    }
    int newY = y - 1; 
    for ( int x = 0; x <= y; ++x )
    {
        int newX = x - 1;
        if ( newX < 0 || newY < 0 )
        {
            grid[ x ][ y ] = 1;
            grid[ y ][ x ] = 1;
        }
        else
        {
            BigInt xVal = grid[ newX ][ y ];
            BigInt yVal = grid[ x ][ newY ];
            BigInt result = xVal + yVal;
            grid[ x ][ y ] = result;
            grid[ y ][ x ] = result;
        }
    }
    return calculate( grid, ++y );
}

int main()
{
    BigInt grid[ gridsize ][ gridsize ];
    grid[ 0 ][ 0 ] = 1;
    BigInt result = calculate( grid, 1 );
    std::cout << result << std::endl;
    return 0;
}
