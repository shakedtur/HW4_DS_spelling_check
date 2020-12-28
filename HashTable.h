#include <conio.h>
#include <math.h>
#include "LinkedList.h"
#include "string.h"
#define SIZE_OF_HASHTABLE 100

typedef struct HashTableElement HashTableElement;

struct HashTableElement
{
	int key;
	LinkedList* chain;
};

typedef struct HashTable HashTable;

struct HashTable
{
	HashTableElement* hashTable;
	int hashFunction;
	int tableSize;
	int cellsTaken;
	int numOfElements;
};


int constantStringHashFunction(char* str);
int accumulateStringHashFunction(char* str);
int improvedHashFunction(char* str);
int ASCIIvalue(char letter);

int hash(char* str, HashTable* ht);
HashTable* initTable(int tableSize, int hashFunction);
int insert(HashTable* ht, char* str);
int deleteElement(HashTable* ht, char* str);
int search(HashTable* ht, char* str);


int ASCIIvalue(char letter) {
	return letter;
}


int constantStringHashFunction(char* str) {
	long int sum = 0;
	for (int j = 0; str[j]; j++)
		sum += str[j];
	return 3;
}


int accumulateStringHashFunction(char* str) {
	long int sum = 0;
	if (str == NULL)
		return 0;
	for (int i = 0; str[i] != '\0'; i++)
		sum = sum + str[i] % SIZE_OF_HASHTABLE;
	return sum;
}

int improvedHashFunction(char* str) {
	long int sum = 0;
	long int count = strlen(str);

	if (str == NULL)
		return 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		sum = sum + (ASCIIvalue(str[i]) * pow(31, (count - 1) - i));
	}
	return sum;
}


int hash(char* str, HashTable* ht) {
	int index = 0;
	switch (ht->hashFunction)
	{
	case 1:
		index = (absult(constantStringHashFunction(str)) % ht->tableSize);
		break;
	case 2:
		index = (absult(accumulateStringHashFunction(str)) % ht->tableSize);
		break;
	case 3:
		index = (absult(improvedHashFunction(str)) % ht->tableSize);
		break;
	default:
		index = -1;//alarm on a error
		break;
	}
	return index;
}


HashTable* initTable(int tableSize1, int hashFunction) {
	HashTable* NewHAsh =(HashTable*) malloc(sizeof(HashTable));
	if (tableSize1 > 0)
		NewHAsh->tableSize = tableSize1;
	else
		NewHAsh->tableSize = SIZE_OF_HASHTABLE;
	NewHAsh->numOfElements = 0;
	NewHAsh->cellsTaken = 0;
	NewHAsh->hashTable =(HashTableElement*) calloc(NewHAsh->tableSize , sizeof(HashTableElement));
	for (int i = 0; i < NewHAsh->tableSize; i++)
	{
		NewHAsh->hashTable[i].key = i;
		//printf("%d",NewHAsh->hashTable[i].key);
	}
	switch (hashFunction)
	{
	case 1:
		NewHAsh->hashFunction = 1;
		break;
	case 2:
		NewHAsh->hashFunction = 2;
		break;
	case 3:
		NewHAsh->hashFunction = 3;
	default:
		NewHAsh->hashFunction = 3;
		break;
	}
	return NewHAsh;
}

//maybe need to fix if it insert the str to right place in Hashtable?

int insert(HashTable* ht, char* str) {
	if (str == NULL && Search_index_in_list(ht->hashTable->chain,str)>=0 )//need to change to or ||
		return 0;
	else
	{
		int indexkey= hash(str, ht);//change the key value according the match hash function
		ht->hashTable[indexkey].chain =addToStart(ht->hashTable[indexkey].chain, str);//add the new str to head of the list
		ht->numOfElements++;
		return 1;
	}
}

//need to fixxxxxxxxxxxx!!!!!!!!!!!!!!!!!!
int deleteElement(HashTable* ht, char* str)
{
	if (str == NULL && Search_index_in_list(ht->hashTable->chain, str) ==NULL)//need to change to or ||
		return 0;
	else {
		int indexExsistKey = hash(str, ht);
		ht->hashTable[indexExsistKey].chain = DeleteElement(ht->hashTable[indexExsistKey].chain, str);
		//ht->hashTable->chain=DeleteElement(ht->hashTable->chain,str);
		ht->numOfElements--;
		return 1;
	}
}

int search(HashTable* ht, char* str)
{
	if (str != NULL && Search_index_in_list(ht->hashTable->chain, str) > 0)//need to change to or ||
		return 1;
	else
		return 0;
}


int absult(int num) {
	if (num >= 0)
		return num;
	else
	{
		return num *= (-1);
	}

}