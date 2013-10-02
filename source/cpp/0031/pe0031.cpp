// In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
// 
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// It is possible to make £2 in the following way:
// 
// 1£1 +50p + 220p + 15p + 12p + 31p
// How many different ways can £2 be made using any number of coins?
#include <iostream>
#include <vector>
#include <map>

typedef unsigned int uint;
typedef std::vector< uint > List;
typedef std::map< uint, uint > Map;
typedef std::pair< uint, uint > Pair;

/*
uint test( const List& coins, Map& store, int target = 200 )
{
    uint total = 0;
    for ( List::const_iterator i = coins.begin(); i != coins.end(); ++i )
    {
        int result = target - *( i );
        if ( result == 0 )
        {
            total += 1;
        }
        else if ( result > 0 )
        {
            Map::iterator mapIter = store.find( result );
            if ( mapIter == store.end() )
            {
                uint testResult = test( coins, store, result );
                mapIter = store.insert( Pair( result, testResult ) ).first;
            }
            total +=  mapIter->second;
        }
    }
    return total;
} 
*/

uint test( const List& coins, Map& store, int start = 0, int target = 3 )  
{
    uint total = 0;
    for ( uint num = start; num < target + 1; ++num )
    {
        for ( List::const_iterator coin = coins.begin(); coin != coins.end(); ++coin )
        {
            int result = num - *( coin );
            if ( result == 0 )
            {
                if ( num == target)
                    std::cout << " and  +" << *( coin ) << std::endl;
                total += 1;
            }
            else if ( result > 0 )
            {
                if ( num == target)
                    std::cout << " + " << *( coin ) ;
                Map::iterator mapIter = store.find( result );
                if ( mapIter != store.end() )
                {
                    uint testResult = test( coins, store, result );
                    mapIter = store.insert( Pair( result, testResult ) ).first;
                }
                //total += 1;
                total += mapIter->second; 
            }
        }
    }
}

int main()
{
    Map store;
    List coins;
    coins.push_back( 1 );
    coins.push_back( 2 );
    coins.push_back( 5 );
    coins.push_back( 10 );
    coins.push_back( 20 );
    coins.push_back( 50 );
    coins.push_back( 100 );
    coins.push_back( 200 );
    uint total = test( coins, store );
    std::cout << total << std::endl;
    return 0;
}
