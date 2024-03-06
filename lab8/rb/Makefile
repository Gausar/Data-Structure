all: rbt

avl.o: rb.c
	gcc -c rb.c -o rb.o 

main.o: main.c
	gcc -c main.c -o main.o 

rbt: avl.o main.o 
	gcc rb.o main.o -o rbt -lm

clean:
	rm -v *.o rbt
