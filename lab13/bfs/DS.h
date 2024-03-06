#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

struct Elm {
	int x;
        struct Elm *next;
};
typedef struct Elm Elm;

// Stack 
struct Stack {
        Elm *top;
        int len;
};
typedef struct Stack Stack;

void s_push(Stack *, int );
void s_pop(Stack *);
void s_print(Stack *);

// Queue
struct Queue {
        Elm *head;
        Elm *tail;
        int len;
};
typedef struct Queue Queue;

void q_push(Queue *, int);
void q_pop(Queue *);
void q_print(Queue *);

// List бүтэц
struct List {
        Elm *head;
        Elm *tail;
        int len;
};
typedef struct List List;

void l_push_back(List *, int);
void l_push_front(List *, int);
void l_insert(List *, int, int);
void l_pop_front(List *);
void l_pop_back(List *);
void l_erase(List *, int);
void l_print(List *);
Elm *l_search(List *, int);

// Graph бүтэц
struct Graph {
	int n;     // Оройн тоо
	int m;     // Ирмэгүүдийн тоо
	List *adj;
};
typedef struct Graph Graph;

void gr_init_graph(Graph *, int);
void gr_add_edge(Graph *, int, int);
void gr_bfs(Graph *, int, int *);
void gr_print_path(int *, int, int);

#endif
