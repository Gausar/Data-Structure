#ifndef __MSORT_H
#define __MSORT_H

#include <string.h>

struct Student {
        char name[30];
        int age;
        float gpa;
};
typedef struct Student Student;

int nereer(const Student *a, const Student *b);
int nasaar(const Student *a, const Student *b);
int golchoor(const Student *a, const Student *b);
void insertion_sort(Student a[],
                    int lo,
                    int hi,
                    int (*less)(const Student *, const Student *));
void merge(Student a[], Student aux[], int lo, int mid, int hi, int (*less)(const Student *, const Student *));

void mergesort(Student a[],
               Student aux[],
               int lo,
               int hi,
               int (*less)(const Student *, const Student *));

#endif
