#pragma once
#include "HashTable.h"
#include <string.h>
typedef struct SpellingSuggestion SpellingSuggestion;


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
	LinkedList* OfferList1 = /*(LinkedList*)*/malloc(sizeof(LinkedList));
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
	LinkedList* OfferList=/*(LinkedList*)*/malloc(sizeof(LinkedList));
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

void removeChar(char* s, char c) {

	int j, n = strlen(s);
	for (int i = j = 0; i < n; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}

//check 3
LinkedList* deleteCharacterCheck(HashTable* dictionaryTable, char* word)
{

	char checkword3[20];
	LinkedList* OfferList3 = malloc(sizeof(LinkedList));
	OfferList3 = NULL;
	for (int i = 0; i < strlen(word); i++)
	{
		/*int delocation = i + '0';*/
		strcpy(checkword3, word);
		checkword3[i] = '3';
		removeChar(checkword3, '3');
		if (isWordInDictionary(dictionaryTable, checkword3) == 1 && strcmp(checkword3, word) != 0) {
			char* Offerword3 = (char*)malloc(20*sizeof(char));
			strcpy(Offerword3, checkword3);
			OfferList3 = addToStart(OfferList3, Offerword3);
		}

	}

	return OfferList3;
}

char* CombainStr(char* str1, char label, char* str3)
{
	char buffer[20];
	char* temp;
	int len1 = strlen(str1);
	int len2 = strlen(str3);
	strcpy(buffer, str1);
	int k = len1 - 1;
	buffer[++k] = label;

	for (int i = 0; i < len2; i++)
		buffer[++k] = str3[i];
	buffer[++k] = '\0';
	temp = buffer;
	return temp;
}

LinkedList* addCharacterCheck(HashTable* dictionaryTable, char* word) {
	char checkword1[20];
	char checkword2[20];
	char temp[20];
	LinkedList* OfferList = (LinkedList*)malloc(sizeof(LinkedList));
	OfferList = NULL;
	for (int i = 0; i < strlen(word); i++)
	{
		int y = 0;
		for (int j = 0; j <= i; j++, y++)
		{
			checkword1[y] = word[j];
			checkword1[y + 1] = '\0';
		}
		for (int j = i + 1, index = 0; j <= strlen(word); j++)
		{
			checkword2[index] = word[j];
			index++;
		}
		for (int j = 'a'; j <= 'z'; j++)
		{
			strcpy(temp, CombainStr(checkword1, j, checkword2));
			if (isWordInDictionary(dictionaryTable, temp) == 1) {
				char* offerword = (char*)malloc(20 * sizeof(char));
				strcpy(offerword, temp);
				OfferList = addToStart(OfferList, offerword);
			}
		}

	}
	return OfferList;
}

//check5
 LinkedList* switchAdjacentCharacterCheck(HashTable* dictionaryTable, char* word)
{
	 char checkword5[20];
	 LinkedList* OfferList5 = /*(LinkedList*)*/malloc(sizeof(LinkedList));
	 OfferList5 = NULL;
	 
	 for (int i = 0; i < (strlen(word)-1); i++)	 {
		 int j = i + 1;
		 strcpy(checkword5, word);
		 char first, secend;
		 first = checkword5[i];
		 secend = checkword5[j];
		 checkword5[i] = secend;//swap
		 checkword5[j] = first;
		 if (isWordInDictionary(dictionaryTable, checkword5) == 1 && strcmp(checkword5, word) != 0) {
			 char* offerword5 = (char*)malloc(20 * sizeof(char));
			 strcpy(offerword5, checkword5);
			 OfferList5 = addToStart(OfferList5, offerword5);
		 }
	 }

	return OfferList5;
}

 LinkedList* TailList(LinkedList* head) {
	 if (head == NULL)
		 return head;
	 while (head->next != NULL)
	 {
		 head = head->next;
	 }
	 return head;
 }

 LinkedList* getWordSuggestions(HashTable* dictionaryTable, char* word) {

	 LinkedList* SuggestionList = malloc(sizeof(LinkedList));
	 LinkedList* AdditionList;
	 if (word == "" || word == NULL) {
		 return SuggestionList;
	 }
	 SuggestionList = NULL;
	 SuggestionList = addSpaceCheck(dictionaryTable, word);
	 AdditionList = replaceCharacterCheck(dictionaryTable, word);
	 SuggestionList= SortedMerge(SuggestionList,AdditionList );
	 //3
	 SuggestionList = SortedMerge(SuggestionList, deleteCharacterCheck(dictionaryTable, word));
	 //4
	 SuggestionList = SortedMerge(SuggestionList, addCharacterCheck(dictionaryTable, word));
	 //5
	 SuggestionList= SortedMerge(SuggestionList, switchAdjacentCharacterCheck(dictionaryTable, word));

	 LinkedList* dupList = SuggestionList;
	 LinkedList* memoryDelList = NULL;
	 int erase = 0;
	 //loop to run on all the list to find any duplicate word
	 while (dupList != NULL) {
		 if (Search_index_in_list(dupList->next, dupList->data) > 0) {
			 char* dupword = dupList->data;
			 memoryDelList = addToStart(memoryDelList, dupword);
			 erase = 1;//flag to mark delete neccery
		 }
		 dupList = dupList->next;
	 }
	 if (erase == 1) {//delete of list of words in memoery delete words
		 while (memoryDelList!=NULL)
		 {
			char* Wordel = memoryDelList->data;
			SuggestionList = DeleteElement(SuggestionList, Wordel);
			memoryDelList = memoryDelList->next;
		 }
	 }

	 return SuggestionList;

 }
