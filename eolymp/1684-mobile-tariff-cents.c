/*

Peter uses the mobile tariff plan "Cents".
Each outgoing call is charged as follows: a connection fee of 1 cent, the first minute of conversation costs 64 cents,
and each subsequent minute costs half as much as the previous one, but not less than 1 cent.
Tariffication is per minute, that is, even if Peter does not use all the time in the last minute, that minute is paid in full.
Find the cost in cents of a phone call with a duration of N seconds.

Input
The file contains a positive integer N (1≤N≤2⋅10^9).

Output
Output the cost of the call in cents.

Examples
Input #1
100

Answer #1
97

*/

#include <assert.h>
#include <math.h>

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
solve(int n)
{
	int c, i, m, r;

	if (n < 0)
		return 0;

	r = 1;
	c = 64;
	m = ceil(n / 60.0);
	for (i = 1; i <= m; i++) {
		r = r + c;
		c = max(c / 2, 1);
	}
	return r;
}

int
main()
{
	assert(solve(0) == 1);
	assert(solve(1) == 65);
	assert(solve(100) == 97);

	return 0;
}
