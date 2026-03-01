/*

A History Lesson
The Pony Express was a mail service operating in the US in 1859-60.

It reduced the time for messages to travel between the Atlantic and Pacific coasts to about 10 days, before it was made obsolete by the transcontinental telegraph.

How it worked
There were a number of stations, where:

The rider switched to a fresh horse and carried on, or
The mail bag was handed over to the next rider
Kata Task
stations is a list/array of distances (miles) from one station to the next along the Pony Express route.

Implement the riders method/function, to return how many riders are necessary to get the mail from one end to the other.

NOTE: Each rider travels as far as he can, but never more than 100 miles.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
riders(int *stations, size_t length)
{
	size_t index;
	int count;
	int distance;

	if (length == 0)
		return 0;

	count = 1;
	distance = 0;
	for (index = 0; index < length; index++) {
		if (distance + stations[index] <= 100)
			distance += stations[index];
		else {
			distance = stations[index];
			count += 1;
		}
	}
	return count;
}

int
main()
{
	int stations_1[] = { 18, 15 };
	int stations_2[] = { 43, 23, 40, 13 };
	int stations_3[] = { 33, 8, 16, 47, 30, 30, 46 };
	int stations_4[] = { 6, 24, 6, 8, 28, 8, 23, 47, 17, 29, 37, 18, 40, 49 };

	assert(riders(stations_1, nelem(stations_1)) == 1);
	assert(riders(stations_2, nelem(stations_2)) == 2);
	assert(riders(stations_3, nelem(stations_3)) == 3);
	assert(riders(stations_4, nelem(stations_4)) == 4);

	return 0;
}
