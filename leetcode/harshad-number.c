/*

An integer divisible by the sum of its digits is said to be a Harshad number.
You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.

Example 1:

Input: x = 18

Output: 9

Explanation:

The sum of digits of x is 9. 18 is divisible by 9. So 18 is a Harshad number and the answer is 9.

Example 2:

Input: x = 23

Output: -1

Explanation:

The sum of digits of x is 5. 23 is not divisible by 5. So 23 is not a Harshad number and the answer is -1.

Constraints:

1 <= x <= 100

Hint 1
Use a while loop and divide x by 10 to find the sum of the digits of x.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A325454
int
niven(int x)
{
	int r, y;

	r = 0;
	for (y = x; y; y /= 10)
		r += y % 10;
	if (!r || (x % r))
		return -1;
	return r;
}

int
main()
{
	static const int tab[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 9, 2, 3, 6, 9, 3, 9, 4, 6, 9, 12, 5,
		9, 6, 9, 7, 9, 8, 9, 12, 9, 1, 3, 9, 2, 3, 4, 6, 9, 3, 9, 6, 7, 9, 5,
		9, 6, 8, 9, 12, 9, 9, 9, 10, 12, 15, 18, 2, 3, 6, 9, 11, 3, 9, 4, 6,
		8, 9, 12, 5, 9, 6, 9, 13, 9, 9, 12, 14, 9, 10, 15
	};

	size_t i;
	int n, x;

	assert(niven(18) == 9);
	assert(niven(23) == -1);

	n = 1;
	for (i = 0; i < nelem(tab); n++) {
		x = niven(n);
		if (x != -1)
			assert(x == tab[i++]);
	}

	return 0;
}
