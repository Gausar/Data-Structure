#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#define EQUATION_LENGTH 1000

#include <stdio.h>
#include <string.h>
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

struct Token {
	int flag;    /*
				  flag = 1 бол уг объект тооны мэдээлэл val-д хадгална
				  flag = 0 бол уг объект op-д тэмдэгт хадгална
				 */
	int val;
	char op;
};
typedef struct Token Token;

struct TokenElm {
        Token x;
        struct TokenElm *next;
};
typedef struct TokenElm TokenElm;

// List бүтэц
struct List {
        TokenElm *head;
        TokenElm *tail;
        int len;
};
typedef struct List List;

void l_push_back(List *, Token);
void l_push_front(List *, Token);
void l_insert(List *, Token, int);
void l_pop_front(List *);
void l_pop_back(List *);
void l_erase(List *, int);
void l_print(List *);


// Postfix functions
int convert_to_int(const char[]);
void tokenize(const char[], List *);
void convert_to_postfix(List *, List *);
int solve(List *);

#endif
