#include <assert.h>

int
id(int n, int a, int b, int c, int d, int e)
{
	int r;

	r = (n == a);
	r += (n == b);
	r += (n == c);
	r += (n == d);
	r += (n == e);
	return r;
}

int
main()
{
	assert(id(1, 1, 2, 3, 2, 1) == 2);
	assert(id(3, 4, 1, 1, 2, 1) == 0);

	return 0;
}
