/*

Task
Reversing an array can be a tough task, especially for a novice programmer. Mary just started coding, so she would like to start with something basic at first. Instead of reversing the array entirely, she wants to swap just its first and last elements.

Given an array arr, swap its first and last elements and return the resulting array.

Example
For arr = [1, 2, 3, 4, 5], the output should be [5, 2, 3, 4, 1]

Input/Output
[input] integer array arr

Constraints: 0 ≤ arr.length ≤ 50,  -1000 ≤ arr[i] ≤ 1000

[output] an integer array

Array arr with its first and its last elements swapped.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
frt(int *a, size_t n)
{
	int t;

	if (n > 0) {
		t = a[0];
		a[0] = a[n - 1];
		a[n - 1] = t;
	}
	return a;
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 5 };
	int r1[] = { 5, 2, 3, 4, 1 };

	assert(!memcmp(frt(a1, nelem(a1)), r1, sizeof(r1)));
	return 0;
}
