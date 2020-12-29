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
///*
//	Add help functions here...
void PrintAllHT(HashTable* ht);//func to print all the elemnts inside the HT in  cronolog order
void PrintHTParmeters(HashTable* ht);//func to show the parameter of the HT as kind of hashfunc
//*/


int main()
{
	////LinkedList* reshima=NULL;
	////char one[]="one";
	////char two[] = "two";
	////char three[] = "three";
	////char ehad[] = "one";
	////reshima=addToStart(reshima, one);
	////PrintList(reshima);
	////reshima=addToStart(reshima, two);
	////reshima=addToStart(reshima, three);
	////PrintList(reshima);
	////int b = Search_index_in_list(reshima, "two");
	////printf("%d\n", b);
	////reshima=DeleteElement(reshima,"two");
	////int a=Search_index_in_list(reshima, "two");
	////PrintList(reshima);
	////printf("%d",a);
	////	return 0;
	//char t[100] = "My hash";
	
	HashTable* testHT = initTable(CONSTABLE, HASHFUNCTYPE);
	//PrintHTParmeters(testHT);
	//PrintAllHT(testHT);
	//char first[] = "first";
	//insert(testHT, first);
	//insert(testHT, t);
	//PrintAllHT(testHT);
	//PrintList(testHT->hashTable->chain);
	//printf("Search befor %d\n", search(testHT,t));
	//////DeleteElement(testHT->hashTable->chain,t);
	////deleteElement(testHT, t);
	////PrintList(testHT->hashTable->chain);
	////printf("Search after del %d\n", search(testHT, t));
	//char above[] = "above";
	//PrintList(testHT->hashTable->chain);
	
	parseWordsToTable(PATH, testHT);
	//printf("AfterREadinggggggggggggggggggggg\n");
	//PrintHTParmeters(testHT);
	//PrintAllHT(testHT);
	//deleteElement(testHT, first);
	//deleteElement(testHT, "ability");
	//PrintAllHT(testHT);
	//printf("search above %d\n", search(testHT,above));
	//printf("search above as a string %d\n", search(testHT, "above"));
	//deleteElement(testHT, "above");
	//PrintHTParmeters(testHT);
	//PrintAllHT(testHT);
	//insert(testHT, "shaked");
	//insert(testHT,"able");
	//insert(testHT, t);
	PrintHTParmeters(testHT);
	deleteElement(testHT, "about");
	PrintHTParmeters(testHT);
	//PrintAllHT(testHT);
	//printf("search above as a string %d\n", search(testHT, "above"));
	//printf("hello");
	
	int d=isWordInDictionary(testHT, "beer");
	int e=isWordInDictionary(testHT, "beel");
	printf("%d,%d\n", d, e);
	LinkedList* suggelist=NULL;
	PrintList(suggelist);
	suggelist= replaceCharacterCheck(testHT, "bake");
	PrintList(suggelist);
	//printf("%d %d", d, e);


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