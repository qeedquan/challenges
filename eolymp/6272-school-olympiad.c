/*

At school programming contest the participants were asked to solve two problems. a students completely coped with the given tasks, and b students solved nothing.

How many participants were in the competition if there were c correct submissions accepted for the first task, and d correct submissions for the second task.

Input
Nonnegative integers a,b,c and d, not greater than 100.

Output
Print the number of participants at school programming contest.

Examples

Input #1
1 2 3 4

Answer #1
8

*/

#include <assert.h>

int
solve(int a, int b, int c, int d)
{
	return -a + b + c + d;
}

int
main()
{
	assert(solve(1, 2, 3, 4) == 8);

	return 0;
}
