#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

struct Elm {
        int x;
        int height;
        int len;
        struct Elm *L;
        struct Elm *R;
};
typedef struct Elm Elm;

// Binary Search Tree
struct AVL {
        Elm *root;
};
typedef struct AVL AVL;

void avl_put(AVL *, int);
Elm *avl_get(const AVL *, int);
void avl_del(AVL *, int);
int avl_delMin(AVL *);
void avl_inorder(const AVL *);
int avl_size(const AVL *, int);
int avl_height(const AVL *, int);

#endif
