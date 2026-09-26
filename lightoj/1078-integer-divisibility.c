/*

If an integer is not divisible by 2 or 5, there will be some multiple of that number in decimal notation with a sequence of only a digit.

For example, you have to find a multiple of 3 which contains only 1's. Then the result 111 (3-digit) divisible by 3. Similarly, if you are finding some multiple of 7 which contains only 3's then, the result is 333333 which is divisible by 7.

Now, you are given the number and the only allowable digit, you should report the number of digits of such a multiple.

Input
Input starts with an integer T (≤ 300), denoting the number of test cases.

Each case will contain two integers n (0 < n ≤ 10^6 and n will not be divisible by 2 or 5) and the allowable digit (1 ≤ digit ≤ 9).

Output
For each case, print the case number and the number of digits of such multiple. If several solutions are there; report the minimum one.

Sample
Input	Output
3
3 1
7 3
9901 1

Case 1: 3
Case 2: 6
Case 3: 12

Notes
For case 1, 111 is the smallest integer, and it contains 3 digits.
For case 2, 333333 is the smallest integer, and it contains 6 digits.

*/

#include <assert.h>

int
solve(int n, int d)
{
	int c, r;

	if (n == 0)
		return 0;

	c = r = 0;
	for (;;) {
		r = ((r * 10) + d) % n;
		c += 1;
		if (r == 0)
			break;
	}
	return c;
}

int
main()
{
	assert(solve(3, 1) == 3);
	assert(solve(7, 3) == 6);
	assert(solve(9901, 1) == 12);

	return 0;
}
