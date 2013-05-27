// In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
// 
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// It is possible to make £2 in the following way:
// 
// £1 + 50p + 2*20p + 5p + 2p + 3*1p
// How many different ways can £2 be made using any number of coins?
#include <iostream>
#include <deque>
#include <map>

typedef unsigned int uint;
typedef std::deque< int > List;

bool loop( uint& outTotal, List coins, int start, int target )  
{
    bool solved = false;
    int coin = coins[ 0 ];
    coins.pop_front();

    bool lastCoin = coins.size() == 0;
    //std::cout << "LOOP:" << coin << " Start:" << start << std::endl;
    for ( int i = 0; i <= target; i += coin )
    {
        int num = i == 0 ? start : start - i;
        //std::cout << coin << ":"<< num << std::endl;
        if ( num == 0 )
        {
            ++outTotal;
            solved = true;
            //std::cout << "--- Solve LOOP:" << coin << " Count:" << outTotal << std::endl;
            break;
        }
        else if ( num < 0 )
        {
            break;
        }
        else if ( !lastCoin )
        { 
            loop( outTotal, coins, num, target );
        }
    }
    return solved;
}

int main()
{
    List coins;
    coins.push_back( 200 );
    coins.push_back( 100 );
    coins.push_back( 50 );
    coins.push_back( 20 );
    coins.push_back( 10 );
    coins.push_back( 5 );
    coins.push_back( 2 );
    coins.push_back( 1 );
    int target = 200;
    uint total = 0;
    loop( total, coins, target, target );
    std::cout << total << std::endl;
    return 0;
}
