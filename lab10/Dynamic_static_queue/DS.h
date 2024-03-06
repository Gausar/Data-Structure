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

// List
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

#endif
