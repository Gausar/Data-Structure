#include "DS.h"
#include "my_qsort.h"

int main()
{
	int n, m, k;
	scanf("%d%d", &n, &m);
	int i, x, y;
	Graph g;
	gr_init_graph(&g, n);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		gr_add_edge(&g, x, y);
	}

	int *cc = (int *) malloc(sizeof(int) * (n + 1));
	gr_connected_components(&g, cc);

	// өөрийн бичсэн quicksort-ыг дуудаж буурахаар эрэмбэлнэ.
	single_pivot_qsort(cc, 1, cc[0]);
    printf("%d\n", cc[0]);
	for (i = 1; i <= cc[0]; i++)
		printf("%d ", cc[i]);
	return 0;
}