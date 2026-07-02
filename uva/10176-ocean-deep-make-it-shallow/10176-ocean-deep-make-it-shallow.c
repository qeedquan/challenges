#include <assert.h>
#include <stdio.h>

typedef long long vlong;

bool
solve(const char *s)
{
	vlong r;

	for (r = 0; *s && *s != '#'; s++) {
		r <<= 1;
		if (*s == '1')
			r += 1;
		r %= 131071;
	}
	return r == 0;
}

int
main()
{
	assert(solve("0#") == true);
	assert(solve("1010101#") == false);

	return 0;
}
