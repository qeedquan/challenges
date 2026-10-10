/*

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

Example 2:

Input: nums = [100]
Output: 0

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

Strategy is to analyze n at a small number to find a pattern

Pick n=4 numbers: a, b, c, d, then

F(0) = 0a + 1b + 2c + 3d
F(1) = 3a + 0b + 1c + 2d
F(2) = 2a + 3b + 0c + 1d
F(3) = 1a + 2b + 3c + 0d

We can see how F(n) transform to F(n+1)

F(0) - F(1) = -3a + b + c + d
F(1) - F(2) = a + -3b + c + d
F(2) - F(3) = a + b + -3c + d
F(3) - F(0) = a + b + c + -3d

So, we can transform to the following expression:

F(1) = F(0) - (a+b+c+d) + 4a
F(2) = F[1] - (a+b+c+d) + 4b
F(3) = F[2] - (a+b+c+d) + 4c

The general formula is:

F(n) = F(n-1) - sum(array) + len(array) * array[n-1]

*/

int
mrf(int *a, size_t n)
{
	size_t i;
	int f, s, r;

	f = s = 0;
	for (i = 0; i < n; i++) {
		s += a[i];
		f += a[i] * i;
	}

	r = f;
	for (i = 1; i < n; i++) {
		f = f - s + (n * a[i - 1]);
		r = max(r, f);
	}
	return r;
}

int
main()
{
	int a1[] = { 4, 3, 2, 6 };
	int a2[] = { 100 };

	assert(mrf(a1, nelem(a1)) == 26);
	assert(mrf(a2, nelem(a2)) == 0);

	return 0;
}
