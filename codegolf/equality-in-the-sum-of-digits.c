/*

Introduction
Let's take the number 180. This is an interesting number because the sum of digits of this number is equal to:

1 + 8 + 0 = 9
And the squared version of this number, or:

180² = 32400 > 3 + 2 + 4 + 0 + 0 = 9
These are both 9. The sum of digits of the original number and the squared number are the same. Of course, this is also found at OEIS: A058369.

Task
Given a non-negative integer n, output the nth positive number with this condition.

Test cases (zero-indexed)
Input > Output

0 > 1
1 > 9
2 > 10
3 > 18
4 > 19
5 > 45
6 > 46
7 > 55
8 > 90
9 > 99
10 > 100
11 > 145
12 > 180
13 > 189
14 > 190
15 > 198
16 > 199
17 > 289
18 > 351
19 > 361
The input can also be 1-indexed if that fits you better.

This is code-golf, so the submission with the least amount of bytes wins!

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
digitsum(uvlong n)
{
	uvlong r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A058369
uvlong
kk2ds(uvlong n)
{
	uvlong i, k, r;

	r = 1;
	k = 2;
	for (i = 0; i < n; k++) {
		if (digitsum(k) == digitsum(k * k)) {
			r = k;
			i = i + 1;
		}
	}
	return r;
}

int
main(void)
{
	static const uvlong tab[] = {1, 9, 10, 18, 19, 45, 46, 55, 90, 99, 100, 145, 180, 189, 190, 198, 199, 289, 351, 361};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(kk2ds(i) == tab[i]);

	return 0;
}
