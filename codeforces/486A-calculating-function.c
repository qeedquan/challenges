/*

For a positive integer n let's define a function f:

f(n) =  - 1 + 2 - 3 + .. + (-1)^n*n

Your task is to calculate f(n) for a given integer n.

Input
The single line contains the positive integer n (1 ≤ n ≤ 10^15).

Output
Print f(n) in a single line.

Examples
input
4
output
2

input
5
output
-3

Note
f(4) =  - 1 + 2 - 3 + 4 = 2

f(5) =  - 1 + 2 - 3 + 4 - 5 =  - 3

*/

#include <assert.h>

// https://oeis.org/A130472
int
f(int n)
{
	int s;

	if (n < 0)
		return 0;

	s = (n & 1) ? -1 : 1;
	return s * (n + 1) / 2;
}

int
main(void)
{
	assert(f(4) == 2);
	assert(f(5) == -3);

	return 0;
}
