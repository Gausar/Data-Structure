#include "DS.h"

int main()
{
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int i, x, y;
	Graph g;
	gr_init_graph(&g, n);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		gr_add_edge(&g, x, y);
	}

	int *pi = (int *) malloc(sizeof(int) * (n + 1));
	gr_bfs(&g, s, pi);
	gr_print_path(pi, s, t);

	free(pi);
	return 0;
}
