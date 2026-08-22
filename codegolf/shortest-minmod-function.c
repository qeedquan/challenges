/*

The minmod function is a variant of the familiar min, which appears in slope-limiting high-resolution schemes for partial differential equations. Given a number of slopes, it picks out the flattest slope, while taking care of relative signs between the slopes.

The function takes an arbitrary number of parameters. Then minmod(x1, x2, ..., xn) is defined as:

min(x1, x2, ..., xn), if all xi are strictly positive
max(x1, x2, ..., xn), if all xi are strictly negative
0, otherwise.

We'll only consider integer inputs, because that does not really affect the implementation and should be more inclusive for some (esoteric) languages.

Write a program or function, which takes n signed integers (for n > 0) via STDIN, ARGV or function argument (you can use an array if that's more convenient than a variadic function), and returns or prints (to STDOUT) the result of minmod(a,b).

You must not use built-in min or max functions (and obviously, no built-in minmod either, if you can actually find that). In addition, you must not use any built-in sorting functions, except to sort a fixed small number of items (less than 5).

If your language doesn't have signed types, you may use an unsigned type and interpret it as two's complement. E.g. if your language only uses unsigned bytes, you can use 255 to stand in for -1 and 128 to stand in for -128, etc.

This is code golf, so the shortest answer (in bytes) wins.

Test Cases
Input          Output

2              2
-3             -3
0              0
3 -5           0
2 4 1          1
0 1 2          0
-1 1 2         0
-4 -2 -3 -2    -2
-5 0 -1        0
1 0 -1         0

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
sign(int x)
{
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

int
minmod(int *a, size_t n)
{
	int r, s;
	size_t i;

	if (n == 0)
		return 0;

	s = sign(a[0]);
	if (s == 0)
		return 0;

	r = a[0];
	for (i = 1; i < n; i++) {
		if (s != sign(a[i]))
			return 0;

		if (s < 0)
			r = max(r, a[i]);
		else
			r = min(r, a[i]);
	}
	return r;
}

int
main(void)
{
	int a1[] = {2};
	int a2[] = {-3};
	int a3[] = {0};
	int a4[] = {3, -5};
	int a5[] = {2, 4, 1};
	int a6[] = {0, 1, 2};
	int a7[] = {-1, 1, 2};
	int a8[] = {-4, -2, -3, -2};
	int a9[] = {-5, 0, -1};
	int a10[] = {1, 0, -1};

	assert(minmod(a1, nelem(a1)) == 2);
	assert(minmod(a2, nelem(a2)) == -3);
	assert(minmod(a3, nelem(a3)) == 0);
	assert(minmod(a4, nelem(a4)) == 0);
	assert(minmod(a5, nelem(a5)) == 1);
	assert(minmod(a6, nelem(a6)) == 0);
	assert(minmod(a7, nelem(a7)) == 0);
	assert(minmod(a8, nelem(a8)) == -2);
	assert(minmod(a9, nelem(a9)) == 0);
	assert(minmod(a10, nelem(a10)) == 0);

	return 0;
}
