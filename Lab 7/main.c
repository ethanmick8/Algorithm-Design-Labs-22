#include "lab7.h"

// In main, I'm simply testing to make sure that all function in the header file, which are
// written in "prelab7.c", do what I want them to do.
int main(void)
{
    Node * list;
    int choice;
    list = NULL;
    while(1) {
        printf("### LIST MENU ###\n");
        printf("1. Initialise List\n");
        printf("2. Insert At Index\n");
        printf("3. Insert At Tail\n");
        printf("4. Remove At Index\n");
        printf("5. Free List\n");
        printf("Enter your choice (1 - 5): ");
        scanf("%d", &choice);
        if(choice == 1) {
            list = initList();
            if( list ) {
                printf("\nList has been successfully initialised.\n"); 
            }
        }
        else if(list == NULL) {
            printf("\nPlease initialise the List before attempting other operations.\n");
        }
        else {
            if(choice == 2) {
                int headData;
                printf("Enter a number: ");
                scanf("%d", &headData);
                if(insertAtHead(&headData, list) == 0) {
                    printf("\nSuccessfully Inserted\n");
                }
                else {
                    printf("\nError occured\n");
                }
            }
            else if(choice == 3) {
                int tailData;
                printf("Enter the data: ");
                scanf("%d", &tailData);
                if(insertAtHead(&tailData, list) == 0) {
                    printf("\nSuccessfully Inserted\n");
                }
                else {
                    printf("\nError occured\n");
                }
            }
            else if(choice == 4) {
                void * removedFromHead = removeHead(list);
                int * p = removedFromHead;
                printf( "The head node was successfully removed.\n" );
                printf( "The value extracted is: %d\n", *p );
            }
            else if(choice == 5) {
                freeList(list);
                printf("\nMemory allocated to list has been successfully deallocated.\n");
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