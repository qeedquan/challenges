#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void
solve(const char *s)
{
	size_t h[256];
	size_t i, m;
	int c;

	memset(h, 0, sizeof(h));
	for (i = m = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (isalpha(c)) {
			h[c] += 1;
			m = max(m, h[c]);
		}
	}

	for (i = 0; i < 256; i++) {
		if (m == h[i])
			putchar(i);
	}
	printf(" %zu\n", m);
}

int
main()
{
	solve("When riding your bicycle backwards down a one-way street, if the");
	solve("wheel falls of a canoe, how many ball bearings does it take to fill");
	solve("up a water buffalo?");
	solve("Hello Howard.");

	return 0;
}
