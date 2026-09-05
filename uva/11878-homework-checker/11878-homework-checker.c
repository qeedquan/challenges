#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
solve(const char **cmds, size_t ncmd)
{
	size_t i, r;
	int a, b, c;

	r = 0;
	for (i = 0; i < ncmd; i++) {
		if (sscanf(cmds[i], "%d+%d=%d", &a, &b, &c) == 3) {
			if (a + b == c)
				r += 1;
		} else if (sscanf(cmds[i], "%d-%d=%d", &a, &b, &c) == 3) {
			if (a - b == c)
				r += 1;
		}
	}
	return r;
}

int
main()
{
	const char *cmds[] = {
		"1+2=3",
		"3-1=5",
		"6+7=?",
		"99-0=99",
	};

	assert(solve(cmds, nelem(cmds)) == 2);

	return 0;
}
