/*

Your task is to finish two functions, minimumSum and maximumSum, that take 2 parameters:

values: an array of integers with an arbitrary length; may be positive and negative
n: how many integers should be summed; always 0 or bigger
Example:
var values = [5, 4, 3, 2, 1];
minimumSum(values, 2); // should return 1+2 = 3
maximumSum(values, 3); // should return 3+4+5 = 12
All values given to the functions will be integers. Also take care of the following special cases:

if values is empty, both functions should return 0
if n is 0, both functions should also return 0
if n is larger than values's length, use the length instead.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
ascending(const void *a, const void *b)
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

int
descending(const void *a, const void *b)
{
	return -ascending(a, b);
}

int
sum(int *array, size_t size, size_t limit, int (*cmp)(const void *, const void *))
{
	int total;
	size_t i;

	qsort(array, size, sizeof(*array), cmp);

	total = 0;
	for (i = 0; i < limit; i++)
		total += array[i];
	return total;
}

int
minsum(int *array, size_t size, size_t limit)
{
	return sum(array, size, limit, ascending);
}

int
maxsum(int *array, size_t size, size_t limit)
{
	return sum(array, size, limit, descending);
}

int
main()
{
	int array[] = { 5, 4, 3, 2, 1 };

	assert(minsum(array, nelem(array), 2) == 3);
	assert(maxsum(array, nelem(array), 3) == 12);
	return 0;
}
