all: hash

hash.o: hash.c DS.h
	gcc -c hash.c -o hash.o

list.o: list.c DS.h
	gcc -c list.c -o list.o 

main.o: main.c DS.h
	gcc -c main.c -o main.o 

hash: hash.o main.o list.o
	gcc hash.o main.o list.o -o hash -lm

clean:
	rm -v *.o hash
