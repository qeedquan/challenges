/*

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3

Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://www.geeksforgeeks.org/find-the-element-that-appears-once/

The idea is to have two counters that keep tracks of bits in the odd/even positions:
1st, 4th, 7th, ...
2nd, 5th, 8th, ...

Use two variables, ones and twos, to track the bits that appear an odd and even number of times, respectively.
In each iteration, XOR the current element with ones to update ones with the bits that appear an odd number of times
then use a bitwise AND operation between ones and the current element to find the common bits that appear three times.
These common bits are removed from both ones and twos using a bitwise AND operation with the negation of the common bits.
Finally, ones contains the element that appears only once.

This makes it so at the end the first counter will be the value we want because we are guaranteed all other elements will appear three times.

*/

int
single(int *a, size_t n)
{
	int b, x, y;
	size_t i;

	x = y = 0;
	for (i = 0; i < n; i++) {
		y |= (x & a[i]);
		x ^= a[i];
		b = ~(x & y);
		x &= b;
		y &= b;
	}
	return x;
}

int
main(void)
{
	int a1[] = { 3, 3, 2, 3 };
	int a2[] = { 2, 2, 3, 2 };
	int a3[] = { 0, 1, 0, 1, 0, 1, 99 };

	assert(single(a1, nelem(a1)) == 2);
	assert(single(a2, nelem(a2)) == 3);
	assert(single(a3, nelem(a3)) == 99);

	return 0;
}
