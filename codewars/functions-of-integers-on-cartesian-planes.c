/*

Let us consider integer coordinates x, y in the Cartesian plane and three functions f, g, h defined by:

f: 1 <= x <= n, 1 <= y <= n --> f(x, y) = min(x, y)
g: 1 <= x <= n, 1 <= y <= n --> g(x, y) = max(x, y)
h: 1 <= x <= n, 1 <= y <= n --> h(x, y) = x + y
where n is a given integer (n >= 1) and x, y are integers.

In the table below you can see the value of the function f with n = 6.

---	x=1	x=2	x=3	x=4	x=5	x=6
y=6	1	2	3	4	5	6
y=5	1	2	3	4	5	5
y=4	1	2	3	4	4	4
y=3	1	2	3	3	3	3
y=2	1	2	2	2	2	2
y=1	1	1	1	1	1	1

The task is to calculate the sum of f(x, y), g(x, y) and h(x, y) for all integers x and y in the domain D: (1 <= x <= n, 1 <= y <= n).

The function sumin (sum of f) will take n as a parameter and return the sum of min(x, y) in D.

The function sumax (sum of g) will take n as a parameter and return the sum of max(x, y) in D.

The function sumsum (sum of h) will take n as a parameter and return the sum of x + y in D.

Examples:
sumin(6) --> 91 (You can verify with the above table for n = 6)
sumax(6) --> 161
sumsum(6) --> 252

sumin(45) --> 31395
sumax(45) --> 61755
sumsum(45) --> 93150

sumin(999) --> 332833500
sumax(999) --> 665167500
sumsum(999) --> 998001000

sumin(5000) --> 41679167500
sumax(5000) --> 83345832500
sumsum(5000) --> 125025000000

*/

#include <assert.h>

typedef unsigned long long uvlong;

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

uvlong
suminbf(uvlong n)
{
	uvlong r, x, y;

	r = 0;
	for (x = 1; x <= n; x++) {
		for (y = 1; y <= n; y++)
			r += min(x, y);
	}
	return r;
}

uvlong
sumaxbf(uvlong n)
{
	uvlong r, x, y;

	r = 0;
	for (x = 1; x <= n; x++) {
		for (y = 1; y <= n; y++)
			r += max(x, y);
	}
	return r;
}

uvlong
sumsumbf(uvlong n)
{
	uvlong r, x, y;

	r = 0;
	for (x = 1; x <= n; x++) {
		for (y = 1; y <= n; y++)
			r += x + y;
	}
	return r;
}

// https://oeis.org/A000330
uvlong
sumin(uvlong n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

// https://oeis.org/A002412
uvlong
sumax(uvlong n)
{
	return n * (n + 1) * (4 * n - 1) / 6;
}

// https://oeis.org/A011379
uvlong
sumsum(uvlong n)
{
	return (n * n) * (n + 1);
}

int
main()
{
	uvlong i;

	for (i = 0; i <= 1000; i++) {
		assert(sumin(i) == suminbf(i));
		assert(sumax(i) == sumaxbf(i));
		assert(sumsum(i) == sumsumbf(i));
	}

	assert(sumin(6) == 91);
	assert(sumax(6) == 161);
	assert(sumsum(6) == 252);

	assert(sumin(45) == 31395);
	assert(sumax(45) == 61755);
	assert(sumsum(45) == 93150);

	assert(sumin(999) == 332833500);
	assert(sumax(999) == 665167500);
	assert(sumsum(999) == 998001000);

	assert(sumin(5000) == 41679167500);
	assert(sumax(5000) == 83345832500);
	assert(sumsum(5000) == 125025000000);

	return 0;
}
