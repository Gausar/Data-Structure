all: lqs

stack.o: stack.c DS.h
	gcc -c stack.c -o stack.o

queue.o: queue.c DS.h
	gcc -c queue.c -o queue.o

list.o: list.c DS.h
	gcc -c list.c -o list.o

main.o: main.c DS.h
	gcc -c main.c -o main.o

lqs: stack.o queue.o list.o main.o
	gcc stack.o queue.o list.o main.o -o lqs

clean:
	rm -v *.o lqs
