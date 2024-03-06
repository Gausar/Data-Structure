#include "my_qsort.h"

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
        /* Оруулан эрэмбэлэх аргыг хэрэгжүүл */
        int i, j, key;
        for(i = lo; i <= hi; i++){
                key = a[i];
                j = i - 1;
                while(j >= 0 && a[j] > key){
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
int partition(int a[], int lo, int hi){
        int i = lo, j = hi + 1;
        while(1){
                while(a[++i] < a[lo]){
                        if(i == hi){
                                break;
                        }
                }
                while(a[lo] < a[--j]){
                        if(j == lo){
                                break;
                        }
                }
                if(i >= j){
                        break;
                }
                swap(&a[i], &a[j]);
        }
        swap(&a[lo], &a[j]);
        return j;
}
/*
  1-pivot хурдан эрэмбэлэх функц.
*/
static void _single_pivot_qsort(int a[], int lo, int hi)
{
        /* Энд quicksort хэрэгжүүл */
        if(hi <= lo + CUTOFF - 1){
                insertion_sort(a, lo, hi);
                return;
        }
        int j = partition(a, lo, hi);
        _single_pivot_qsort(a, lo, j - 1);
        _single_pivot_qsort(a, j + 1, hi);
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

int partition2(int a[], int lo, int hi, int *lp){
        if(a[lo] > a[hi]){
                swap(&a[lo], &a[hi]);
        }
        int left = lo + 1;
        int right = hi - 1;
        int i = lo + 1;
        int p = a[lo], q = a[hi];
        while(i <= right){
                if(a[i] < p){
                        swap(&a[i], &a[left]);
                        left++;
                }
                else if(a[i] >= q){
                        while(a[right] > q && i < right){
                                right--;
                        }
                        swap(&a[i], &a[right]);
                        right--;
                        if(a[i] < p){
                                swap(&a[i], &a[left]);
                                left++;
                        }
                }
                i++;
        }
        left--;
        right++;
        swap(&a[lo], &a[left]);
        swap(&a[hi], &a[right]);
        *lp = left;
        return right;
}
/*
  Dual-pivot хурдан эрэмбэлэх функц
*/
static void _dual_pivot_qsort(int a[], int lo, int hi)
{
        if(hi <= lo + CUTOFF - 1){
                insertion_sort(a, lo, hi);
                return;
        }
        if(lo < hi){
                int lp, rp;
                rp = partition2(a, lo, hi, &lp);
                _dual_pivot_qsort(a, lo, lp - 1);
                _dual_pivot_qsort(a, lp + 1, rp - 1);
                _dual_pivot_qsort(a, rp + 1, hi);
        }
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

