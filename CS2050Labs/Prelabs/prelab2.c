#include <stdio.h>
#include <stdlib.h>

// Symbolic Constant(s)
#define FILENAME "prelab2file.txt"

// function prototype(s)
float * readFloatFileIntoArray( FILE * fptr, int * length );
void freeFloatArray( float * array );

// main function
int main( int argc, char * argv[] )
{
    int length = 0;
    float * array;
    FILE * openReadFile;

    // call function to get the values from the file
    array = readFloatFileIntoArray( openReadFile, &length );

    if( array == NULL )
    {
        printf( "Malloc failed. There were no values to be read.\n" );
    }
    else
    {
        printf( "The array values from the file are:\n" );
        for ( int i = 0; i < length; ++i )
        {
            printf( "%.2f\n", array[i] );
        } // end for
    } // end else

    // call freeFloatArray function to free the allocated memory
    freeFloatArray( array );

    return 0;
} // end main

/* This function is designed to open a file specified by the user in the calling
function, and obtain the length/size of the file from the first entry in the file,
which is assumed to designate how many float values will follow in the file.
After this, the function will allocate the correct amount of memory with malloc for
a float array and read the values from the value into this array. This array will
then be returned to the calling function (main). If the file can't be opened, or
malloc fails, this function returns NULL. */ 
float * readFloatFileIntoArray( FILE * fptr, int * length )
{
    fptr = fopen( FILENAME, "r" ); // attempt to open the file

    // make sure the file can be opened before performing key function tasks
    if( NULL != fptr )
    {
        fscanf( fptr, "%d", length ); // obtain the length from the file

        float * array = malloc( sizeof(float) ** length ); // allocate memory

        // check to see if malloc failed. If so, return NULL
        if ( array == NULL )
        {
            return NULL;
        } // end if
        // otherwise, read the float values from the file into the array
        else
        {
            for ( int i = 0; i < * length; ++i )
            {
                fscanf( fptr, "%f\n", &array[i] );
            } // end for
        } // end else

        fclose( fptr ); // close the file

        return (float *)array; // return the float array
    } // end if
    // if the file can't be opened, the function returns NULL
    else
    {
        return NULL;
    } // end else
} // end function readFloatFileIntoArray

/* This function is designed to free the memory allocated by malloc for the float
array. The user will pass their array variable by reference to this function, and
it will free the memory as well as set their array value to NULL so that they don't 
accidently reference memory that has been freed. */
void freeFloatArray( float * array )
{
    free( array ); // use the "free" function to free the memory
    array = NULL; // visualization (technically the "free" function already does this)
} // end function freeFloatArray