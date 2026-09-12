#include <assert.h>
#include <stdio.h>

int
solve(const char *s)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] != '-')
			continue;
		if (s[i + 1] == 'B')
			continue;
		if (s[i + 1] && s[i + 2] == 'B')
			continue;
		if (s[i + 1] == 'S')
			continue;
		if (i > 0 && s[i - 1] == 'S')
			continue;
		r += 1;
	}
	return r;
}

int
main()
{
	assert(solve("---B--S-D--S--") == 4);
	assert(solve("DDBDDBDDBDD") == 0);

	return 0;
}
