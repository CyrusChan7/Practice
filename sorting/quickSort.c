#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// function prototyping
void quick_sort(int arr[], int first, int last);
int partition(int arr[], int first, int last);

int main(){

	int unsortedArray[7] = {1,9,4,3,5,2,3};
	printf("Array before sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	quick_sort(unsortedArray, 0, 6);

	printf("Array after sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	return 0;
}

void quick_sort(int arr[], int first, int last){

	if (last <= first){
		return;
	}

	int mid = partition(arr, first, last);

	// recursively sort each half
	quick_sort(arr, first, mid-1);
	quick_sort(arr, mid+1, last);

}

int partition(int arr[], int first, int last){
	int pivot = arr[last];
	int length = (first + last + 1);
	int mid = length / 2;
	printf("mid is %d, returning %d\n", mid, mid);
	return mid;
}

/* Info about quick sort:

-First it takes a random pivot and compares all elements to it, if it is smaller than or equal to
pivot, move it to the left. Else if it is greater, then move it to the right
	-Keep recursively doing this until the bottom is reached
	-Aka a Divide and Conquer sort

*/
