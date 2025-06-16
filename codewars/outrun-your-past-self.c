/*

You are running a race on a circular race track against the ghost of your past self.

Each time you lap your ghost, you get a confidence boost because you realize how much faster you got.

Given your speed (km/h), your ghosts speed (km/h), the length of the circular race track (km) and the time you run (h), predict how often you will lap your ghost.

Lapping your ghost means going from being behind your ghost to being in front of your ghost.

*/

#include <assert.h>
#include <math.h>

int
laps(int speed, int ghostspeed, int time, int roundlength)
{
	double count;

	if (speed < ghostspeed)
		return 0;

	count = (speed - ghostspeed) * time;
	count /= roundlength;
	return floor(count) + fmod(count, 1);
}

int
main()
{
	assert(laps(20, 30, 50, 14) == 0);
	assert(laps(20, 10, 30, 40) == 7);
	assert(laps(2000, 30, 50, 14) == 7035);
	assert(laps(1205, 303, 5052, 1337) == 3408);

	return 0;
}
