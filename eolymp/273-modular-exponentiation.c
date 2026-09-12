/*

Three positive integers x, n, and m are given. Find the value of x^n (mod m).

Input
The input contains three positive integers x, n, m (1≤x,m≤10^9, 2≤n≤10^7).

Output
Print one integer — the value of x^n (mod m).

Examples

Input #1
2 3 100

Answer #1
8

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
modexp(uvlong a, uvlong b, uvlong m)
{
	uvlong x, y;

	if (m == 0)
		return 0;

	x = a % m;
	y = b / 2;
	if (b == 1)
		return x;
	if (b % 2 == 0)
		return modexp((x * x) % m, y, m) % m;
	return (x * modexp((x * x) % m, y, m)) % m;
}

int
main()
{
	assert(modexp(2, 3, 100) == 8);

	return 0;
}
