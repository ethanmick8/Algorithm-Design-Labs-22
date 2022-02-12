#include <stdio.h>

// function prototype(s)
int numboccur( int array[], int size, int query );

// function main
int main(void)
{
    int j; // variable that stores integer returned by function
    int size = 10; // specified size of array
    int array[] = {0,1,2,3,4,5,6,7,8}; // declaration of array
    int query = 5; // specified query integer

    // obtain number of occurences from function
    j = numboccur( array, size, query );

    // print number of occurences
    printf( "Number of Occurences = %d\n", j );

    return 0;
} // end function main

// function that returns # of integers in array greater than query integer
int numboccur( int array[], int size, int query )
{
    int i; // counter variable
    int j = 0; //variable to be returned

    // loop through the array
    for ( i = 0; i < size-1; i++ )
    {
        if ( array[i] >= query )
        {
            j += 1;
        } // end if
    } // end for

    return j;
} // end function numboccur