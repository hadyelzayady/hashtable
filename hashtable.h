#ifndef _HASHTABLELIB_H_
#define _HASHTABLELIB_H_
typedef struct Node Node;
struct Node {
	char*key;
	int value;
	Node* next;
};

typedef struct Node** table;
typedef struct Hashtable Hashtable;
struct Hashtable {
	table table;
	int size;
};
Hashtable hashtable(int size);
int hashstring(int size,char* str);
int insert(Hashtable ht,char* key, int value);
int getValue(Hashtable ht,char*key);
int removekey(Hashtable ht,char*input);
void freeHash(Hashtable ht);

#endif
