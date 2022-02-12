#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype(s)
float findLEQ(float * array, int arraySize, float num, float * result );

// main function
int main(void)
{
    srand(time(0));
    int arraySize = 10;
    float check; // variable that function will be assigned to
    float array[arraySize];
    float num; // variable for user input
    float result = 0.0; // variable to be passed by reference

    printf( "The array of floats is:\n" );
    for ( int i = 0; i < arraySize; ++i )
    {
        array[i] = (rand() % 10 ) + 1;
        printf("%.2f%s", array[i], (((i + 1) == arraySize) ? "]\n\n" : ", "));
    }

    printf( "Please enter a float number:" );
    scanf( "%f", &num );

    check = findLEQ( array, arraySize, num, &result ); // check to see if any values in array are less than user entered value

    if ( check == 1 )
    {
        printf( "The number %.2f is the largest number in the array that is less than the number you entered.\n", num );
    }
    else
    {
        printf( "There is no number in the array less than the number you entered.\n" );
    }

    return 0;
} // end main


// function that takes array & user-provided number, and
// checks to see if a number exists that is less than the
// user-provided number. If so, pass-by-reference changes
// the user-provided number to the applicable number that
// is the largest of all applicable numbers.
float findLEQ(float * array, int arraySize, float num, float * result )
{
    int i = 0;
    int checker = 0; // variable that will be returned

    for ( i = 0; i < arraySize; ++i )
    {
        if ( array[i] < num )
        {
            if ( array[i] > *result )
            {
                *result = array[i];
                checker = 1;
            }    
        }
    }

    return checker;
} // end function findLEQ