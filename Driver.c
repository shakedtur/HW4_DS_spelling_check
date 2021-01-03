#define _CRT_SECURE_NO_WARNINGS
#include "WordSpellingChecker.h"
//#include "HashTable.h"

 // חשוב מאוד!!!! לשנות את הערכים של הנתיב לקובץ וגודל של הטבלת גיבוב רק כאן!!!!
#define PATH "dictionary.txt"
#define CONSTABLE 1024//1024
#define HASHFUNCTYPE 3 //1 or 2 or 3
//enum ABC { a = 97, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z };

int parseWordsToTable(char* path, HashTable* ht);
SpellingSuggestion* spellingCheck(char* text);
void ShowSpellOffers(SpellingSuggestion* offers);
int IsExsistSuggerst(SpellingSuggestion* offers1, char* word1);
///*
//	Add help functions here...
void PrintAllHT(HashTable* ht);//func to print all the elemnts inside the HT in  cronolog order
void PrintHTParmeters(HashTable* ht);//func to show the parameter of the HT as kind of hashfunc
//*/


int main()
{
	char* mishpat = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	printf("%s\n",mishpat);

	SpellingSuggestion* Halofot = spellingCheck(mishpat);
	ShowSpellOffers(Halofot);

	return 0;
}

int parseWordsToTable(char* path, HashTable* ht)
{
	FILE* myfile;
	char word[20];
	char* ptrword;

	fopen_s(&myfile, path, "rt");
	if (!myfile) {
		printf("Error, can't read file!!!");
		return 0;
		//exit(1);
	}
	while (!feof(myfile)) {
		ptrword = (char*)malloc(20 * sizeof(char));
		//fgets(ptrword, 20, myfile);
		fscanf(myfile, "%s", ptrword);
		insert(ht, ptrword);
		//printf("%s ", ptrword);
	}

	fclose(myfile);
	return 1;

}

SpellingSuggestion* spellingCheck(char* text)
{

	char str1[20];
	int j = 0;
	HashTable* dict = initTable(CONSTABLE, HASHFUNCTYPE);
	SpellingSuggestion* Firstwrongword= malloc(sizeof(SpellingSuggestion));
	Firstwrongword->originalWord = (char*)malloc(20 * sizeof(char));
	SpellingSuggestion* Lastsuggestion = NULL;
	SpellingSuggestion* ptrFirstwrong = Firstwrongword;
	int flag = 0;
	if (text == NULL || text == "")
		return Firstwrongword = NULL;
	parseWordsToTable(PATH, dict);
	PrintHTParmeters(dict);
	for (int i = 0; i <= strlen(text); i++)	{
		
		if (text[i] == ' ' || text[i] == '\0') {
			str1[j] = '\0';
			j = 0;
		//search if the word is wrong according the dictionary
			if (isWordInDictionary(dict, str1) == 0) {
				if (flag == 0) {
					strcpy(Firstwrongword->originalWord, str1);
					Firstwrongword->suggestions = getWordSuggestions(dict, str1);
					Firstwrongword->next = NULL;
					Lastsuggestion = Firstwrongword;
					flag = 1;
				}
				else{
					if (IsExsistSuggerst(Firstwrongword,str1) == 0) {
						SpellingSuggestion* WrongwordNext = /*(SpellingSuggestion*)*/malloc(sizeof(SpellingSuggestion));
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
		else{
			str1[j] = text[i];
			j++;
		}
	}
	if (flag == 0)
		return ptrFirstwrong = NULL;
	else
		return ptrFirstwrong;
}

void ShowSpellOffers(SpellingSuggestion* offers)
{
	SpellingSuggestion* temp=offers;
	while (temp!=NULL)
	{
		printf("The word ''%s'' was misspelled. Did you mean:\n\t", temp->originalWord);
		PrintList(temp->suggestions);
		temp = temp->next;
	}
	printf("\n");

}

int IsExsistSuggerst(SpellingSuggestion* offers1,char* word1) {
	SpellingSuggestion* temp1 = offers1;
	if (offers1 == NULL)
		return NULL;
	while (temp1 != NULL){
		if (temp1->originalWord == word1||strcmp(temp1->originalWord,word1)==0)
			return 1;
		temp1 = temp1->next;
	}
	return NULL;
}


void PrintAllHT(HashTable* ht) {
	printf("====================================\n");
	for (int i = 0; i < ht->tableSize; i++)
	{
		printf("%d ", i);
		PrintList(ht->hashTable[i].chain);
	}
	printf("====================================\n");

}
void PrintHTParmeters(HashTable* ht) {
	printf("-----------------------------------\n");
	printf("hashFunction: %d\n",ht->hashFunction);
	printf("tableSize: %d\n",ht->tableSize);
	printf("callsTaken: %d\n",ht->cellsTaken);
	printf("numOfElements: %d\n",ht->numOfElements);
	printf("-----------------------------------\n");
	
}