// #include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node Node;
#define MAX_LENGTH 30
struct Node {
	char*key;
	int value;
	Node* next;
};
int size = 10;
Node** hashtable;
int hashstring(char* str)
{
	int sum = 0;
	int length = strlen(str);
	// printf("%i\n",length );
	for (int i = 0; i < length; ++i)
	{
		sum += str[i];
	}
	// printf("%i\n",sum % size );

	return sum % size;
}
int insert(char* key, int value)
{
	int i = hashstring(key);
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->value = value;
	node->next = hashtable[i];
	hashtable[i] = node;
	return 0;
}
int getValue(char*key)
{
	int i = hashstring(key);
	Node*next = hashtable[i];
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
int removekey(char*input)
{
	int i = hashstring(input);
	Node*next = hashtable[i];
	Node*prev = next;
	while (next != NULL)
	{
		if (strcmp(next->key, input) == 0)
		{
			if (prev != next)
			{
				prev->next = next->next;
			}
			else { hashtable[i] = NULL; }
			free(next);

			return 0;
		}
		next = next->next;
		prev = next;
	}
	return 0;
}
void freeHash()
{
	Node*temp;
	Node*next;
	for (int i = 0; i < size; ++i)
	{
		next = hashtable[i];
		while (next != NULL)
		{
			temp = next;
			next = next->next;
			free(temp);
		}
		hashtable[i] = NULL;
	}
}

int main()
{
	hashtable = calloc(10, sizeof(Node*)*size);
	insert("hello world\0", 1);
	insert("hello orldw\0", 2);
	// printf("%s\n",hashtable[0]->value );
	printf("%i\n", getValue("hello orldw"));
	printf("%i\n", getValue("hello world"));
	// removekey("hello world");
	freeHash();
	return 0;
}