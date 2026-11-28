/*

A demonic number is a positive integer whose decimal representation consists of only 6. The list of demonic numbers starts with 6, 66, 666, 6666.

Given a positive integer, output the nearest demonic number. If there are two, output the bigger one.

Testcases:

n   output
1   6
2   6
3   6
6   6
35  6
36  66
37  66
100 66
365 66
366 666
666 666
999 666

This is code-golf. Shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
demon(uvlong n)
{
	uvlong i, r;

	r = 6;
	for (i = 1; i < n; i++)
		r = (r * 10) + 6;
	return r;
}

uvlong
neardemon(uvlong n)
{
	uvlong l, x0, x1, d0, d1;

	if (n == 0)
		return 6;

	l = log10(n);
	x0 = demon(l);
	x1 = demon(l + 1);

	d0 = max(x0, n) - min(x0, n);
	d1 = max(x1, n) - min(x1, n);

	return (d0 < d1) ? x0 : x1;
}

int
main(void)
{
	assert(neardemon(0) == 6);
	assert(neardemon(1) == 6);
	assert(neardemon(2) == 6);
	assert(neardemon(3) == 6);
	assert(neardemon(6) == 6);
	assert(neardemon(35) == 6);
	assert(neardemon(36) == 66);
	assert(neardemon(37) == 66);
	assert(neardemon(100) == 66);
	assert(neardemon(365) == 66);
	assert(neardemon(366) == 666);
	assert(neardemon(666) == 666);
	assert(neardemon(999) == 666);

	return 0;
}
