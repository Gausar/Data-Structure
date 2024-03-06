#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
        char ovog[20];
        char ner[20];
        char id[11];
};
typedef struct Student Student;

struct Elm {
        Student x;
        struct Elm *next;
};
typedef struct Elm Elm;

// List бүтэц
struct List {
        Elm *head;
        Elm *tail;
        int len;
};
typedef struct List List;

void l_push_back(List *, Student);
void l_push_front(List *, Student);
void l_insert(List *, Student, int);
void l_pop_front(List *);
void l_pop_back(List *);
void l_erase(List *, int);
void l_print(List *);
Elm *l_search(List *, const char []);

// Hash хүснэгт
#define HASH_TABLE_SIZE 1000000
struct HashTable {
        List *h;
        int len;
};
typedef struct HashTable HashTable;

void ht_insert(HashTable *, const Student);
int ht_hash(const char []);
Student *ht_search(HashTable *, const char []);
void ht_del(HashTable *, const char []);
void ht_update(HashTable *, const Student);
void ht_init(HashTable *);
void ht_release(HashTable *);
void student_print(FILE *, const Student *);

#endif
