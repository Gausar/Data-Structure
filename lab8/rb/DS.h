#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
        char name[30];
	char id[20];
        int age;
        float gpa;
};
typedef struct Student Student;

struct Elm {
	Student x;
	int color;
        struct Elm *L;
        struct Elm *R;
        struct Elm *parent;
};
typedef struct Elm Elm;

// Binary Search Tree
struct RBT {
        Elm *root;
};
typedef struct RBT RBT;


int less(const Student *, const Student *);
void rb_put(RBT *, const Student *);
Elm *rb_get(const RBT *, const char[]);
void rb_del(RBT *, const char[]);
void print(Elm *p);
#endif
