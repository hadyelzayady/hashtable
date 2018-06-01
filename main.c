// #include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int main()
{
	Hashtable ht=hashtable(10);
	insert(ht,10,"hellow world\0",15);
	int x=getValue(ht,10,"hellow world\0");
	printf("%i\n", x);
	freeHash(ht,10);
	return 0;
}