#include <stdio.h>
#include <stdlib.h>

int iterative_binary_search(int arr[], int len, int target){

	int first = 0;
	int last = len - 1;

	while(first <= last){

		int mid = (first + last) / 2;
		if (target == arr[mid]){
			return mid;
		}

		if (target < arr[mid]){
			last = mid - 1;
		}
		else if (target > arr[mid]) {
			first = mid + 1;
		}
	}
	return -1;
}

int recursive_binary_search(int arr[], int len, int target){

	if (len <= 0){		// if it reaches base case while target is still not found
						// return -1, signaling fail
		return -1;
	}

	int mid = len / 2;

	if (target == arr[mid]){
		printf("Found\n");
		return 1;
	}

	else if (target < arr[mid]){		// if target is less than mid, it must be
										// in the first half of the array
		return recursive_binary_search(arr, mid, target);	// recursively search
	}
	else if (target > arr[mid]){
		return recursive_binary_search(arr+mid+1, len-mid-1, target);
	}
}


int main(){

	int sortedArray[7] = {1,3,3,6,8,10,13};
	printf("Array before searching it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", sortedArray[i]);
	}
	printf("\n");

	printf("Searching for 5 iteratively...\n");
	int returnVal1 = iterative_binary_search(sortedArray, 7, 5);
	if (returnVal1 == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item was found at index position %d\n", returnVal1);
	}


	printf("Searching for 5 iteratively...\n");
	int returnVal2 = iterative_binary_search(sortedArray, 7, 5);
	if (returnVal2 == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item was found at index position %d\n", returnVal2);
	}

	printf("Searching for 13 iteratively...\n");
	returnVal2 = iterative_binary_search(sortedArray, 7, 13);
	if (returnVal2 == -1){
		printf("Item not found in array\n");
	}
	else {
		printf("The item was found at index position %d\n", returnVal2);
	}
	

	return 0;
}

/* Info about Binary Search:

-Array must be sorted beforehand (disadvantage of BS compared to Linear Sort)
	-Keeping array sorted can be expensive

-Two ways of implementing Binary Search, iteratively or recursively, the latter is preferred
-Best search for an unordered array is Linear Search O(n)

-General paradigm:
	-Divide the array into half the size every time, until the item is found (or not)
		--If item found, return the index or 1, if fail return -1
	-Which half to keep depends on the middle element's value and target's value, whether it is greater or lesser
		-Middle element is at index (first+last) / 2

-After k iterations, roughly n/ 2^k candidates remain
-When 2^k >= n, candidates run out or when k >= log(2 subscript) n

-Recursive Binary Search runs in O(logn) because half of all elements are thrown out every recursive call

*/