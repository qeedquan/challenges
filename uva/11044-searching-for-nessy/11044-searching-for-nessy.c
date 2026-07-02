#include <assert.h>

int
sonars(int n, int m)
{
	return (n / 3) * (m / 3);
}

int
main(void)
{
	assert(sonars(6, 6) == 4);
	assert(sonars(7, 7) == 4);
	assert(sonars(9, 13) == 12);

	return 0;
}
