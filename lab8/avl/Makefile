all: avl

avl.o: avl.c DS.h
	gcc -c avl.c -o avl.o 

main.o: main.c DS.h
	gcc -c main.c -o main.o 

avl: avl.o main.o 
	gcc avl.o main.o -o avl -lm

clean:
	rm -v *.o avl
