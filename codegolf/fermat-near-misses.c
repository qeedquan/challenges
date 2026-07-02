/*

Fermat's last theorem says that there there are no positive, integral solutions to the equation a^n + b^n = c^n for any n>2. This was proven to be true by Andrew Wiles in 1994.

However, there are many "near misses" that almost satisfy the diophantine equation but miss it by one. Precisely, they are all the greater than 1 and are integral solutions of a^3 + b^3 = c^3 + 1 (the sequence is the value of each side of the equation, in increasing order).

Your task is given n, to print out the first n values of this sequence.
Here are the first few values of the sequence:

1729, 1092728, 3375001, 15438250, 121287376, 401947273, 3680797185, 6352182209, 7856862273, 12422690497, 73244501505, 145697644729, 179406144001, 648787169394, 938601300672, 985966166178, 1594232306569, 2898516861513, 9635042700640, 10119744747001, 31599452533376, 49108313528001, 50194406979073, 57507986235800, 58515008947768, 65753372717929, 71395901759126, 107741456072705, 194890060205353, 206173690790977, 251072400480057, 404682117722064, 498168062719418, 586607471154432, 588522607645609, 639746322022297, 729729243027001

This is code-golf, so shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

#define cube(x) ((x) * (x) * (x))

// https://oeis.org/A050794
uvlong
gen(uvlong n, uvlong *r)
{
	uvlong a, b, c, i;

	i = 0;
	for (c = 3; i < n && c < ULLONG_MAX; c++) {
		for (a = 2; a < c; a++) {
			for (b = a; b < c; b++) {
				if (cube(a) + cube(b) == cube(c) + 1) {
					a = c;
					r[i++] = cube(c) + 1;
				}
			}
		}
	}
	return i;
}

void
test(uvlong *r, size_t n)
{
	uvlong v[128];
	uvlong m;

	m = gen(n, v);
	assert(n == m);
	assert(!memcmp(v, r, sizeof(*r) * n));
}

int
main(void)
{
	uvlong a1[] = {1729ULL, 1092728ULL, 3375001ULL, 15438250ULL, 121287376ULL, 401947273ULL, 3680797185ULL, 6352182209ULL};

	test(a1, nelem(a1));

	return 0;
}
