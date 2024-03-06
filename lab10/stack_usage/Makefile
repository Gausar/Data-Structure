all: cbt

cbtree.o: cbtree.c DS.h
	gcc -c cbtree.c -o cbtree.o

main.o: main.c DS.h
	gcc -c main.c -o main.o

stack.o: stack.c DS.h
	gcc -c stack.c -o stack.o

cbt: cbtree.o main.o stack.o
	gcc cbtree.o main.o stack.o -o cbt

clean:
	rm -v *.o cbt
