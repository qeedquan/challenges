/*

Some numbers such as: 6, 12, 20, 30, 42, 56, 60, 90, 120 and so on as can be expressed as a product of consecutive integer numbers as shown below.

6   = 2 * 3
12  = 3 * 4
30  = 5 * 6
60  = 3 * 4 * 5
90  = 9 * 10
120 = 4 * 5 * 6
Write a program or function that outputs a list of consecutive integers which product equals the specified number.

Examples of numbers that are not fit for this logic are:

99  = 9 * 11  (Product of non-consecutive numbers)
121 = 11 * 11 (Same numbers)
2   = 1 * 2   (Product of itself and 1)
13  = 13      (Product of only one number)
Please note that for the case of 2 = 2 * 1, we do not consider it as a valid result, as a integer multiplied by 1 gives the same result. For this question, we would consider only integers >= 2 in the product.

Input

A valid 32-bit positive integer. Can be from standard input, a function argument, etc.

Output

A list of consecutive integer numbers >= 2 (in either ascending or descending order). If there are several combinations of consecutive integers, just provide one instance will do. If you provide more, its fine.

Restrictions

The code should take a reasonable amount of time (< 5 minutes) to run on a standard computer for all valid inputs (positive 32-bit integers). If there is a consecutive integer product, the code should output one or more within the time limit. Else, the code should terminate with no output within the time limit.

This is code golf, so the shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>

void
range(int n, int a, int b)
{
	int i;

	printf("%d -> [ ", n);
	for (i = a; i < b; i++)
		printf("%d ", i);
	printf("]\n");
}

void
solve(int n)
{
	int c, i, s;

	s = 2;
	i = 2;
	c = 1;
	while (s < n) {
		s *= i + c;
		c += 1;
		if (s == n)
			range(n, i, i + c);

		if (s >= n) {
			i += 1;
			s = i;
			c = 1;
		}
	}
}

int
main(void)
{
	int i;

	for (i = 0; i <= 1024; i++)
		solve(i);

	return 0;
}
