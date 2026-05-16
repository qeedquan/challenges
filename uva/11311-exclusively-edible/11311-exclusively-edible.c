#include <assert.h>
#include <string.h>

const char *
nim(int m, int n, int r, int c)
{
	int above, below;
	int left, right;
	int outcome;

	above = r;
	below = m - 1 - r;
	left = c;
	right = n - 1 - c;
	outcome = above ^ below ^ left ^ right;
	if (outcome == 0)
		return "Hansel";
	return "Gretel";
}

int
main()
{
	assert(!strcmp(nim(2, 3, 0, 2), "Gretel"));
	assert(!strcmp(nim(11, 11, 5, 5), "Hansel"));

	return 0;
}
