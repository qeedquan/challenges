#include <assert.h>

int
last3(int n)
{
	return (((n * (n + 2) / 2) * 3) - 6);
}

int
main(void)
{
	assert(last3(3) == 15);
	assert(last3(5) == 45);
	assert(last3(7) == 87);

	return 0;
}
