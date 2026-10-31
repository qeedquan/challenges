/*

The magic sum of 3s is calculated on an array by summing up odd numbers which include the digit 3. Write a function magic_sum which accepts an array of integers and returns the sum.

Example: [3, 12, 5, 8, 30, 13] results in 16 (3 + 13)

If the sum cannot be calculated, 0 should be returned.

*/

#include <stdio.h>
#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
has3(int n)
{
	for (; n > 0; n /= 10) {
		if (n % 10 == 3)
			return 1;
	}
	return 0;
}

int
magicsum(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		if ((a[i] & 1) && has3(a[i]))
			r += a[i];
	}
	return r;
}

int
main()
{
	int a1[] = {3};
	int a2[] = {3, 13};
	int a3[] = {30, 34, 330};
	int a4[] = {3, 12, 5, 8, 30, 13};

	assert(magicsum(a1, nelem(a1)) == 3);
	assert(magicsum(a2, nelem(a2)) == 16);
	assert(magicsum(a3, nelem(a3)) == 0);
	assert(magicsum(a4, nelem(a4)) == 16);
	assert(magicsum(NULL, 0) == 0);
	return 0;
}
