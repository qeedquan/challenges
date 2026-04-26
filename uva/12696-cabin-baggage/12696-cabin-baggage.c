#include <assert.h>

int
allowed(double h, double w, double d, double m)
{
	if (h < 0 || w < 0 || d < 0 || m < 0)
		return 0;
	return ((h + w + d <= 125.0) || (h <= 56.0 && w <= 45.0 && d <= 25.0)) && m <= 7.0;
}

int
main(void)
{
	assert(allowed(51.23, 40.12, 21.20, 3.45) == 1);
	assert(allowed(60.00, 30.00, 20.00, 7.00) == 1);
	assert(allowed(52.03, 41.25, 23.50, 7.01) == 0);
	assert(allowed(50.00, 45.00, 30.10, 6.02) == 0);

	return 0;
}
