#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct Array {
        int a[100];
        int len;
};

// Стак
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
// ...
// List
// ...


// Complete Binary Tree
struct CBTree {
        struct Array tree;
};
typedef struct CBTree CBTree;
#define cb_arr tree.a
#define cb_len tree.len

void cb_push(CBTree *, int);
void cb_preorder(const CBTree *, int);
void cb_inorder(const CBTree *, int);
void cb_postorder(const CBTree *, int);

#endif
