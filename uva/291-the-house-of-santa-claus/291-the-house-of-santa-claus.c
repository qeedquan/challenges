#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int a;
	int b;
} Edge;

typedef struct {
	Edge edges[8];
	int visited[8];
	int order[9];
} Graph;

void
init(Graph *g)
{
	static const Edge edges[] = {
		{ 1, 2 },
		{ 1, 3 },
		{ 1, 5 },
		{ 2, 3 },
		{ 2, 5 },
		{ 3, 4 },
		{ 3, 5 },
		{ 4, 5 },
	};

	memcpy(g->edges, edges, sizeof(edges));
	memset(g->visited, 0, sizeof(g->visited));
	memset(g->order, 0, sizeof(g->order));
}

void
gen(Graph *g, int n, int o)
{
	size_t i;

	g->order[o] = n;
	if (o == nelem(g->order) - 1) {
		for (i = 0; i < nelem(g->order); i++)
			printf("%d", g->order[i]);
		printf("\n");
		return;
	}

	for (i = 0; i < nelem(g->edges); i++) {
		if (!g->visited[i]) {
			if (g->edges[i].a == n) {
				g->visited[i] = 1;
				gen(g, g->edges[i].b, o + 1);
				g->visited[i] = 0;
			} else if (g->edges[i].b == n) {
				g->visited[i] = 1;
				gen(g, g->edges[i].a, o + 1);
				g->visited[i] = 0;
			}
		}
	}
}

int
main(void)
{
	Graph g;

	init(&g);
	gen(&g, 1, 0);

	return 0;
}
