#ifndef _HASHTABLELIB_H_
#define _HASHTABLELIB_H_
typedef struct Node Node;
struct Node {
	char*key;
	int value;
	Node* next;
};

typedef Node** Hashtable;

Hashtable hashtable(int size);
int hashstring(int size,char* str);
int insert(Hashtable ht,int size,char* key, int value);
int getValue(Hashtable ht,int size,char*key);
int removekey(Hashtable ht,int size,char*input);
void freeHash(Hashtable ht,int size);

#endif
