/*

In the Milky Way galaxy, on the planet Neptune, there are n cities, some of which are connected by roads.
Emperor Maximus of the Milky Way galaxy has decided to make an inventory of the roads on Neptune.
However, as it turns out, he is not very good at math, so he asks you to count the number of roads.

Input
The first line contains the number n (0≤n≤100).
Each of the next n lines contains n numbers, each either zero or one.
If the position (i,j) in the square matrix is one, then the i-th and j-th cities are connected by a road; if it is zero, they are not connected.

Output
Print the number of roads on the planet Neptune.

https://static.e-olymp.com/content/12/12b9f05204852791120b7e675644657953915f2f.gif

Examples
Input #1
5
0 1 0 0 0
1 0 1 1 0
0 1 0 0 0
0 1 0 0 0
0 0 0 0 0

Answer #1
3

*/

#include <assert.h>
#include <stdio.h>

size_t
solve(size_t n, int m[n][n])
{
	size_t i, j, r;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++)
			r += m[i][j];
	}
	return r;
}

int
main()
{
	int m1[5][5] = {
		{ 0, 1, 0, 0, 0 },
		{ 1, 0, 1, 1, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	};

	assert(solve(5, m1) == 3);

	return 0;
}
