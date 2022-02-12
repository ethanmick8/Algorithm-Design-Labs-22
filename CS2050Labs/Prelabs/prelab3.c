#include <stdio.h>
#include <stdlib.h>

// file used to test createDoubleArray and freeDoubleArray
#define FILENAME "prelab3file.txt" 

/* Function returns a double array that can be indexed starting at
minindex and ending at maxindex. After allocation, the freeDoubleArray
will be called to free the array at its specific index location */
double * createDoubleArray( int minIndex, int maxIndex )
{
    double * array; // declaration of double array to be created
    int size = ( maxIndex - minIndex + 1 ); // calculate the requested size

    array = (double *)malloc( size * sizeof(double) ); // mallocate the double array 
    // ^^^^^ ( (double *) optional for some reason )

    return array - minIndex; // return the address that is minIndex units b4 the start address
} // end function createDoubleArray

/* This function frees the memory allocated in the createDoubleArray
function. Because the index changes the specific location of the memory
that is allocated to a location minIndex units before the start, we have
to add minIndex back to free the memory */
void freeDoubleArray( double * array, int minIndex )
{
    free( array + minIndex );   
} // end function freeDoubleArray

// This main function just tests to make sure the above two function operate correctly
int main(void)
{
    /* Create an array to that will hold the average rainfall for each year from 1960
    to 1980 */
    double * rainfall = createDoubleArray(1960, 1970);

    FILE * fp = fopen( FILENAME, "r" ); // open the file

    if ( fp != NULL )
    {
        // scan the values into the array from the file
        for ( int i = 1960; i <= 1970; i++ )
        {    
            fscanf( fp, "%lf", &rainfall[i] );
        }

        // Print the avg rainfall from the year 1969
        printf( "Average rainfall in 1969: %.2lf\n", rainfall[1969] );

        // Calculate and print average of values from 1960 through 1965
        double sum = 0.0;
        for ( int i = 1960; i < 1965; i++ ) 
        {   
            sum += rainfall[i];
        }
        printf("Avg rainfall 1960-1965: %.2lf\n", sum / 5 );

        // call freeDoubleArray to free the memory from wherever it was specified to be
        freeDoubleArray( rainfall, 1960 );

        // close the file
        fclose( fp );
    } 

    return 0;
} // end function main