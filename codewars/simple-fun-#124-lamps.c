/*

Task
N lamps are placed in a line, some are switched on and some are off. What is the smallest number of lamps that need to be switched so that on and off lamps will alternate with each other?

You are given an array a of zeros and ones - 1 mean switched-on lamp and 0 means switched-off.

Your task is to find the smallest number of lamps that need to be switched.

Example
For a = [1, 0, 0, 1, 1, 1, 0], the result should be 3.

 a     --> 1 0 0 1 1 1 0  swith --> 0 1     0  became--> 0 1 0 1 0 1 0

Input/Output
[input] integer array a

array of zeros and ones - initial lamp setup, 1 mean switched-on lamp and 0 means switched-off.

2 < a.length <= 1000

[output] an integer

minimum number of switches.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
lamps(int *a, size_t n)
{
	size_t i, x, y;

	x = y = 0;
	for (i = 0; i < n; i++) {
		if (!(i & 1))
			(a[i]) ? x++ : y++;
		else
			(a[i]) ? y++ : x++;
	}
	return min(x, y);
}

int
main()
{
	int a1[] = { 1, 0, 0, 1, 1, 1, 0 };
	int a2[] = { 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 };
	int a3[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int a4[] = { 1, 0, 1 };
	int a5[] = { 1, 0, 1, 0 };
	int a6[] = { 0, 1, 0, 1, 0 };
	int a7[] = { 1, 0, 1, 0, 0, 1, 0, 1 };
	int a8[] = { 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 };

	assert(lamps(a1, nelem(a1)) == 3);
	assert(lamps(a2, nelem(a2)) == 5);
	assert(lamps(a3, nelem(a3)) == 6);
	assert(lamps(a4, nelem(a4)) == 0);
	assert(lamps(a5, nelem(a5)) == 0);
	assert(lamps(a6, nelem(a6)) == 0);
	assert(lamps(a7, nelem(a7)) == 4);
	assert(lamps(a8, nelem(a8)) == 5);

	return 0;
}
