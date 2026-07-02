#include <assert.h>

int
electrons(int n)
{
	int e;

	if (n < 1)
		return 0;

	e = (n < 4) ? 2 : 0;
	if ((20 < n && n < 31) || (38 < n && n < 49) || (56 < n && n < 81) || (88 < n && n < 113))
		e += 18;
	return (e) ? e : 8;
}

int
main(void)
{
	assert(electrons(1) == 2);
	assert(electrons(2) == 2);
	assert(electrons(3) == 2);
	assert(electrons(4) == 8);
	assert(electrons(18) == 8);
	assert(electrons(19) == 8);
	assert(electrons(20) == 8);
	assert(electrons(21) == 18);
	assert(electrons(26) == 18);
	assert(electrons(30) == 18);
	assert(electrons(31) == 8);
	assert(electrons(92) == 18);
	assert(electrons(118) == 8);

	return 0;
}
