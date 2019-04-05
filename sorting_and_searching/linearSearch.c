#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int len, int target){
	for (int i = 0; i < len; i++){		// n + 1
		if (arr[i] == target){			// n. Total comparisons = 2n + 1
			return i;
		}
	}
	return -1;
}


int main(){

	int unsortedArray[7] = {1,9,7,4,5,3,20};
	printf("Printing out the array:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	printf("\nSearching for 4\n");
	int returnVal = linear_search(unsortedArray, 7, 4);
	if (returnVal == -1){
		printf("Not found\n");
	}
	else {
		printf("Item found at index position %d\n", returnVal);
	}

	printf("\nSearching for 20\n");
	returnVal = linear_search(unsortedArray, 7, 20);
	if (returnVal == -1){
		printf("Not found\n");
	}
	else {
		printf("Item found at index position %d\n", returnVal);
	}

	printf("\nSearching for 8\n");
	returnVal = linear_search(unsortedArray, 7, 8);
	if (returnVal == -1){
		printf("Not found\n");
	}
	else {
		printf("Item found at index position %d\n", returnVal);
	}


	return 0;
}


/* Info about Linear Search:

-It is the best search algorithm for an unordered array
-By convention, return true or the index if found, else return false or -1
	
-Worse case is if the item is not found, followed closely if found at
	the last index
-Best case is if the item is found at index 0; O(1)
-Average case is still O(n) because where the center is depends on the n

-May use sentinel to cut comparisons by half, still O(n) but with half
	the leading constant

*/