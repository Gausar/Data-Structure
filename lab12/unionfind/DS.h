#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WeightedUF {
	int N;
	int *id;
	int *sz;
};
typedef struct WeightedUF WeightedUF;

void uf_init(WeightedUF *, int);
int uf_find(WeightedUF *, int);
void uf_union(WeightedUF *, int, int);
int uf_connected(WeightedUF *, int, int);

#endif
