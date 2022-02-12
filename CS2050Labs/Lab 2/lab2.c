#include "lab2.h"

#define FILENAME "numbers.txt"

/* This function takes a file pointer and an int pointer. The file pointer points to
the file that the function will be asked to access by the calling function, while the int
pointer is used to find the array size from the file so that it can be passed back to
the calling function. The function will return a pointer to the array if it succeeds in
reading through it, and NULL if it doesn't */
int * createIntArrayFromFile( FILE * fp, int * size )
{
    fp = fopen( FILENAME, "r" ); // open the file for reading
    
    // make sure the file can be opened before performing key function tasks
    if( NULL != fp )
    {
        fscanf( fp, "%d", size ); // obtain the size from the file

        int * array;
        array = malloc( sizeof(int) ** size ); // mallocate

        // Error check: See if malloc failed. If so, return NULL
        if ( array == NULL )
        {
            return NULL;
        } // end if
        // otherwise, read the float values from the file into the array
        else
        {
            for ( int i = 0; i < * size; ++i )
            {
                fscanf( fp, "%d\n", &array[i] );
            } // end for
        } // end else

        fclose( fp ); // close the file

        return (int *)array; // return the float array
    } // end if
    // if the file can't be opened, the function returns NULL
    else
    {
        return NULL;
    } // end else
} // end function readFloatFileIntoArray

/* This function is designed to take an in array pointer, the size of the array, a
double integer pointer and a user-specified query integer. The function will take this
information and look through the array for instances of the query integer with a for
loop. Upon finding an instance, the function will set the result pointer equal to the
address of the first instance. The function also increments a "looptester" variable if
this occurs, so that the it is then able to determine whether to return 0 (indicating
success) or 1 (failure). */
int firstAddressOf( int * array , int size , int ** result , int element )
{
    int looptester = 0; // test variable for determining return value

    // loop through the array and search element
    for( int i = 0; 0 < size; ++i )
    {
        // the first time element is found (if at all), enter this loop
        if( array[i] == element )
        {
            *result = array + i; // dereferencing a DOUBLE pointer, assigning it to a signle pointer (*result)
            looptester += 1; // increment looptester
            break; // leave the for loop
        } // end if
    } // end for

    // if looptester was not incremented (still 0), we know element wasn't found
    if( looptester == 0 )
    {
        return 1; // return 1 (indicating failure)
    } // end if
    // otherwise, it must've been a success
    else
    {
        return 0; // return 0 (indicating success)
    }
} // end function firstAddressOf

/* This function is designed to free the memory allocated by malloc for the float
array. The user will pass their array variable by reference to this function, and
it will free the memory as well as set their array value to NULL so that they don't 
accidently reference memory that has been freed. */
void freeArray( int * array )
{
    free( array ); // use the "free" function to free the memory
    array = NULL; // visualization (technically the "free" function already does this)
} // end function freeArray