/*

You've purchased a ready-meal from the supermarket.

The packaging says that you should microwave it for 4 minutes and 20 seconds, based on a 600W microwave.

Oh no, your microwave is 800W! How long should you cook this for?!

Input
You'll be given 4 arguments:

1. needed power
The power of the needed microwave.
Example: "600W"

2. minutes
The number of minutes shown on the package.
Example: 4

3. seconds
The number of seconds shown on the package.
Example: 20

4. power
The power of your microwave.
Example: "800W"

Output
The amount of time you should cook the meal for formatted as a string.

Example: "3 minutes 15 seconds"

Note: the result should be rounded up.

59.2 sec  -->  60 sec  -->  return "1 minutes 0 seconds"

All comments/feedback/translations appreciated.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
cooktime(const char *required_power, int minutes, int seconds, char *power, char *output)
{
	double value0, value1;
	int time;

	if (sscanf(required_power, "%lfW", &value0) != 1)
		return NULL;
	if (sscanf(power, "%lfW", &value1) != 1)
		return NULL;

	time = ceil(((minutes * 60) + seconds) * value0 / value1);
	sprintf(output, "%d minutes %d seconds", time / 60, time % 60);
	return output;
}

void
test(const char *required_power, int minutes, int seconds, char *power, const char *expected)
{
	char output[128];

	assert(cooktime(required_power, minutes, seconds, power, output));
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("600W", 4, 20, "800W", "3 minutes 15 seconds");
	test("800W", 3, 0, "1200W", "2 minutes 0 seconds");
	test("100W", 8, 45, "50W", "17 minutes 30 seconds");
	test("7500W", 0, 5, "600W", "1 minutes 3 seconds");
	test("450W", 3, 25, "950W", "1 minutes 38 seconds");
	test("21W", 64, 88, "25W", "55 minutes 0 seconds");
	test("83W", 61, 80, "26W", "199 minutes 0 seconds");
	test("38W", 95, 22, "12W", "302 minutes 0 seconds");
	return 0;
}
