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
int Search_Nmber(LinkedList*, int Index);
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

void PrintList(LinkedList* head) {
	LinkedList* temp = head;
	printf("\nThe list is: ");
	while (temp != NULL) {
		printf("%s ", temp->data);
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

///need to change!!!!!!!!!!!!!!!!!!!!!!!!!!!
int Search_Nmber(LinkedList* head, char* letter) {
	LinkedList* temp = head;
	int count = 0;
	while (temp !=NULL) {
		count++;
		if (temp->data == letter)
			return count;
		temp = temp->next;
	}
	return 0;
}

//LinkedList* DeleteElement(LinkedList *, char*) {
//
//}
