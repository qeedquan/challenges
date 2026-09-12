#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

vlong
solve(const char s[6][3], vlong n)
{
	vlong p[64];
	vlong l[8];
	vlong a, b;
	vlong i;

	if (n < 0 || n >= 64)
		return -1;

	memset(l, 0, sizeof(l));
	memset(p, 0, sizeof(p));

	for (i = 0; i < 6; i++) {
		a = s[i][0] - 'A' + 1;
		b = s[i][1] - 'A' + 1;
		if (!l[a])
			l[a] = b;
	}

	if (l[2] != 1 && l[3] != 1) {
		a = 3;
		b = 0;
	} else if (l[l[1]] == 1) {
		a = 3;
		b = 2;
	} else {
		a = 2;
		b = 1;
	}

	p[1] = 1;
	for (i = 2; i <= n; i++)
		p[i] = (p[i - 1] * a) + b;
	return p[n];
}

int
main()
{
	const char s1[6][3] = { "AB", "BC", "CA", "BA", "CB", "AC" };
	const char s2[6][3] = { "AB", "BA", "CA", "BC", "CB", "AC" };

	assert(solve(s1, 3) == 7);
	assert(solve(s2, 2) == 5);

	return 0;
}
