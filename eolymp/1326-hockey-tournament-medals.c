/*

Forest residents have decided to hold a hockey tournament between N teams.
In how many ways can sets of gold, silver, and bronze medals be distributed, if each medal can be awarded to only one team?

Examples

Input #1
17

Answer #1
4080

*/

#include <assert.h>

#define cube(x) ((x) * (x) * (x))

int
solve(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return cube(n - 1) - (n - 1);
}

int
main()
{
	assert(solve(17) == 4080);

	return 0;
}
