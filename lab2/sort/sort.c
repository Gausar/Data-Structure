#include "sort.h"
void read(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
}

void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insertion_sort(int a[], int n)
{	
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн insertion sort-ийг
	 * хийх кодыг бичнэ.
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо
	 ***************************************************/
	int i, key, j;
	for(i = 0; i < n; i++){
		j = i - 1;
		key = a[i];

	while(j >= 0 && key < a[j]){
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = key;
	}
}

void selection_sort(int a[], int n)
{
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн selection sort-ийг
	 * хийх кодыг бичнэ.
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо
	 ***************************************************/
	int k;
    for(int i = 0; i < n - 1; i++){
		k = i;
		for(int j = i; j < n; j++){
			if(a[k] > a[j]){
				k = j;
			}
		}
		if(k != i){
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}

void bubble_sort(int a[], int n)
{
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн bubble sort-ийг
	 * хийх кодыг бичнэ.
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо
	 ***************************************************/
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++){
			if(a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
