/*

Description

Consider the natural numbers from 1 to N. By associating to each number a sign (+ or -) and calculating the value of this expression we obtain a sum S. The problem is to determine for a given sum S the minimum number N for which we can obtain S by associating signs for all numbers between 1 to N.

For a given S, find out the minimum value N in order to obtain S according to the conditions of the problem.

Input

The only line contains in the first line a positive integer S (0< S <= 100000) which represents the sum to be obtained.

Output

The output will contain the minimum number N for which the sum S can be obtained.

Sample Input

12

Sample Output

7

Hint

The sum 12 can be obtained from at least 7 terms in the following way: 12 = -1+2+3+4+5+6-7.

Source

Romania OI 2002

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A140358
int
mink(int s)
{
	int n, v;

	v = 0;
	n = 1;
	while (v < s || ((v - s) & 1)) {
		v += n;
		n += 1;
	}
	return n - 1;
}

int
main(void)
{
	static const int tab[] = {
		0, 1, 3, 2, 3, 5, 3, 5, 4, 5, 4, 5, 7, 5, 7, 5, 7, 6, 7, 6, 7, 6, 7, 9,
		7, 9, 7, 9, 7, 9, 8, 9, 8, 9, 8, 9, 8, 9, 11, 9, 11, 9, 11, 9, 11, 9,
		11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 11, 13, 11, 13, 11, 13, 11, 13,
		11, 13, 11, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 15, 13,
		15, 13
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(mink(i) == tab[i]);

	return 0;
}
