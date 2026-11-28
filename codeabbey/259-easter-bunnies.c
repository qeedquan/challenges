/*

You come across a family of Easter bunnies. They are quite one-dimensional creatures, and they have a very special way of leaving Easter eggs in an array with fields 1, 2, 3, ...

Each bunny has a unique hop length and leaves an egg at each position visited if that position was without an egg, otherwise they steal the egg from the position and leave it egg-free. How mean is that!

The first bunny has a hop length of 2, and leaves eggs at positions 2, 4, 6, 8, 10, 12 and so on.

The second bunny has a hop length of 3, and leaves an egg at position 3, steals the egg from position 6, leaves an egg at position 9, steals the egg from position 12 and so on.

The third bunny has a hop length of 4, and steals the egg from position 4, steals the egg from position 8, leaves a new egg at position 12 and so on.

Problem Statement
Given a single integer N the task is to determine the number of Easter eggs in array positions 1 .. N once all the bunnies with hop lengths from 2 to N have visited those fields. Value N won't exceed few billions.

For example, the bunnies with hop lengths from 2 to 8 leave 6 eggs in the array positions 1 to 8.

Input data: consists of several Ns - just split a line on spaces.
Answer: should provide the same amount of results (egg-counts for every test-case).

Example:

input:
3 8 15 97

answer:
2 6 12 88

*/

#include <assert.h>
#include <math.h>

int
solve(int n)
{
	if (n < 1)
		return 0;
	return n - floor(sqrt(n));
}

int
main()
{
	assert(solve(3) == 2);
	assert(solve(8) == 6);
	assert(solve(15) == 12);
	assert(solve(97) == 88);

	return 0;
}
