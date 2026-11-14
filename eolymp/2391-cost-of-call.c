/*

Find the cost of a phone call in kopecks with a duration of n seconds, if the connection cost is a kopecks and the tariff is per minute;
that is, at the first second of each minute, a charge of b kopecks is applied.

Input
Three non-negative integers a, b, and n (0≤a,b≤99, 0≤n≤86400).

Output
Print the cost of the phone call in kopecks.

Examples
Input #1
5 10 120

Answer #1
25

*/

#include <assert.h>

int
solve(int a, int b, int n)
{
	int m;

	if (n < 1)
		return 0;

	m = n / 60;
	if (n < 60 || n % 60)
		m += 1;
	return a + (b * m);
}

int
main()
{
	assert(solve(5, 10, 120) == 25);

	return 0;
}
