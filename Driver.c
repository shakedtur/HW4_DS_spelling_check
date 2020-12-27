#define _CRT_SECURE_NO_WARNINGS
//#include "WordSpellingChecker.h"
#include "HashTable.h"


//int parseWordsToTable(char* path, HashTable* ht);
//SpellingSuggestion* spellingCheck(char* text);
///*
//	Add help functions here...
//*/

int main()
{
	char t[100] = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	////int a = constantStringHashFunction(t);
	////printf("%d" , a);
	////long int b = accumulateStringHashFunction(t);
	////printf("%d", b);
	//int c = improvedHashFunction(t);
	//printf("%d", c);
	//char* text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	//SpellingSuggestion* spellingSuggestions = spellingCheck(text);
	//printSpellingSuggestions(spellingSuggestions);
	//LinkedList* head = NULL;
	char lior[100] = "lior";
	char shaked[100] = "shaked";
	char aaaa[100] = "cscscscscscttt";
	LinkedList* head = NULL;
	head = BuildNode(lior);
	PrintList(head);
	head = addToStart(head, shaked);
	PrintList(head);
	head = addToStart(head, "tttttttttt");
	PrintList(head);
	head = addToStart(head, "cscscscscscttt");
	PrintList(head);
	int a = Search_Nmber(head, shaked);
	printf("%d\n",a);
	//head = DeleteElement(head, a);
	//PrintList(head);
	//printf("%d", a);
}
