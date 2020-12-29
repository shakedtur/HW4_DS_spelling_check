#pragma once
#include "HashTable.h"

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

char strplace(char* word1,int location,char tav) {
	char wordtemp[20];
	strcpy(wordtemp, word1);
	wordtemp[location] = tav;
	return wordtemp;
}


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
