/*

In your childhood you most likely had to solve the riddle of the house of
Santa Claus. Do you remember that the importance was on drawing the
house in a stretch without lifting the pencil and not drawing a line twice?
As a reminder it has to look like shown in Figure 1.
Well, a couple of years later, like now, you have to “draw” the house
again but on the computer. As one possibility is not enough, we require all
the possibilities when starting in the lower left corner. Follow the example
in Figure 2 while defining your stretch.
All the possibilities have to be listed in the outputfile by increasing
order, meaning that 1234... is listed before 1235... .

Output
So, an outputfile could look like this:
12435123
13245123
...
15123421

*/

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
