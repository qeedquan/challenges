#include <assert.h>
#include <stdbit.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	return stdc_count_ones(n);
}

int
main()
{
	assert(solve(4) == 1);
	assert(solve(5) == 2);
	assert(solve(6) == 2);

	return 0;
}
