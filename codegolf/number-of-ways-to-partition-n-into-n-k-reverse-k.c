/*

In this challenge you are asked to find in how many ways we can express a positive integer n as the sum of two positive integers k and the reverse of k.

Here is an example using n = 1069 :
188 + 881 = 1069
287 + 782 = 1069
386 + 683 = 1069
485 + 584 = 1069
980 + 89 = 1069
So, the answer here would be 5.

rules
As you can see we count every pair once: {188,881} is the same as {881,188}.
If a number cannot be expressed as such, your program should return 0.
Your program should take as input a positive integer and return an integer.

test cases

1 -> 0
2 -> 1 (this is 1 + 1 = 2)
22 -> 2
101 -> 1 ( this is 100 + 001 = 100 + 1 = 101 )
132 -> 4
8547 -> 20
49886 -> 0
955548 -> 113
1100000 -> 450

This is CodeGolf! The shortest code in bytes, wins!

*/

#include <assert.h>

typedef unsigned long ulong;

ulong
rev(ulong n)
{
	ulong r;

	for (r = 0; n; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

ulong
krk(ulong n)
{
	ulong i, j, k, r;

	for (i = r = 0; i <= n; i++) {
		j = rev(i);
		k = rev(j);
		if (i + j == n && (i <= j || i != k))
			r++;
	}
	return r;
}

int
main(void)
{
	assert(krk(1) == 0);
	assert(krk(2) == 1);
	assert(krk(22) == 2);
	assert(krk(101) == 1);
	assert(krk(132) == 4);
	assert(krk(1069) == 5);
	assert(krk(8547) == 20);
	assert(krk(49886) == 0);
	assert(krk(955548) == 113);
	assert(krk(1100000) == 450);

	return 0;
}
