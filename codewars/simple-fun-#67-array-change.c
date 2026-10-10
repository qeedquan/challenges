/*

Task
You are given an array of integers. On each move you are allowed to increase exactly one of its element by one. Find the minimal number of moves required to obtain a strictly increasing sequence from the input.

Example
For arr = [1, 1, 1], the output should be 3.

Input/Output
[input] integer array arr

Constraints:

3 ≤ inputArray.length ≤ 100,

-10000 ≤ inputArray[i] ≤ 10000.

[output] an integer

The minimal number of moves needed to obtain a strictly increasing sequence from inputArray.

It's guaranteed that for the given test cases the answer always fits signed 32-bit integer type.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
arraychange(int *a, size_t n)
{
	int c, p;
	size_t i;

	if (n == 0)
		return 0;

	c = 0;
	p = a[0];
	for (i = 1; i < n; i++) {
		if (p >= a[i]) {
			c += p - a[i] + 1;
			p += 1;
		} else
			p = a[i];
	}
	return c;
}

int
main()
{
	int a1[] = { 1, 1, 1 };
	int a2[] = { -1000, 0, -2, 0 };
	int a3[] = { 2, 1, 10, 1 };
	int a4[] = { 2, 3, 3, 5, 5, 5, 4, 12, 12, 10, 15 };

	assert(arraychange(a1, nelem(a1)) == 3);
	assert(arraychange(a2, nelem(a2)) == 5);
	assert(arraychange(a3, nelem(a3)) == 12);
	assert(arraychange(a4, nelem(a4)) == 13);

	return 0;
}
