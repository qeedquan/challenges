#include <stdio.h>
#include <string.h>

void
solve(int n, const char *s)
{
	int c[256];
	int i;

	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++)
		c[s[i] & 0xff]++;

	if (c['B'] > 0 && c['W'] == 0 && c['T'] == 0)
		puts("BANGLAWASH");
	else if (c['W'] > 0 && c['B'] == 0 && c['T'] == 0)
		puts("WHITEWASH");
	else if (c['A'] == n)
		puts("ABANDONED");
	else if (c['B'] > c['W'])
		printf("BANGLADESH %d - %d\n", c['B'], c['W']);
	else if (c['B'] < c['W'])
		printf("WWW %d - %d\n", c['W'], c['B']);
	else
		printf("DRAW %d %d\n", c['W'], c['T']);
}

int
main()
{
	solve(3, "BBB");
	solve(3, "WWW");
	solve(3, "BWB");
	solve(4, "BWWT");
	solve(3, "BTW");
	solve(2, "AA");

	return 0;
}
