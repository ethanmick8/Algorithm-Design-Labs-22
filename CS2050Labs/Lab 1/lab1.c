#include "lab1.h"

// REQUIRED FUNCTION IMPLEMENTATIONS
// This function works together with the (slightly modified) starter code also present in
// this zip file in order to do the required tasks specified on the lab document. I've
// made comments where I see fit and after testing my code everything seems to work just fine.
int avgOdd(int *array, int size, float *result )
{
    int i; // for loop counter
    int count = 0; // variable that will store the number of elements averaged (the return value)
    int sum = 0; // variable that will store the sum of all odd elements encountered

    // loop through the values of the array from main, keeping track of the number of odd elements
    // and also the total value of those odd elements
    for ( i = 0; i < size; ++i )
    {
        // proceed only if the array value is NOT even (so odd)
        if ( !(array[i] % 2 == 0) )
        {
            count += 1; // add 1 to count, indicating an odd value was found.
            sum += array[i]; // add the found odd value to the sum.
        } // end if
    } // end for

    // take the average only if at least 1 element was found
    // after doing that, return count (as indicated by the lab document).
    if ( count != 0 )
    {
        *result = sum / count; //take the average and place it in the result pointer.
        return count;
    } // end if
    // otherwise, return count (which would be 0)
    else
    {
        return count;
    } // end else
} // end function avgOdd