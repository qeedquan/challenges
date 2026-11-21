/*

Imagine you start on the 5th floor of a building, then travel down to the 2nd floor, then back up to the 8th floor. You have travelled a total of 3 + 6 = 9 floors of distance.

Given an array representing a series of floors you must reach by elevator, return an integer representing the total distance travelled for visiting each floor in the array in order.

// simple examples
elevatorDistance([5,2,8]) = 9
elevatorDistance([1,2,3]) = 2
elevatorDistance([7,1,7,1]) = 18

// if two consecutive floors are the same,
//distance travelled between them is 0
elevatorDistance([3,3]) = 0

Array will always contain at least 2 floors. Random tests will contain 2-20 elements in array, and floor values between 0 and 30.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
distance(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 1; i < n; i++)
		r += abs(a[i] - a[i - 1]);
	return r;
}

int
main()
{
	int a1[] = {5, 2, 8};
	int a2[] = {1, 2, 3};
	int a3[] = {7, 1, 7, 1};
	int a4[] = {3, 3};

	assert(distance(a1, nelem(a1)) == 9);
	assert(distance(a2, nelem(a2)) == 2);
	assert(distance(a3, nelem(a3)) == 18);
	assert(distance(a4, nelem(a4)) == 0);

	return 0;
}
