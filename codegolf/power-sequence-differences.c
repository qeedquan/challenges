/*

Your task
Given two positive integers x and d (such that d<x), output the 5th term of the dth difference of the sequence n^x

Example
Let's say we are given the inputs x=4 and d=2.

First, we get the series n^4:

0^4=0
1^4=1
2^4=16
3^4=81
...
These are the first 10 elements:

0 1 16 81 256 625 1296 2401 4096 6561
Now we work out the differences:

0 1 16 81 256 625 1296 2401  // Original series
 1 15 65 175 369 671 1105    // 1st difference
  14 50 110 194 302 434      // 2nd difference
Finally, we get the 5th term (1-indexed) and output:

302
Note: this is sequence, so as long as the 5th term is somewhere in your output, it's fine.

Test cases
x  d  OUTPUT
4  2  302
2  1  9
3  2  30
5  3  1830

This Python program can be used to get the first three differences of any power series.

a = [n ** m for n in range(10)]
print('Series:', a)

b = [y - x for x, y in zip(a, a[1:])]
print('1st:', b)

c = [w - v for v, w in zip(b, b[1:])]
print('2nd:', c)

d = [u - t for t, u in zip(c, c[1:])]
print('3rd:', d)

Rules
This is sequence, so the input/output can be in any form.
This is code-golf, so shortest code in bytes wins!

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
f(vlong x, vlong d, vlong b)
{
	if (d < 0)
		return 0;

	if (d == 0)
		return pow(b, x);

	return f(x, d - 1, b + 1) - f(x, d - 1, b);
}

/*

@loopy walt

Straight-forward recursion.

*/

vlong
psd(vlong x, vlong d)
{
	return f(x, d, 4);
}

int
main(void)
{
	assert(psd(4, 2) == 302);
	assert(psd(2, 1) == 9);
	assert(psd(3, 2) == 30);
	assert(psd(5, 3) == 1830);

	return 0;
}
