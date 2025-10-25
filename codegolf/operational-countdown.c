/*

Given a non negative integer number n output how many steps to reach zero using radicals, divisions or subtractions.

The algorithm
Get digits count (d) of n.

Try the following operations in order:
n^(1/d)
n/d
n-d

Take the first integer result not equal to n. Floating point errors must be avoided !

Repeat the process with the value obtained until you reach 0.

Example
1500 -> 8

1500 -> 4 digits , ( / ) => 375 // step 1
375 -> 3 digits , ( / ) => 125 // step 2
125 -> 3 digits , ( √ ) => 5 // step 3
5 -> 1 digits , ( - ) => 4 // step 4
4 -> 1 digits , ( - ) => 3 // step 5
3 -> 1 digits , ( - ) => 2 // step 6
2 -> 1 digits , ( - ) => 1 // step 7
1 -> 1 digits , ( - ) => 0 // step 8

Input: a non negative integer number. You don't have to handle inputs not supported by your language (obviously, abusing this is a standard loophole)

Output: the number of steps to reach 0

Test cases
n -> steps

0 -> 0
1 -> 1
2 -> 2
4 -> 4
10 -> 6
12 -> 7
16 -> 5
64 -> 9
100 -> 19
128 -> 7
1000 -> 70
1296 -> 7
1500 -> 8
5184 -> 8
10000 -> 133
21550 -> 1000
26720 -> 100
1018080 -> 16
387420489 -> 10

Rules
Input/output can be given by any convenient method.
You can print it to STDOUT, return it as a function result or error message/s.
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
Answers must not fail due to floating point errors.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

Sandbox: https://codegolf.meta.stackexchange.com/a/20518/84844

*/

#include <assert.h>
#include <math.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
nroot(uvlong n, uvlong d)
{
	uvlong x, y;
	double s;

	if (d == 0)
		return 0;

	s = pow(n, 1.0 / d);
	x = pow(floor(s), d);
	y = pow(ceil(s), d);
	if (x == n)
		return floor(s);
	if (y == n)
		return ceil(s);
	return 0;
}

uvlong
digits(uvlong n)
{
	uvlong r;

	if (n == 0)
		return 1;

	for (r = 0; n; n /= 10)
		r++;

	return r;
}

uvlong
countdown(uvlong n)
{
	uvlong c, d;
	uvlong x, y, z;

	for (c = 0; n && c < ULLONG_MAX; c++) {
		d = digits(n);
		x = nroot(n, d);
		y = (n % d) ? 0 : n / d;
		z = n - d;

		if (x && x != n)
			n = x;
		else if (y && y != n)
			n = y;
		else
			n = z;
	}
	return c;
}

int
main(void)
{
	assert(countdown(0) == 0);
	assert(countdown(1) == 1);
	assert(countdown(2) == 2);
	assert(countdown(4) == 4);
	assert(countdown(10) == 6);
	assert(countdown(12) == 7);
	assert(countdown(16) == 5);
	assert(countdown(64) == 9);
	assert(countdown(100) == 19);
	assert(countdown(128) == 7);
	assert(countdown(1000) == 70);
	assert(countdown(1296) == 7);
	assert(countdown(1500) == 8);
	assert(countdown(5184) == 8);
	assert(countdown(10000) == 133);
	assert(countdown(21550) == 1000);
	assert(countdown(26720) == 100);
	assert(countdown(1018080) == 16);
	assert(countdown(387420489) == 10);

	return 0;
}
