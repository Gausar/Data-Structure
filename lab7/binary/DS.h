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
struct BST {
        Elm *root;
};
typedef struct BST BST;

void bs_put(BST *, int);
Elm *bs_get(const BST *, int);
void bs_del(BST *, int);
int bs_delMin(BST *);
void bs_inorder(const BST *);
int bs_rank(const BST *, int);
int bs_size(const BST *, int);
Elm *bs_floor(const BST *, int);
Elm *bs_ceiling(const BST *, int);
int bs_height(const BST *, int);

#endif
