all: bfs

stack.o: stack.c DS.h
	gcc -c stack.c -o stack.o

queue.o: queue.c DS.h
	gcc -c queue.c -o queue.o

list.o: list.c DS.h
	gcc -c list.c -o list.o

graph.o: graph.c DS.h
	gcc -c graph.c -o graph.o

main.o: main.c DS.h
	gcc -c main.c -o main.o

bfs: stack.o queue.o list.o main.o graph.o
	gcc stack.o queue.o list.o main.o graph.o -o bfs

clean:
	rm -v *.o bfs
