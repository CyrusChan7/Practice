#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} node_t;

typedef struct linkedList {
	node_t * head;
	node_t * tail;
} LL_t;

LL_t * LLcreate(){
	LL_t * temp = malloc(sizeof(LL_t));
	if (temp == NULL){
		return NULL;
	}
	else {
		temp->head = NULL;
		temp->tail = NULL;
		return temp;
	}
}

int freeYourMallocs(LL_t * list){
	if (list == NULL){
		return 1;	// return 1 signifying that the list was already freed or invalid input
	}

	// free everything then set their pointers back to NULL
	free(list->head);
	list->head = NULL;
	free(list->tail);
	list->tail = NULL;
	free(list);
	list = NULL;

	return 0;	// no errors
}

int main(){

	LL_t * newIntList = LLcreate();
	if (newIntList == NULL){
		printf("Failed to create a new linked list.\n");
	} else {
		printf("Linked list creation success.\n");
	}

	int returnValue = freeYourMallocs(newIntList);
	if (returnValue == 1){
		printf("The list was either freed already or the input is invalid.\n");
	} else if (returnValue == 0) {
		printf("Linked list freed successfully.\n");
	}

	return 0;
}