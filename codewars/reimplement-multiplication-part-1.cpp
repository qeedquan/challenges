/*

Define a function mul(a, b) that takes two non-negative integers a and b and returns their product.

You should only use the + and/or - operators. Using * is cheating!

You can do this iteratively or recursively.

*/

#include <cassert>

// https://stackoverflow.com/questions/3722004/how-can-i-perform-multiplication-using-bitwise-operators
int mul(int x, int y)
{
	bool neg = false;
	if (x < 0 && y >= 0)
	{
		x = -x;
		neg = true;
	}
	else if (y < 0 && x >= 0)
	{
		y = -y;
		neg = true;
	}
	else if (x < 0 && y < 0)
	{
		x = -x;
		y = -y;
	}

	int r = 0;
	while (y != 0)
	{
		if ((y & 1) == 1)
			r += x;
		x <<= 1;
		y >>= 1;
	}
	if (neg)
		r = -r;

	return r;
}

int main()
{
	auto N = 10000;
	for (auto x = -N; x <= N; x++)
	{
		for (auto y = -N; y <= N; y++)
			assert(mul(x, y) == x * y);
	}
	return 0;
}
