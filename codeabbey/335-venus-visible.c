/*

https://imgur.com/ZLs8zUS

The picture above was taken about 3 weeks ago, when I was running with my dog over snow drifts in the late evening and suddenly noticed Jupiter, Moon and Venus perfroming what is called Parade. Sorry for quality, it was bit unexpected - both the event is rare and clear days (rather nights) here are scarce in winter.

These days you still can see Venus on the western horizon soon after sunset. Jupiter also. Few days later (on Mar-23-2023) Moon again will align between them. Though one needs to watch them carefully around sunset since all three will dive under horizon quite soon after (and they are not well visible when the Sun is yet in the sky).

A bit of astronomy
Following days the Moon will travel leftward (each day shifting by roughly the same distance which is between Venus and Jupiter here). Jupiter rounds the sky hundred times more slowly, so it can be considered motionless, while Venus is in fact "swinging" to the left and right of the Sun (here Sun is set hour or two ago, to the right), never wandering too far from it. This is because orbit of Venus is inside orbit of Earth - it is closer to the Sun and obviously we never can see it, say, on the opposite side of the sky (which is all right for "outer" planets, like Jupiter).

Due to the same fact, Venus has visible "phases", just like the Moon. Really it is almost always in the form of the creschent, just like the Moon. However it is so tiny to our eye that only very sharp-sighted people can discern it. That was surprise for famous matematician Gauss, when he invited his mother to look at Venus through telescope and she said "wow, it looks larger, but its creschent is upside down!" - he didn't know his mother was aware of the phases of Venus even without magnification.

Problem Statement
Our goal is to figure out at which position Venus sends maximum light to the Earth! Of course when it is too close to the Sun its light is obscured by daylight, but for the sake of calculations let's ignore this fact (suppose we are observing it from the top of Everest mountain where athmosphere is less dense).

This amount of light depends on two factors - the phase of the Venus, and its distance to us. Consider the diagram below to clarify this.

https://imgur.com/dle3vRO
Let's assume the orbits of the Earth and Venus are perfect circles (they are slightly elliptical in fact) so that the distances from them to the Sun are constant. Distance to Earth Re is 1 ("astronomical unit") and distance to Venus Rv is given in relation to it, say 0.7. So we see the distance between Earth and Venus, marked D depends on relative position of the Venus.

Let's describe this position by the angle alpha - between direction from Sun to Venus (purple, non-horizontal) - and direction from the Earth to Sun (horizontal, purple). When Venus is behind the Sun, alpha is zero. When Venus is between Sun and Earth, this angle becomes maximal, 180 degrees.

The light reaching us from any celestial body (and any light source) decreases in proportion to distance squared (to this source).

Now about the phases. Obviously Venus is "full" when it is behind the Sun, in opposition to Earth. When it is nearest to Earth, on contrary, we see only its back side (similar to "new moon" condition) - or rather don't see anything at all. This obviously is the factor of the angle between our line of sight to Venus (green line) and direction of falling light (purple line between Venus and Sun). Let's call this angle gamma.

Really the amount of light reflected from the body depends on the quality of the surface. It is big relief to us that Venus (as almost all celestial bodies) reflects light in almost completely "diffuse" way - every beam scatters uniformly in all directions. That's why moon looks so evenly lighted despite it is not flat.

The light reduction due to phase in this condition is found by using the angle between line of sight and direction of light, particularly, multiply by (1 + cos(gamma)) / 2.

You are to tell, for several different distances Rv the angles alpha at which Venus reaches maximum apparent brightness.

Input: the first line provides N - total number of test-cases.
The next line contains N values of Rv.

Answer should have angle of maximum visible brightness for each testcase, rounded to the nearest integer (in degrees).

Example

input
3
0.515 0.664 0.848

answer:
130 151 169

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#define rad2deg(x) ((x) * 180 / M_PI)

/*

1. Distance Geometry: By the law of cosines in the Sun-Earth-Venus triangle

This is assuming Re=1
D^2 = 1 + Rv^2 - 2*Rv*cos(alpha)

2. Phase angle (gamma): The angle between our line of sight to Venus and the direction of falling sunlight from the Sun satisfies:

cos(gamma) = (Rv^2 + D^2 - 1) / (2*Rv*D)

3. Apparent Brightness (B): Brightness is directly proportional to the visible illuminated phase and inversely proportional to the square of its distance from Earth:

B ~ (1 + cos(gamma)) / 2*D^2

Maximize B using the parameter alpha.
Just use brute force since alpha ranges are small enough.

*/

int
solve(double Rv)
{
	double cos_gamma;
	double alpha;
	double step;
	double max_brightness;
	double best_angle;
	double B, D, D2;

	step = 1e-5;
	max_brightness = -FLT_MAX;
	best_angle = 0;
	for (alpha = 0; alpha < M_PI; alpha += step) {
		D2 = 1 + (Rv * Rv) - (2 * Rv * cos(alpha));
		D = sqrt(D2);
		cos_gamma = ((Rv * Rv) + D2 - 1) / (2 * Rv * D);
		B = (1 + cos_gamma) / (2 * D2);
		if (B > max_brightness) {
			max_brightness = B;
			best_angle = alpha;
		}
	}
	return round(180 - rad2deg(best_angle));
}

int
main()
{
	assert(solve(0.515) == 130);
	assert(solve(0.664) == 151);
	assert(solve(0.848) == 169);

	return 0;
}
