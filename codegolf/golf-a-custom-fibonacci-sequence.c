/*

The Fibonacci sequence is a fairly well known thing around here. Heck, it even has its own tag. However, for all that, we sure like to stick to our roots of 1, 1, ... (or is it 0, 1, ...? We may never know...).
In this challenge, the rules are the same, but instead of getting the nth item in the Fibonacci sequence, you will get the nth item in the Fibonacci-esque sequence starting with x, y, ....

Input
Three integers, in whatever order you want. n is the index (0 or 1 indexed) of term in the sequence for your output. x and y are the first two items in your current program run's Fibonacci sequence.

Output
The nth term in the Fibonacci sequence starting with x, y.

Test Cases
(0-indexed)

n   x     y     out
5   0     0     0
6   0     1     8
6   1     1     13
2   5     5     10
10  2     2     178
3   3     10    23
13  2308  4261  1325165
0   0     1     0
1   0     1     1
(1-indexed)

n   x     y     out
6   0     0     0
7   0     1     8
7   1     1     13
3   5     5     10
11  2     2     178
4   3     10    23
14  2308  4261  1325165
1   0     1     0
2   0     1     1

Caveats
Assume 0 <= x <= y.

Please note your input order (must be constant).

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
customfib(uvlong n, uvlong x, uvlong y)
{
	uvlong a, b, c;
	uvlong i;

	a = x;
	b = y;
	for (i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

int
main(void)
{
	assert(customfib(5, 0, 0) == 0);
	assert(customfib(6, 0, 1) == 8);
	assert(customfib(6, 1, 1) == 13);
	assert(customfib(2, 5, 5) == 10);
	assert(customfib(10, 2, 2) == 178);
	assert(customfib(3, 3, 10) == 23);
	assert(customfib(13, 2308, 4261) == 1325165);
	assert(customfib(0, 0, 1) == 0);
	assert(customfib(1, 0, 1) == 1);

	return 0;
}
