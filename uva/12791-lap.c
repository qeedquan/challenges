/*

In motorsports it is very common that the leader pilot in a race, at a certain moment, overtakes the
last pilot. The leader, at this moment, is one lap ahead of the last pilot, who then becomes a straggler.
In this task, given the time it takes for the fastest pilot, and for the slowest pilot, to complete one lap,
you have to determine in which lap the slowest pilot will become a straggler. You should consider that,
at the beginning, they are side by side at the start line of the circuit, both at the start of lap number 1
(the first lap of the race); and that a new lap always begins right after the leader crosses the start line.

Input
The input contains several test cases. Each test case consists of one line with two integers X and
Y (1 ≤ X < Y ≤ 10000), the times, in seconds, that it takes for the fastest and the slowest pilot,
respectively, to complete one lap.

Output
For each test case in the input program should output line, containing one integer: the lap in which
the slowest pilot will become a straggler.

Sample Input
1 10
4 8
5 7
6875 7109

Sample Output
2
2
4
31

*/

#include <assert.h>
#include <math.h>

int
solve(int x, int y)
{
	int d, r;

	d = y - x;
	if (d == 0)
		return 0;

	r = y / d;
	if (y % d)
		r++;
	return r;
}

int
main()
{
	assert(solve(1, 10) == 2);
	assert(solve(4, 8) == 2);
	assert(solve(5, 7) == 4);
	assert(solve(6875, 7109) == 31);

	return 0;
}
