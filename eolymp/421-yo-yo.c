/*

The yo-yo toy consists of a spool wound with a string.
If, while holding the end of the string, you release the spool, it will rotate, first descending, and then, due to inertia, rising back up.
However, the height to which the spool rises on each ascent will be k times less than the height from which it descended.
The spool is considered to have stopped if the height of its next ascent is less than or equal to 1.

https://static.e-olymp.com/content/7e/7e3ec62d894d14336318780135e4af88bc431f25.gif

Write a program that, given the length of the string l and the coefficient k,
calculates the number of ascents the spool makes before stopping.
For example, if l=17 and k=2, then the ascents will be to the heights of 8.5, 4.25, 2.125, 1.0625, and then it will stop.
Thus, the answer would be 4 ascents.

Input
Two integers l (1≤l≤10^9) and k (2≤k≤100).

Output
Print one integer — the number of ascents.

Examples

Input #1
17 2

Answer #1
4

Input #2
1 2

Answer #2
0

Input #3
59049 3

Answer #3
9

*/

#include <assert.h>
#include <stdio.h>

long
solve(long l, long k)
{
	double h;
	long r;

	if (k < 1)
		return 0;

	r = 0;
	h = l;
	for (h /= k; h > 1; h /= k)
		r += 1;
	return r;
}

int
main()
{
	assert(solve(17, 2) == 4);
	assert(solve(1, 2) == 0);
	assert(solve(59049, 3) == 9);

	return 0;
}
