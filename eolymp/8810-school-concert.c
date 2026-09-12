/*

At the school concert a students sang, b students danced, and c students sang and danced. How many participants were there in total?

Input
Three positive integers a,b and c (a,b,c≤10^18).

Output
Print the number of participants at the school concert.

Examples
Input #1
13 9 5

Answer #1
17

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong a, vlong b, vlong c)
{
	return a + b - c;
}

int
main()
{
	assert(solve(13, 9, 5) == 17);

	return 0;
}
