#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
solve(int s, int n, int m)
{
	switch (s) {
	case 'r':
	case 'Q':
		return min(n, m);
	case 'K':
		return ((n + 1) / 2) * ((m + 1) / 2);
	case 'k':
		return ((n * m) / 2) + ((n * m) % 2);
	}
	return -1;
}

int
main()
{
	assert(solve('r', 6, 7) == 6);
	assert(solve('k', 8, 8) == 32);

	return 0;
}
