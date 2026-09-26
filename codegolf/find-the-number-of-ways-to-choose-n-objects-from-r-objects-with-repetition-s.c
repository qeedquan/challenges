/*

For example, if n is 5 and r is 2, it would mean the number of lists below:

[1,1,1,1,1]
[1,1,1,2,2]
[1,1,2,2,2]
[2,2,1,1,1]
[2,2,2,1,1]
[2,2,2,2,2]
which is 6.

If n is 4 and r is 3:

[1,1,1,1]
[1,1,2,2]
[1,1,3,3]
[2,2,1,1]
...
[3,3,3,3]
which is 9.

where each item has a neighbour whose value is the same.

For example, [1,2,1,1,2] is not counted, because both 2 are alone.

Goal
Your task is to write a program/function which takes two inputs in any order, and which produces the required output.

Detail
You can assume that r≥2.

Scoring
This is code-golf. Shortest solution in bytes wins.

Bonus
Multiply your score by 0.3 if the complexity of your program is below O(e^n).

For example, 10 bytes becomes 3 bytes.

Testcases
Can be generated from this Pyth test suite.

Usage: two lines per testcase, n on top, r below.

n r output
2 5 5
4 4 16
6 3 33
8 2 26

Additional information
When r=2: OEIS A006355.

*/

#include <assert.h>

int
f(int n, int r)
{
	int i, s;

	if (n < 2)
		return 0;

	s = 0;
	for (i = 0; i <= n - 2; i++)
		s += f(i, r);
	return (s * (r - 1)) + 1;
}

/*

@Jakube

Explanation:
Let f(n, r) be the number of ways to create such a list with the last number being 0. Obviously it doesn't matter if we take 0 or any other number.

It's easy to see, that the following recursion holds:

f(n, r) = 0                                  ... if n < 2
f(n, r) = sum(f(i, r), i <= n-2) * (r-1) + 1 ... otherwise
If n == 0, than the list cannot end with the number 0. If n == 1, than the only number in the list has no neighbor. Therefore both cases have the value zero.

If n >= 2, than it could end in 2, 3, ... n zeros. The digit before the last zero can be any of the number 1, 2, ..., r-1. These are r-1 possibilities. Therefore I'll add up all f(i,n) and multiply by r-1. At the end I'll have to add 1 (for the case that all digits are zeros).

The result to the question than is: r * f(n, r), since the list can end in any of the r numbers.

*/

int
ways(int n, int r)
{
	return r * f(n, r);
}

int
main(void)
{
	assert(ways(2, 5) == 5);
	assert(ways(4, 4) == 16);
	assert(ways(6, 3) == 33);
	assert(ways(8, 2) == 26);

	return 0;
}
