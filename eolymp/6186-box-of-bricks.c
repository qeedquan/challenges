/*

https://static.e-olymp.com/content/fb/fbeea93e3ef2170e6990571a5555e4be4d2a11cc.jpg

Pasha assembled box of bricks in the form of a rectangular parallelepiped and thought over the question:
what is the minimal number of bricks lying on the route between two opposite corners of the parallelepiped,
if it is allowed to pass from brick to other brick through the common face, edge or vertex?
In the figure, the opposite bricks are highlighted.

Help Pasha to write a program that calculates the minimal number of bricks on the route.

Input
Integer n, m, k (1≤n,m,k≤1000) — the size of rectangular parallelepiped (in bricks).

Output
Integer — the minimal number of bricks.

Examples
Input #1
3 3 3

Answer #1
3

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int n, int m, int k)
{
	return max(max(n, max(m, k)), 0);
}

int
main()
{
	assert(solve(3, 3, 3) == 3);

	return 0;
}
