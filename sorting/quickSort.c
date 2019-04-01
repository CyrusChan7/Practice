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

	for (int k = 1; k < 7; k++){
		assert(unsortedArray[k-1] <= unsortedArray[k]);
	}
	printf("All assertions passed successfully, exiting program\n");

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

	int smallIndex = 0;
	for (int i = 0; i < last; i++){
		if (arr[i] <= pivot){
			// pseudo insertion-sort, swaps all elements smaller than pivot to the left
			int temp = arr[i];
			arr[i] = arr[smallIndex];
			arr[smallIndex] = temp;
			smallIndex++;
		}
	}
	// swapping pivot so it ends up in the center
	int temp2 = arr[smallIndex];
	arr[smallIndex] = arr[last];
	arr[last] = temp2;

	// printf("smallIndex is %d, returning it\n", smallIndex);
	return smallIndex;
}

/* Info about quick sort:

-First it takes a random pivot and compares all elements to it, if it is smaller than or equal to
pivot, move it to the left. Else if it is greater, then move it to the right
	-Keep recursively doing this until the bottom is reached
	-Aka a Divide and Conquer sort
	-The sort is in-place in nature

-O(nlogn) is the average case and best case
	-Worst case is O(n^2)

	-Rationale:
		-Each partitioning operation takes O(n) operations because of the for loop. On average,
		there are logn partitioning operations. Therefore O(nlogn)

-Why use Quick Sort over Merge Sort if Merge Sort's worse case is always going to be O(nlogn)? 
	This is because QS is cheap to use because the sorting is in-place and does not require the
	creation of new array(s)

-How to overcome Quick Sort's worse case of O(n^2) on an already sorted array? 
	Randomize the pivot as opposed to selecting a specified element based on index position

-Almost all programming languages STL use quick sort for sorting

*/
