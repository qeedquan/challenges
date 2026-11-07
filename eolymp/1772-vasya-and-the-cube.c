/*

A standard die has faces numbered 1, 2, 3, 4, 5, and 6. Vasya rolls this die repeatedly until the sum of the rolled numbers exceeds a given value n.

Vasya is wondering: What is the most probable final sum? Write a program to determine the answer to this question.

Input
The input contains a single line with the number n (5<n≤2147483647).

Output
Output the single number that answers the question.

Examples
Input #1
12

Answer #1
13

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
	assert(solve(12) == 13);

	return 0;
}
