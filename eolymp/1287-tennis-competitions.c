/*

It is necessary to form a team to represent a school at tennis competitions.
There are A girls and B boys participating in the tennis section.
How many different mixed pairs can be chosen to participate in the competitions?

Input
A single line contains 2 non-negative integers A and B separated by a space, where A,B≤10^6.

Output
Output a single integer — the answer to the problem.

Examples

Input #1
6 9

Answer #1
54

*/

#include <assert.h>

int
solve(int a, int b)
{
	return a * b;
}

int
main()
{
	assert(solve(6, 9) == 54);

	return 0;
}
