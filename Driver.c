#define _CRT_SECURE_NO_WARNINGS
//#include "WordSpellingChecker.h"
#include "HashTable.h"

 // חשוב מאוד!!!! לשנות את הערכים של הנתיב לקובץ וגודל של הטבלת גיבוב רק כאן!!!!
#define PATH "dictionary1.txt"
#define CONSTABLE 10
#define HASHFUNCTYPE 2 //1 or 2 or 3

int parseWordsToTable(char* path, HashTable* ht);
//SpellingSuggestion* spellingCheck(char* text);
///*
//	Add help functions here...
//*/

void PrintAllHT(HashTable* ht);//func to print all the elemnts inside the HT in  cronolog order
void PrintHTParmeters(HashTable* ht);//func to show the parameter of the HT as kind of hashfunc



int main()
{
	char t[100] = "My hash";
	HashTable* testHT = initTable(CONSTABLE, HASHFUNCTYPE);
	PrintHTParmeters(testHT);
	PrintAllHT(testHT);
	char first[] = "first";
	insert(testHT, first);
	insert(testHT, t);
	PrintAllHT(testHT);
	PrintList(testHT->hashTable->chain);
	printf("Search befor %d\n", search(testHT,t));
	////DeleteElement(testHT->hashTable->chain,t);
	//deleteElement(testHT, t);
	//PrintList(testHT->hashTable->chain);
	//printf("Search after del %d\n", search(testHT, t));

	PrintList(testHT->hashTable->chain);
	parseWordsToTable(PATH, testHT);
	printf("AfterREadinggggggggggggggggggggg\n");
	PrintHTParmeters(testHT);
	PrintAllHT(testHT);
	deleteElement(testHT, first);//כששולחים כתובת של מילה למחיקה היא נמחקת
	deleteElement(testHT, "ability");//כששולחים מילה זהה בכתיב, היא לא נמחקת מהטבלה
	PrintAllHT(testHT);
	printf("search my hash %d\n", search(testHT, t));//החיפוש לא מגיע למפתח של הרשימה המקושרת
	printf("search My hash as a string %d\n", search(testHT, "My hash"));
	
	
	printf("hello");


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