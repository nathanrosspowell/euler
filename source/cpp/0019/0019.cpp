// You are given the following information.
//
//   1 Jan 1900 was a Monday
//     Thirty days has September,
//     April, June and November,
//     All the rest have thirty-0ne,
//     Saving February alone,
//     Which has twenty-eight rain or shine,
//     And on a leap year, twenty-nine
//   A Leap year occurs on any year divisible by four, but not on a century, unless it's divisble by 400,
//
// How many Sundays fell on the first month during the twentieth century ( 1 Jan 1901 to 31 Dec 2000 ).
#include <iostream>

bool leapYear( int year )
{
    if ( year % 100 == 0 )
    {
        return year % 400 == 0;
    }
    return year % 4 == 0;
}

void getYear( int* months, int year )
{
    int feb = leapYear( year ) ? 29 : 28;
    months[ 0 ] = 31;
    months[ 1 ] = feb;
    months[ 2 ] = 31;
    months[ 3 ] = 30;
    months[ 4 ] = 31;
    months[ 5 ] = 30;
    months[ 6 ] = 31;
    months[ 7 ] = 31;
    months[ 8 ] = 30;
    months[ 9 ] = 31;
    months[ 10 ] = 30;
    months[ 11 ] = 31;
}

int daysInYear( int year )
{
    return leapYear( year ) ? 366 : 365;
}

int startDayIndex()
{
    return daysInYear( 1900 ) % 7;
}

bool isSunday( int dayIndex )
{
    return dayIndex % 7 == 6;
}

int main()
{
    int sundaysOnTheFirst = 0;
    int day = startDayIndex();
    for ( size_t year = 1901; year < 2001; ++year )
    {
        int months[ 12 ];
        getYear( months, year );
        for ( size_t month = 0; month < 12; ++month )
        {
            day += months[ month ];
            if ( isSunday( day ) )
            {
                ++sundaysOnTheFirst;
            }
        }

    }
    std::cout << sundaysOnTheFirst << std::endl;
    return 0;
}
