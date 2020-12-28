#define _CRT_SECURE_NO_WARNINGS
//#include "WordSpellingChecker.h"
#include "HashTable.h"


int parseWordsToTable(char* path, HashTable* ht);
//SpellingSuggestion* spellingCheck(char* text);
///*
//	Add help functions here...
//*/
#define CONSTABLE 5

int main()
{
	//char t[100] = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
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
	DeleteElement(head, "tttttttttt");
	DeleteElement(head, shaked);
	DeleteElement(head, "cscscscscscttt");

	//char lior[100] = "lior";
	//char shaked[100] = "shaked";
	//char aaaa[100] = "aaaa";
	//char bbb[100] = "bbb";
	//LinkedList* head = NULL;
	//head = BuildNode(lior);
	//PrintList(head);
	//head = addToStart(head, shaked);
	//PrintList(head);
	//head = addToStart(head, bbb);
	//PrintList(head);
	//head = addToStart(head, aaaa);
	//PrintList(head);
	//head = DeleteElement(head, bbb);
	//PrintList(head);
	//head = DeleteElement(head, aaaa);
	//DeleteElement(head, shaked);
	//PrintList(head);
	//head = DeleteElement(head, lior);
	//PrintList(head);

	////part 2 testing
	//int a = Search_Nmber(head, shaked);
	//printf("%d\n",a);

	char t[100] = "My hash";
	//int a1 = constantStringHashFunction(t);
	//printf("%d\n", a1);
	//long int b = accumulateStringHashFunction(t);
	//printf("%d\n", b);
	//long int c = improvedHashFunction(t);
	//printf("%d\n", c);
	HashTable* testHT = initTable(CONSTABLE,2);
	int indextest = hash(t, testHT);
	printf("indextest %d\n", indextest);
	char first[] = "first";
	insert(testHT, first);
	insert(testHT, t);
	PrintList(testHT->hashTable->chain);
	printf("Search befor %d", search(testHT,t));
	////DeleteElement(testHT->hashTable->chain,t);
	//deleteElement(testHT, t);
	//PrintList(testHT->hashTable->chain);
	//printf("Search after del %d\n", search(testHT, t));

	PrintList(testHT->hashTable->chain);
	parseWordsToTable("dictionary1.txt", testHT);
	for (int i = 0; i < CONSTABLE; i++)
	{
		PrintList(testHT->hashTable[i].chain);
	}
	printf("hello");



	//head = DeleteElement(head, a);
	//PrintList(head);
	//printf("%d", a);
}

int parseWordsToTable(char* path, HashTable* ht)
{
	FILE* myfile;
	char word[20];
	path = "dictionary1.txt";
	fopen_s(&myfile, path, "rt");//dict1 is small file
	if (!myfile) {
		printf("Error, can't read file!!!");
		return 0;
		//exit(1);
	}
	while (fgets(word, 20, myfile)) {
		insert(ht, word);
		printf("%s", word);
	}
	fclose(myfile);
	return 1;

}
