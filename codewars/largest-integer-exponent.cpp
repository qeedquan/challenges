/*

Write a method named getExponent(n,p) that returns the largest integer exponent x such that px evenly divides n. if p<=1 the method should return null/None (throw an ArgumentOutOfRange exception in C#).

*/

#include <cassert>

typedef long long vlong;

vlong mod(vlong x, vlong m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

vlong get_exponent(vlong n, vlong p)
{
	if (p <= 1)
		return -1;

	vlong e = 0;
	vlong m = 1;
	while (!mod(n, m))
	{
		m *= p;
		e += 1;
	}
	return e - 1;
}

int main()
{
	assert(get_exponent(27, 3) == 3);
	assert(get_exponent(28, 3) == 0);
	assert(get_exponent(280, 7) == 1);
	assert(get_exponent(-250, 5) == 3);
	assert(get_exponent(18, 1) == -1);
	assert(get_exponent(128, 4) == 3);
	assert(get_exponent(0, 0) == -1);

	return 0;
}
