#include <stdio.h>
#include <stdlib.h>

int optimized_linear_search(int arr[], int len, int target){
	arr[len] = target; 	// MAY HAVE SIDE EFFECTS!!

	int i = 0;
	while (arr[i] != target){		// n + 1
		i++;
	}

	if (i != len){					// 1. Total comparisons become n + 2
		return i;
	}
	else {
		return -1;
	}

}


int main(){

	int unsortedArray[7] = {1,9,7,4,5,3,20};
	printf("Printing out the array:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	printf("\nSearching for 4\n");
	int returnVal = optimized_linear_search(unsortedArray, 7, 4);
	if (returnVal == -1){
		printf("Not found\n");
	}
	else {
		printf("Item found at index position %d\n", returnVal);
	}

	printf("\nSearching for 20\n");
	returnVal = optimized_linear_search(unsortedArray, 7, 20);
	if (returnVal == -1){
		printf("Not found\n");
	}
	else {
		printf("Item found at index position %d\n", returnVal);
	}

	printf("\nSearching for 8\n");
	returnVal = optimized_linear_search(unsortedArray, 7, 8);
	if (returnVal == -1){
		printf("Not found\n");
	}
	else {
		printf("Item found at index position %d\n", returnVal);
	}


	return 0;
}


/* Info about Linear Search (optimized version):

-May use sentinel to cut comparisons by half, still O(n) but with half
	the leading constant

-But why do we care about cutting constants?
	-Big-O leading constants do not matter when comparing two different algorithms with different Big-O
		-They do matter however when their Big-O growth rate is the same. Optimized vs unoptimized

*/