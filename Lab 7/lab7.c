#include "lab7.h"

// HELPER FUNCTIONS ------------------------------------------------------------------------------------->

// This function creates a new Node * to a struct. It allocates memory for the Node *,
// and if malloc works it dereferences the node * and assigns our passed in data and next
// struct variables to it. It then returns the Node *
Node * createNode(void * data, Node * next)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node));
    if( newNode ) { // make sure malloc worked
        *newNode = (Node){data, next};
    }
    return newNode;
}

// This function takes a Node * and an int representing size. The function retrieves the data pointer from the
// passed in list that holds size, and then it dereferences the sizePtr and sets it equal to whatever size was
// passed in (allows size to be easily changed)
void setSize(Node * list, int size)
{
    int * sizePtr = list -> data;
    *sizePtr = size;
}

// LIST FUNCTIONS ------------------------------------------------------------------------------------->

// This function initializes an "empty" Node pointer and returns it. A placeholder/dummy node is
// also initialized here, and the empty Node pointer points to this node. The function makes sure memory
// can be allocated, and it ensures that the dummy node is the only member of the initialized list, but
// that it does not count as an actual member and thus size, stored in the dummy node, is initialized to 0.
Node * initList()
{
    int * size = malloc(sizeof(int)); // malloc for our size variable
    if(!size) { // check malloc
        return NULL;
    }
    *size = 0; // dereference and initialize size, assuming it was allocated
    return createNode(size, NULL); // return a malloced Node, with size as the data and no next pointer
    // UNECESSARY ( above is revised implementation )
    /* if( list == NULL ) // make sure malloc worked
    {
        printf( "The list could not be initialized.\n" );
        return NULL;
    }
    Node * dummyNode;
    dummyNode = createNode();
    if( dummyNode == NULL )
    {
        printf( "The list could not be initialized.\n" );
        return NULL;
    }
    list = dummyNode; // placeholder is only node
    list -> next = NULL; // reaffirm
    list -> data = size; // store size in dummy node
    return list; */
}

// This function takes a Node pointer and returns the size of the list, retrieved from the list
// that is passed in. This function ASSUMES that a valid Node * is passed in, presumably initialized with initList
int getSize(Node *list)
{
    int * size = list -> data; // retrieve size from list
    return *size; // return dereferenced size
}

// This function takes a list *, void * representing user data, and an integer index. The function inserts data into
// the list at the given index only if it is valid, and if the index is equal to the size of the list, the node is inserted
// at the tail of the list. The function returns 0 on success, and 1 on error.
int insertAtIndex(Node *list, void *data, int index)
{
    int size = getSize(list);
    if( index < 0 || index > size ) {
        // index is invalid
        return 1; // failure
    }
    Node * newNode = createNode(data, NULL);
    if( newNode == NULL ) {
        return 1;
    } else {
        Node * temp = list; // make a copy of the list pointer
        // this is done because pointer parameters like "Node *list" probably shouldn't be assigned new values
        // (general rule of thumb)
        while( --index > 0 ) { // decrement and then do the comparison ( bc dummy)
            temp = temp -> next; // move forward
        }
        // insert the newNode after the node we are currently on, temp->next is our index after while loop
        newNode -> next = temp -> next; // after the current location of temp
        temp -> next = newNode; // we do the above b/c the first node in the list (initial temp) is a dummy
    }
    setSize(list, size + 1);
    return 0; // success
}

// This function takes a list pointer and a void * representing user data and inserts a
// new Node at the tail of the passed in list. It returns 1 on error, 0 on success. The function
// loops through to the tail assuming the list is not empty (error) and adds it there. It does all this simply
// by calling insertAtIndex, where the index parameter is equal to the size of the list (the tail index)
int insertAtTail(Node *list, void *data)
{
    int ec = insertAtIndex(list, data, getSize(list));
    if( ec == 1) {
        return 1; // failure
    }
    return 0; // success
    // Uneccessary (above is revised implementation)
    /* if( list == NULL )
    {
        return 1; // failure
    }
    Node * temp = list;
    Node * newNode = createNode();
    if( newNode == NULL )
    {
        return 1;
    }
    newNode -> data = data; // assign data
    while( temp -> next != NULL ) // move through list until tail is reached
    {
        temp = temp -> next;
    }
    temp -> next = newNode; // old tail points to new tail
    newNode -> next = NULL;
    return 0; // success */
}

