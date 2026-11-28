/*

Your friend invites you out to a cool floating pontoon around 1km off the beach. Among other things,
the pontoon has a huge slide that drops you out right into the ocean, a small way from a set of
stairs used to climb out.

As you plunge out of the slide into the water, you see a shark hovering in the darkness under the
pontoon... Crap!

You need to work out if the shark will get to you before you can get to the pontoon. To make it
easier... as you do the mental calculations in the water you either freeze when you realise you are
dead, or swim when you realise you can make it!

You are given 5 variables;

* sharkDistance = distance from the shark to the pontoon. The shark will eat you if it reaches you
  before you escape to the pontoon.

* sharkSpeed = how fast it can move in metres/second.

* pontoonDistance = how far you need to swim to safety in metres.

* youSpeed = how fast you can swim in metres/second.

* dolphin = a boolean, if true, you can half the swimming speed of the shark as the dolphin will
  attack it.

* The pontoon, you, and the shark are all aligned in one dimension.

If you make it, return "Alive!", if not, return "Shark Bait!".

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *
shark(int pontoon_distance, int shark_distance, double you_speed, double shark_speed, bool dolphin)
{
	double time1, time2;

	time1 = pontoon_distance / you_speed;
	time2 = shark_distance / shark_speed;
	if (dolphin)
		time2 *= 2;
	if (time1 < time2)
		return "Alive!";
	return "Shark Bait!";
}

void
test(int pontoon_distance, int shark_distance, double you_speed, double shark_speed, bool dolphin, const char *result)
{
	const char *output;

	output = shark(pontoon_distance, shark_distance, you_speed, shark_speed, dolphin);
	puts(output);
	assert(!strcmp(output, result));
}

int
main()
{
	test(12, 50, 4, 8, true, "Alive!");
	test(7, 55, 4, 16, true, "Alive!");
	test(24, 0, 4, 8, true, "Shark Bait!");

	return 0;
}
