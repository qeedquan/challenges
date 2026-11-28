/*

Let's make a contentWeight function that takes in two parameters: bottleWeight and scale. This function will return the weight of the contents inside the bottle.

bottleWeight will be an integer representing the weight of the entire bottle (contents included).

scale will be a string that you will need to parse. It will tell you how the content weight compares to the weight of the bottle by itself. 2 times larger, 6 times larger, and 15 times smaller would all be valid strings (smaller and larger are the only comparison words).

The first test case has been filled out for you. Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
content_weight(int bottle_weight, const char *scale)
{
	char relative[16];
	int times;
	double weight;

	if (sscanf(scale, "%d times %15s", &times, relative) != 2)
		return -1;

	if (!strcmp(relative, "larger"))
		weight = bottle_weight / (1 + times);
	else if (!strcmp(relative, "smaller"))
		weight = bottle_weight / (1 + (1.0 / times));
	else
		return -1;

	return bottle_weight - weight;
}

int
main()
{
	assert(content_weight(120, "2 times larger") == 80);
	return 0;
}
