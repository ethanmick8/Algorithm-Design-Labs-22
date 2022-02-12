#include "lab2.h"

#define FILENAME "numbers.txt"

// main function (really just skin and bones to make sure values are assigned correctly)
int main(void)
{
    int size = 0;
    int * array;
    FILE * openReadFile = fopen( FILENAME, "r" );


    // call function to get values from the file
    array = createIntArrayFromFile( openReadFile, &size );

    if( array == NULL )
    {
        printf( "Malloc failed. There were no values to be read.\n" );
    }
    else
    {
        printf( "The array values from the file are:\n" );
        for ( int i = 0; i < size; ++i )
        {
            printf( "%d\n", array[i] );
        } // end for
    } // end else

    int element = 4;
    int * result = 0;
    int test;

    test = firstAddressOf( array, size, &result, element );

    if ( test == 0 )
    {
        printf( "The element was successfully found.\n" );
        printf( "The elements address is: %p", result );
    }
    else
    {
        printf( "No element of this value was found in the file.\n" );
    }

    freeArray( array );

    return 0;
} // end main

