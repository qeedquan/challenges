/*

Lagrange’s four-square theorem states that every positive integer can be expressed as the sum of four
squares of integers. For example:
3 = 1^2 + 1^2 + 1^2 + 0^2
31 = 5^2 + 2^2 + 1^2 + 1^2
However some positive integers can be expressed even as the sum of three squares of non-negative
integers. For example:
3 = 1^2 + 1^2 + 1^2
17 = 0^2 + 1^2 + 4^2
In this problem you have to find expression of given integer K as the sum of three squares, or state
that it is impossible.

Input
The first line contains integer N (0 < N ≤ 10000), it is number of tests. Each of the next N lines
contains a positive integers K (0 < K ≤ 50000).

Output
For each test case print a line formatted like this: ‘a b c’. Where a ≤ b ≤ c and K = a^2 + b^2 + c^2.

If there is more than one possible answer, print the one that comes first lexicographically.
If expression in three squares of non-negative integers do not exist print ‘-1’ (see examples).

Sample Input
3
13
15
17

Sample Output
0 2 3
-1
0 1 4

*/

#include <stdio.h>
#include <math.h>

int
solve(int n, int r[3])
{
	int a, b, c, c2;

	for (a = 0; (a * a) < n; a++) {
		for (b = a; (b * b) + (a * a) < n; b++) {
			c2 = n - (a * a) - (b * b);
			if (c2 < 0)
				continue;

			c = sqrt(c2);
			if (c * c == c2) {
				r[0] = a;
				r[1] = b;
				r[2] = c;
				return 1;
			}
		}
	}
	return 0;
}

void
test(int n)
{
	int r[3];

	if (solve(n, r))
		printf("%d %d %d\n", r[0], r[1], r[2]);
	else
		printf("-1\n");
}

int
main()
{
	test(13);
	test(15);
	test(17);

	return 0;
}
