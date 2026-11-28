/*

You are given a positive integer n. Your task is to find any three integers a, b and c (0≤a,b,c≤10^9) for which (a⊕b)+(b⊕c)+(a⊕c)=n, or determine that there are no such integers.

Here a⊕b denotes the bitwise XOR of a and b. For example, 2⊕4=6 and 3⊕1=2.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤10^4) — the number of test cases. The following lines contain the descriptions of the test cases.

The only line of each test case contains a single integer n (1≤n≤10^9).

Output
For each test case, print any three integers a, b and c (0≤a,b,c≤10^9) for which (a⊕b)+(b⊕c)+(a⊕c)=n. If no such integers exist, print −1.

Example

input
5
4
1
12
2046
194723326

output
3 3 1
-1
2 4 6
69 420 666
12345678 87654321 100000000

Note
In the first test case, a=3, b=3, c=1, so (3⊕3)+(3⊕1)+(3⊕1)=0+2+2=4.

In the second test case, there are no solutions.

In the third test case, (2⊕4)+(4⊕6)+(2⊕6)=6+2+4=12.

*/

#include <assert.h>

typedef long long vlong;

vlong
xoreval(vlong a, vlong b, vlong c)
{
	return (a ^ b) + (b ^ c) + (a ^ c);
}

/*

If n is even the following holds:

a = b = n/2
c = 0

(a ^ b) = 0
(b ^ c) = n/2
(a ^ c) = n/2
n/2 + n/2 = n

If n is odd, there are no solution:

Use case by case analysis to show that:

Let a = b = c
a^b = 0
b^c = 0
a^c = 0
0 = n
n has to be 0 for this case to work

a != b, b = c (this also holds for a = c, b != c since we can just relabel variable names)
a^b = x
b^c = 0
a^c = x
2x = n
n has to be divisible by 2 for this case to work

a != b, a != c, b != c
a ^ b = x
b ^ c = y
a ^ c = z
x + y + z = n

For this case consider the parity of the values:
odd + odd = even
even + even = even
even + odd = odd

which implies

(odd + odd) + even = even
(odd + even) + odd = even

(odd + odd) + odd = odd

So x, y, z has to be all odds

This implies
(a^b)&1 = 1
(b^c)&1 = 1
(a^c)&1 = 1

Due to this, we can work in GF(2) to get the property where a+b = a^b

Then we can brute force and show that all combinations of the truth table of a, b, and c gives an even parity.
Hence the result can never be an odd number.

*/

vlong
threexor(vlong n, vlong *a, vlong *b, vlong *c)
{
	if (n & 1)
		return -1;

	*a = *b = n / 2;
	*c = 0;
	return 0;
}

vlong
threexorbf(vlong n, vlong *a, vlong *b, vlong *c)
{
	vlong i, j, k;

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			for (k = 0; k <= n; k++) {
				if (xoreval(i, j, k) == n) {
					*a = i;
					*b = j;
					*c = k;
					return 0;
				}
			}
		}
	}
	return -1;
}

void
test(vlong n)
{
	vlong a, b, c;

	if (threexor(n, &a, &b, &c) < 0)
		assert(threexorbf(n, &a, &b, &c) < 0);
	else
		assert(xoreval(a, b, c) == n);
}

int
main(void)
{
	test(4);
	test(1);
	test(12);
	test(2046);
	test(194723326ULL);
	test(101);
	test(202);
	test(203);

	return 0;
}
