#include <assert.h>

int
salary(int a, int b, int c)
{
	if ((a > b && a < c) || (a > c && a < b))
		return a;
	if ((b < a && b > c) || (b < c && b > a))
		return b;
	return c;
}

int
main(void)
{
	assert(salary(1000, 2000, 3000) == 2000);
	assert(salary(3000, 2500, 1500) == 2500);
	assert(salary(1500, 1200, 1800) == 1500);

	return 0;
}
