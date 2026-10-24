/*

In this kata you are given an array to sort but you're expected to start sorting from a specific position of the array (in ascending order) and optionally you're given the number of items to sort.

Examples:
sectSort([1, 2, 5, 7, 4, 6, 3, 9, 8], 2) //=> [1, 2, 3, 4, 5, 6, 7, 8, 9]
sectSort([9, 7, 4, 2, 5, 3, 1, 8, 6], 2, 5) //=> [9, 7, 1, 2, 3, 4, 5, 8, 6]

Documentation:
sectSort(array, start, length);

array - array to sort
start - position to begin sorting
length - number of items to sort (optional)

if the length argument is not passed or is zero, you sort all items to the right of the start position in the array

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
secsort(int *array, size_t start, size_t length)
{
	qsort(array + start, length, sizeof(*array), cmp);
}

void
test(int *array, size_t size, size_t start, size_t length, int *expected)
{
	secsort(array, start, length);
	assert(!memcmp(array, expected, sizeof(*expected) * size));
}

int
main()
{
	int array1[] = { 1, 2, 5, 7, 4, 6, 3, 9, 8 };
	int array2[] = { 9, 7, 4, 2, 5, 3, 1, 8, 6 };

	int expected1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int expected2[] = { 9, 7, 1, 2, 3, 4, 5, 8, 6 };

	test(array1, nelem(array1), 2, 7, expected1);
	test(array2, nelem(array2), 2, 5, expected2);

	return 0;
}
