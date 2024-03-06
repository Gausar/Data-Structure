#include "DS.h"

void uf_init(WeightedUF *p_uf, int n)
{
	p_uf->N = n;
	p_uf->id = (int *) malloc(sizeof(int) * n);
	p_uf->sz = (int *) malloc(sizeof(int) * n);	
	int i;
	for (i = 0; i < n; i++) {
		p_uf->id[i] = i;
		p_uf->sz[i] = 1;
	}
}

int uf_connected(WeightedUF *p_uf, int p, int q)
{
	/* Энд функцийг хэрэгжүүлнэ үү */
	if(uf_find(p_uf, p) == uf_find(p_uf, q)){
		return 1;
	}
	else return 0;
}

int uf_find(WeightedUF *p_uf, int p)
{
	while(p_uf->id[p] != p){
		p_uf->id[p] = p_uf->id[p_uf->id[p]];
		p = p_uf->id[p];
	}
	return p;
}

void uf_union(WeightedUF *p_uf, int p, int q)
{
	/*int i = uf_find(p_uf, q) ;
	int j = uf_find(p_uf, p) ;

	if (j == i){
		return ;
	}
	if (p_uf->sz[i] < p_uf->sz[j]) {
		p_uf->sz[j] += p_uf->sz[i];
        p_uf->id[i] = j;
    } else {
        p_uf->sz[i] += p_uf->sz[j];
        p_uf->id[j] = i;
    }*/
	int i = uf_find(p_uf, q) ;
	int j = uf_find(p_uf, p) ;

	if (j == i){
		return ;
	}
	if (i == 0){
		int temp = i ;
		i = j  ;
		j = temp ;
	}
	if (j == 0){
		p_uf->sz[j] = p_uf->sz[j] + p_uf->sz[i];
		p_uf->id[i] = j ;
		return ; 	
	}
	if (p_uf->sz[i] < p_uf->sz[j]){
		int temp = i ;
		i = j ;
		j = temp ;
	}
	p_uf->sz[i] = p_uf->sz[i] + p_uf->sz[j] ;
	p_uf->id[j] = i ;
}