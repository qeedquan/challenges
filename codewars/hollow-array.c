/*

An array is said to be hollow if it contains 3 or more 0s in the middle that are preceded and followed by the same number of non-zero elements. Furthermore, all the zeroes in the array must be in the middle of the array.

Write a function that accepts an integer array and returns true if it is a hollow array, else false.

Examples
[2, 3, 0, 0, 0, 5, 6] --> true
[2, 0, 0, 0, 5, 6] --> false // 1 nonzero to the left but 2 to the right
[2, 3, 0, 0, 5, 6] --> false // less than 3 zeroes in the middle
[0, 2, 0, 0, 0, 5, 6] --> false // 1 zero not in the middle
[0, 0, 0, 0, 0] --> true // 0 nonzero elements at both ends
[] --> false

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
ishollow(int *a, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		if (a[i] == 0)
			break;
	}

	for (j = n; j > i; j--) {
		if (a[j - 1] == 0)
			break;
	}

	if (j - i < 3 || i != n - j)
		return false;

	for (; i != j; i++) {
		if (a[i] != 0)
			return false;
	}

	return true;
}

int
main()
{
	int a1[] = { 2, 3, 0, 0, 0, 5, 6 };
	int a2[] = { 2, 0, 0, 0, 5, 6 };
	int a3[] = { 2, 3, 0, 0, 5, 6 };
	int a4[] = { 0, 2, 0, 0, 0, 5, 6 };
	int a5[] = { 0, 0, 0, 0, 0 };
	int a6[] = { -1, 0, 0, 0, 3 };
	int a7[] = { 1, 0, 0, 0, 0 };
	int a8[] = { 100, 0, 0, 3 };

	assert(ishollow(a1, nelem(a1)) == true);
	assert(ishollow(a2, nelem(a2)) == false);
	assert(ishollow(a3, nelem(a3)) == false);
	assert(ishollow(a4, nelem(a4)) == false);
	assert(ishollow(a5, nelem(a5)) == true);
	assert(ishollow(NULL, 0) == false);
	assert(ishollow(a6, nelem(a6)) == true);
	assert(ishollow(a7, nelem(a7)) == false);
	assert(ishollow(a8, nelem(a8)) == false);

	return 0;
}
