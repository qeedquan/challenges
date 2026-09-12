#include <cassert>

int solve(int d, int m, int y, int Y)
{
	if (d != 29 || m != 2)
		return Y - y;
	auto c1 = (Y / 4) - (Y / 100) + (Y / 400);
	auto c2 = (y / 4) - (y / 100) + (y / 400);
	return c1 - c2;
}

int main()
{
	assert(solve(29, 2, 1888, 1910) == 4);
	assert(solve(29, 2, 1988, 2010) == 5);
	assert(solve(1, 1, 1988, 2010) == 22);
	assert(solve(31, 12, 1988, 2010) == 22);

	return 0;
}
