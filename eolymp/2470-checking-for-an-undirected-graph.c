/*

Given a square matrix n×n consisting of zeros and ones, determine whether it can represent the adjacency matrix of a simple undirected graph.
Recall that a simple graph does not contain loops or multiple edges.

Input
The first line contains the integer n (1≤n≤100). Each of the next n lines contains n numbers, describing the adjacency matrix.

Output
Print YES if the graph is simple undirected, and NO otherwise.

Examples

Input #1
3
0 1 1
1 0 1
1 1 0

Answer #1
YES

Input #2
3
0 1 1
1 0 1
0 1 0

Answer #2
NO

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
solve(size_t n, int m[n][n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (m[i][j] != m[j][i])
				return "NO";
			if (i == j && m[i][j])
				return "NO";
		}
	}
	return "YES";
}

int
main()
{
	int m1[3][3] = {
		{ 0, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 1, 0 },
	};

	int m2[3][3] = {
		{ 0, 1, 1 },
		{ 1, 0, 1 },
		{ 0, 1, 0 },
	};

	assert(!strcmp(solve(3, m1), "YES"));
	assert(!strcmp(solve(3, m2), "NO"));

	return 0;
}
