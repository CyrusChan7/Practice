#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){

	int unsortedArray[7] = {1,9,4,3,5,2,3};
	printf("Array before sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	//selection_sort(unsortedArray, 7);

	printf("Array after sorting it:");
	for (int i = 0; i < 7; i++){
		printf(" %d", unsortedArray[i]);
	}
	printf("\n");

	return 0;
}
