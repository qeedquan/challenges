/*

Definition
a(1) = 1
a(2) = 1
a(n) = a(n-a(n-1)) + a(n-a(n-2)) for n > 2 where n is an integer
Task
Given positive integer n, generate a(n).

Testcases
n  a(n)
1  1
2  1
3  2
4  3
5  3
6  4
7  5
8  5
9  6
10 6
11 6
12 8
13 8
14 8
15 10
16 9
17 10
18 11
19 11
20 12
Reference
Obligatory OEIS A005185

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// http://oeis.org/A005185
int *
Q(int n)
{
	int i, *p;

	if (n < 1)
		return NULL;

	p = calloc(n + 2, sizeof(*p));
	if (!p)
		return NULL;

	p[1] = 1;
	p[2] = 1;
	for (i = 3; i < n; i++)
		p[i] = p[i - p[i - 1]] + p[i - p[i - 2]];
	return p;
}

int
main(void)
{
	static const int tab[] = {1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 8, 8, 8, 10, 9, 10, 11, 11, 12, 12, 12, 12, 16, 14, 14, 16, 16, 16, 16, 20, 17, 17, 20, 21, 19, 20, 22, 21, 22, 23, 23, 24, 24, 24, 24, 24, 32, 24, 25, 30, 28, 26, 30, 30, 28, 32, 30, 32, 32, 32, 32, 40, 33, 31, 38, 35, 33, 39, 40, 37, 38, 40, 39};

	int *p;

	p = Q(nelem(tab) + 1);
	assert(p);
	assert(!memcmp(p + 1, tab, sizeof(tab)));
	free(p);

	return 0;
}
