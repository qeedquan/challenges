/*

In this question at Code Review they tried to find the fastest way to return the unique element in an array where all the elements are the same except one. But what is the shortest code that accomplish the same thing?

Goal
Find the unique element in an array and return it.

Rules
The input array will contain only integer, strictly positive numbers, so you can use 0 as the end of the input if your language needs it.
The size of the array will be at least 3 and will have a finite size. You can limit the size of the array to any limit your language has.
Every element in the array will be the same, except for one which will be different.
You must output the value (not the position) of the unique element in any standard format. You can output leading or trailing spaces or newlines.
You can take the input array in any accepted format.
Examples
Input                   Output
------------------------------
[ 1, 1, 1, 2, 1, 1 ]      2
[ 3, 5, 5, 5, 5 ]         3
[ 9, 2, 9, 9, 9, 9, 9 ]   2
[ 4, 4, 4, 6 ]            6
[ 5, 8, 8 ]               5
[ 8, 5, 8 ]               5
[ 8, 8, 5 ]               5

Winner
This is code-golf, so may the shortest code for each language win!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
uniq(int *a, size_t n)
{
	size_t i, j;
	size_t c[2];
	int x[2];

	if (n == 0)
		return 0;

	c[0] = 1;
	c[1] = 0;
	x[0] = x[1] = a[0];
	for (i = 1; i < n; i++) {
		j = (x[0] != a[i]);
		c[j] += 1;
		x[j] = a[i];
	}
	return (c[0] < c[1]) ? x[0] : x[1];
}

int
main(void)
{
	int a1[] = {1, 1, 1, 2, 1, 1};
	int a2[] = {3, 5, 5, 5, 5};
	int a3[] = {9, 2, 9, 9, 9, 9, 9};
	int a4[] = {4, 4, 4, 6};
	int a5[] = {5, 8, 8};
	int a6[] = {8, 5, 8};
	int a7[] = {8, 8, 5};

	assert(uniq(a1, nelem(a1)) == 2);
	assert(uniq(a2, nelem(a2)) == 3);
	assert(uniq(a3, nelem(a3)) == 2);
	assert(uniq(a4, nelem(a4)) == 6);
	assert(uniq(a5, nelem(a5)) == 5);
	assert(uniq(a6, nelem(a6)) == 5);
	assert(uniq(a7, nelem(a7)) == 5);

	return 0;
}
