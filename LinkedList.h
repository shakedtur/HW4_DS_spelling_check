#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList LinkedList;

struct LinkedList {
	char* data;
	LinkedList* next;
};

void	PrintList(LinkedList*);
LinkedList* BuildNode(char*);
LinkedList* addToStart(LinkedList*, char*);
LinkedList* FreeList(LinkedList*);
LinkedList* DeleteElement(LinkedList*, char*);
int Search_index_in_list(LinkedList* head, char* letter);
int isInList(LinkedList*, char*);