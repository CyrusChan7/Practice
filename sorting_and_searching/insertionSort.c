#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int len){
	for (int i = 1; i < len; i++){
		int newElement = arr[i];
		int j = i;
		while (j > 0 && arr[j-1] > newElement){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = newElement;	// reset the position as it got messed up in
								// the continuous swapping above
	}

}


int main(){
	int unsortedArray[5] = {3,8,7,10,2};

	printf("Before sorting:");
	for (int i = 0; i < 5; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	insertion_sort(unsortedArray, 5);

	printf("After sorting:");
	for (int i = 0; i < 5; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");


	return 0;
}

/* Info about Insertion Sort:

-Basic paradigm:
	-Separates the array into two parts of either sorted or unsorted like Selection Sort
	-Sorted section increases one at a time like Selection Sort

-Worst case time complexity of O(n^2), (where the array is in decreasing order)
-Best case is when array is already sorted, still O(n) because it needs to make n comparisons
-Average case O(n^2)
	-Worst case carries more meaning in this context than best case
	-The best sorting algorithms run in O(nlogn) (divide and conquer)

*/