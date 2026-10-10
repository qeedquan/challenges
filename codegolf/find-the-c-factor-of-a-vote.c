/*

In this challenge you will be determining how controversial a vote is, given an array of other votes, by figuring out a number called the C-factor. What is the C-factor, you ask?

Well, imagine you've got multiple votes on an election. We'll use 1 and 0 for the sake of the challenge to represent two different candidates in an election. Here's the ten votes in our sample election:

0110111011
Now, say we want to find the C-factor of any vote for candidate 0. We can do that with the following function:

f(o,v)=abs(o−mean(v))

In f, o is the vote we want to determine the C-factor for, and v is an array of votes. So, using our function, to get the C-factor of any vote for candidate 0:

f(0,[0,1,1,0,1,1,1,0,1,1])=0.7

A lower C-factor shows that the vote was less controversial in comparison to the other votes.
So, a vote for candidate 0 is more different from the other votes than a vote for candidate 1.
In comparison, the C-factor for a candidate 1 vote is 0.3, so it is less controversial because it is more like the other votes.

The Challenge
Write a function f(o,v) to determine the C-factor of a vote o given results of a vote v.

o must be an integer, either 0 or 1.

v must be an array (or similar container type depending on language specifications) of arbitrary length containing zeroes and ones.

The function should return or print to the console the resulting C-factor given the function parameters, using the formula above or a modified method.

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
mean(double *x, size_t n)
{
	double m;
	size_t i;

	if (n == 0)
		return 0;

	m = 0;
	for (i = 0; i < n; i++)
		m += x[i];
	return m / n;
}

double
cfactor(double o, double *v, size_t n)
{
	return fabs(o - mean(v, n));
}

int
main(void)
{
	double v1[] = {0, 1, 1, 0, 1, 1, 1, 0, 1, 1};
	double v2[] = {1, 1, 1};

	printf("%f\n", cfactor(0, v1, nelem(v1)));
	printf("%f\n", cfactor(1, v2, nelem(v2)));

	return 0;
}
