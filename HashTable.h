#include <conio.h>
#include <math.h>
#include "LinkedList.h"
#include "string.h"
#define SIZE_OF_HASHTABLE 90000

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

//help function
int ASCIIvalue(char);
int absult(int);

int constantStringHashFunction(char* str);
int accumulateStringHashFunction(char* str);
int improvedHashFunction(char* str);
int hash(char* str, HashTable* ht);
HashTable* initTable(int tableSize, int hashFunction);
int insert(HashTable* ht, char* str);//need to improve by linkist function
int deleteElement(HashTable* ht, char* str);
//int search(HashTable* ht, char* str);

int constantStringHashFunction(char* str) {
	long int sum = 0;
	for (int j = 0; str[j]; j++)
		sum += str[j];
	//return sum % SIZE_OF_HASHTABLE;
	return 3;
}


int accumulateStringHashFunction(char* str) {
	long int sum = 0;
	if (str == NULL)
		return 0;
	for (int i = 0; str[i] != '\0'; i++)
		sum = sum + str[i]/* % SIZE_OF_HASHTABLE*/;
	return sum;

}

int improvedHashFunction(char* str) {
	long int sum = 0;
	long int count = strlen(str);

	if (str == NULL)
		return 0;
	for (int i = 0; str[i]!='\0' ; i++)
	{
		sum = sum + (ASCIIvalue(str[i]) * pow(31,(count - 1)- i));
	}

	return sum;
}

int hash(char* str, HashTable* ht)
{
	int index = 0;
	switch (ht->hashFunction)
	{
	case 1:
		index = (absult(constantStringHashFunction(str))%ht->tableSize);
		break;
	case 2:
		index=(absult(accumulateStringHashFunction(str)) % ht->tableSize);
		break;
	case 3:
	index = (absult(improvedHashFunction(str)) % ht->tableSize);
	default:
		index = -1;//alarm on a error
		break;
	}
	return index;
}

HashTable* initTable(int tableSize1, int hashFunction)
{
	HashTable* NewHAsh= malloc(sizeof(HashTable));
	if (tableSize1 > 0)
		NewHAsh->tableSize = tableSize1;
	else
		NewHAsh->tableSize = 1;
	NewHAsh->numOfElements = 0;
	NewHAsh->cellsTaken = 0;
	NewHAsh->hashTable = NULL;

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

int insert(HashTable* ht, char* str)
{
	if(/*search() &&*/str==NULL)
	return 0;
	else
	{
		ht->hashTable->key = hash(str, ht->tableSize);//change the key value according the match hash function
		ht->hashTable->chain=str;/*add to start*/
		return 1;
	}
}

int deleteElement(HashTable* ht, char* str)
{
	if (/*search() &&*/str == NULL)
		return 0;
	else
		ht->hashTable->chain;//delete linklist
		return 1;
}


//help function

int ASCIIvalue(char letter)
{
	return letter;
}

int absult(int num) {
	if (num >= 0)
		return num;
	else
	{
		return num *= (-1);
	}

}























