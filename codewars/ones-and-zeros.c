/*

Given an array of ones and zeroes, convert the equivalent binary value to an integer.

Eg: [0, 0, 0, 1] is treated as 0001 which is the binary representation of 1.

Examples:

Testing: [0, 0, 0, 1] ==> 1
Testing: [0, 0, 1, 0] ==> 2
Testing: [0, 1, 0, 1] ==> 5
Testing: [1, 0, 0, 1] ==> 9
Testing: [0, 0, 1, 0] ==> 2
Testing: [0, 1, 1, 0] ==> 6
Testing: [1, 1, 1, 1] ==> 15
Testing: [1, 0, 1, 1] ==> 11
However, the arrays can have varying lengths, not just limited to 4.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
arr2bin(unsigned *a, size_t n)
{
	unsigned r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r = (r << 1) | a[i];
	return r;
}

int
main()
{
	unsigned a1[] = { 0, 0, 0, 1 };
	unsigned a2[] = { 0, 0, 1, 0 };
	unsigned a3[] = { 0, 1, 0, 1 };
	unsigned a4[] = { 1, 0, 0, 1 };
	unsigned a5[] = { 0, 0, 1, 0 };
	unsigned a6[] = { 0, 1, 1, 0 };
	unsigned a7[] = { 1, 1, 1, 1 };
	unsigned a8[] = { 1, 0, 1, 1 };

	assert(arr2bin(a1, nelem(a1)) == 1);
	assert(arr2bin(a2, nelem(a2)) == 2);
	assert(arr2bin(a3, nelem(a3)) == 5);
	assert(arr2bin(a4, nelem(a4)) == 9);
	assert(arr2bin(a5, nelem(a5)) == 2);
	assert(arr2bin(a6, nelem(a6)) == 6);
	assert(arr2bin(a7, nelem(a7)) == 15);
	assert(arr2bin(a8, nelem(a8)) == 11);

	return 0;
}
