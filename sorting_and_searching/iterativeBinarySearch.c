#include <stdio.h>
#include <stdlib.h>

int iterative_binary_search(int arr[], int len, int target){

	int first = 0;
	int last = len - 1;

	while(first <= last){	// while there are more than one element

		int mid = (first + last) / 2;
		if (target == arr[mid]){
			return mid;				// return the index position at which it was found at
		}
		else if (target < arr[mid]){
			last = mid - 1;			// throw away the last half by changing the last to mid-1
		}
		else if (target > arr[mid]) {
			first = mid + 1;		// throw away the first half by changing the start to mid+1
		}
	}
	return -1;		// not found
}

int main(){

	int sortedArray[7] = {1,3,3,6,8,10,13};
	printf("Array before searching it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", sortedArray[i]);
	}
	printf("\n");

	printf("\nSearching for 5 iteratively...\n");
	int returnVal = iterative_binary_search(sortedArray, 7, 5);
	if (returnVal == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item was found at index position %d\n", returnVal);
	}

	printf("\nSearching for 13 iteratively...\n");
	returnVal = iterative_binary_search(sortedArray, 7, 13);
	if (returnVal == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item was found at index position %d\n", returnVal);
	}

	printf("\nSearching for 3 iteratively...\n");
	returnVal = iterative_binary_search(sortedArray, 7, 3);
	if (returnVal == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item was found at index position %d\n", returnVal);
	}

	return 0;
}