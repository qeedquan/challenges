#include <assert.h>

int
solve(const char *s)
{
	static const int tab[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };

	int r;

	for (r = 0; *s; s++) {
		if (*s == ' ')
			r += 1;
		else if ('a' <= *s && *s <= 'z')
			r += tab[*s - 'a'];
	}
	return r;
}

int
main()
{
	assert(solve("welcome to ulab") == 29);
	assert(solve("good luck and have fun") == 41);

	return 0;
}
