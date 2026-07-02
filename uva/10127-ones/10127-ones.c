#include <assert.h>

// https://oeis.org/A099679
int
ones(int n)
{
	int i, r;

	if (!(n % 2) || !(n % 5))
		return -1;

	r = 0;
	for (i = 1; i <= n; i++) {
		r = (r * 10 + 1) % n;
		if (r == 0)
			return i;
	}
	return -1;
}

int
main()
{
	assert(ones(3) == 3);
	assert(ones(7) == 6);
	assert(ones(9901) == 12);

	return 0;
}
