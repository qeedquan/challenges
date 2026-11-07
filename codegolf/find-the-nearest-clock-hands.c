/*

Challenge

Given a number of seconds past midnight, output the smallest angle between any two hands on a clock face, using as few bytes as possible.

You may assume that the number of seconds is always less than 86400. Angles may be represented in degrees or radians.

A reference solution is at: http://ideone.com/eVdgC0

Test Cases (results in degrees)

0 -> 0
60 -> 0.5
600 -> 5
3600 -> 0
5400 -> 45
6930 -> 84.75
50000 -> 63.333

Clarificarions

The clock has 3 hands: hours, minutes and seconds.
All hands move continuously, thus hour and minute hands can be found between graduations on the clock face.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
clockangle(double sec)
{
	double sh, mh, sm;
	double hf, mf, sf;
	double h, m, s;

	s = fmod(sec, 60);
	m = fmod(sec / 60, 60);
	h = fmod(sec / 3600, 12);

	sf = s / 60;
	mf = m / 60;
	hf = h / 12;

	sm = fabs(sf - mf);
	sh = fabs(sf - hf);
	mh = fabs(mf - hf);

	sm = (sm > 0.5) ? 1 - sm : sm;
	sh = (sh > 0.5) ? 1 - sh : sh;
	mh = (mh > 0.5) ? 1 - mh : mh;

	return fmin(sm, fmin(sh, mh)) * 360;
}

void
test(double sec, double r)
{
	double v;

	v = clockangle(sec);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(0, 0);
	test(60, 0.5);
	test(3600, 0);
	test(5400, 45);
	test(6930, 84.75);
	test(50000, 63.333);

	return 0;
}
