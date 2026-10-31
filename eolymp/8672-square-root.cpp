/*

Given a positive integer n. Find its square root.

Input
One positive integer n (1≤n≤10^16).

Output
Print the square root of the given number rounded to 6 decimal places.

Examples

Input #1
1

Answer #1
1.000000

Input #2
1000000

Answer #2
1000.000000

Input #3
10

Answer #3
3.162278

*/

#include <cassert>
#include <cstdio>
#include <cmath>

// https://en.wikipedia.org/wiki/Square_root_algorithms#Bakhshali_method
double xsqrt(double x)
{
	if (x < 0)
		return NAN;

	if (x == 0)
		return 0;

	auto s = x;
	for (auto i = 0; i < 8; i++)
	{
		auto a = (s - x * x) / (2 * x);
		x = x + a;
		x = x - (a * a) / (2 * x);
	}
	return x;
}

int main()
{
	printf("%.6f\n", xsqrt(1));
	printf("%.6f\n", xsqrt(1000000));
	printf("%.6f\n", xsqrt(10));

	for (double i = 0; i <= 10000; i += 1e-3)
		assert(fabs(sqrt(i) - xsqrt(i)) < 1e-16);

	return 0;
}
