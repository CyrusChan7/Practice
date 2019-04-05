#include <stdio.h>
#include <stdlib.h>

int recursive_binary_search(int arr[], int len, int target){

	if (len <= 0){		// if it reaches base case while target is still not found
						// return -1, signaling fail
		return -1;
	}

	int mid = len / 2;		// divide the length of mid by half every recursive call

	if (target == arr[mid]){
		return 1;
	}

	else if (target < arr[mid]){
		return recursive_binary_search(arr, mid, target);	// recursively search the first half of the array
	}
	else if (target > arr[mid]){
		return recursive_binary_search(arr+mid+1, len-mid-1, target);	// recursively search the last half of the array
	}
}

int main(){

	int sortedArray[7] = {1,3,3,6,8,10,13};
	printf("Array before searching it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", sortedArray[i]);
	}
	printf("\n");


	printf("\nSearching for 5 recurisvely...\n");
	int returnVal = recursive_binary_search(sortedArray, 7, 5);
	if (returnVal == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item is present in the array\n");
	}

	printf("\nSearching for 3 recurisvely...\n");
	returnVal = recursive_binary_search(sortedArray, 7, 3);
	if (returnVal == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item is present in the array\n");
	}

	printf("\nSearching for 10 recurisvely...\n");
	returnVal = recursive_binary_search(sortedArray, 7, 10);
	if (returnVal == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item is present in the array\n");
	}
	

	return 0;
}