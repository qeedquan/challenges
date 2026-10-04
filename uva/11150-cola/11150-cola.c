#include <assert.h>

int
solve(int n)
{
	int r;

	r = n;
	while (n >= 3) {
		r += n / 3;
		n = (n / 3) + (n % 3);
	}
	if (n == 2)
		r += 1;
	return r;
}

int
main()
{
	assert(solve(8) == 12);

	return 0;
}
