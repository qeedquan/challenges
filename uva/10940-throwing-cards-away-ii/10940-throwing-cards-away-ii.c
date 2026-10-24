#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A152423
int
josv(int n)
{
	int s;

	if (n < 0)
		return 0;
	if (n <= 1)
		return 1;

	s = ceil(log2(n));
	return (2 * n) - (1 << s);
}

int
josvbf(int n)
{
	if (n < 0)
		return 0;
	if (n <= 1)
		return 1;
	if (n & 1)
		return (josvbf((n + 1) / 2) - 1) * 2;
	return josvbf(n / 2) * 2;
}

int
main()
{
	static const int tab[] = {
		1, 2, 2, 4, 2, 4, 6, 8, 2, 4, 6, 8, 10, 12, 14, 16, 2, 4, 6, 8, 10,
		12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 2, 4, 6, 8, 10, 12, 14,
		16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48,
		50, 52, 54, 56, 58, 60, 62, 64, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20
	};

	size_t i;

	assert(josv(7) == 6);
	assert(josv(19) == 6);
	assert(josv(10) == 4);
	assert(josv(6) == 4);

	for (i = 0; i < nelem(tab); i++)
		assert(josv(i + 1) == tab[i]);

	for (i = 0; i <= 1000; i++)
		assert(josv(i) == josvbf(i));

	return 0;
}
