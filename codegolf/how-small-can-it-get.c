/*

Starting with a positive integer N, find the smallest integer N' which can be computed by repeatedly dividing N by one of its digits (in base-10). Each selected digit must be a divisor of N greater than 1.

Example #1
The expected output for N = 230 is N' = 23:

230/2=115
115/5=23

Example #2
The expected output for N = 129528 is N' = 257:

129528/8=16191
16191/9=1799
1799/7=257

Beware of non-optimal paths!

We could start with 129528 / 9 = 14392, but that would not lead to the smallest possible result. The best we can do if we first divide by 9 is:

129528/9=14392
14392/2=7196
7196/7=1028
1028/2=514 --> wrong!

Rules
Input can be taken in any reasonable format (integer, string, array of digits, ...).
This is code-golf, so the shortest answer in bytes wins!
Test cases
1         --> 1
7         --> 1
10        --> 10
24        --> 1
230       --> 23
234       --> 78
10800     --> 1
10801     --> 10801
50976     --> 118
129500    --> 37
129528    --> 257
8377128   --> 38783
655294464 --> 1111

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long uvlong;

void
count(uvlong x, uvlong d[10])
{
	memset(d, 0, sizeof(*d) * 10);
	do {
		d[x % 10] = 1;
		x /= 10;
	} while (x);
}

uvlong
smallest(uvlong x)
{
	uvlong d[10];
	uvlong i, r;

	count(x, d);

	r = x;
	for (i = 2; i < 10; i++) {
		if (d[i] && !(x % i))
			r = min(r, smallest(x / i));
	}
	return r;
}

int
main(void)
{
	assert(smallest(1) == 1);
	assert(smallest(7) == 1);
	assert(smallest(10) == 10);
	assert(smallest(24) == 1);
	assert(smallest(230) == 23);
	assert(smallest(234) == 78);
	assert(smallest(10800) == 1);
	assert(smallest(10801) == 10801);
	assert(smallest(50976) == 118);
	assert(smallest(129500) == 37);
	assert(smallest(129528) == 257);
	assert(smallest(8377128) == 38783);
	assert(smallest(655294464) == 1111);

	return 0;
}
