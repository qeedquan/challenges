/*

In this Kata, we will calculate running pace. To do that, we have to know the distance and the time.

Create the following function:

Where: distance - A float with the number of kilometres

time - A string containing the time it took to travel the distance. It will always be minutes:seconds. For example "25:00" means 25 minutes. You don't have to deal with hours.

The function should return the pace, for example "4:20" means it took 4 minutes and 20 seconds to travel one kilometre.

Note: The pace should always return only the number of minutes and seconds. You don't have to convert these into hours. Floor the number of seconds.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
pace(double distance, const char *time, char *output)
{
	double minute;
	double second;
	int value;

	if (sscanf(time, "%lf:%lf", &minute, &second) != 2)
		return NULL;

	value = ((minute * 60) + second) / distance;
	sprintf(output, "%d:%02d", value / 60, value % 60);
	return output;
}

void
test(double distance, const char *time, const char *expected)
{
	char output[128];

	assert(pace(distance, time, output));
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(1, "3:15", "3:15");
	test(5, "25:00", "5:00");
	test(15, "75:00", "5:00");
	test(2.51, "10:43", "4:16");
	test(4.99, "22:32", "4:30");
	test(0.2, "0:38", "3:10");
	test(42.195, "122:57", "2:54");

	return 0;
}
