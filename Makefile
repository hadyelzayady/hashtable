all: hashtable.o main.o
	gcc hashtable.o main.o
hashtable.o: hashtable.c
	gcc -c hashtable.c
main.o:main.c
	gcc -c main.c
clean:
	rm *.o