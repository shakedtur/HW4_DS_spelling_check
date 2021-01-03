#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList LinkedList;

struct LinkedList {
	char* data;
	LinkedList  * next;
};

void	PrintList(LinkedList *);
LinkedList *	BuildNode(char*);
LinkedList *	addToStart(LinkedList *, char*);
LinkedList *	FreeList(LinkedList *);
LinkedList *	DeleteElement(LinkedList *, char*);
int Search_index_in_list(LinkedList* head, char* letter);
int isInList(LinkedList*, char*);


LinkedList* BuildNode(char* letter) {
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	node->data = letter;
	node->next = NULL;
	return node;
}

LinkedList* addToStart(LinkedList* head, char* letter)
{
	LinkedList* new_elem = BuildNode(letter);
	new_elem->next = head;
	return new_elem;
}

LinkedList* SumList(LinkedList* head, LinkedList* tail) {
	if (head == NULL) {
		head = tail;
		return head;
	}
	while (head->next!=NULL)
	{
		head = head->next;
	}
	head->next = tail;
}

LinkedList* SortedMerge(LinkedList *  a, LinkedList*  b)
{
	LinkedList*  result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}




void PrintList(LinkedList* head) {
	LinkedList* temp = head;
	printf("The list is: ");
	while (temp != NULL) {
		printf("|%s|", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


LinkedList* FreeList(LinkedList* head) {
	LinkedList* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}


int Search_index_in_list(LinkedList* head, char* letter) {
	LinkedList* temp = head;
	int count = 0;
	if (head == NULL)
		return NULL;
	while (temp !=NULL) {
		count++;
		if (temp->data == letter||strcmp(temp->data,letter)==0)//added strcmp()
			return count;
		temp = temp->next;
	}
	return NULL;
}

LinkedList* DeleteElement(LinkedList* temp_list, char* string) {
	int position = Search_index_in_list(temp_list, string) - 1;
	LinkedList* previous = temp_list, * current = temp_list->next;
	if (temp_list == NULL)
		return 0;
	if (position == 0) {
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


int isInList(LinkedList* temp_list, char* string) {
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