/*

Introduction

Today I went fishing alone with my canoe, unfortunately I fell asleep and the stream brought me away, I lost my oars, now it's night and I am lost in the ocean! I can't see the coast so I must be far away!

I have my cell phone but is malfunctional because it got wet by the salty water, I can't talk or hear anything because the mic and phone speaker are broken, but I can send SMS to my friend who is on the coast's beach!

My friend has a very powerful torch and he raised it on top of bamboo's canes to show me the right direction, but I can’t row because I have no oars, so I must tell him how far I am so he can send someone to catch me!

My friend told me that he is keeping the torch at 11.50 meters on the sea level, and I can see the light right over the horizon. Now I only remember from the school that the Earth radius should be 6371 Km at the sea level, and I’m sittin in my canoe so you can assume that my eyes are at sea level too.

Task

Since the currents are moving me moment by moment, my friend is raising the torch from time to time (now it’s at 12.30 meters), please write a full program or function that will help me to calculate the distance from my friend’s position!

Here is a diagram (not to scale):

https://i.stack.imgur.com/FhOkf.png

The orange point labelled M is me, the red point labelled T is the torch. The green line is the linear distance between M and T

Input

Take from standard input the torch height h in meters at the sea level, which I see right on top of the horizon, in the form of a floating point number with two decimals precision (with the accuracy of 1 centimeter or 0.01 meters), in the range from 0 to 100 included.

Output

You should return the euclidean length of the green line with the accuracy of 1 cm. For example if you output in meters, should be with two decimals (at least). The output can be either meters or kilometers, but respecting the accuracy.

Test cases:

All values in meters.

11.5 > 12105.08
13.8 > 13260.45
Rules

Shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

r is earth's radius

r^2+x^2 = (r+h)^2          # Pythagoras base
r^2+x^2 = r^2 + 2rh + h^2  # right term distributed
x^2     = 2rh + h^2        # -r^2
x       = sqrt(2rh + h^2)  # sqrt

*/

double
greenline(double h)
{
	// earth radius
	static const double R = 6371000.0;
	return sqrt((2 * R * h) + (h * h));
}

void
test(double h, double r)
{
	double d;

	d = greenline(h);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-2);
}

int
main(void)
{
	test(11.5, 12105.08);
	test(13.8, 13260.45);
	return 0;
}
