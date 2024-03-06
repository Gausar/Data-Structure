#include "DS.h"
/*
  Графыг эхлүүлэх функц: `g` графын хөршүүдийг хадгалах жагсаалтан хүснэгтийг эхлүүлэх функц.
  Санах ойг бэлдэж, жагсаалтын `head`, `tail` утгуудад `NULL` онооно.
 */
void gr_init_graph(Graph *g, int n)
{
	int i;
	g->adj = (List *) malloc(sizeof(List) * (n + 1));
	g->n = n;
	for (i = 0; i <= n; i++) {
		g->adj[i].head = g->adj[i].tail = NULL;
		g->adj[i].len = 0;
	}
}

/*
  Гүний нэвтрэлтийн функц: `g` граф дээр гүний нэвтрэлт хийн холбоост бүрдлүүдийн талаарх
  даалгаварт заагдсан мэдээллийг хэвлэнэ.
 */

void DFS(Graph g, int v, int *k, int *mark, int *edge){
	mark[v] = 1;
	(*k)++;
	Elm *n = g.adj[v].head;
	while(n != NULL){
		if(mark[n->x] == 0){
			DFS(g, n->x, k, mark, edge);
			edge[n->x] = v;
		}
		n = n->next;
	}
}

void gr_connected_components(Graph *g, int *cc)
{
	int count = 0;
	int n = g->n;
	int *mark = (int*)malloc(sizeof(int) * (n + 1));

	for(int i = 1; i <= n; i++){
		mark[i] = 0;
	}
	int *edge = (int*)malloc(sizeof(int) * (n + 1));
	for(int i = 1; i <= n; i++){
		if(mark[i] == 0){
			int d = 0;
			DFS(*g, i, &d, mark, edge);
			count++;
			cc[count] = d;
		}
	}
	cc[0] = count;
}

/*
  Ирмэг нэмэх функц: `g` графын ирмэгүүдийг хадгалах `adj` жагсаалтан хүснэгтэд ирмэг нэмнэ.
  Уг граф нь чиглэлгүй граф тул `x`-с `y`, `y`-с `x` гэсэн хоёр ирмэгийг оруулна.
 */
void gr_add_edge(Graph *g, int x, int y)
{
	l_push_back(&g->adj[x], y);
	l_push_back(&g->adj[y], x);
}
