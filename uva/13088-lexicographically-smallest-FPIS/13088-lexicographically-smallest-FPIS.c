#include <stdio.h>
#include <string.h>

void
solve(const char *s)
{
	size_t i, m, n, t;
	char h[256];

	memset(h, 0, sizeof(h));
	for (n = 0; s[n]; n++)
		h[s[n] & 0xff] = 1;

	m = 0;
	for (i = 'a'; i <= 'z'; i++)
		m += h[i];

	t = 0;
	for (i = 'a'; i <= 'z'; i++) {
		if (!h[i])
			continue;

		for (; t < n - m + 1; t++)
			putchar(i);
		m -= 1;
	}
	puts("");
}

int
main()
{
	solve("bca");
	solve("pqab");
	solve("aabb");
	solve("c");

	return 0;
}
