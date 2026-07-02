#include <assert.h>

int
values(int a, int b, int c, int d, int l)
{
	int i, r, v;

	r = 0;
	for (i = 0; i <= l; i++) {
		v = (a * i * i) + (b * i) + c;
		if (v % d == 0)
			r++;
	}
	return r;
}

int
main(void)
{
	assert(values(0, 0, 10, 5, 100) == 101);
	assert(values(0, 0, 10, 6, 100) == 0);
	assert(values(1, 2, 3, 4, 5) == 0);
	assert(values(1, 2, 3, 3, 5) == 4);

	return 0;
}
