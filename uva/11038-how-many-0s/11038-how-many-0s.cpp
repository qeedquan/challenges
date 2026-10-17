#include <cassert>
#include <algorithm>
#include <format>
#include <string>

using namespace std;

typedef long long vlong;

vlong zerosbf(vlong n)
{
	vlong r = 0;
	for (vlong i = 0; i <= n; i++)
	{
		auto s = format("{}", i);
		r += count(s.begin(), s.end(), '0');
	}
	return r;
}

vlong zeros(vlong n)
{
	if (n < 0)
		return 0;

	vlong r = 1;
	vlong p = 1;
	vlong t = 0;
	while (n != 0)
	{
		if (n % 10)
			r += (n / 10) * p;
		else
			r += ((n / 10) - 1) * p + (t + 1);
		t += (n % 10) * p;
		n /= 10;
		p *= 10;
	}
	return r;
}

vlong solve(vlong m, vlong n)
{
	return zeros(n) - zeros(m - 1);
}

int main()
{
	assert(solve(10, 11) == 1);
	assert(solve(100, 200) == 22);
	assert(solve(0, 500) == 92);
	assert(solve(1234567890, 2345678901) == 987654304);
	assert(solve(0, 4294967295) == 3825876150);

	for (vlong i = 0; i <= 10000; i++)
		assert(zeros(i) == zerosbf(i));

	return 0;
}
