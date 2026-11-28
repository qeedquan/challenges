#include <stdio.h>

const char *
solve(int p, int h, int o)
{
	if (o - p >= h)
		return "Props win!";
	return "Hunters win!";
}

int
main()
{
	puts(solve(2, 2, 3));
	puts(solve(2, 2, 4));

	return 0;
}
