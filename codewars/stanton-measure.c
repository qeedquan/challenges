/*

The Stanton measure of an array is computed as follows: count the number of occurences for value 1 in the array. Let this count be n. The Stanton measure is the number of times that n appears in the array.

Write a function which takes an integer array and returns its Stanton measure.

Examples
The Stanton measure of [1, 4, 3, 2, 1, 2, 3, 2] is 3, because 1 occurs 2 times in the array and 2 occurs 3 times.

The Stanton measure of [1, 4, 1, 2, 11, 2, 3, 1] is 1, because 1 occurs 3 times in the array and 3 occurs 1 time.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
stanton(int *a, size_t n)
{
	size_t i;
	int c, x;

	for (x = i = 0; i < n; i++)
		x += (a[i] == 1);
	for (c = i = 0; i < n; i++)
		c += (a[i] == x);
	return c;
}

int
main()
{
	int a1[] = { 1, 4, 3, 2, 1, 2, 3, 2 };
	int a2[] = { 1, 4, 1, 2, 11, 2, 3, 1 };

	assert(stanton(a1, nelem(a1)) == 3);
	assert(stanton(a2, nelem(a2)) == 1);

	return 0;
}
