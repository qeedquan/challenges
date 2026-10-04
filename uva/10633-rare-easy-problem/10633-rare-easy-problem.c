#include <stdio.h>

typedef long long vlong;

void
solve(vlong n)
{
	vlong i;

	for (i = 9; i >= 0; i--) {
		if (!((n - i) % 9))
			printf("%lld ", (((n - i) / 9) * 10) + i);
	}
	printf("\n");
}

int
main()
{
	solve(18);
	return 0;
}
