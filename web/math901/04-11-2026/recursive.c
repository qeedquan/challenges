#include <stdio.h>

int
P(int n)
{
	if (n >= 100)
		return n - 1;
	return P(P(n + 2));
}

int
main()
{
	printf("%d\n", P(85) + P(2));
	return 0;
}
