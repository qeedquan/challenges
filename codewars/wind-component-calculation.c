/*

When landing an airplane manually, the pilot knows which runway he is using and usually has up to date wind information (speed and direction). This information alone does not help the pilot make a safe landing; what the pilot really needs to know is the speed of headwind, how much crosswind there is and from which side the crosswind is blowing relative to the plane.

Let's imagine there is a system in the ATC tower with speech recognition that works so that when a pilot says "wind info" over the comms, the system will respond with a helpful message about the wind.

Your task is to write a function that produces the response before it is fed into the text-to-speech engine.

Input:

runway (string: "NN[L/C/R]"). NN is the runway's heading in tens of degrees. A suffix of L, C or R may be present and should be ignored. NN is between 01 and 36.
wind_direction (int). Direction wind is blowing from in degrees. Between 0 and 359.
wind_speed (int). Wind speed in knots
Output:

a string in the following format: "(Head|Tail)wind N knots. Crosswind N knots from your (left|right)."
The wind speeds must be correctly rounded integers. If the rounded headwind component is 0, "Head" should be used. Similarly, "right" in case crosswind component is 0.

Calculating crosswind and headwind:

A = Angle of the wind from the direction of travel (radians)
WS = Wind speed
CW = Crosswind
HW = Headwind

CW = sin(A) * WS
HW = cos(A) * WS
More information about wind component calculation: http://en.wikipedia.org/wiki/Tailwind

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

char *
message(const char *runway, int wind_direction, int wind_speed, char *output)
{
	const char *direction0;
	const char *direction1;
	double angle;
	int crosswind;
	int headwind;

	if (sscanf(runway, "%lf", &angle) != 1)
		return NULL;

	angle = deg2rad(wind_direction - (10 * angle));
	crosswind = round(sin(angle) * wind_speed);
	headwind = round(cos(angle) * wind_speed);

	direction0 = (headwind < 0) ? "Tailwind" : "Headwind";
	direction1 = (crosswind < 0) ? "left" : "right";
	sprintf(output, "%s %d knots. Crosswind %d knots from your %s.", direction0, abs(headwind), abs(crosswind), direction1);

	return output;
}

void
test(const char *runway, int wind_direction, int wind_speed, const char *expected)
{
	char output[128];

	message(runway, wind_direction, wind_speed, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("18L", 170, 15, "Headwind 15 knots. Crosswind 3 knots from your left.");
	test("22", 160, -120, "Tailwind 60 knots. Crosswind 104 knots from your right.");
	test("18", 210, 14, "Headwind 12 knots. Crosswind 7 knots from your right.");
	test("36", 258, 16, "Tailwind 3 knots. Crosswind 16 knots from your left.");
	test("22L", 160, 14, "Headwind 7 knots. Crosswind 12 knots from your left.");
	test("18", 70, 15, "Tailwind 5 knots. Crosswind 14 knots from your left.");

	return 0;
}
