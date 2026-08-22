#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
seq(vlong n)
{
	vlong i, r;

	if (n <= 0)
		return 0;

	for (r = 0; n != 0; n /= 10) {
		r += 45 * (n / 10);
		for (i = ((n / 10) * 10) + 1; i <= n; i++)
			r += i % 10;
	}
	return r;
}

vlong
solve(vlong a, vlong b)
{
	return seq(b) - seq(a - 1);
}

int
main()
{
	assert(solve(1, 10) == 46);
	assert(solve(10, 20) == 48);
	assert(solve(30, 40) == 52);

	return 0;
}
