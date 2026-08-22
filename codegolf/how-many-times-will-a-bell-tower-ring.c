/*

Introduction
A bell tower will ring its bells every hour, n times, with n being the the current hour on a 12 hour clock.

For example, a bell will ring 5 times at 5pm, and 10 times at 10am.

Task
Given two times in a suitable format, output the number of times the bell will ring, inclusive of the start and end times

Examples
"10am-12pm"
10+11+12= 33

[01:00, 05:00]
1+2+3+4+5 = 15

[11, 15]
11+12+1+2+3 = 29

[10:00pm, 10:00am]
10+11+12+1+2+3+4+5+6+7+8+9+10 = 88
If the start is the same as the end then the you simply just ouput the number of chimes for that hour:

[5pm, 5pm]
5 = 5
As you can see, you may choose an input method but the output must be an integer on its own (or an acceptable alternative) trailing/ leading newlines and spaces are allowed.

Note:

inputs may span from the afternoon of one day to the morning of the next.
the difference between the two times will never be more than 24 hours.
input is flexible so long as you clearly state what format your input is.
your input must have a clear distinction between AM and PM.

*/

#include <assert.h>

int
f(int a, int b)
{
	int r;

	if (a < 0 || b < 0 || a > 23 || b > 23)
		return 0;

	r = 0;
	do {
		a %= 24;
		if (a > 12)
			r += a - 12;
		else if (a < 1)
			r += 12;
		else
			r += a;
	} while (a++ != b);

	return r;
}

int
main()
{
	assert(f(10, 12) == 33);
	assert(f(1, 5) == 15);
	assert(f(11, 15) == 29);
	assert(f(22, 10) == 88);
	assert(f(10, 10) == 10);
	assert(f(11, 10) == 156);
	assert(f(0, 23) == 156);
	assert(f(22, 1) == 34);
	assert(f(5, 5) == 5);
	return 0;
}
