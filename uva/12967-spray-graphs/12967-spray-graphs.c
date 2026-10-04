#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A173033
uvlong
solve(uvlong n)
{
	static const uvlong tab[] = { 0, 1, 4, 12, 28 };

	uvlong i, m, r;

	m = nelem(tab);
	if (n < m)
		return tab[n];

	r = tab[m - 1];
	for (i = m; i <= n; i++)
		r = (r * 2) + 4;
	return r;
}

int
main()
{
	static const uvlong tab[] = {
		1, 4, 12, 28, 60, 124, 252, 508, 1020, 2044, 4092, 8188, 16380, 32764,
		65532, 131068, 262140, 524284, 1048572, 2097148, 4194300, 8388604,
		16777212, 33554428, 67108860, 134217724, 268435452, 536870908, 1073741820,
		2147483644, 4294967292, 8589934588, 17179869180
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
