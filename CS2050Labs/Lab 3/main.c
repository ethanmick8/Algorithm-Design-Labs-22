#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

int main(void)
{
    int * array; // array variable
    int size = 55; // size to be tested
    signed int index = 0; // index to be tested in getAtIndex
    int getAtIndexValue; // value to be assigned return value from getAtIndex
    float average; // value to be assigned average from average function

    array = createCenteredArray( size );

    signed int temp = size-1;
    temp = temp / 2;

    for( signed int i = -temp; i <= temp; i++ )
    {
        printf( "Value %d = %p\n", i, array + i ); // if you're reading this, I only used %p to ensure my function worked
    }

    getAtIndexValue = getAtIndex( array, size, index ); // really not sure why this wasn't working, maybe its just my hastily written main func

    if ( getAtIndexValue == 1 )
    {
        printf( "Requested Index does not exist.\n" );
    }
    else
    {
        printf( "Value at requested index is %d\n", getAtIndexValue );
    }

    average = averageLowerHalf( array, size );
    printf( "The average of the lower half of the array is %.2f\n", average );

    freeCenteredArray( array, size );

    return 0;
} // end function main