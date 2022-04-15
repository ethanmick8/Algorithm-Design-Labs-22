#include "lab8.h"

// In main, I'm simply testing to make sure that all function in the header file, which are
// written in "prelab8.c", do what I want them to do.
int main(void)
{
    Queue * queue;
    int choice;
    queue = NULL;
    while(1) {
        printf("### LIST MENU ###\n");
        printf("1. Initialise Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Get Queue Size\n");
        printf("5. Peek\n");
        printf("6. Free Queue\n");
        printf("Enter your choice (1 - 6): ");
        scanf("%d", &choice);
        if(choice == 1) {
            queue = initQueue();
            if( queue ) {
                printf("\nQueue has been successfully initialised.\n"); 
            }
        }
        else if(queue == NULL) {
            printf("\nPlease initialise the Queue before attempting other operations.\n");
        }
        else {
            if(choice == 2) {
                int data;
                printf("Enter a number: ");
                scanf("%d", &data);
                if(enQueue(queue, &data) == 0) {
                    printf("\nSuccessfully Queued.\n");
                }
                else {
                    printf("\nError occured.\n");
                }
            }
            else if(choice == 3) {
                void * data = deQueue(queue);
                if(data == NULL) {
                    printf("\nThe passed in queue was empty.\n" );
                }
                else {
                    printf("\nSuccessfully deQueued.\n");
                    int * p = data;
                    printf("The data at the dequeued node is: %d\n", *p );
                }
            }
            else if(choice == 4) {
                int size = getSize(queue);
                printf( "\nThe size of the queue is %d\n", size);
            }
            else if(choice == 5) {
                void * data = peek(queue);
                if(data == NULL) {
                    printf("\nThe passed in queue was empty.\n" );
                }
                else {
                    printf("\nSuccessfully peeked.\n");
                    int * p = data;
                    printf("The value of the data we peeked is: %d\n", *p );
                }
            }
            else if(choice == 6) {
                freeQueue(queue);
                printf("\nMemory allocated for queue has been successfully deallocated.\n");
            }
        }

        if(choice < 1 || choice > 6) {
            printf("\nWrong Choice.\n");
        }

        int again;
        printf("\nTo return to the List Menu, enter 1: ");
        scanf("%d", &again);
        if(again != 1) {
            break;
        }
    }
    return 0;
}