#include <stdio.h>

typedef long long vlong;

void
solve()
{
	vlong i;

	for (i = 9999; i <= 10005; i++)
		printf("%lld %lld\n", i, i * i);
}

int
main()
{
	solve();
	return 0;
}
