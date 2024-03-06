#ifndef __MYHEAP_H
#define __MYHEAP_H

#include <string.h>

struct Msg {
        char text[100];
        int priority, time;
};
typedef struct Msg Msg;

struct Array {
        Msg a[100000];
        int len;
};


// Heap
struct Heap {
        struct Array heap;
};
typedef struct Heap Heap;
#define h_arr heap.a
#define h_len heap.len

int less(const Msg *, const Msg *);
void insert(Heap *, const Msg);
Msg delMin(Heap *);

#endif
