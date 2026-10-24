/*

In the supermarket there is an action — "Buying any two goods, the third you receive for free, out of three selected goods you pay the two most expensive."

Mamed, going to the supermarket, knows what goods he wants to buy, and knows their prices.
Determine the minimum amount of money that he needs to take with him to buy these goods.

Input
The first line contains one number n (1≤n≤1000). Second line contains n numbers — the prices of goods chosen by Mamed. All prices are positive integers, no more than 10000.

Output
Print one number — the minimum amount of money that Mamed should take with him to the supermarket.

Examples
Mamed will first pass through the cash register with goods worth 1,3 and 4 — will pay 7 hryvnia and will receive a commodity worth 1 as a gift,
and then again go into supermarket and will buy goods worth 5 and 7, receiving another product worth 5 as a gift.

Input #1
6
1 5 4 3 5 7

Answer #1
19

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return 1;
	if (x > y)
		return -1;
	return 0;
}

int
solve(int *a, size_t n)
{
	size_t i;
	int r;

	qsort(a, n, sizeof(*a), cmp);

	r = 0;
	for (i = 0; i < n; i++) {
		if ((i % 3) != 2)
			r += a[i];
	}
	return r;
}

int
main()
{
	int a1[] = { 1, 5, 4, 3, 5, 7 };

	assert(solve(a1, nelem(a1)) == 19);

	return 0;
}
