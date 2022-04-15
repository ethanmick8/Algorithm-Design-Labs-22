#include "lab9.h"

// Starter Code Functions -------------------------------------------------------------->

void * createArray(size_t elementSize, int numElements) {
	int *array = malloc(sizeof(int) + elementSize * numElements);
	if(!array) {
		return NULL;
	}
	*array = numElements;
	return ++array;
}

void freeArray(void *array) {
	int *arr = array;
	free(arr - 1);
}

int getSize(int *array) {
	return array[-1];
}

// Function Main ----------------------------------------------------------------------->
int main() {
	int * array = createArray(sizeof(int), 5);
	for( int i = 0; i < 5; i++ ) { // ascending order
		array[i] = i+1;
	}
	int size = getSize(array);
	printf("Size better be 5 -> %d\n", size);
	int test = isSortedDescending(array);
	printf("Original Array not sorted descending. proof: %d\n", test);
	for( int i = 0; i < 5; i++ ) { // descending order
		array[i] = -(i+1);
	}
	test = isSortedDescending(array);
	printf("Nooowww its descending. proof: %d\n", test);
	int testtest = descendingBinarySearch(array, 45);
	printf("45 aint in this array. proof it didnt work: %d\n", testtest);
	testtest = descendingBinarySearch(array, -2);
	printf("-2 is tho. proof it worked: %d\n", testtest);

	freeArray(array);
}