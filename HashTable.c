#define _CRT_SECURE_NO_WARNINGS
#include "HashTable.h"

int ASCIIvalue(char letter) {	//funcation to retun value of letter in int form
	return letter;
}


int constantStringHashFunction(char* str) {	//For each possible input string, a stack function returns a value of 3.
	long int sum = 0;
	for (int j = 0; str[j]; j++)
		sum += str[j];
	return 3;
}


int accumulateStringHashFunction(char* str) { //Returns the sum of the characters of the string by ascii value
	long int sum = 0;
	if (str == NULL)
		return 0;
	for (int i = 0; str[i] != '\0'; i++)
		sum = sum + str[i] % SIZE_OF_HASHTABLE;
	return sum;
}


int improvedHashFunction(char* str) { // for the string str of length n characters the function returns the stack value calculated
	if (str == NULL)
		return 0;
	int sum = 0;
	int count = strlen(str);
	for (int i = 0; str[i] != '\0'; i++)
		sum = sum + (ASCIIvalue(str[i]) * pow(31, count - i));
	return sum;
}


int hash(char* str, HashTable* ht) {	//return index (cell) of hashtable
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


HashTable* initTable(int tableSize1, int hashFunction) { //Creates an empty table and with the help of a stacking function it gets set the keys of the organs will fit
	HashTable* NewHAsh = (HashTable*)malloc(sizeof(HashTable));
	if (tableSize1 > 0)
		NewHAsh->tableSize = tableSize1;
	else
		NewHAsh->tableSize = SIZE_OF_HASHTABLE;
	NewHAsh->numOfElements = 0;
	NewHAsh->cellsTaken = 0;
	NewHAsh->hashTable = (HashTableElement*)calloc(NewHAsh->tableSize, sizeof(HashTableElement));
	for (int i = 0; i < NewHAsh->tableSize; i++)
		NewHAsh->hashTable[i].key = i;
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


int insert(HashTable* ht, char* str) { //adding word to hashtable
	int indexkey = hash(str, ht);//change the key value according the match hash function
	if (str == NULL || Search_index_in_list(ht->hashTable[indexkey].chain, str) > 0)
		return 0;
	else {
		if (ht->hashTable[indexkey].chain == NULL) //count the number of cells with at list one value
			ht->cellsTaken++;
		ht->hashTable[indexkey].chain = addToStart(ht->hashTable[indexkey].chain, str);//add the new str to head of the list
		ht->numOfElements++;
		return 1;
	}
}


int deleteElement(HashTable* ht, char* str) {	//delete element in hashtable
	int indexExsistKey = hash(str, ht);
	if (str == NULL || Search_index_in_list(ht->hashTable[indexExsistKey].chain, str) == 0)
		return 0;
	else {
		ht->hashTable[indexExsistKey].chain = DeleteElement(ht->hashTable[indexExsistKey].chain, str);
		ht->numOfElements--;
		if (ht->hashTable[indexExsistKey].chain == NULL)//count the number of cells with at list one value
			ht->cellsTaken--;
		return 1;
	}
}


int search(HashTable* ht, char* str) { //function receives a string and a table and checks whether the string exists in the table
	int indexkeysearch = hash(str, ht);
	if (str == NULL || Search_index_in_list(ht->hashTable[indexkeysearch].chain, str) == 0)
		return 0;
	else
		return 1;
}


int absult(int num) { //Turns a number into a positive
	if (num >= 0)
		return num;
	else
		return num *= (-1);
}