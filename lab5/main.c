#include "my_qsort.h"
#include <stdio.h>


int main()
{
	FILE *fin = NULL;
	fin = fopen("input.txt", "r");
	if (!fin) {
		printf("input.txt file error!\n");
		exit(-1);
	}
	int i, n;
	fscanf(fin, "%d", &n);
	int *a;
	a = (int *) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) 
		fscanf(fin, "%d", &a[i]);
	fclose(fin);

	//single_pivot_qsort(a, 0, n - 1);
	dual_pivot_qsort(a, 0, n - 1);

	FILE *fout = fopen("output.txt", "w+");
	for (i = 0; i < n; i++)
		fprintf(fout, "%d ", a[i]);
	fclose(fout);

	free(a);
	return 0;
}
