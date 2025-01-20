/*

In long multiplication, after multiplying the numbers, you are left with the partial products, in this challenge you will output those partial products.

Because long multiplication is long, to compensate your code will need to be as short as possible.

Examples
34, 53
102, 1700

48, 38
384, 1440

361, 674
1444, 25270, 216600

0, 0
0

1, 8
8
Specifications
Input / Output may be in any reasonable format such as array, comma-separated string (or any other delimiter that's not a digit), list, function arguments, etc.
Partial products must be in increasing order.
If a partial product is 0, you can choose whether you want to output it or not.
This is code-golf so shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(long *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%ld ", a[i]);
	printf("\n");
}

long
sign(long x)
{
	return (x < 0) ? -1 : 1;
}

size_t
longmul(long x, long y, long *r)
{
	size_t i;
	long s;

	s = (sign(x) == sign(y)) ? 1 : -1;
	x = labs(x);
	y = labs(y);
	i = 0;
	do {
		r[i++] = s * x * (y % 10);
		s *= 10;
		y /= 10;
	} while (y);

	return i;
}

void
test(long x, long y, long *r, size_t nr)
{
	long p[128];
	size_t np;

	np = longmul(x, y, p);
	dump(p, np);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	long p1[] = {102, 1700};
	long p2[] = {384, 1440};
	long p3[] = {1444L, 25270L, 216600L};
	long p4[] = {0};
	long p5[] = {8};

	test(34, 53, p1, nelem(p1));
	test(48, 38, p2, nelem(p2));
	test(361, 674, p3, nelem(p3));
	test(0, 0, p4, nelem(p4));
	test(1, 8, p5, nelem(p5));

	return 0;
}
