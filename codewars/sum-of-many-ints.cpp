/*

Write this function:

f(n, m) = Sum[i=1, n] i%m

for i from 1 to n, do i % m and return the sum

f(n=10, m=5) // returns 20 (1+2+3+4+0 + 1+2+3+4+0)
You'll need to get a little clever with performance, since n can be a very large number

*/

#include <cassert>

int triangular(int n)
{
	return n * (n + 1) / 2;
}

int fs(int n, int m)
{
	if (m < 1)
		return 0;

	auto r = 0;
	for (auto i = 1; i <= n; i++)
		r += i % m;
	return r;
}

int f(int n, int m)
{
	if (m < 1)
		return 0;

	return triangular(m - 1) * (n / m) + triangular(n % m);
}

int main()
{
	assert(f(10, 5) == 20);

	auto L = 3'000;
	for (auto n = 0; n <= L; n++)
	{
		for (auto m = 0; m <= L; m++)
			assert(f(n, m) == fs(n, m));
	}
	return 0;
}
