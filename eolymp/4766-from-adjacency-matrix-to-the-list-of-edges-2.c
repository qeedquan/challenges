/*

The simple oriented graph is given by the adjacency matrix. Print its representation as a list of edges.

Input
The first line contains number of vertices n (1≤n≤100) in the graph. Each of the next n lines contains n elements – the description of adjacency matrix.

Output
Print the list of edges, ordered first by the first vertex in a pair that describes an edge, then by the second vertex.

Examples
Input #1
3
0 1 0
0 0 1
1 1 0

Answer #1
1 2
2 3
3 1
3 2

*/

#include <stdio.h>

void
solve(size_t n, int m[n][n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (m[i][j])
				printf("%zu %zu\n", i + 1, j + 1);
		}
	}
}

int
main()
{
	int m[3][3] = {
		{ 0, 1, 0 },
		{ 0, 0, 1 },
		{ 1, 1, 0 },
	};

	solve(3, m);

	return 0;
}
