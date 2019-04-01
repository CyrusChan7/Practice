#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int binary_search(int arr[], int len, int target){

	if (len <= 0){		// if it reaches base case while target is still not found
						// return 0
		return 0;
	}

	int mid = len / 2;

	if (target == arr[mid]){
		printf("Found\n");
		return 1;
	}

	else if (target < arr[mid]){		// if target is less than mid, it must be
										// in the first half of the array
		return binary_search(arr, mid, target);	// recursively search
	}
	else if (target > arr[mid]){
		return binary_search(arr+mid+1, len-mid-1, target);
	}


}

int main(){

	int sortedArray[7] = {1,3,3,6,8,10,13};
	printf("Array before searching it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", sortedArray[i]);
	}
	printf("\n");

	printf("Searching for 1\n");
	binary_search(sortedArray, 7, 1);

	return 0;
}