#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void merge_sort(int arr[], int first, int last){
	if (last <= first){
		return;
	}

	int mid = (first+last) / 2;

	merge_sort(arr, first, mid);
	merge_sort(arr, mid+1, last);

	merge(arr, first, mid, last);

}

// Most of the below code in this function DO NOT belong to me, I claim no credit
// for the work done in the merge function
void merge(int arr[], int first, int mid, int last){ 
	int len = last-first+1;
	int newArr[len];
	int left = first;
	int right = mid+1;
	int newPos = 0;

	while (left <= mid && right <= last){
		if (arr[left] < arr[right]){
			newArr[newPos++] = arr[left++];
		} else {
			newArr[newPos++] = arr[right++];
		}
	}

	// Flush non-empty piece
	while (left <= mid){
		newArr[newPos++] = arr[left++];
	}
	while (right <= last){
		newArr[newPos++] = arr[right++];
	}

	for (int i = 0; i < len; i++){
		arr[i] = newArr[i];
	}

}


int main(){

	int unsortedArray[7] = {1,9,4,3,5,2,3};
	printf("Array before sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	merge_sort(unsortedArray, 0, 6);

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