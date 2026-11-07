/*

Task
Given integers n, l and r, find the number of ways to represent n as a sum of two integers A and B such that l ≤ A ≤ B ≤ r.

Example
For n = 6, l = 2 and r = 4, the output should be 2

There are just two ways to write 6 as A + B, where 2 ≤ A ≤ B ≤ 4:

6 = 2 + 4 and 6 = 3 + 3

Input/Output
[input] integer n

A positive integer.

Constraints: 5 ≤ n ≤ 10^6.

[input] integer l

A positive integer.

Constraints: 1 ≤ l ≤ r.

[input] integer r

A positive integer.

Constraints: l ≤ r ≤ 10^6

[output] an integer

*/

#include <assert.h>

int
count(int n, int l, int r)
{
	int i, c;

	c = 0;
	for (i = l; i <= r; i++) {
		if (n - i <= r && n - i >= i)
			c++;
	}
	return c;
}

int
main()
{
	assert(count(6, 2, 4) == 2);
	assert(count(6, 3, 3) == 1);
	assert(count(10, 9, 11) == 0);
	assert(count(24, 8, 16) == 5);
	assert(count(24, 12, 12) == 1);
	assert(count(93, 24, 58) == 12);
	return 0;
}
