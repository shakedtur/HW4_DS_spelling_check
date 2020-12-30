#pragma once
#include "HashTable.h"
#include <string.h>
typedef struct SpellingSuggestion SpellingSuggestion;

//enum ABC {a=97,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

struct SpellingSuggestion {
	char* originalWord;
	LinkedList  * suggestions;
	SpellingSuggestion* next;
};

int wordSpellingChecker(HashTable* dictionaryTable);
int isWordInDictionary(HashTable* dictionaryTable, char* word);
LinkedList* addSpaceCheck(HashTable* dictionaryTable, char* word);
LinkedList* replaceCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* deleteCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* addCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* switchAdjacentCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* getWordSuggestions(HashTable* dictionaryTable, char* word);

int isWordInDictionary(HashTable* dictionaryTable, char* word)
{
	if (word == NULL || search(dictionaryTable, word) == 0)
		return 0;
	else
		return 1;
}

LinkedList* addSpaceCheck(HashTable* dictionaryTable, char* word)
{
	char checkword1[20];
	char wordtemp2[20];
	LinkedList* OfferList1 = (LinkedList*)malloc(sizeof(LinkedList));
	OfferList1 = NULL;
	for (int i = 1; i < strlen(word); i++)
	{
		strcpy(checkword1, word);
		checkword1[i] = '\0';
		if (isWordInDictionary(dictionaryTable, checkword1) == 1 ) {
			int startcopy = i;
			for (int j = 0; j < strlen(wordtemp2); j++)//copy the rest string to wordtemp2
			{
				wordtemp2[j] = word[startcopy];
				startcopy++;
			}
			if (isWordInDictionary(dictionaryTable, wordtemp2) == 1) {//search if the secnd word also appering the dict
				checkword1[i] = ' ';//plant sapce + end of string
				checkword1[++i] = '\0';
				strcat(checkword1, wordtemp2);
				char* offerword1 = (char*)malloc(20 * sizeof(char));//add to the linklist a one string of the 2 words
				strcpy(offerword1, checkword1);
				OfferList1 = addToStart(OfferList1, offerword1);
			}

		}
	}

	return OfferList1;
}

char* strplace(char* word1,int location) {
	char wordtemp[20];
	for (int i = 0; i < strlen(wordtemp); i++)
	{
		wordtemp[i] = word1[location];

	}
	return wordtemp;
}

//check 2
LinkedList* replaceCharacterCheck(HashTable* dictionaryTable, char* word)
{
	char checkword[20];
	LinkedList* OfferList=(LinkedList*)malloc(sizeof(LinkedList));
	OfferList = NULL;
	for (int i = 0; i < strlen(word); i++)
	{
		strcpy(checkword, word);
		for (int j = 'a'; j <= 'z'; j++)
		{
			checkword[i] = j;
			if (isWordInDictionary(dictionaryTable, checkword) == 1 && strcmp(checkword,word)!=0) {
				char* offerword = (char*)malloc(20 * sizeof(char));
				strcpy(offerword, checkword);
				OfferList = addToStart(OfferList, offerword);
			}
		}

	}
	return OfferList;
}
