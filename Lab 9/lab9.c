#include "lab9.h"

// Helper Function(s) ------------------------------------------------------------------>

// This function performs binary search on an array expected to be in descending order.
// It returns 1 if the specified query element is found, and 0 if it is not. This function
// is used in descendingBinarySearch() in order to simplify its implementation. In 
// addition to the inclusion of first and last ints to simplify the search, an int *
// representing the index is included so that descendingBinarySearch() can obtain the
// index value of the element it is searching for if it is found to be in the array.
int binarySearch(int *array, int first, int last, int query, int * index)
{
	int mid = (first + last)/2;
	if( query < array[mid] ) { // then it's in the 2nd half
		return binarySearch(array, mid-1, last, query, index); // recursively call again
	}
	if( query > array[mid] ) { // 1st half
		return binarySearch(array, mid+1, last, query, index); // recursion 1st half
	}
	if( array[mid] == query ) { // found it
		*index = mid; // dereference index and set it equal to query's index (mid)
		return 1; // success
	}
	else { // query element is not in array
		return 0; // failure
	}
}

// Lab Functions ----------------------------------------------------------------------->

// The function takes an int * representing an array, as well as an integer acting as a
// query (representing an element in the array). The function calls isSortedDescending()
// to make sure the passed in array is in descending order. If it is, the function 
// calls the binary search helper function, passing a pre-declared index value by reference
// as well as 0 for the starting index (assumed), and the size-1 for the last index (in
// addition to the array and element, ofc). If the helper returns 0, we know that the element
// was not found, and so -1 is returned. If the helper doesn't return 0, we know it must
// have found the element in the array, and so the function returns index, which the
// helper function will have modified to set equal to the index of element.
int descendingBinarySearch(int *array, int element)
{
	if( isSortedDescending(array) == 0 ) { // if array isn't sorted
		return -1; // failure
	}
	int size = getSize(array);
	int index = 0;
	if( binarySearch(array, 0, size-1, element, &index) == 0 ) { // if element isn't in array
		return -1; // failure
	}
	return index; // index successfully found
}

// The function takes an int * representing an array, and checks to see if it is sorted
// in descending order. It calls getSize to retrieve the size for use in a for loop that
// iterates through the array, checking each index to see if that index's successor index
// is greater than it. If it is, the array is not in descending order and 0 is returned.
// The for loop will complete if the comparsion statement checking for that is never met,
// and then we'll know that it must be sorted correctly, so we can just return 1.
int isSortedDescending(int *array)
{
	int size = getSize(array); // call getSize to use in for loop
	for( int i = 0; i < size-1; i++ ) { // loop through array
		if( array[i+1] > array[i] ) {
			return 0; // not sorted
		}
	}
	return 1; // sorted
}