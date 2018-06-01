// #include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int main()
{
	Hashtable ht=hashtable(10);
	insert(ht,"hellow world\0",15);
	insert(ht,"hellow worldw\0",12);
	int x=getValue(ht,"hellow world\0");
	int y=getValue(ht,"hellow worldw\0");
	printf("%i\n", x);
	printf("%i\n", y);
	freeHash(ht);
	return 0;
}