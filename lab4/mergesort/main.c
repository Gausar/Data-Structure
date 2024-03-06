#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
        FILE *fin = NULL;
        fin = fopen("myinput2.txt", "r");
        if (!fin) {
                printf("input file error!\n");
                exit(-1);
        }
        int i, n;
        fscanf(fin, "%d", &n);
        Student *a, *aux;
        a = (Student *) malloc(sizeof(Student) * n);
        aux = (Student *) malloc(sizeof(Student) * n);
        for (i = 0; i < n; i++) {
                fscanf(fin, "%s%d%f", a[i].name, &a[i].age, &a[i].gpa);
        }
        fclose(fin);
        mergesort(a, aux, 0, n - 1, nereer);
        mergesort(a, aux, 0, n - 1, nasaar);
        mergesort(a, aux, 0, n - 1, golchoor);

        for (i = 0; i < n; i++)
                printf("%3.1f\t%d\t%s\n", a[i].gpa, a[i].age, a[i].name);

        return 0;
}
