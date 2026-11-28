/*

Amelia is studying modeling. She is interested in models with moving parts.

As her first task, she made a rectangular box of size 2×n, which contains two parallel rails and a rectangular bar on each of them.
The short bar has size 1×a, and the long one has size 1×b.
The long bar has a stopper at each end, and the short one is always between these two stoppers.

https://static.e-olymp.com/content/e6/e6a8a193abe6d33cc1dc7626e616464d4bba7125.gif

The bars can be moved along the rails, one bar at a time, as long as the short bar is between the stoppers.
So, on each move, Amelia selects one of the bars and moves it, while the other one stays in place.

Initially, both bars are aligned to one side of the box, and Amelia wants them to be aligned to the other side in as few moves as possible.
What is the minimal number of moves she should do to achieve her goal?

Input
The input consists of three integers a, b, and n (1≤a<b≤n≤10^7).

Output
Print a single integer — the minimal number of moves Amelia needs to do.

Examples

Input #1
1 3 6

Answer #1
5

Input #2
2 4 9

Answer #2
7

Note
A possible solution for the first example is shown below.

https://static.e-olymp.com/content/ab/ab7784c70d5a4ab1612adb1383c1cc5cf6bd3789.gif

*/

#include <assert.h>
#include <math.h>

int
solve(int a, int b, int n)
{
	return ceil((n - b) * 1.0 / (b - a)) * 2 + 1;
}

int
main()
{
	assert(solve(1, 3, 6) == 5);
	assert(solve(2, 4, 9) == 7);

	return 0;
}
