/*

Description

Write a program that, given three positive integers x, y and z (x, y, z < 2^32, x ≤ y), computes the bitwise exclusive disjunction (XOR) of the arithmetic progression x, x + z, x + 2z, …, x + kz, where k is the largest integer such that x + kz ≤ y.

Input

The input contains multiple test cases. Each test case consists of three integers x, y, z separated by single spaces on a separate line. There are neither leading or trailing blanks nor empty lines. The input ends once EOF is met.

Output

For each test case, output the value of  on a separate line. There should be neither leading or trailing spaces nor empty lines.

Sample Input

2 173 11
Sample Output

48
Source

POJ Founder Monthly Contest – 2008.01.31, frkstyc

*/

#include <assert.h>
#include <limits.h>

void
swap(unsigned *a, unsigned *b)
{
	unsigned t;

	t = *a;
	*a = *b;
	*b = t;
}

unsigned
triangular(unsigned n)
{
	return n * (n + 1) / 2;
}

unsigned
recurse(unsigned a, unsigned b, unsigned c, unsigned n)
{
	unsigned r;

	if (n == 0)
		return 0;

	r = (b / c) * n;
	r += (a / c) * triangular(n - 1);
	r += recurse(c, ((a * n) + b) % c, a % c, (((a % c) * n) + (b % c)) / c);
	return r;
}

unsigned
xorap(unsigned x, unsigned y, unsigned z)
{
	unsigned i, l, r;

	if (z == 0)
		return 0;

	if (x > y)
		swap(&x, &y);

	l = sizeof(l) * CHAR_BIT;
	for (r = i = 0; i < l; i++)
		r |= (recurse(z, x, 1U << i, (y - x) / z + 1) & 1) << i;
	return r;
}

unsigned
xorapbf(unsigned x, unsigned y, unsigned z)
{
	unsigned k, n, r;

	if (z == 0)
		return 0;

	if (x > y)
		swap(&x, &y);

	n = (y - x) / z;
	for (r = k = 0; k <= n; k++)
		r ^= x + (k * z);
	return r;
}

int
main(void)
{
	unsigned x, y, z, N;

	assert(xorap(2, 173, 11) == 48);

	N = 300;
	for (x = 0; x <= N; x++) {
		for (y = 0; y <= N; y++) {
			for (z = 0; z <= N; z++) {
				assert(xorap(x, y, z) == xorapbf(x, y, z));
			}
		}
	}

	return 0;
}
