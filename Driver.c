#define _CRT_SECURE_NO_WARNINGS
#include "WordSpellingChecker.h"
#define PATH "dictionary.txt"
#define Original_Size_Of_HashTable 1024
#define HASHFUNCTYPE 3

int parseWordsToTable(char* path, HashTable* ht);
SpellingSuggestion* spellingCheck(char* text);
void ShowSpellOffers(SpellingSuggestion* offers);
int IsExsistSuggerst(SpellingSuggestion* offers1, char* word1);
void PrintAllHT(HashTable* ht);
void PrintHTParmeters(HashTable* ht);

void main() {
	char* mishpat = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	printf("%s\n", mishpat);
	SpellingSuggestion* Halofot = spellingCheck(mishpat);
	printf("\n");
	ShowSpellOffers(Halofot);
}


int parseWordsToTable(char* path, HashTable* ht) { //open text of dictionary
	FILE* myfile;
	char word[20];
	char* ptrword;
	fopen_s(&myfile, path, "rt");
	if (!myfile) {
		printf("Error, can't read file!!!");
		return 0;
	}
	while (!feof(myfile)) {
		ptrword = (char*)malloc(20 * sizeof(char));
		fscanf(myfile, "%s", ptrword);
		insert(ht, ptrword);
	}
	fclose(myfile);
	return 1;
}


SpellingSuggestion* spellingCheck(char* text) {	//main fucnation openid dictionary
	char str1[20];
	int j = 0;
	HashTable* dict = initTable(Original_Size_Of_HashTable, HASHFUNCTYPE);
	SpellingSuggestion* Firstwrongword = malloc(sizeof(SpellingSuggestion));
	Firstwrongword->originalWord = (char*)malloc(20 * sizeof(char));
	SpellingSuggestion* Lastsuggestion = NULL;
	SpellingSuggestion* ptrFirstwrong = Firstwrongword;
	int flag = 0;
	if (text == NULL || text == "")
		return Firstwrongword = NULL;
	parseWordsToTable(PATH, dict); //opening dictionary from text
	PrintHTParmeters(dict);
	for (int i = 0; i <= strlen(text); i++) {
		if (text[i] == ' ' || text[i] == '\0') {
			str1[j] = '\0';
			j = 0;
			if (isWordInDictionary(dict, str1) == 0) { //if the word not in dictionary
				if (flag == 0) {
					strcpy(Firstwrongword->originalWord, str1);
					Firstwrongword->suggestions = getWordSuggestions(dict, str1);
					Firstwrongword->next = NULL;
					Lastsuggestion = Firstwrongword;
					flag = 1;
				}
				else {	///if the word in dictionary
					if (IsExsistSuggerst(Firstwrongword, str1) == 0) {
						SpellingSuggestion* WrongwordNext = malloc(sizeof(SpellingSuggestion));
						WrongwordNext->originalWord = (char*)malloc(20 * sizeof(char));
						strcpy(WrongwordNext->originalWord, str1);
						WrongwordNext->suggestions = getWordSuggestions(dict, str1);
						WrongwordNext->next = NULL;
						Lastsuggestion->next = WrongwordNext;
						Lastsuggestion = Lastsuggestion->next;
					}
				}
			}
		}
		else {
			str1[j] = text[i];
			j++;
		}
	}
	if (flag == 0)
		return ptrFirstwrong = NULL;
	else
		return ptrFirstwrong;
}


void ShowSpellOffers(SpellingSuggestion* offers)	//print fucation
{
	SpellingSuggestion* temp = offers;
	while (temp != NULL) {
		if (temp->suggestions != NULL) {
			printf("The word ''%s'' was misspelled. Did you mean:\n", temp->originalWord);
			PrintList(temp->suggestions);
		}
		else
			printf("The word ''%s'' was misspelled. No suggestions found for this word.\n", temp->originalWord);
		temp = temp->next;
	}
}


int IsExsistSuggerst(SpellingSuggestion* offers1, char* word1) { //check if the dictionary have suggestent
	SpellingSuggestion* temp1 = offers1;
	if (offers1 == NULL)
		return NULL;
	while (temp1 != NULL) {
		if (temp1->originalWord == word1 || strcmp(temp1->originalWord, word1) == 0)
			return 1;
		temp1 = temp1->next;
	}
	return NULL;
}


void PrintAllHT(HashTable* ht) {	//print fucation
	printf("====================================\n");
	for (int i = 0; i < ht->tableSize; i++) {
		printf("%d ", i);
		PrintList(ht->hashTable[i].chain);
	}
	printf("====================================\n");
}


void PrintHTParmeters(HashTable* ht) {	//print fucation
	printf("-----------------------------------\n");
	printf("hashFunction: %d\n", ht->hashFunction);
	printf("tableSize: %d\n", ht->tableSize);
	printf("callsTaken: %d\n", ht->cellsTaken);
	printf("numOfElements: %d\n", ht->numOfElements);
	printf("-----------------------------------\n");
}