/*

Task
The manager of a industrial plant is planning to buy a machine of either type A or type B. For each day’s operation:

The number of repairs, X, that machine A needs is a Poisson random variable with mean 0.88. The daily cost of operating A is Ca = 160 + 40*X^2.
The number of repairs, Y, that machine B needs is a Poisson random variable with mean 1.55. The daily cost of operating B is Cb = 128 + 40*Y^2.
Assume that the repairs take a negligible amount of time and the machines are maintained nightly to ensure that they operate like new at the start of each day.
Find and print the expected daily cost for each machine.

Input Format

A single line comprised of  space-separated values denoting the respective means for  and :

0.88 1.55
If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

There are two lines of output. Your answers must be rounded to a scale of 3 decimal places (i.e., 1.234 format):

On the first line, print the expected daily cost of machine A.
On the second line, print the expected daily cost of machine B.

*/

#include <stdio.h>

/*

λ = mean
If X ~ Poisson(λ), then E(X) = λ, Var(X) = λ

The formula for operating cost is given as a + bX^2, so the expectation is:

E(a + bX^2)

We can pull a and b out since they are constants
E(a + bX^2) = a + bE(X^2)
Need function to determine E(X^2)

Use Var(X) = E(X^2) - E(X)^2 so we have
E(X^2) = λ^2 + λ

*/

void
solve(double X, double Y)
{
	printf("%.3f\n", 160 + 40 * ((X * X) + X));
	printf("%.3f\n", 128 + 40 * ((Y * Y) + Y));
}

int
main(void)
{
	solve(0.88, 1.55);
	return 0;
}
