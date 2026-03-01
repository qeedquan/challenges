/*

You've just recently been hired to calculate scores for a Dart Board game!

Scoring specifications:

0 points - radius above 10
5 points - radius between 5 and 10 inclusive
10 points - radius less than 5
If all radii are less than 5, award 100 BONUS POINTS!

Write a function that accepts an array of radii (can be integers and/or floats), and returns a total score using the above specification.

An empty array should return 0.

Examples:
scoreThrows( [1, 5, 11] )    =>  15
scoreThrows( [15, 20, 30] )  =>  0
scoreThrows( [1, 2, 3, 4] )  =>  140

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
score(int *a, size_t n)
{
	size_t c, i;
	int r;

	r = 0;
	for (c = i = 0; i < n; i++) {
		if (a[i] < 5) {
			r += 10;
			c += 1;
		} else if (a[i] <= 10)
			r += 5;
	}
	if (c == n)
		r += 100;

	return r;
}

int
main()
{
	int a1[] = {1, 5, 11};
	int a2[] = {15, 20, 30};
	int a3[] = {1, 2, 3, 4};

	assert(score(a1, nelem(a1)) == 15);
	assert(score(a2, nelem(a2)) == 0);
	assert(score(a3, nelem(a3)) == 140);

	return 0;
}
