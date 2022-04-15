#include "lab4.h"

// This function takes a size_t as a parameter that represents the size of an array. The
// function then creates an array of the specified size, first by declaring the array and
// then allocating memory with malloc equivilant to the requested size of ints plus one 
// additional slot equal to the size of size_t, where the function will then store the 
// size parameter at the beginning of the created array. (array+1) is then returned, cast
// to void for simplification.
int * createIntArray( size_t size )
{
    int * array; // array declaration
    array = (int *)malloc( size * sizeof(int) + sizeof(size_t) ); // mallocate
    array[0] = size; // assign size to the first element of the array
    return (void *)(array + 1); // return the array starting at the first address + 1
} // end function createIntArray

// This function takes an integer pointer to an array as a parameter, and simply returns
// the size of the array(a size_t), which is expected to be stored at the true beginning of 
// the array, which would be referenced as array[-1] in this case, since createIntArray 
// returned array+1.
size_t getSize( int * array )
{
    return (size_t *)array[-1]; // simply return the size_t
} // end function getSize

// This function takes an int pointer to an array as a parameter, and then utilizes that
// parameter in order to call my getSize function in order to obtain the size of the passed
// in array. After that, the function utilizes a for loop to loop through the array elements,
// printing each one out in succession on the same line. After all elements are printed,
// the function prints a newline and that's all there is to it.
void printArray( int * array )
{
    size_t size = getSize( array ); // call getSize to, well, get the size
    
    // for loop that loops through the array, printing out all the elements on one line
    // upon exit of the for loop (i.e. all elements are printed), a newline is printed.
    for( int i = 0; i <= size-1; i++ )
    {
        printf( "%d ", array[i] );
    }
    printf( "\n" );
} // end function printArray

// This function takes an int pointer to an array as a parameter, using that parameter to
// call my getSize function, so that its return value (the size) can be used in a for loop
// that contains an "even only" if conditional statement. Whenever the if is entered (i.e. i
// is even and thus represents an even index of the array), the value at that index is added
// to the int variable sum. After the array has been fully looped through, the function returns
// sum.
int sumEvenIndices( int * array )
{
    size_t size = getSize( array ); // call getSize

    int sum = 0; // variable that will hold total sum

    // loop through the elements of the array, adding the contents of even indices to
    // sum, while ignoring the contents of all other indices. (Note: size-1 is used b/c
    // otherwise we'd have 1 to many considering array[0] is the first)
    for( size_t i = 0; i <= size-1; i++ )
    {
        if( i % 2 == 0 )
        {
            sum += array[i];
        }
    }

    return sum; // return the integer holding the sum of all values at even indices
} // end function sumEvenIndices

// This function takes an integer pointer to an array as a parameter and
// calls the free() function from the C library to free the specific 
// memory stored for that array. "array-1" is used in free because the
// array contains a reserved first element that stores the size of the array,
// so that must be accounted for.
void freeArray( int * array )
{
    free( array - 1 );
} // end function freeArray