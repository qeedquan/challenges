/*

Task
You are given two numbers a and b where 0 ≤ a ≤ b. Imagine you construct an array of all the integers from a to b inclusive. You need to count the number of 1s in the binary representations of all the numbers in the array.

Example
For a = 2 and b = 7, the output should be 11

Given a = 2 and b = 7 the array is: [2, 3, 4, 5, 6, 7]. Converting the numbers to binary, we get [10, 11, 100, 101, 110, 111], which contains 1 + 2 + 1 + 2 + 2 + 3 = 11 1s.

Input/Output
[input] integer a
Constraints: 0 ≤ a ≤ b.

[input] integer b
Constraints: a ≤ b ≤ 100.

[output] an integer

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A000788
uvlong
bitcount(uvlong n)
{
	uvlong b, r;

	r = 0;
	for (b = 1; b <= n; b <<= 1) {
		r += (n >> 1) & ~(b - 1);
		if (n & b)
			r += (n & ((b << 1) - 1)) - (b - 1);
	}
	return r;
}

uvlong
rangebitcount(uvlong a, uvlong b)
{
	if (a)
		a -= 1;
	return bitcount(b) - bitcount(a);
}

int
main()
{
	static const uvlong tab[] = {
		0, 1, 2, 4, 5, 7, 9, 12, 13, 15, 17, 20, 22, 25, 28, 32, 33, 35, 37,
		40, 42, 45, 48, 52, 54, 57, 60, 64, 67, 71, 75, 80, 81, 83, 85, 88,
		90, 93, 96, 100, 102, 105, 108, 112, 115, 119, 123, 128, 130, 133, 136,
		140, 143, 147, 151, 156, 159, 163, 167, 172, 176, 181, 186
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(rangebitcount(0, i) == tab[i]);

	assert(rangebitcount(2, 7) == 11);
	assert(rangebitcount(0, 1) == 1);
	assert(rangebitcount(4, 4) == 1);

	return 0;
}
