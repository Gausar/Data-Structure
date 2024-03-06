all: bst

bst.o: bst.c DS.h
	gcc -c bst.c -o bst.o 

main.o: main.c DS.h
	gcc -c main.c -o main.o 

bst: bst.o main.o 
	gcc bst.o main.o -o bst -lm

clean:
	rm -v *.o bst
