/*

Braid Description
In this braid, when a strand crosses over the top of another strand it adds the other strand's value to itself and all other strand values pass through. The braid has three strands and each strand begins at 1. The first crossover is the leftmost strand crossing over the middle strand. The next crossover is the rightmost strand crossing over the new middle strand (previously the leftmost strand). These two steps of crossovers repeat. In other words, the first crossover is [a, b, c] -> [b, a+b, c] and the second is [a, b, c] -> [a, b+c, b]. Using these rules here are the first six levels of the braid:

1,1,1
1,2,1
1,3,2
3,4,2
3,6,4
6,9,4
Your task
Write a golfed program or function that accepts an integer as the braid level and outputs the three values for that level of the braid. You must indicate if your levels are zero- or one-based. Input and output may come in any reasonable format and trailing white space is allowed.

Test Cases (1-based)
1 -> 1,1,1

2 -> 1,2,1

5 -> 3,6,4

10 -> 28,41,19

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swapi(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

int
f(int x)
{
	if (x < 2)
		return 1;
	return f(x - 1) + f(x - 3);
}

/*

@Doorknob

Based on the following formula:

f(-1) = 1
f(0)  = 1
f(1)  = 1
f(x)  = f(x-1) + f(x-3)

braid(x) = {
    [f(x-1), f(x), f(x-2)]  if x is even,
    [f(x-2), f(x), f(x-1)]  if x is odd
}

*/

void
braid(int n, int r[3])
{
	r[0] = f(n - 1);
	r[1] = f(n);
	r[2] = f(n - 2);
	if (n & 1)
		swapi(&r[0], &r[2]);
}

void
test(int n, const int r[3])
{
	int x[3];

	braid(n, x);
	printf("%d %d %d\n", x[0], x[1], x[2]);
	assert(!memcmp(r, x, sizeof(x)));
}

int
main(void)
{
	static const int tab[][3] = {
	    {1, 1, 1},
	    {1, 2, 1},
	    {1, 3, 2},
	    {3, 4, 2},
	    {3, 6, 4},
	    {6, 9, 4},
	    {6, 13, 9},
	    {13, 19, 9},
	    {13, 28, 19},
	    {28, 41, 19},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		test(i + 1, tab[i]);

	return 0;
}
