#define _CRT_SECURE_NO_WARNINGS
#include "WordSpellingChecker.h"


int isWordInDictionary(HashTable* dictionaryTable, char* word) {	//check if word in dictionary
	if (word == NULL || search(dictionaryTable, word) == 0)
		return 0;
	else
		return 1;
}


//Spell checking 1
LinkedList* addSpaceCheck(HashTable* dictionaryTable, char* word) { //The function takes the wordand for each pair of adjacent letters it adds a space
	char checkword1[20];
	char wordtemp2[20];
	LinkedList* OfferList1 = /*(LinkedList*)*/malloc(sizeof(LinkedList));
	OfferList1 = NULL;
	for (int i = 1; i < strlen(word); i++) {
		strcpy(checkword1, word);
		checkword1[i] = '\0';
		if (isWordInDictionary(dictionaryTable, checkword1) == 1) {
			int startcopy = i;
			for (int j = 0; j < strlen(wordtemp2); j++) {	//copy the rest string to wordtemp2
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


//Spell checking 2
LinkedList* replaceCharacterCheck(HashTable* dictionaryTable, char* word) { //The function replaces each character with a word and replaces each of the characters between ‘a’ and ‘z
	char checkword[20];
	LinkedList* OfferList = malloc(sizeof(LinkedList));
	OfferList = NULL;
	for (int i = 0; i < strlen(word); i++) {
		strcpy(checkword, word);
		for (int j = 'a'; j <= 'z'; j++) {
			checkword[i] = j;
			if (isWordInDictionary(dictionaryTable, checkword) == 1 && strcmp(checkword, word) != 0) { //if the word in dicitonary and does not appear again
				char* offerword = (char*)malloc(20 * sizeof(char));
				strcpy(offerword, checkword);	//copy word
				OfferList = addToStart(OfferList, offerword);
			}
		}
	}
	return OfferList;
}


void removeChar(char* s, char c) { //remove char from string
	int j, n = strlen(s);
	for (int i = j = 0; i < n; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}


//Spell checking 3
LinkedList* deleteCharacterCheck(HashTable* dictionaryTable, char* word) { //The function deletes every character in the word and if the new word appears in the dictionary then it will be added to the list of suggestions
	char checkword3[20];
	LinkedList* OfferList3 = malloc(sizeof(LinkedList));
	OfferList3 = NULL;
	for (int i = 0; i < strlen(word); i++) {
		/*int delocation = i + '0';*/
		strcpy(checkword3, word);
		checkword3[i] = '3';
		removeChar(checkword3, '3');
		if (isWordInDictionary(dictionaryTable, checkword3) == 1 && strcmp(checkword3, word) != 0) { //if the word in dicitonary and does not appear again
			char* Offerword3 = (char*)malloc(20 * sizeof(char));
			strcpy(Offerword3, checkword3); //copy word
			OfferList3 = addToStart(OfferList3, Offerword3);
		}
	}
	return OfferList3;
}


char* three_string_to_one(char* string1, char* string2, char* letter) {	//add 3 strings to one
	int length_of_string1 = strlen(string1);
	int length_of_string2 = strlen(string2);
	char string3[20];
	strcpy(string3, string1); //copy fisrt string
	string3[length_of_string1] = letter; //addint the letter
	int new_length_of_strin = length_of_string1;
	for (int i = 0; i < length_of_string2; i++) { //add secound string
		string3[new_length_of_strin] = string2[i];
		new_length_of_strin++;
	}
	char* temp = string3;
	return temp;
}


//Spell checking 4
LinkedList* addCharacterCheck(HashTable* dictionaryTable, char* word) { //Between any two adjacent letters, before and after the word, the function adds each of the characters from 'a' to 'z.'
	char checkword1[20];
	char checkword2[20];
	char checkword3[20];
	LinkedList* OfferList = (LinkedList*)malloc(sizeof(LinkedList));
	OfferList = NULL;
	for (int i = 0; i < strlen(word); i++) {
		int count = 0;
		for (int j = 0; j <= i; j++, count++) { //count letter under the first condition and thus passes through all letters
			checkword1[count] = word[j]; //add to fisrt string
			checkword1[count+1] = '\0';
		}
		for (int j = i + 1, index = 0; j <= strlen(word); j++) { //count letter under the first condition and thus passes through all letters
			checkword2[index] = word[j];	//add to secound string
			index++;
		}
		for (int j = 'a'; j <= 'z'; j++) {
			strcpy(checkword3, three_string_to_one(checkword1, checkword2, j)); //adding all string and letters
			if (isWordInDictionary(dictionaryTable, checkword3) == 1) { //if the word in dicitonary
				char* offerword = (char*)malloc(20 * sizeof(char));
				strcpy(offerword, checkword3);
				OfferList = addToStart(OfferList, offerword);
			}
		}
	}
	return OfferList;
}


//Spell checking 5
LinkedList* switchAdjacentCharacterCheck(HashTable* dictionaryTable, char* word) { //For every two adjacent letters the function performs a substitution and if the new word appears in the dictionary then it will be added
	char checkword5[20];
	LinkedList* OfferList5 = malloc(sizeof(LinkedList));
	OfferList5 = NULL;
	for (int i = 0; i < (strlen(word) - 1); i++) {
		int j = i + 1;
		strcpy(checkword5, word); //copy word
		char first, secend;
		first = checkword5[i];
		secend = checkword5[j];
		checkword5[i] = secend;//swap
		checkword5[j] = first;
		if (isWordInDictionary(dictionaryTable, checkword5) == 1 && strcmp(checkword5, word) != 0) { //if the word in dicitonary and does not appear again
			char* offerword5 = (char*)malloc(20 * sizeof(char));
			strcpy(offerword5, checkword5);
			OfferList5 = addToStart(OfferList5, offerword5);
		}
	}
	return OfferList5;
}


LinkedList* getWordSuggestions(HashTable* dictionaryTable, char* word) { //The list of suggestions consists of words according to each of the five methods described above.
	LinkedList* SuggestionList = malloc(sizeof(LinkedList));
	LinkedList* AdditionList;
	if (word == "" || word == NULL)
		return SuggestionList;
	SuggestionList = NULL;
	//Spell checking 1
	SuggestionList = addSpaceCheck(dictionaryTable, word);
	//Spell checking 2
	AdditionList = replaceCharacterCheck(dictionaryTable, word);
	SuggestionList = SortedMerge(SuggestionList, AdditionList);
	//Spell checking 3
	SuggestionList = SortedMerge(SuggestionList, deleteCharacterCheck(dictionaryTable, word));
	//Spell checking 4
	SuggestionList = SortedMerge(SuggestionList, addCharacterCheck(dictionaryTable, word));
	//Spell checking 5
	SuggestionList = SortedMerge(SuggestionList, switchAdjacentCharacterCheck(dictionaryTable, word));
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
		while (memoryDelList != NULL) {
			char* Wordel = memoryDelList->data;
			SuggestionList = DeleteElement(SuggestionList, Wordel);
			memoryDelList = memoryDelList->next;
		}
	}
	return SuggestionList;
}