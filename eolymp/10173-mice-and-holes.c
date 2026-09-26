/*

There are n mice and n holes on a straight line. Each hole can only accommodate 1 mouse.
A mouse can stay in its place, move one step to the right from x to x+1, or move one step to the left from x to x−1.
Any of these moves takes 1 minute. Assign mice to holes so that the time when the last mouse hides in a hole is minimized.

Input
The first line contains the number n (n≤10^5).
The second line contains the coordinates of n mice. The third line contains the coordinates of n holes.
The coordinates of mice and holes are integers from 0 to 19.

Output
Print the minimum time it takes for the last mouse to hide in a hole.

Examples

Input #1
4
3 6 1 9
5 3 11 2

Answer #1
2

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
solve(int *a, int *b, size_t n)
{
	size_t i;
	int r;

	qsort(a, n, sizeof(*a), cmp);
	qsort(b, n, sizeof(*b), cmp);

	r = 0;
	for (i = 0; i < n; i++)
		r = max(r, abs(a[i] - b[i]));
	return r;
}

int
main()
{
	int a[] = { 3, 6, 1, 9 };
	int b[] = { 5, 3, 11, 2 };

	assert(solve(a, b, nelem(a)) == 2);

	return 0;
}
