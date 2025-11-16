/*

Given a string of digits or an integer as input, you will have to indexize it.

This is how you modify the input. We will use 30043376111 as an example:

First, find the sum of the indices of each occurrence of the respective digits:

0: 1 + 2 = 3
1: 8 + 9 + 10 = 27
3: 0 + 4 + 5 = 9
4: 3
6: 7
7: 6
Then, construct a new integer or string where the digits above go in the order of the sums of their indices. In the case that multiple digits yield the same sum, the smaller digit comes before the larger one:

047631
Finally, remove any leading zeroes, and return or print the result:

47631
You must write a program or function which returns or prints the input indexized.

This is code-golf, so shortest code in bytes wins!

More test cases can be added if requested.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

void
count(uvlong x, uvlong d[10][2])
{
	char b[sizeof(x) * CHAR_BIT];
	uvlong i;

	for (i = 0; i < 10; i++) {
		d[i][0] = i;
		d[i][1] = 0;
	}

	snprintf(b, sizeof(b), "%llu", x);
	for (i = 0; b[i]; i++)
		d[b[i] - '0'][1] += i;
}

uvlong
number(uvlong d[10][2])
{
	char b[16];
	size_t i;

	for (i = 0; i < 10 && d[i][1]; i++)
		b[i] = d[i][0] + '0';
	b[i] = '\0';
	return strtoull(b, NULL, 10);
}

int
cmp(const void *a, const void *b)
{
	const uvlong *x, *y;
	int i;

	x = a;
	y = b;

	if (!x[1] && y[1])
		return 1;

	if (x[1] && !y[1])
		return -1;

	for (i = 1; i >= 0; i--) {
		if (x[i] < y[i])
			return -1;
		if (x[i] > y[i])
			return 1;
	}
	return 0;
}

uvlong
indexize(uvlong x)
{
	uvlong d[10][2];

	count(x, d);
	qsort(d, nelem(d), sizeof(*d), cmp);
	return number(d);
}

int
main(void)
{
	assert(indexize(30043376111ULL) == 47631ULL);

	return 0;
}
