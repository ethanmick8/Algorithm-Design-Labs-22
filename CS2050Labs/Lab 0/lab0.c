#include "lab0.h"

int countOccurrences( int size, int array[], int query )
{
    int i; // counter
    int count = 0; // variable used to store # of instances of query

    for ( i = 0; i < size; ++i )
    {
        if ( array[i] == query )
        {
            count += 1;
        } // end if
    } // end for

    return count;
} // end function countOccurences
