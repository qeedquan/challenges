/*

You are given three piles of casino chips: white, green and black chips:

the first pile contains only white chips
the second pile contains only green chips
the third pile contains only black chips
Each day you take exactly two chips of different colors and head to the casino. You can choose any color, but you are not allowed to take two chips of the same color in a day.

You will be given an array representing the number of chips of each color and your task is to return the maximum number of days you can pick the chips. Each day you need to take exactly two chips.

solve([1,1,1]) = 1, because after you pick on day one, there will be only one chip left
solve([1,2,1]) = 2, you can pick twice; you pick two chips on day one then on day two
solve([4,1,1]) = 2
More examples in the test cases. Good luck!

Brute force is not the way to go here. Look for a simplifying mathematical approach.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int *a, size_t n)
{
	size_t i;
	int m, s;

	if (n == 0)
		return 0;

	m = INT_MIN;
	s = 0;
	for (i = 0; i < n; i++) {
		s += a[i];
		m = max(m, a[i]);
	}
	return min(s / 2, s - m);
}

int
main()
{
	int a1[] = {1, 1, 1};
	int a2[] = {1, 2, 1};
	int a3[] = {4, 1, 1};
	int a4[] = {8, 2, 8};
	int a5[] = {8, 1, 4};
	int a6[] = {7, 4, 10};
	int a7[] = {12, 12, 12};
	int a8[] = {1, 23, 2};

	assert(solve(a1, nelem(a1)) == 1);
	assert(solve(a2, nelem(a2)) == 2);
	assert(solve(a3, nelem(a3)) == 2);
	assert(solve(a4, nelem(a4)) == 9);
	assert(solve(a5, nelem(a5)) == 5);
	assert(solve(a6, nelem(a6)) == 10);
	assert(solve(a7, nelem(a7)) == 18);
	assert(solve(a8, nelem(a8)) == 3);
	return 0;
}
