#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"


LinkedList* BuildNode(char* word) {	//funcation building node by geting word and put in list
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	node->data = word;
	node->next = NULL;
	return node;
}


LinkedList* addToStart(LinkedList* head, char* word) {	//funcation adding node to start by the list
	LinkedList* new_elem = BuildNode(word);
	new_elem->next = head;
	return new_elem;
}


LinkedList* SortedMerge(LinkedList* a, LinkedList* b) { //funcation to merge
	LinkedList* result = NULL;
	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);
	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}


void PrintList(LinkedList* head) {	//funcation to print
	LinkedList* temp = head;
	if (temp != NULL) {
		while (temp != NULL) {
			printf("\n");
			printf("%s", temp->data);
			temp = temp->next;
		}
		printf("\n\n");
	}
	else {
		printf("No suggestions found for this word.");
		printf("\n\n");
	}
}


LinkedList* FreeList(LinkedList* head) {	//funcation to free memory
	LinkedList* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}


int Search_index_in_list(LinkedList* head, char* word) { //search word in linklist
	LinkedList* temp = head;
	int count = 0;
	if (head == NULL)
		return NULL;
	while (temp != NULL) {
		count++;
		if (temp->data == word || strcmp(temp->data, word) == 0)//added strcmp()
			return count;
		temp = temp->next;
	}
	return NULL;
}

LinkedList* DeleteElement(LinkedList* temp_list, char* string) {	//funcation do delete word in linkedlist
	int position = Search_index_in_list(temp_list, string) - 1;
	LinkedList* previous = temp_list, * current = temp_list->next;
	if (temp_list == NULL)
		return 0;
	if (position == 0) { //if need to delete the first word
		LinkedList* temp = temp_list;
		temp_list = temp_list->next;
		free(temp);
		return temp_list;
	}
	while (previous != NULL) {
		if (previous->data == string || strcmp(previous->data, string) == 0)//added strcmp()
			break;
		current = previous;
		previous = previous->next;
	}
	if (previous != NULL)
		current->next = previous->next;
	free(previous);
	return temp_list;
}


int isInList(LinkedList* temp_list, char* string) {	//check if word in the list
	LinkedList* temp = temp_list;
	if (temp_list == NULL)
		return 0;
	while (temp != NULL) {
		if (temp->data == string)
			return 1;
		temp = temp->next;
	}
	return 0;
}