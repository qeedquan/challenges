#include <assert.h>

typedef long long vlong;

/*

a[i] = 1 / (sqrt(i) + sqrt(i + 1)) = sqrt(i + 1) - sqrt(i)

Sum[i=1] m*a[i] = n =>
sqrt(m + 1) - 1 = n =>
m = (n + 1)^2 - 1

*/

vlong
solve(vlong n)
{
	return (n + 1) * (n + 1) - 1;
}

int
main()
{
	assert(solve(200) == 40400);

	return 0;
}
