/*

A triangular number is a number that can be expressed as the sum of consecutive positive integers, starting at 1. They can also be expressed with the formula n(n + 1) / 2, where n is some positive integer.

A number's digitangular counterpart is calculated in the following way:

Split a number into an array of its digits e.g. 613 => [6 1 3]
For each number in the array, calculate the nth triangular number; [6 1 3] => [21 1 6]
Sum the resultant array; [21 1 6] => 28
Your task is, given an integer n, repeatedly calculate n's digitangular counterpart, until the result is equal to 1, then output all values that were calculated. You may output the values in any order, and with an optional inclusion of the original number at the start of the array. This is a code-golf so the shortest code wins.

Test cases
23 => 9 45 25 18 37 34 16 22 6 21 4 10 1
72 => 31 7 28 39 51 16 22 6 21 4 10 1
55 => 30 6 21 4 10 1
78 => 64 31 7 28 39 51 16 22 6 21 4 10 1
613 => 28 39 51 16 22 6 21 4 10 1
8392 => 90 45 25 18 37 34 16 22 6 21 4 10 1
11111 => 5 15 16 22 6 21 4 10 1
8592025 => 117 30 6 21 4 10 1
999999999 => 405 25 18 37 34 16 22 6 21 4 10 1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
triangular(uvlong n)
{
	return n * (n + 1) / 2;
}

uvlong
digitangular(uvlong n)
{
	uvlong r;

	r = 0;
	do {
		r += triangular(n % 10);
		n /= 10;
	} while (n > 0);
	return r;
}

size_t
gen(uvlong n, uvlong *r)
{
	size_t i;

	i = 0;
	do {
		r[i++] = n = digitangular(n);
	} while (n > 1);

	return i;
}

void
test(uvlong n, uvlong *r, size_t nr)
{
	uvlong p[32];
	size_t np;

	np = gen(n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	uvlong r1[] = {9, 45, 25, 18, 37, 34, 16, 22, 6, 21, 4, 10, 1};
	uvlong r2[] = {31, 7, 28, 39, 51, 16, 22, 6, 21, 4, 10, 1};
	uvlong r3[] = {30, 6, 21, 4, 10, 1};
	uvlong r4[] = {64, 31, 7, 28, 39, 51, 16, 22, 6, 21, 4, 10, 1};
	uvlong r5[] = {28, 39, 51, 16, 22, 6, 21, 4, 10, 1};
	uvlong r6[] = {90, 45, 25, 18, 37, 34, 16, 22, 6, 21, 4, 10, 1};
	uvlong r7[] = {5, 15, 16, 22, 6, 21, 4, 10, 1};
	uvlong r8[] = {117, 30, 6, 21, 4, 10, 1};
	uvlong r9[] = {405, 25, 18, 37, 34, 16, 22, 6, 21, 4, 10, 1};

	test(23, r1, nelem(r1));
	test(72, r2, nelem(r2));
	test(55, r3, nelem(r3));
	test(78, r4, nelem(r4));
	test(613, r5, nelem(r5));
	test(8392, r6, nelem(r6));
	test(11111, r7, nelem(r7));
	test(8592025, r8, nelem(r8));
	test(999999999, r9, nelem(r9));

	return 0;
}
