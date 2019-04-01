#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// function prototyping
void selection_sort(int arr[], int len);
void swap(int * index1, int * index2);

int main(int argc, char const *argv[]){
	
	int unsortedArray[7] = {1,9,4,6,5,2,3};
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


	return 0;
}

void selection_sort(int arr[], int len){
	int min = arr[0];
	unsigned int indexCounter = 0;
	for (int i = 0; i < len; i++){
		min = arr[i];
		for (int j = i; j < len; j++){
			if (arr[j] < min){
				min = arr[j];
				indexCounter = i;
			}
		}
		/* swapping algorithm 
		temp = a;
		a = b;
		b = temp;
		*/
		int temp = arr[j];
		arr[j] = arr[indexCounter];
		arr[indexCounter] = temp;
	}


}

/* Info about the sort:

-The array is divided into sorted (on the left) and unsorted (on the right)

Big-O notation is O(n^2)

*/