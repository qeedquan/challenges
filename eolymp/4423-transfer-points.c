/*

To unload the new avenue, it was decided to launch two new bus routes at different sections of the avenue. The final stops of each of the buses are known.

Determine the number of stops where you can change from one bus to another.

Input
Four numbers - the numbers of the final stops, first of the first, then of the second bus. Numbers do not exceed 10^9.

Output
Print the required number of stops.

Examples

Input #1
3 6 4 2

Answer #1
2

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
solve(int a, int b, int c, int d)
{
	int r;

	if (a > b)
		swap(&a, &b);
	if (c > d)
		swap(&c, &d);

	r = min(b, d) - max(a, c) + 1;
	r = max(r, 0);
	return r;
}

int
main()
{
	assert(solve(3, 6, 4, 2) == 2);

	return 0;
}
