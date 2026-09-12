#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
solve(const char *s)
{
	int a, b;

	if (sscanf(s, "%d %d", &a, &b) == 2)
		return 2 * a * b * M_PI;
	if (sscanf(s, "%d", &a) == 1)
		return (a * a * M_PI) / 8;
	return -1;
}

int
main()
{
	printf("%.3f\n", solve("10 10"));
	printf("%.3f\n", solve("15 20"));
	return 0;
}
