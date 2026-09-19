#include <assert.h>
#include <stdio.h>
#include <string.h>

int
solve(int n, int k, const char *s)
{
	int h[256];
	int f[256];
	int c, i, p;

	memset(h, 0, sizeof(h));
	memset(f, 0, sizeof(f));

	c = 0;
	for (i = 0; i < n; i++) {
		p = s[i] & 0xff;
		if (f[p] && i - h[p] <= k)
			c += 1;
		h[p] = i;
		f[p] = 1;
	}
	return c;
}

int
main()
{
	assert(solve(6, 2, "SULTAN") == 0);
	assert(solve(6, 1, "MAHBUB") == 0);
	assert(solve(6, 2, "MAHBUB") == 1);

	return 0;
}
