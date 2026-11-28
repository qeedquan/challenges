/*

Write a function

TripleDouble(long num1, long num2)

which takes numbers num1 and num2 and returns 1 if there is a straight triple of a number at any place in num1 and also a straight double of the **same** number in num2.

If this isn't the case, return 0


## Examples

TripleDouble(451999277, 41177722899) == 1 // num1 has straight triple 999s and
                                          // num2 has straight double 99s

TripleDouble(1222345, 12345) == 0 // num1 has straight triple 2s but num2 has only a single 2

TripleDouble(12345, 12345) == 0

TripleDouble(666789, 12345667) == 1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long uvlong;

void
straight(uvlong n, uvlong d[10])
{
	uvlong c, x, y;

	memset(d, 0, sizeof(*d) * 10);
	c = 1;
	x = n % 10;
	for (n /= 10; n; n /= 10) {
		y = n % 10;
		c = (x == y) ? c + 1 : 1;
		d[x] = max(d[x], c);
		x = y;
	}
	d[x] = max(d[x], c);
}

uvlong
tripledouble(uvlong n1, uvlong n2)
{
	uvlong d1[10], d2[10];
	uvlong i;

	straight(n1, d1);
	straight(n2, d2);
	for (i = 0; i < 10; i++) {
		if (d1[i] == 3 && d2[i] == 2)
			return 1;
	}
	return 0;
}

int
main()
{
	assert(tripledouble(451999277, 41177722899) == 1);
	assert(tripledouble(1222345, 12345) == 0);
	assert(tripledouble(12345, 12345) == 0);
	assert(tripledouble(666789, 12345667) == 1);
	assert(tripledouble(451999277, 411777228) == 0);
	assert(tripledouble(1112, 122) == 0);

	return 0;
}
