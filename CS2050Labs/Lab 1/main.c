#include "lab1.h"

int main() 
{
    float result; // variable for use in avgOdd function
	int j; // variable used for avgOdd function's return value


	FILE *file = fopen("numbers.txt", "r");

	if(!file) {
		// Unable to open the specified file
		return EXIT_FAILURE;
	}

	int size;

	if(fscanf(file, "%d", &size) != 1) {
		fclose(file);
		// Unable to read the array size from the file
		return EXIT_FAILURE;
	}

	int array[size];

	for(int i = 0; i < size; ++i) {
		fscanf(file, "%d", array + i);
	}

    fclose(file);

	// call the function to take attempt to take the average
	j = avgOdd( array, size, &result );

	if ( j == 0 )
	{
		// A return value of 0 indicates the below statement occured. (No odds)
		printf( "ERROR: The elements in the file were unable to be averaged." );
	}
	else
	{
        // The only other possible return value is the number of elements averaged, as specified in the lab document.
		printf( "The number of elements averaged was: %d\n", j );
		printf( "The average was: %.2f\n", result);
	}

	return 0;
} // end main
