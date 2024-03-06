#ifndef MYSORT_H
#define MYSORT_H

#include <stdio.h>

/* Эрэмбэлэх функц */
void insertion_sort(int (*), int);
void selection_sort(int (*), int);
void bubble_sort(int (*), int);

/* Дамжуулсан хүснэгтийг Хэвлэх функц */
void print(int (*), int);
void read(int (*), int);

#endif
