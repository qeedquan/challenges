#include <assert.h>
#include <stdint.h>

typedef unsigned long long uvlong;

bool
solve(uvlong n)
{
	uvlong i, m, r;

	r = 0;
	for (i = 0; i < 32; i++) {
		m = (n << i) | (n >> (32 - i));
		m &= 0x1f;
		r |= 1ULL << m;
	}
	return r == UINT32_MAX;
}

int
main()
{
	assert(solve(65535) == false);
	assert(solve(65259922) == false);
	assert(solve(81354525) == true);
	assert(solve(112805325) == false);
	assert(solve(122525196) == false);
	assert(solve(192052550) == true);
	assert(solve(225525450) == true);
	assert(solve(299525510) == false);
	assert(solve(318353525) == true);
	assert(solve(344152934) == false);
	assert(solve(502445252) == true);
	assert(solve(522595252) == true);
	assert(solve(1296752550) == false);
	assert(solve(3999995011) == true);
	assert(solve(4000000000) == false);

	return 0;
}
