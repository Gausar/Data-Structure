#include "sort.h"

int A[1000];

int main()
{
        int n;
        scanf("%d", &n);
        read(A, n);
        insertion_sort(A, n);
        print(A, n);

        read(A, n);
        selection_sort(A, n);
        print(A, n);

        read(A, n);
        bubble_sort(A, n);
        print(A, n);    
        return 0;
}
