all: cc

graph.o: graph.c DS.h
	gcc -c graph.c -o graph.o

list.o: list.c DS.h
	gcc -c list.c -o list.o

main.o: main.c DS.h
	gcc -c main.c -o main.o

qsort.o: qsort.c my_qsort.h
	gcc -c qsort.c -o qsort.o

cc: qsort.o main.o graph.o list.o
	gcc qsort.o main.o graph.o list.o -o cc

clean:
	rm -v *.o cc
