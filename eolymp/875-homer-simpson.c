/*

Homer Simpson, a very smart guy, likes eating Krusty-burgers.
It takes Homer M minutes to eat a Krusty-burger.
However, there's a new type of burger in Apu's Kwik-e-Mart.
Homer likes those too. It takes him N minutes to eat one of these burgers.
Given T minutes, you have to determine the maximum number of burgers Homer can eat within the time limit.

If Homer cannot exactly fill the lunch break, output the remaining time as well.
The goal is to find a combination where the leftover time is as small as possible.

Input
Each test case consists of three integers M, N, T (1≤M,N,T≤1000000).

Output
For each test case, print in a single line the maximum number of burgers Homer can eat.
If there is any unused time left, also print this number separated by a single space.
The output should correspond to the combination leaving as little unused time as possible.

Examples
Input #1
3 5 54

Answer #1
18

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
solve(int m, int n, int t)
{
	return t / min(m, n);
}

int
main()
{
	assert(solve(3, 5, 54) == 18);

	return 0;
}
