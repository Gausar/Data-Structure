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
  Төвшний нэвтрэлтийн функц: `g` граф дээр `s` оройгоос эхлэн төвшний нэвтрэлтийг хийнэ.
  `pi`: Төвшний нэвтрэлт хийсний дараа `pi[u]` нь `u` оройд ямар оройгоос ирснийг хадгална.
 */
void gr_bfs(Graph *g, int s, int pi[])
{
	Queue q;
    q.len = 0;
    q.head = q.tail = NULL;

    int *visited = (int *)malloc((g->n + 1) * sizeof(int));
    for (int i = 0; i <= g->n; i++) {
        visited[i] = 0;
        pi[i] = -1;
    }

    q_push(&q, s);
    visited[s] = 1;

    while (q.len > 0) {
        int u = q.head->x;
        q_pop(&q);

        Elm *v = g->adj[u].head;
        while (v != NULL) {
            if (!visited[v->x]) {
                visited[v->x] = 1;
                pi[v->x] = u;
                q_push(&q, v->x);
            }
            v = v->next;
        }
    }

    free(visited);
}

/*
  Замын оройнуудыг хэвлэх функц: `pi` хүснэгтээс `s`, `t` орой хоорондын замын мэдээллийг хэвлэнэ.
  Хамгийн эхний мөрөнд замын уртыг, дараагийн мөрөнд `s` оройгоос эхлэн ямар оройгоор дамжиж
  очиж байгаа оройнуудыг 1 хоосон зайгаар тусгаарлан хэвлэнэ.
  Хэрэв зам байхгүй бол `-1` гэсэн ганц утга хэвлэнэ.
 */
void gr_print_path(int pi[], int s, int t)
{
	Stack st;
	st.len = 0;
	st.top = NULL;
	/* Энд функцийг хэрэгжүүл */
	//...
	
    if (pi[t] == -1) {
		printf("-1\n");
        return;
    }

    int v = t;
	int q = 1;
    while (v != s) {
        s_push(&st, v);
		q++;
        v = pi[v];
    }
    s_push(&st, s);
	
	printf("%d\n", st.len);
    while (st.len > 0) {
        printf("%d ", st.top->x);
        s_pop(&st);
    }
    printf("\n");
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
