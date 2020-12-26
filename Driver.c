#define _CRT_SECURE_NO_WARNINGS
//#include "WordSpellingChecker.h"
#include "HashTable.h"


//int parseWordsToTable(char* path, HashTable* ht);
//SpellingSuggestion* spellingCheck(char* text);
///*
//	Add help functions here...
//*/
#define CONSTABLE 90000
int main()
{
	char t[100] = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	int a = constantStringHashFunction(t);
	printf("%d\n" , a);
	long int b = accumulateStringHashFunction(t);
	printf("%d\n", b);
	long int c = improvedHashFunction(t);
	printf("%d\n", c);

	HashTable* test = initTable(CONSTABLE,2);
	int indextest = hash(t, test);

	printf("hello");


	//char* text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	//SpellingSuggestion* spellingSuggestions = spellingCheck(text);
	//printSpellingSuggestions(spellingSuggestions);
	return 0;
}
