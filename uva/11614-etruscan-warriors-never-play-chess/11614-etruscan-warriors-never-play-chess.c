#include <assert.h>

int
rows(int n)
{
	int i;

	for (i = 1; n >= i; i++)
		n -= i;
	return i - 1;
}

int
main(void)
{
	assert(rows(3) == 2);
	assert(rows(6) == 3);
	assert(rows(7) == 3);
	assert(rows(8) == 3);
	assert(rows(9) == 3);
	assert(rows(10) == 4);

	return 0;
}
