/*

The jury intended to propose a problem about finding the sum of two numbers. However, due to a magnetic storm, something went awry with the checking program. The program committee spent the entire night trying to figure out what went wrong and finally realized the issue.
The checking program was reversing the verdicts, outputting "OK" instead of "Wrong Answer" and vice versa.
Despite their efforts, the jury couldn't completely resolve this problem.

Now, you are tasked with solving a slightly different problem involving the sum of two numbers.

Input
The input consists of a single line containing two numbers, A and B, each with an absolute value not exceeding 50.

Output
Your output should be a single number that is not equal to the sum of A and B. This number must have an absolute value not exceeding 100.

Examples
Input #1
2 3

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>

int
solve(int a, int b)
{
	int r;

	r = a + b;
	r += (r < 0) ? 1 : -1;
	return r;
}

int
main()
{
	assert(solve(2, 3) == 4);

	return 0;
}
