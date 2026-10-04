/*

Sometimes some mathematical results are hard to believe. One of the common problems is the birthday paradox. Suppose you are at a party where there are 23 people including you. What is the probability that at least two people in the party have the same birthday?Surprisingly, the result is more than 0.5.

Here you have to do the opposite. You have given the number of days in a year. Remember that you can be on a different planet, for example, in Mars, a year is 669 days long. You have to find the minimum number of people you have to invite to a party such that the probability of at least two people in the party having the same birthday is at least 0.5.

Input
Input starts with an integer T (≤ 20000), denoting the number of test cases.

Each case contains an integer n (1 ≤ n ≤ 10^5) in a single line, denoting the number of days in a year on the planet.

Output
For each case, print the case number and the desired result.

Sample
Input	Output
2
365
669

Case 1: 22
Case 2: 30

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A088141
int
solve(int n)
{
	double p;
	int r;

	if (n < 0)
		return 0;

	r = 1;
	for (p = 1.0; (1.0 - p) < 0.5; r++)
		p *= (n - r) / (n * 1.0);
	return r - 1;
}

int
main()
{
	static const int tab[] = {
		1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11
	};

	size_t i;

	assert(solve(365) == 22);
	assert(solve(669) == 30);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
