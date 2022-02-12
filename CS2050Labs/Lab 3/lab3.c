#include "lab3.h"

/* This function will create a centered array assuming the size that is passed is an ODD value.
If the value is odd, the function allocates the memory for thr array with malloc. It then checks
to see if the size passed was 1, and if so the array pointer is assigned to 0 and it is returned
immediately (being that it is already centered). Assuming this isn't the case, the function will
calculate the value of indicies before/after 0, so that that value can then be used to iterate
through the array, placing corresponding values at their indicies and completing the creation of
the array. Then, array is returned, pointing to 0. */
int * createCenteredArray( int size )
{
    int * array; // declaration of array to be created

    // only create the array if the number of array elements (size) is odd
    if ( size % 2 != 0 )
    {
        array = (int *)malloc( size * sizeof(int) ); // mallocate

        // special case of size = 1; in this case our array will just be centered at the 0
        if ( size == 1 )
        {
            array[0] = 0;
            return array;
        } // end if

        signed int temp = size - 1; // hold the number of values before and after the 0 (signed to accomodate neg values)
        temp = temp / 2; // divide into its two "halves"

        // this for loop works to assign appropriate values at their appropriate indices
        for( int i = 0; i <= size; i++ )
        {
            array[temp-i] = temp-i;
            array[0] = 0;
        } // end for

        // by now, array (or &array[0]) should point to 0, directly in the middle of the allocated array
        // now, we can return the pointer to that location
        return array;
    } // end if
    // otherwise (if size is even), return NULL
    else
    {
        return NULL;
    } // end else
} // end function createCenteredArray

/* This function takes an int array pointer and the size of the array, as well as a specified 
index value. It will then calculate the temp value as was done in the previous function, so 
that a for loop can then be utilized to determine whether or not the specified index value exists
for the specified array. If it does, the value at that index is returned. If it doesn't, 1
is returned. */
int getAtIndex( int * array, int size, int index )
{
    signed int temp = size - 1; // create the holder variable again (same as in createCenteredArray)
    temp = temp / 2; // split into halves

    int indexValue; // variable to be returned; will be assigned the value at the specified index

    // loop through the array indicies, and if a match is found (i.e. the index is valid) return the value stored there
    for( signed int i = -temp; i <= temp; i++ ) // i is signed int here to accomodate negative values
    {
        /* Note: I tested this with various different index values in the included main.c function,
        but couldn't figure out how to get it to recognize a succesful match (existing index). I
        don't know why it won't work, as I even checked to see if replacing i with the specific index
        value that I was attempting to pass would work, and it worked exactly the way I wanted. It's
        probably just something small that I'm forgetting about, but I wanted to make note of it. */
        if( array + i == array + index )
        {
            indexValue = array[i];
        } // end if
        // otherwise, the index is assumed to be invalid and we return 1 indicating error
        else
        {
            return 1;
        } // end else
    } // end for

    return indexValue; // return the value assuming if loop above was entered
} // end function getAtIndex

/* This function takes an int array pointer and the size of the array. It then makes
the temp calculation done in the previous two functions, so that a for loop can be utilized
to loop through the values in the lower half of the passed array. adding each to the "sum"
variable. Sum is then divided by the number of values that were seen, and that float value
is assigned to the variable "average". That variable is then returned. */
float averageLowerHalf( int * array, int size )
{
    signed int temp = size - 1; // holder variable (refer to previous two functions)
    temp = temp / 2;

    int sum; // variable that will hold the lump sum of the values in the lower half
    float average; // final variable that will hold the average of the lower half; this will be returned

    // loop through the lower half of the array, adding the values to the average variable
    for( signed int i = -temp; i <= 0; i++ )
    {
        sum += array[i];
    } // end for

    average = sum / ( temp + 1 ); // divide sum by the number of values in the lower half + the value 0

    return average; // return the average

} // end function averageLowerHalf

/* This function serves to free the memory that was allocated in the createCenteredArray function.
Like the previous functions, it takes an pointer to an int array as well as the size of that
array. The function calls free() to free the memory, as well as set the array value to NULL
so that the user is unable to accidentally reference memory that has been freed. */
void freeCenteredArray( int * array, int size )
{
    free( array );
    array = NULL; // just a lil visualization
} // end function freeCenteredArray