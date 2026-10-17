/*

When studying the topic "Amount of information", it is often necessary to solve the equation 2 I=N, where N is known, and I needs to be found.
Seventh graders, who do not know logarithms, solve the problem as follows: if the root is an integer, it is the answer.
Otherwise, the solution includes the two integers closest to the root.

Input
A natural number N (N<1000000000).

Output
The solution (see the sample output in the examples).

Examples
Input #1
4

Answer #1
I=2

*/

#include <stdio.h>
#include <math.h>

int
ispow2(int n)
{
	return n > 0 && !(n & (n - 1));
}

void
solve(int n)
{
	int i;

	if (n < 1) {
		puts("I=0");
		return;
	}

	i = log2(n);
	if (ispow2(n))
		printf("I=%d\n", i);
	else
		printf("%d<I<%d\n", i, i + 1);
}

int
main()
{
	solve(4);
	solve(6);
	solve(10);
	solve(16);
	solve(100);
	solve(128);

	return 0;
}
