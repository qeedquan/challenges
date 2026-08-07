/*

An array is **circularly sorted** if the elements are sorted in ascending order, but displaced, or rotated, by any number of steps. 

Complete the function/method that determines if the given array of integers is circularly sorted.


## Examples

These arrays are circularly sorted (true):

[2, 3, 4, 5, 0, 1]       -->  [0, 1] + [2, 3, 4, 5]
[4, 5, 6, 9, 1]          -->  [1] + [4, 5, 6, 9]
[10, 11, 6, 7, 9]        -->  [6, 7, 9] + [10, 11]
[1, 2, 3, 4, 5]          -->  [1, 2, 3, 4, 5]
[5, 7, 43, 987, -9, 0]   -->  [-9, 0] + [5, 7, 43, 987]
[1, 2, 3, 4, 1]          -->  [1] + [1, 2, 3, 4]


While these are not (false):
[4, 1, 2, 5]
[8, 7, 6, 5, 4, 3]
[6, 7, 4, 8]
[7, 6, 5, 4, 3, 2, 1]

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool
circlesorted(int *a, size_t n)
{
	size_t i, j, k, l;
	int m;

	if (n == 0)
		return true;

	m = INT_MAX;
	for (i = 0; i < n; i++) {
		if (m >= a[i]) {
			j = i;
			m = a[i];
		}
	}

	for (i = 0; i < n - 1; i++) {
		k = (j + i) % n;
		l = (k + 1) % n;
		if (a[k] > a[l])
			return false;
	}
	return true;
}

int
main()
{
	int a1[] = { 2, 3, 4, 5, 0, 1 };
	int a2[] = { 4, 5, 6, 9, 1 };
	int a3[] = { 10, 11, 6, 7, 9 };
	int a4[] = { 1, 2, 3, 4, 5 };
	int a5[] = { 5, 7, 43, 987, -9, 0 };
	int a6[] = { 1, 2, 3, 4, 1 };

	int a7[] = { 4, 1, 2, 5 };
	int a8[] = { 8, 7, 6, 5, 4, 3 };
	int a9[] = { 6, 7, 4, 8 };
	int a10[] = { 7, 6, 5, 4, 3, 2, 1 };

	assert(circlesorted(a1, nelem(a1)) == true);
	assert(circlesorted(a2, nelem(a2)) == true);
	assert(circlesorted(a3, nelem(a3)) == true);
	assert(circlesorted(a4, nelem(a4)) == true);
	assert(circlesorted(a5, nelem(a5)) == true);
	assert(circlesorted(a6, nelem(a6)) == true);

	assert(circlesorted(a7, nelem(a7)) == false);
	assert(circlesorted(a8, nelem(a8)) == false);
	assert(circlesorted(a9, nelem(a9)) == false);
	assert(circlesorted(a10, nelem(a10)) == false);

	return 0;
}
