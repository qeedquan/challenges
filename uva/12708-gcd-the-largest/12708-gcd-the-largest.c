#include <assert.h>
#include <stdio.h>

typedef long long vlong;

// https://quickgrid.wordpress.com/2015/02/05/uva-problem-12708-gcd-the-largest-solution/
// https://oeis.org/A004526
vlong
solve(vlong n)
{
	return n / 2;
}

int
main()
{
	assert(solve(2) == 1);
	assert(solve(5) == 2);

	return 0;
}
