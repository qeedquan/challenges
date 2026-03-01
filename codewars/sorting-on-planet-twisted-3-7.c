/*

#Sorting on planet Twisted-3-7

There is a planet... in a galaxy far far away. It is exactly like our planet, but it has one difference: #The values of the digits 3 and 7 are twisted. Our 3 means 7 on the planet Twisted-3-7. And 7 means 3.

Your task is to create a method, that can sort an array the way it would be sorted on Twisted-3-7.

7 Examples from a friend from Twisted-3-7:

[1,2,3,4,5,6,7,8,9] -> [1,2,7,4,5,6,3,8,9]
[12,13,14] -> [12,14,13]
[9,2,4,7,3] -> [2,7,4,3,9]
There is no need for a precheck. The array will always be not null and will always contain at least one number.

You should not modify the input array!

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have also created other katas. Take a look if you enjoyed this kata!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
xfm(int n)
{
	int p, s, r, x;

	s = 1;
	if (n < 0) {
		s = -s;
		n = -n;
	}

	r = 0;
	p = 1;
	while (n > 0) {
		x = n % 10;
		if (x == 3)
			x = 7;
		else if (x == 7)
			x = 3;

		r += p * x;
		n /= 10;
		p *= 10;
	}
	return s * r;
}

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	x = xfm(x);
	y = xfm(y);
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
sort(int *a, size_t n, int *r)
{
	memcpy(r, a, sizeof(*a) * n);
	qsort(r, n, sizeof(*r), cmp);
}

void
test(int *a, size_t n, int *r)
{
	int p[128];

	sort(a, n, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a2[] = {12, 13, 14};
	int a3[] = {9, 2, 4, 7, 3};

	int r1[] = {1, 2, 7, 4, 5, 6, 3, 8, 9};
	int r2[] = {12, 14, 13};
	int r3[] = {2, 7, 4, 3, 9};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	return 0;
}
