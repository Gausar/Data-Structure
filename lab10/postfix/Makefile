all: postfix

postfix.o: postfix.c DS.h
	gcc -c postfix.c -o postfix.o

stack.o: stack.c DS.h
	gcc -c stack.c -o stack.o 

list.o: list.c DS.h
	gcc -c list.c -o list.o 

main.o: main.c DS.h
	gcc -c main.c -o main.o 

postfix: postfix.o main.o list.o stack.o
	gcc postfix.o main.o list.o stack.o -o postfix -lm

clean:
	rm -v *.o postfix
