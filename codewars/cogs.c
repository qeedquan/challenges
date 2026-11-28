/*

http://bestanimations.com/Science/Gears/loadinggears/loading-gears-animation-6-4.gif

Kata Task
You are given a list of cogs in a gear train

Each element represents the number of teeth of that cog

e.g. [100, 75] means

1st cog has 100 teeth
2nd cog has 75 teeth
If the first cog rotates clockwise at 1 RPM what is the RPM of the final cog?

(use negative numbers for anti-clockwise rotation)

Notes
no two cogs share the same shaft

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
cogrpm(double *cogs, size_t ncogs)
{
	double speed;
	size_t i;

	speed = 1;
	for (i = 1; i < ncogs; i++)
		speed *= cogs[i - 1] / cogs[i];

	if (!(ncogs & 1))
		speed = -speed;

	return speed;
}

int
main()
{
	double cogs1[] = {100, 75};
	double cogs2[] = {1, 2, 3};
	double cogs3[] = {50, 50};

	printf("%f\n", cogrpm(cogs1, nelem(cogs1)));
	printf("%f\n", cogrpm(cogs2, nelem(cogs2)));
	printf("%f\n", cogrpm(cogs3, nelem(cogs3)));
	return 0;
}
