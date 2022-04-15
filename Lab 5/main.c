#include "lab5.h"

// for Lab 5 testing purposes
// really didn't give myself a lot of time to do this, and I'm pretty sure I didn't do it right
// but hopefully lab5.c provides the correct method of creating the required functions
int main(void)
{
    FILE * fp = fopen( "cardata.txt", "r" );
    if( fp == NULL )
    {
        printf( "File no work\n" );
        return 0; // bye bye program
    }

    Car * array = createArray( sizeof( Car ), 5 );

    int size = getSize( array );

    // lil file scan action
    for( int i = 0; i <= size; i++ )
    {
        fscanf( fp, "%d", &(array[i].vin) );
        fscanf( fp, "%f", &(array[i].milesDriven) );
        fscanf( fp, "%d", &(array[i].numberOfAccidents) );
    }

    updateMilesDriven( array + 3, 1.0 ); // add a mile
    printf( "\nCar 3's Updated Miles: %.2f\n", array[3].milesDriven );

    incrementNumberOfAccidents( array + 3 );
    printf( "Car 3's Updated Accident Count: %d\n", array[3].numberOfAccidents );

    Car * getLuigisCar = getCarByVIN( array, 500 );
    printf( "Luigi has had %d accidents in %.2f miles. What the hell Luigi.\n", getLuigisCar->numberOfAccidents, getLuigisCar->milesDriven );

    Car * leastMiles = getWithLeastMilesDriven( array );
    printf( "The car with the least miles driven has a VIN of %d\n", leastMiles->vin );

    freeArray( (void *)array );

    return 0;
}