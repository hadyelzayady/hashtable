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
int insert(Hashtable ht,int size,char* key, int value)
{
	int i = hashstring(size,key);
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->value = value;
	node->next = ht[i];
	ht[i] = node;
	return 0;
}
int getValue(Hashtable ht,int size,char*key)
{
	int i = hashstring(size,key);
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
int removekey(Hashtable ht,int size,char*input)
{
	int i = hashstring(size,input);
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
void freeHash(Hashtable ht,int size)
{
	Node*temp;
	Node*next;
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
	Hashtable myhashtable = calloc(10, sizeof(Node*));
	return myhashtable;
}