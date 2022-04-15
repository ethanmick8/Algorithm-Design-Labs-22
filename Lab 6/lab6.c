#include "lab6.h"

// This function takes no parameters. It declares a List pointer, or "Node" pointer called
// "list", and allocates memory for it. It then sets the list to null by setting list -> data 
// equal to NULL, so that the list is empty. It then returns the list.
Node * initList()
{
    Node * list; // declaration of List pointer
    list = malloc( sizeof(Node) ); // call malloc to allocate memory for the List pointer
    if( list == NULL ) // make sure malloc succeeded
    {
        return NULL;
    }
    list -> data = NULL; // signify the list is empty
    return list; // return the empty list

    // SIMPLIFIED IMPLEMENTATION (LAB SOLUTION):
    return NULL;
}

// This function takes a List * as a parameter and returns the size of the list. It creates a temporary
// Node * variable that is then used to determine the size of the Node * passed in. The function checks for
// the case that the list is empty first, before looping through the list until the end is reached, incrementing
// a count variable for each node encountered.
int getSize(Node * list)
{
    Node * temp = list; // set a temporary variable equal to list to ensure no funky business goes on
    int count = 0; // variable that stores the size of the List

    // if the list is empty, return count, which should still be 0
    if( temp == NULL )
    {
        return count;
    }
    // otherwise, loop through the list until we reach the end, incrementing count for each Node
    // that is encountered
    else
    {
        while( temp != NULL )
        {
            count++;
            temp = temp -> next; // temp points to the next node in the list
        }
    }

    return count;
}

// This function takes a double Node pointer, and a void pointer that references user data. It will
// return 0 on success, or 1 on failure. To do this, the function first creates a newNode, checking that
// malloc succeeds for this. It also checks to see if the list is empty, and performs a special case for that
// scenario. Finally, the core function of the function is the [refer to in-code notes, I'm running out of time]
int insertAtHead(Node ** list, void * data)
{
    int ec = 0; // default error code is success

    Node * newNode; // init a new Node
    newNode = malloc( sizeof(Node) ); // allocate memory for that node
    if( newNode == NULL ) // make sure malloc worked, if it didn't return 1
    {
        return ec++;
    }
    else if( list == NULL ) // also check to see if the list is an empty list
    {
        newNode -> data = data; // put the passed in data in the Node
        newNode -> next = NULL; // Now newNode is the only Node
        return ec; // success
    }
    else
    {
        newNode -> data = data; // put the passed in data in the Node
        newNode -> next = *list; // newNode points to list, which points to NULL
        *list = newNode; // list, technically the "head", becomes the Node we created
        return ec; // success
    }
}

// This function takes a double Node pointer, and removes and returns the data stored at the head
// of the List, or NULL if the list is empty. To do this, [check in code notes for function code explanation,
// I'm running out of time]
void * removeFromHead(Node ** list)
{
    void * removedData; // declare return value
    if( list == NULL ) // if the list is empty, return NULL
    {
        return NULL;
    }

    Node * temp; // use a temporary Node * again

    temp = *list; // assign list to temp
    removedData = temp -> data; // retrieve the data about to be removed
    // SUGGESTION: *list = temp -> next; // move the list pointer to the node after the one being deleted
    free( temp -> data ); // free that data
    // (exclude) temp = temp -> next; // make the list point to the next node
    // (exclude) * list = temp; // reassign so the passed-by-reference value can be updated
    return removedData;
}

// This function takes a double Node pointer and frees the memory allocated to the List.
// It first checks to see if the list is empty, in which case it can just free the list. If it isn't,
// then a temporary Node * is used to free each Node of the list safely.
void freeList(Node ** list)
{
    if( list == NULL )
    {
        free( list ); // just free the "empty" list
    }

    Node * temp; // temporary Node *

    while( temp != NULL )
    {
        temp = *list; // set the temporary list * equal to the passed in double Node pointer
        *list = temp -> next; // make temp list point to the next node in the list
        free( temp ); // free the node safely
        // ADD: temp = *list; // move forward in iteration
    }
}

// This function takes a list of Car structs, and returns a pointer to the car with the most
// miles driven, or NULL if the list is empty. I was running short on time, so the notes within the
// actual function can be referred to when looking for an explanation regarding my code here.
Car * getWithMostMilesDriven(Node * list)
{
    int listSize = getSize( list ); // call getSize for a quick check
    if( listSize == 0 ) // if the list is empty, return NULL
    {
        return NULL;
    }
    float maxMilesDriven = 0.0; // variable to be assigned value retrieved by getMilesDriven()

    Car * testCar; // variable used to store list data we're looking at
    Car * requestedCar; // return variable
    Node * temp = list; // temp list to avoid messing up list

    // loop through the list of Car structs, using our "testCar" variable to acquire and test Cars stored
    // in the data of our list nodes. Use a comparison statement to locate the car with the most miles driven
    // and store that car in requestedCar, which will be returned after the list has been looped through.
    while( temp != NULL )
    {
        testCar = temp -> data; // set the data stored (Car struct) in the list data equal to our Car * variable
        if( testCar -> milesDriven >= maxMilesDriven )
        {
            testCar -> milesDriven = maxMilesDriven; // it becomes the new max
            requestedCar = testCar; // assign testCar to requestedCar, because (so far) its the car we're looking for
            temp = temp -> next; // move to the next node in the list
        }
    }

    return requestedCar; // return car with most miles on it
}

// This function takes a list of car structs, and prints each struct on each own line. If the list is
// empty, the function prints a statement indicating that. Otherwise, the function uses a temporary variable
// to represent the list, as well as a holder Car struct that will store Cars accessed from the data in the list.
// the while loop will allow each successive car struct to be printed out in its entirety.
void printCars(Node * list)
{
    int listSize = getSize( list ); // grab the size
    if( listSize == 0 ) // if the list is empty, return NULL
    {
        printf( "The list is empty; there are no cars here.\n" );
        return; // terminate function
    }

    // initializations
    int i = 0;
    int VIN;
    float miles;
    int accidents;
    Node * temp = list; // temp list again, just like prev functions
    Car * aCar; // struct variable used to access and print members of each car stored in the data of the list

    // fancy header
    printf( "***********************************************************\n" );
    printf( "************************ CAR DATA *************************\n" );
    printf( "***********************************************************\n\n" );

    // loop through the list, accessing the car in each Node and assigning the Car struct members to their corresponding
    // variables before printing out the struct on its own line, and moving to the next node.
    while( temp != NULL )
    {
        aCar = temp -> data; // retrieve the car stored in whatever Node we're on
        VIN = aCar -> vin;
        miles = aCar -> milesDriven;
        accidents = aCar -> numberOfAccidents;
        printf( "Car %d: VIN: %d Miles Driven: %.2f Number of Accidents: %d\n", (i + 1), VIN, miles, accidents );
        temp = temp -> next; // move to the next member of the list
        i++; // next car
    }
}