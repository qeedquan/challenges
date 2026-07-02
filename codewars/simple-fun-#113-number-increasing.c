/*

Task
Initially a number 1 is written on a board. It is possible to do the following operations with it:

multiply the number by 3; increase the number by 5. Your task is to determine that using this two operations step by step, is it possible to obtain number n?

Example
For n = 1, the result should be true.

1 = 1

For n = 2, the result should be false.

For n = 3, the result should be true.

1 x 3 = 3

For n = 4, the result should be false.

For n = 5, the result should be false.

For n = 6, the result should be true.

1 + 5 = 6

For n = 18, the result should be true.

1 + 5 = 6  --> 6 x 3 = 18

For n = 32, the result should be true.

1 x 3 x 3 x 3 = 27  --> 27 + 5 = 32

For n = 100, the result should be false.

For n = 101, the result should be true.

1 + 5 + 5 + 5 ... +5 = 101

Input / Output
[input] integer n
positive integer, n ≤ 100000

[output] a boolean value
true if N can be obtained using given operations, false otherwise.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A335155
bool
numinc(long n)
{
	while (n > 1) {
		if (n % 5 == 1)
			return true;
		if (!(n % 3))
			n /= 3;
		else
			n -= 5;
	}
	return n == 1;
}

int
main()
{
	static const long tab[] = {
		1, 3, 6, 8, 9, 11, 13, 14, 16, 18, 19, 21, 23, 24, 26, 27, 28, 29, 31,
		32, 33, 34, 36, 37, 38, 39, 41, 42, 43, 44, 46, 47, 48, 49, 51, 52, 53,
		54, 56, 57, 58, 59, 61, 62, 63, 64, 66, 67, 68, 69, 71, 72, 73, 74, 76,
		77, 78, 79, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 96, 97, 98,
		99, 101, 102, 103, 104, 106
	};

	long i, j, n;

	n = tab[nelem(tab) - 1];
	for (i = j = 0; i <= n; i++) {
		if (i == tab[j]) {
			assert(numinc(i) == true);
			j += 1;
		} else
			assert(numinc(i) == false);
	}

	assert(numinc(1) == true);
	assert(numinc(2) == false);
	assert(numinc(3) == true);
	assert(numinc(4) == false);
	assert(numinc(5) == false);
	assert(numinc(6) == true);
	assert(numinc(100) == false);
	assert(numinc(101) == true);
	assert(numinc(12345) == false);
	assert(numinc(54321) == true);

	return 0;
}
