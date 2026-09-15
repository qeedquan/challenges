#include <stdio.h>

void
solve(int n, int m)
{
	int b, i, j, p, s;

	s = (n + 3) / 4;
	s = (s / m) + !!(s % m);
	b = 0;
	for (i = 1; i <= s; i++) {
		printf("signature %d\n", i);
		p = m * 4;
		for (j = 1; j <= m; j++) {
			printf(" sheet %d: pages %d and %d (front); pages %d and %d (back)\n",
			    j, (j * 2) + b, p - (j * 2) + 1 + b, p - (j * 2) + 2 + b, (j * 2) - 1 + b);
		}
		b += p;
	}
}

int
main()
{
	solve(9, 2);
	return 0;
}
