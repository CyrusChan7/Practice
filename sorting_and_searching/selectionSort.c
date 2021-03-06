#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// function prototyping
void selection_sort(int arr[], int len);

int main(int argc, char const *argv[]){
	
	int unsortedArray[7] = {1,9,4,3,5,2,3};
	printf("Array before sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	selection_sort(unsortedArray, 7);

	printf("Array after sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	// testing assertions
	for (int k = 1; k < 7; k++){
		assert(unsortedArray[k-1] <= unsortedArray[k]);
	}
	printf("All assertions passed, program is exiting gracefully.\n");

	return 0;
}

void selection_sort(int arr[], int len){

	int minNumber = arr[0];
	unsigned int indexOfMin = 0;

	for (int i = 0; i < len; i++){

		minNumber = arr[i];
		indexOfMin = i;

		for (int j = i; j < len; j++){
			if (arr[j] < minNumber){
				minNumber = arr[j];
				indexOfMin = j;
			}
		}

		int tempNum = arr[i];			// temp = a;
		arr[i] = arr[indexOfMin];		// a = b;
		arr[indexOfMin] = tempNum;		// b = temp;
	}

}

/* Info about selection sort:

-The array is divided into sorted (on the left) and unsorted (on the right)

-Big-O notation is O(n^2) due to the nature of the nested for loops
	-The comparisons are O(1) constant time
	-The swappings are also O(1) constant time

	-There are no average cases or worse cases, it will always be O(n^2)

*/