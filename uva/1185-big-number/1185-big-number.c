#include <assert.h>
#include <stdio.h>
#include <math.h>

int
solve(int n)
{
	double v;
	int i, r;

	if (n < 0)
		return 0;

	r = 0;
	v = 0;
	for (i = 1; i <= n; i++) {
		v += log10(i);
		r = v;
	}
	return r + 1;
}

int
main()
{
	assert(solve(10) == 7);
	assert(solve(20) == 19);

	return 0;
}
