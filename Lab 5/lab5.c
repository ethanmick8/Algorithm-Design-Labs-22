#include "lab5.h"

// This function takes a size_t representing the size of the element type the user wishes to
// create an array of, as well as an int representing the number of those elements. It then
// creates an array, calls malloc to allocate memory for the requested parameters ( + an additional
// memory space for the size), and then stores the size at the [0] location. The function returns
// the array starting at the [1] position, and as a void *, so that the size at the beginning isn't
// part of the array and any data type can be used, respectively.
void * createArray(size_t elementSize, int numElements)
{
    int * array; // initialize array as int *, doesn't necessarily mean this is the type
    array = malloc( numElements * sizeof(elementSize) + sizeof(int) ); // mallocate
    if( array == NULL ) // make sure malloc succeeded
    {
        printf( "Memory could not be allocated.\n" );
        return NULL;
    }
    array[0] = numElements; // store the size before the beginning of the array
    return (void *)(array + 1); // return the array cast to void so any data type can be used.
}

// This function takes a void * to an array and returns the size stored right before the start of
// the array. This size is expected to be of type int, so when array - 1 is returned, it is cast as
// an int. An addition * is also placed in front of this so that the actual return type is int, as
// required.
int getSize(void * array)
{
    return * (int *)(array - 1); // position right before the start of the array
}
// ****** BETTER LOGICAL WAY OF IMPLEMENTING THE ABOVE FUNCTION FOLLOWS:
// int get size( void * array )
// {
//     int *arr = array; <-- not technically casting, void can pass to a pointer of any type already
//     return arr[-1]; <-- now, we just return our pointer to the array, at [-1]
// }

// This function takes a pointer to a single Car struct, and simply returns the VIN associated with
// that Car.
int getVin(Car * car)
{
    return car -> vin; // return the VIN for the specific car passed in
}

// This function takes a pointer to a single Car struct, and simply returns the float for miles
// driven associated with that Car.
float getMilesDriven(Car * car)
{
    return car -> milesDriven; // return the float for miles Driven of the car passed in
}

// This function takes a pointer to a single Car struct, and simply returns the amount of accidents
// associated iwht that Car.
int getNumberOfAccidents(Car * car)
{
    return car -> numberOfAccidents; // return the number of accidents associated with the car passed in
}

// This function takes a pointer to a single Car struct, as well as a float specifying a specific numbers
// of miles to add to that Car's "milesDriven". It simply assigns the milesToAdd float to the milesDriven
// by using the += arithmetic operator
void updateMilesDriven(Car * car, float milesToAdd)
{
    car -> milesDriven += milesToAdd; // add specified # of miles to mileDriven member of the struct
}

// This function takes a pointer to a single Car struct, and increments that Car's number of accidents
// by 1.
void incrementNumberOfAccidents(Car * car)
{
    car -> numberOfAccidents += 1; // increment numberOfAccidents member of the Car struct by 1
}

// This function takes an array of Car structs, and an integer specifying a specific VIN. The function
// then calls getSize to get the size of the array passed in so that it can be used to loop through and
// look for a car with the specified VIN. The function utilizes my getVin() function to do this. If a matching
// car is found, the function assigns that car to a variable and then returns that variable. The function
// also has a variable called "loopTester", which allows it to understand whether or not a Car was successfully
// found, so that NULL can be returned if the Car was not found.
Car * getCarByVIN(Car * array, int VIN)
{
    int size = getSize( array ); // use getSize to retrieve the size of the passed in array
    int testVIN = 0; // variable used for testing with getVIN function in the for loop
    int loopTester = 0;

    Car * requestedCar; // initialize the return variable

    // loop through the array of Car structs, calling getVin() for each iteration and checking
    // to see whether or not that Car's VIN matches the VIN passed in from the calling function.
    for( int i = 0; i <= size; i++ )
    {
        testVIN = getVin( array + i );
        if( testVIN == VIN )
        {
            requestedCar = array + i;
            loopTester += 1;
        }
    }

    // check to see if the if loop above was entered. If loopTester is == 0, that means it
    // wasn't entered and thus the function failed to find a car with the reqested VIN
    if( loopTester == 0 )
    {
        return NULL; // indicating failure
    }

    return requestedCar;
}

// This function takes an array of Car structs, and loops through that array looking for the Car that
// has the least miles driven. The function calls getSize() to get the size for a for loop, which then
// calls getMilesDriven() for each iteration (car) in the array. If the milesDriven is the lowest
// encountered thus far, that becomes the new leastMilesDriven and the associated Car is assigned to
// the functions return value. Once the whole array has been looped through, our return value should
// hold the car with the least miles driven. The function then just returns that value.
Car * getWithLeastMilesDriven(Car * array)
{
    int size = getSize( array );
    float milesDriven; // variable to be assigned value retrieved by getMilesDriven()
    float leastMilesDriven = 1000000000.00; // assuming no car has a billion miles on it

    Car * requestedCar; // variable for the car we're looking for

    // loop through the array of Car structs, repeatedly calling getMilesDriven and then
    // testing the value for that specific car to see if it has the least miles driven
    for( int i = 0; i <= size; i++ )
    {
        milesDriven = getMilesDriven( array + i );
        if( milesDriven < leastMilesDriven )
        {
            leastMilesDriven = milesDriven; // if so, this milesDriven becomes the new leastMilesDriven
            requestedCar = array + i; // if so, the car in quested becomes our new requested Car
        }
    }

    return requestedCar; // return car with least miles on it
}

// This function takes an array of Car structs, and prints out each struct on its own line. To do so,
// the function retrieves the size of the array with getSize(), and loops through the array. Variables
// are used and are assigned the values retrieved with their respective getter functions for each iteration
// (car) in the loop. The retrieved data for each car is then printed on a single line, with the first car
// being called "Car 1" and so on.
void printCars(Car * array)
{
    int size = getSize( array );
    int VIN;
    float miles;
    int accidents;

    // fancy header
    printf( "***********************************************************\n" );
    printf( "************************ CAR DATA *************************\n" );
    printf( "***********************************************************\n\n" );

    // loop through the array, printing out each struct on its own line
    for( int i = 0; i <= size; i ++ )
    {
        VIN = getVin( array + i );
        miles = getMilesDriven( array + i );
        accidents = getNumberOfAccidents( array + i );
        printf( "Car %d: VIN: %d Miles Driven: %.2f Number of Accidents: %d\n", (i + 1), VIN, miles, accidents );
    }
}

// This function takes a void pointer to an array as a parameter and
// calls the free() function from the C library to free the specific 
// memory stored for that array. "array-1" is used in free because the
// array contains a reserved first element that stores the size of the array,
// so that must be accounted for.
void freeArray(void * array)
{
    free( array - 1);
}
// ****** BETTER LOGICAL WAY OF IMPLEMENTING THE ABOVE FUNCTION FOLLOWS:
// int get size( void * array )
// {
//     int *arr = array;
//     free( arr[-1] );
// }