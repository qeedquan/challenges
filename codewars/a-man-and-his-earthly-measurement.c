/*

Background
Eratosthenes of Cyrene was a greek philosopher, mathematician, geographer, and so much more. He was a man of learning who became the chief librarian at the Library of Alexandria. He invented the principle of geography and is best known for his remarkably accurate calculation of Earth's circumference.

He measured Earth's circumference without ever leaving Egypt. He knew that on a certain day in his hometown of Cyrene that the sun would be directly overhead, and a well would cast no shadow. However on that same day due north in Alexandria, a rod would cast a shadow. Using the height of the rod, the length of its shadow, the distance to the well,　and a little bit of geometric know-how he was able to calculate the circumference of the Earth.

Your Task
Given the rod's height, the shadow's length, and the distance from the rod to the well(in km): Calculate the circumference of Earth (within 5% error).(and other spheres)

Resources
https://en.wikipedia.org/wiki/Eratosthenes

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
circumference(double rod_height, double shadow_length, double distance_to_well)
{
	return 2 * M_PI * distance_to_well / atan(shadow_length / rod_height);
}

void
test(double rod_height, double shadow_length, double distance_to_well, double expected)
{
	double value;

	value = circumference(rod_height, shadow_length, distance_to_well);
	printf("%f\n", value);
	assert(fabs(value - expected) < (expected * 0.05));
}

int
main()
{
	test(8.1, 1.0, 800, 40075);
	test(1, 5, 20, 91.4);
	test(2, 5, 50, 263.8);
	return 0;
}
