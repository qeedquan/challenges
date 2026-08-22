/*

In this challenge posed by xnor, we were asked to implement XOR multiplication. In this challenge the goal is to find the first n XOR primes. XOR primes are very similar to regular primes as you can see by the following definitions:

Definition of Prime Number: A positive number greater than 1 which cannot be formed through multiplication of two numbers except through the multiplication of 1 and itself.

Definition of XOR Prime: A positive number greater than 1 which cannot be formed through XOR multiplication of two numbers except through the XOR multiplication of 1 and itself. Note that the XOR primes compose oeis sequence A014580.

XOR multiplication is defined as binary long multiplication without carrying. You can find more information about XOR multiplication in xnor's challenge.

Input:
An integer n.

Output:
The first n XOR primes.

Here are the XOR primes under 500:
2 3 7 11 13 19 25 31 37 41 47 55 59 61 67 73 87 91 97 103 109 115 117 131 137 143 145 157 167 171 185 191 193 203 211 213 229 239 241 247 253 283 285 299 301 313 319 333 351 355 357 361 369 375 379 391 395 397 415 419 425 433 445 451 463 471 477 487 499

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
xormul(unsigned a, unsigned b)
{
	unsigned r;

	r = 0;
	while (b) {
		r ^= (b & 1) * a;
		a <<= 1;
		b >>= 1;
	}
	return r;
}

// https://oeis.org/A014580
bool
xorprime(unsigned n)
{
	unsigned a, b;

	for (a = 2; a < n; a++) {
		for (b = a; b < n; b++) {
			if (xormul(a, b) == n)
				return false;
		}
	}
	return true;
}

size_t
gen(size_t n, unsigned *r)
{
	size_t i;
	unsigned p;

	p = 2;
	for (i = 0; i < n && p < UINT_MAX; p++) {
		if (xorprime(p))
			r[i++] = p;
	}
	return i;
}

int
main(void)
{
	static const unsigned tab[] = {2, 3, 7, 11, 13, 19, 25, 31, 37, 41, 47, 55, 59, 61, 67, 73, 87, 91, 97, 103, 109, 115, 117, 131, 137, 143, 145, 157, 167, 171, 185, 191, 193, 203, 211, 213, 229, 239, 241, 247, 253, 283, 285, 299, 301, 313, 319, 333, 351, 355, 357, 361, 369, 375, 379, 391, 395, 397, 415, 419, 425, 433, 445, 451, 463, 471, 477, 487, 499};

	unsigned p[128];
	size_t n;

	n = gen(nelem(tab), p);
	assert(n == nelem(tab));
	assert(!memcmp(p, tab, sizeof(tab)));

	return 0;
}
