#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
int hashstring(int size,char* str)
{
	int sum = 0;
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		sum += str[i];
	}
	return sum % size;
}
int insert(Hashtable myhashtable,char* key, int value)
{
	int i = hashstring(myhashtable.size,key);
	table ht=myhashtable.table;
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->value = value;
	node->next = ht[i];
	ht[i] = node;
	return 0;
}
int getValue(Hashtable myhashtable,char*key)
{

	int i = hashstring(myhashtable.size,key);
	table ht=myhashtable.table;
	Node*next = ht[i];
	Node*prev = next;
	while (next != NULL)
	{
		if (strcmp(next->key, key) == 0)
		{
			return next->value;
		}
		next = next->next;
		prev = next;
	}
	return 0;
}
int removekey(Hashtable myhashtable,char*input)
{
	int i = hashstring(myhashtable.size,input);
	table ht=myhashtable.table;
	Node*next = ht[i];
	Node*prev = next;
	while (next != NULL)
	{
		if (strcmp(next->key, input) == 0)
		{
			if (prev != next)
			{
				prev->next = next->next;
			}
			else { ht[i] = NULL; }
			free(next);
			return 0;
		}
		next = next->next;
		prev = next;
	}
	return 0;
}
void freeHash(Hashtable myhashtable)
{
	Node*temp;
	Node*next;
	table ht=myhashtable.table;
	int size=myhashtable.size;
	for (int i = 0; i < size; ++i)
	{
		next =ht[i];
		while (next != NULL)
		{
			temp = next;
			next = next->next;
			free(temp);
		}
		ht[i] = NULL;
	}
}

Hashtable hashtable(int size)
{
	table mytable = calloc(10, sizeof(Node*));
	Hashtable myhashtable={.size=size,.table=mytable};
	return myhashtable;
}