/*

Four integers a, b, c, d are given. Find the difference between the second and the third biggest element.

Input
Four integers a, b, c, d. All numbers do not exceed 30000 by absolute value.

Output
Print one number - the difference between the second and the third biggest element.

Examples

Input #1
4 5 7 1

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int
solve(int a, int b, int c, int d)
{
	int x[4] = { a, b, c, d };

	qsort(x, 4, sizeof(*x), cmp);
	return x[2] - x[1];
}

int
main()
{
	assert(solve(4, 5, 7, 1) == 1);

	return 0;
}
