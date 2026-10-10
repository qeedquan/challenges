#include <assert.h>
#include <math.h>

typedef long long vlong;

/*

log(C(n, k)) = log(n!/(n - k)!k!)
             = log(n!) - log((n - k)!k!)

*/

vlong
solve(vlong n, vlong k)
{
	vlong i;
	double r;

	r = 0;
	for (i = n - k + 1; i <= n; i++)
		r += log10(i);
	for (i = 1; i <= k; i++)
		r -= log10(i);
	return floor(r) + 1;
}

int
main()
{
	assert(solve(20, 5) == 5);
	assert(solve(100, 10) == 14);
	assert(solve(200, 15) == 23);

	return 0;
}
