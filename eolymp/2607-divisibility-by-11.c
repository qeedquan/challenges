/*

Divisibility by 11 is often stated as follows: separately add the digits at even and at odd positions in the number.
If the difference of these sums is divisible by 11, then the number itself is divisible by 11.
Calculate the product of these sums.

Input
A natural number n such that 10≤n≤2⋅10^9.

Output
Print the product of the sums of the digits at even and at odd positions.

Examples

Input #1
27

Answer #1
14

Input #2
2821

Answer #2
36

Input #3
10001

Answer #3
0

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	uvlong f, x, y;

	for (f = x = y = 0; n; n /= 10) {
		if (!f)
			x += n % 10;
		else
			y += n % 10;
		f ^= 1;
	}
	return x * y;
}

int
main()
{
	assert(solve(27) == 14);
	assert(solve(2821) == 36);
	assert(solve(10001) == 0);

	return 0;
}
