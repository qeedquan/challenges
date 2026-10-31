/*

Olena is the second-to-last in the list of students in her class. Find the total number of students if Olena's position in the list is known.

Input
A natural number.

Output
The answer to the problem.

Examples
Input #1
20

Answer #1
21

*/

#include <assert.h>

int
solve(int n)
{
	return n + 1;
}

int
main()
{
	assert(solve(20) == 21);

	return 0;
}
