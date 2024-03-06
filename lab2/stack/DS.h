#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>

struct Array {
        int a[100];
        int len;
};
// Stack 
struct Stack {
        struct Array stack;
};
typedef struct Stack Stack;
#define s_arr stack.a
#define s_len stack.len

void s_push(Stack *, int );
void s_pop(Stack *);
void s_print(Stack *);


// Queue
struct Queue {
        struct Array queue; 
};
typedef struct Queue Queue;
#define q_arr queue.a
#define q_len queue.len

void q_push(Queue *, int);
void q_pop(Queue *);
void q_print(Queue *);

// List
struct List {
        struct Array list;
};
typedef struct List List;
#define l_arr list.a
#define l_len list.len

void l_push_back(List *, int);
void l_push_front(List *, int);
void l_insert(List *, int, int);
void l_pop_front(List *);
void l_pop_back(List *);
void l_erase(List *, int);
void l_print(List *);
int l_search(List *, int);

#endif
