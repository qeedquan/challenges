/*

Create a routine to calculate the position of each unit of a clock with an arbitrary number of units (minutes, hours, half-days, days, years, parsecs, quarter-quells, etc), where each unit can be equally sub-divided into an arbitrary number of sub-units; after n base units have elapsed.

Basically, figure out what a clock would show after n seconds given user defined lengths for minutes, hours, days, etc.

For example, after 86,400 seconds on a clock that has 60 seconds in a minute, 60 minutes in an hour, 12 hours per half day, 2 half days per day, and 365 days in a year; you get the following:

clockFunction(86400,[60,60,12,2,365]) = 0,0,0,0,1
(Standard Clock)

clockFunction(86400,[60,60,12,2]) = 0,0,0,0
(Standard Clock - Rolling Over)

clockFunction(7430201,[100,100,10,10,3,12]) = 1,2,3,4,1,2
(French Republican Calendar [sec / min, min / hr, hrs / day, days / wk, wks / mo, mo / yr])

clockFunction(2443332,[60,60,24,365]) = 12,42,6,28
(Standard Clock - Donnie Darko)

clockFunction(63570500940,[60,60,12,2,365,10000]) = 0, 29, 4, 1, 294, 2015
(Standard Clock - Back to the Future)

Shortest code that works wins!

Clarifications:

All Units are integer
All Units are greater than 0

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

void
clocktime(vlong t, vlong *u, size_t n, vlong *r)
{
	size_t i;

	for (i = 0; i < n; i++) {
		r[i] = t % u[i];
		t = t / u[i];
	}
}

void
test(vlong t, vlong *u, size_t n, vlong *r)
{
	vlong x[32];

	clocktime(t, u, n, x);
	assert(!memcmp(x, r, sizeof(*r) * n));
}

int
main()
{
	vlong u1[] = { 60, 60, 12, 2, 365 };
	vlong u2[] = { 60, 60, 12, 2 };
	vlong u3[] = { 100, 100, 10, 10, 3, 12 };
	vlong u4[] = { 60, 60, 24, 365 };
	vlong u5[] = { 60, 60, 12, 2, 365, 10000 };

	vlong r1[] = { 0, 0, 0, 0, 1 };
	vlong r2[] = { 0, 0, 0, 0 };
	vlong r3[] = { 1, 2, 3, 4, 1, 2 };
	vlong r4[] = { 12, 42, 6, 28 };
	vlong r5[] = { 0, 29, 4, 1, 294, 2015 };

	test(86400, u1, nelem(u1), r1);
	test(86400, u2, nelem(u2), r2);
	test(7430201, u3, nelem(u3), r3);
	test(2443332, u4, nelem(u4), r4);
	test(63570500940, u5, nelem(u5), r5);

	return 0;
}
