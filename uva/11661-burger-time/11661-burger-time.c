#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

ssize_t
solve(const char *s)
{
	ssize_t a, b, i, r;

	a = -1;
	b = -1;
	r = SSIZE_MAX;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'Z':
			return 0;
		case 'R':
			a = i;
			break;
		case 'D':
			b = i;
			break;
		}
		if (a < 0 || b < 0)
			continue;
		if (a - b > 0)
			r = min(r, a - b);
		if (b - a > 0)
			r = min(r, b - a);
	}
	return r;
}

int
main()
{
	assert(solve("RD") == 1);
	assert(solve("..Z..") == 0);
	assert(solve(".R......D.") == 7);
	assert(solve(".R..Z...D.") == 0);
	assert(solve("...D..R...") == 3);
	assert(solve("..D...R.RR...DD...D.R...R") == 2);

	return 0;
}
