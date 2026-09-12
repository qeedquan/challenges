/*

Break two numbers up into their powers of 2, if they share any, return a falsey value. Otherwise, return a truthy value.

If one input is 0, the answer will always be truthy. if one input is 255, the answer will be falsey if the other is not 0.

Example
Given 5 and 3

5 = 2⁰ + 2²
3 = 2⁰ + 2¹
Both share 2⁰, return falsey.

Given 8 and 17

8  = 2³
17 = 2⁰ + 2⁴
Neither share any powers, return truthy.

I/O
Input and output can be through any standard means

Input will always be two integers in the range 0 <= n <= 255

Output should be one truthy or falsey value

Test Cases
Truthy:
1, 2
3, 4
2, 4
8, 17
248, 7

Falsey:
1, 3
6, 4
8, 8
Standard Loopholes apply.

This is code-golf, so fewest bytes wins!

*/

#include <assert.h>

typedef unsigned long long uvlong;

bool
solve(uvlong a, uvlong b)
{
	return !(a & b);
}

int
main()
{
	assert(solve(1, 2) == true);
	assert(solve(3, 4) == true);
	assert(solve(2, 4) == true);
	assert(solve(8, 17) == true);
	assert(solve(248, 7) == true);

	assert(solve(1, 3) == false);
	assert(solve(6, 4) == false);
	assert(solve(8, 8) == false);

	return 0;
}
