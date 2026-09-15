/*

You are to create a sequence of integers, but with a twist.
When counting up from 1, any number containing a 9 should be skipped.
For instance, you would go from 8, to 10, to 11, skipping 9.
The sequence will therefore look like: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, ..., 18, 20, ..., etc.
You are given an integer n, and your task is to return the n-th number in this sequence.

For example, if you're asked for the 9th number in the sequence, the sequence would look as follows: 1, 2, 3, 4, 5, 6, 7, 8, 10.
Hence, you would return 10.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A007095
int
base9(int n)
{
	int b, r;

	r = 0;
	for (b = 1; n > 0; n /= 9) {
		r += (n % 9) * b;
		b *= 10;
	}
	return r;
}

int
main()
{
	static const int tab[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21,
		22, 23, 24, 25, 26, 27, 28, 30, 31, 32, 33, 34, 35, 36, 37, 38, 40, 41,
		42, 43, 44, 45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 60, 61,
		62, 63, 64, 65, 66, 67, 68, 70, 71, 72, 73, 74, 75, 76, 77, 78, 80, 81,
		82, 83, 84
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(base9(i) == tab[i]);

	return 0;
}
