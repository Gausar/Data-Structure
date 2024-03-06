#include "my_qsort.h"
#include <stdio.h>

/*
  quicksort эрэмбэлэх аргын цааш хуваагдах ёсгүй хэмжээ
*/
#ifndef CUTOFF
#define CUTOFF 10
#endif

static int init_seed = 0;  // Random seed 1 удаа эхлүүлнэ

/*
  Оруулан эрэмбэлэх функц.
  [lo, hi] завсрах тоонуудыг оруулан эрэмбэлэх аргаар эрэмбэлнэ.
*/
static void insertion_sort(int a[], int lo, int hi)
{
        for(int i = lo; i <= hi; i++){
                int key = a[i];
                int j = i - 1;
                while(key > a[j] && j >= lo){
                        a[j + 1] = a[j];
                        j--;
                }
                a[j + 1] = key; 
        }
}

/*
  Хоёр утгыг хооронд солих функц
*/
static void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

/*
  [lo, hi] завсрыг санамсаргүйгээр холих функц.
*/
static void random_shuffle(int a[], int lo, int hi)
{
        if (init_seed == 0) {
                srand(time(NULL));
                init_seed = 1;
        }
        int i, j;
        for (i = lo; i <= hi; i++) {
                j = rand() % (hi - lo) + lo;
                swap(&a[i], &a[j]);
        }
}

/*
  1-pivot хурдан эрэмбэлэх функц.
*/
static void _single_pivot_qsort(int a[], int lo, int hi)
{

        int piv = a[lo];
        int i = lo;
        int j = hi + 1;
        if(hi - lo > CUTOFF){
                while(1){
                        while(a[++i] > a[lo]){
                                if(i == hi) break;
                        }
                        while(a[lo] > a[--j]){
                                if(j == lo) break;
                        }
                        if(i >= j) break;
                        swap(&a[i], &a[j]);
                }
                swap(&a[lo], &a[j]);
                _single_pivot_qsort(a, lo, j - 1);
                _single_pivot_qsort(a, j + 1, hi);

        }
        else insertion_sort(a, lo, hi);
}

/*
  wrapper function for _single_pivot_qsort
  _single_pivot_qsort-ыг дуудахад ашиглах функц
 */
void single_pivot_qsort(int a[], int lo, int hi)
{
        random_shuffle(a, lo, hi);
        _single_pivot_qsort(a, lo, hi);
}

/*
  Dual-pivot хурдан эрэмбэлэх функц
*/
static void _dual_pivot_qsort(int a[], int lo, int hi)
{
        
        if(hi - lo > CUTOFF){
                if(a[lo] < a[hi]){
                        swap(&a[lo], &a[hi]);
                }
                int piv1 = a[lo];
                int piv2  = a[hi];
                int k = lo + 1;
                int g = hi - 1;
                int j = lo + 1;
                while(k <= g){
                        if(a[k] > piv1){
                                swap(&a[k], &a[j]);
                                j++;
                        }
                        else if(a[k] <= piv2){
                                while(a[g] > piv2 && k < g){
                                        g--;
                                }
                                swap(&a[k], &a[g]);
                                g--;
                                if(a[k] > piv1){
                                        swap(&a[k], & a[j]);
                                        j++;
                                }
                        }
                        k++;
                }
                j--;
                g++;
                swap(&a[lo], &a[j]);
                swap(&a[hi], &a[g]);
                _dual_pivot_qsort(a, lo, j - 1);
                _dual_pivot_qsort(a, j + 1, g - 1);
                _dual_pivot_qsort(a, g + 1, hi);

        }
        else insertion_sort(a, lo, hi);
}
/*
  wrapper function for _dual_pivot_qsort
  _dual_pivot_qsort-ыг дуудахад ашиглах функц
*/
void dual_pivot_qsort(int a[], int lo, int hi)
{
        random_shuffle(a, lo, hi);
        _dual_pivot_qsort(a, lo, hi);
}

