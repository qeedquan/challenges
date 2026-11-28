#include <stdio.h>

int
solve(int n)
{
	int r;

	if (n < 1)
		return 0;

	r = n * (n + 1) / 2;
	return r % 100;
}
int
main()
{
	printf("%d\n", solve(2005));
	return 0;
}
