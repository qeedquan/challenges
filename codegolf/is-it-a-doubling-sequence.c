/*

A doubling sequence is an array of numbers where each subsequent number is at least twice the previous number.

Given an ordered list of numbers, determine if the numbers in the list (nx) have the property that:

n1*2 <= n2

n2*2 <= n3 ...

and so on until reaching the end of the list.

Input
A list of two or more numbers.

Output
Any distinct True or False value.

Examples:
[10,20,30] -> False
[10,20,40] -> True
[1,2,3] -> False
[1,2,4] -> True
[1,2,10] -> True
[1,1] -> False
[10,1] -> False

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
doubling(int *a, size_t n)
{
	size_t i;

	if (n == 0)
		return false;

	for (i = 1; i < n; i++) {
		if ((a[i - 1] * 2) > a[i])
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = {10, 20, 30};
	int a2[] = {10, 20, 40};
	int a3[] = {1, 2, 3};
	int a4[] = {1, 2, 4};
	int a5[] = {1, 2, 10};
	int a6[] = {1, 1};
	int a7[] = {10, 1};

	assert(doubling(a1, nelem(a1)) == false);
	assert(doubling(a2, nelem(a2)) == true);
	assert(doubling(a3, nelem(a3)) == false);
	assert(doubling(a4, nelem(a4)) == true);
	assert(doubling(a5, nelem(a5)) == true);
	assert(doubling(a6, nelem(a6)) == false);
	assert(doubling(a7, nelem(a7)) == false);

	return 0;
}
