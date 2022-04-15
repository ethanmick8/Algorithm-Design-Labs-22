#include "lab8.h"

// STRUCT DEFINITIONS --------------------------------------------------------------------->

typedef struct Node Node;

struct Queue {
    int size;
    Node *head;
    Node *tail;
};

struct Node {
    void *data;
    Node *next;
};

// HELPER FUNCTIONS ----------------------------------------------------------------------->

// Computational Complexity: O(1)
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

// Computational Complexity: O(1)
// This function takes a Queue * and an int representing size. The function retrieves the 
// data from the passed in queue that holds size, and assigns the passed in size variable
// to it (allows size to be easily changed)
void setSize(Queue *q, int size)
{
    q -> size = size; // assign new size to size variable of the passed in Queue
}

// REQUIRED FUNCTIONS --------------------------------------------------------------------->

// Computational Complexity: O(1)
// The function initializes an empty Queue * and returns it. It calls malloc to allocate
// memory for it, and returns NULL if malloc fails. It sets the Queue struct members of size
// to 0, and head and tail pointers both to NULL.
Queue * initQueue()
{
    Queue * newQueue; // init Queue pointer
    newQueue = malloc(sizeof(Queue));
    if(!newQueue) { // error check malloc
        return NULL;
    }
    newQueue -> size = 0; // empty Queue
    newQueue -> head = NULL; // initialize head to NULL
    newQueue -> tail = NULL; // tail to NULL
    return newQueue;
}

// Computational Complexity: O(1)
// This function takes a Queue pointer and returns the size of the queue, retrieved from the 
// queue that is passed in. This function ASSUMES that a valid Queue * is passed in, 
// presumably initialized with initQueue()
int getSize(Queue *q)
{
    int size = q -> size; // retrieve size from the queue
    return size;
}

// Computational Complexity: O(1)
// This function takes a Queue pointer, as well as a data pointer. It places the data onto 
// the back of the queue. It returns 0 on success, or 1 on failure. The function uses both
// helper functions, as well as getSize, in its implementation. It checks for the
// the possibility of an empty queue, as well as a nonexistent one. It assumes nothing about
// the contents of the passed in queue
int enQueue(Queue *q, void *data)
{
    int size = getSize(q); // retrieve the size
    if(size == 0) { // if the passed in queue is empty
        Node * newNode = createNode(data, NULL); // create new node with the passed in data
        if( newNode == NULL ) { // make sure the node could be created
            return 1; // failure
        }
        q -> head = q -> tail = newNode; // both ptrs point to only node in the queue
        setSize(q, size + 1); // increment size with our helper function
        return 0; // success
    }
    Node * newNode = createNode(data, NULL); // create new node
    if( newNode == NULL ) { // check that node was created
        return 1; // failure
    }
    q -> tail -> next = newNode; // add newNode to the back of the queue
    q -> tail = newNode; // update the tail pointer
    setSize(q, size + 1);
    return 0; // success
}

// Computational Complexity: O(1)
// This function takes a Queue pointer, and returns the data at the front of the Queue
// (IE: the next item that would be returned from a call to deQueue) if the queue is not 
// empty. Otherwise, it returns NULL. (This function does not remove the data, it just takes
// a peek)
void * peek(Queue *q)
{
    int size = getSize(q); // check the size of the passed in queue *
    if(size == 0) { // if queue is empty
        return NULL;
    }
    return (q -> head -> data); // retrieve and return
}

// Computational Complexity: O(1)
// This function takes a Queue pointer, and removes and returns the data at the front of the 
// Queue. If the Queue is empty, the function returns NULL. The function does this by
// initializing a temporary Node *, p, and setting it equal to the node that head points to.
// head can then be moved to its next * node, and p, the front node, can be removed.
void * deQueue(Queue *q)
{
    int size = getSize(q); // check size
    if(size == 0) { // if queue is empty
        return NULL;
    }
    Node * p; // init a temporary Node * 
    p = q -> head; // p points to the first node in the queue, just like head
    void * data = p -> data; // retrieve the data in the to be removed node
    q -> head = q -> head -> next; // now, head points to the next variable in the queue
    free(p); // free the memory associated with the removed node
    setSize(q, size - 1); // decrement size
    return data;
}

// Computational Complexity: O(N), where N is the number of variables being freed.
// This function takes a Queue pointer, and frees all memory allocated to the queue. It does
// so by calling deQueue() in a while loop until it returns NULL. Doing so will free each
// node present in the queue, leaving only the initialized empty list, which can then be
// freed just as it would be if the passed in queue had been empty.
void freeQueue(Queue *q)
{
    int size = getSize(q);
    if(size == 0) { // an empty queue was passed
        free(q); // free the Queue
        return; // end function
    }
    while(deQueue(q)) { // loop until deQueue returns NULL
    } // deQueue will free all nodes in the Queue
    free(q); // free the now empty Queue
}
