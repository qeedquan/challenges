#include <assert.h>

int
cigs(int n, int k)
{
	if (n < 1 || k < 2)
		return n;
	return n + (n - 1) / (k - 1);
}

int
cigsbf(int n, int k)
{
	int d, e, r;

	if (n < 1 || k < 2)
		return n;

	r = n;
	do {
		d = n / k;
		e = n % k;
		r += d;
		n = d + e;
	} while (n >= k);

	return r;
}

int
main(void)
{
	int n, k;

	assert(cigs(4, 3) == 5);
	assert(cigs(10, 3) == 14);
	assert(cigs(100, 5) == 124);

	for (n = 0; n <= 10000; n++) {
		for (k = 0; k <= 10000; k++) {
			assert(cigs(n, k) == cigsbf(n, k));
		}
	}

	return 0;
}