// This function takes a pointer to a list, and an index value. It fetches the data at the requested
// index and returns it. The function checks for the edge case regarding an index that is out of range.
// It does this by using a while loop that avoids the placeholder at the front of the list and loops until
// the requested node is encountered.
void * getAtIndex(Node *list, int index)
{
    int size = getSize(list);
    if(  index < 0 || index >= size ) {
        return NULL; // failure
    }
    Node * temp = list -> next; // avoid placeholder node at beginning
    while(index-- > 0) { // postfix operator because we need to stop at the requested node
        temp = temp -> next; // move to next node
    }
    return temp -> data; // retrieve data at requested node
}

// This function takes a list pointer and an index, and uses a temp variable to loop through
// to the requested index and remove the data there. The function checks for edge cases like whether
// or not the list is empty, or whether the index is out of range.
void * removeAtIndex(Node *list, int index)
{
    int size = getSize(list);
    if(  index < 0 || index >= size ) {
        return NULL; // failure
    }
    Node * temp = list;
    while(index-- > 0) { // postfix operator because we need to stop at the requested node
        temp = temp -> next; // move to next node
    }
    // remove requested node, should be equal to temp->next after while loop
    Node * remove = temp -> next;
    temp -> next = remove -> next;
    void * data = remove -> data; // retrieve data
    free(remove); // safely free removed node
    setSize(list, size - 1); // decrement size
    return data; // return the retrieved data
    // previous implementation
    /* Node * temp = list;
    if( temp == NULL || getSize( temp ) == 0 )
    {
        return NULL; // failure
    }
    if( index > getSize( temp ) )
    {
        // invalid index
        return NULL;
    }
    Node * newNode = createNode(); // allocate memory
    Node * beforeIndex; // used to reestablish linked list connection when node is removed
    if( newNode == NULL )
    {
        return NULL;
    }
    (list -> data)--; //decrement size
    for( int i = -1; i < index; i++ ) // -1 because dummy Node exists
    {
        beforeIndex = temp;
        temp = temp -> next; // move to next node
    }
    void * data = temp -> data; // retrieve data at requested node
    beforeIndex -> next = temp -> next; // take index node out / maintain linked list
    free( temp ); // remove safely

    return data; // return it */
}

// This function takes a double pointer to a list struct and frees all memory associated
// with it. effectively setting the list pointer to null. It just uses a temp variable to
// loop through the linked list, freeing each node as it is encountered.
void freeList(Node **list)
{
    Node * temp = *list; // create a temproary variable to point to the beginning of the list
    free(temp -> data); // free the memory allocated in initList (for size)
    for(Node * delete = temp; temp; delete = temp) { // manually iterate through, delete each node as it is encountered
        temp = temp -> next;
        free(delete);
    }
    *list = NULL; // set list to NULL
    // previous implementation, not 'incorrect' just not as efficient
    /* while( temp != NULL )
    {
        *list = temp -> next; // make temp list point to the next node in the list
        free( temp ); // free the node safely
        temp = *list; // move forward in iteration
    } */
} // end function
// BONUS: Here is an alternative way of implementing freeList() for this assignment
// This implementation is identical to the one above, it's just a bit more straightforward and uses another function
// to free the data in a more clean way
/* void freeList(Node **list)
{
    while(getSize(*list)) {
        removeAtIndex(*list, 0);
    }
    free((*list)->data); // dereference list(its a pointer passed to our initialized list)
    // (Note: place the whole statement in parenthesis just to be safe bc of precedence)
    free(*list); // free all data allocated to the list
    *list = NULL; // because of a double pointer all we have to say is this
} */