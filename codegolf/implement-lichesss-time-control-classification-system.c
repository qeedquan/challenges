/*

From the FAQs:

Lichess time controls are based on estimated game duration = (clock initial time in seconds) + 40 × (clock increment). For instance, the estimated duration of a 5+3 game is 5 × 60 + 40 × 3 = 420 seconds.

≤ 29s = UltraBullet
≤ 179s = Bullet
≤ 479s = Blitz
≤ 1499s = Rapid
≥ 1500s = Classical

Your task: given a time control, output which category (mentioned above) that control fits in. (However, don't follow this classification strictly: read on to see why)

I/O
Input a floating point number representing the starting time in minutes and an integer representing the increment in seconds by any reasonable means according to our defaults for I/O methods.

Output one of 5 fixed distinct values through the same output method equivalent to a particular time control (UltraBullet, Bullet, Blitz, Rapid, Classical), following the method described above. For example, I can use the numbers 1 to 5, 5 different error messages, or even just the plain names of each category. This must be fixed for all inputs and specified in your answer; you may not, for example, arbitrarily output numbers whose values modulo 5 represent the true output.

NOTE: Since minutes are input as a decimal, there is a hole between Rapid and Classical where numbers with value 1499<x<1500
 cannot be classified (which does not occur on Lichess since arbitrary time controls are not possible). In this case output Classical.

Thus the classification you must follow is this:

≤ 29s = UltraBullet
≤ 179s = Bullet
≤ 479s = Blitz
≤ 1499s = Rapid
> 1499s = Classical

Test cases
These are only for the test cases, since I had to pick a format.

Input format: (Starting time in minutes)+(Increment in seconds)
Output format: 1 to 5 representing UltraBullet, Bullet, Blitz, Rapid, Classical

5+3                 -> 3 (5*60+3*40 = 420 ≤ 479)
0.5+0               -> 2 (0.5*60+0*40 = 30 ≤ 179)
0+6                 -> 3 (0*60+6*40 = 240 ≤ 479)
0.125+0             -> 1 (0.125*60+0*40 = 7.5 ≤ 29)
2.9916666667+0      -> 3 (2.9916666667*60+0*40 = 179.5 ≤ 479)
10+2                -> 4 (10*60+2*40 = 680 ≤ 1499)
90.5+0              -> 5 (90.5*60+0*40 = 5430 > 1499)
25+0                -> 5 (25*60+0*40 = 1500 > 1499)
24.32+1             -> 5 (24.32*60+1*40 = 1499.2 > 1499)
5.983333333333333+3 -> 3 (5.983333333333333*60+3*40 = 479 ≤ 479)

This is code-golf, so shortest answer wins!

*/

#include <assert.h>
#include <stdio.h>

int
tc(const char *s)
{
	double t, dt;

	if (!sscanf(s, "%lf+%lf", &t, &dt))
		return -1;

	t = (60 * t) + (40 * dt);
	if (t <= 29)
		return 1;
	if (t <= 179)
		return 2;
	if (t <= 479)
		return 3;
	if (t <= 1499)
		return 4;
	return 5;
}

int
main()
{
	assert(tc("5+3") == 3);
	assert(tc("0.5+0") == 2);
	assert(tc("0+6") == 3);
	assert(tc("0.125+0") == 1);
	assert(tc("2.9916666667+0") == 3);
	assert(tc("10+2") == 4);
	assert(tc("90.5+0") == 5);
	assert(tc("25+0") == 5);
	assert(tc("24.32+1") == 5);
	assert(tc("5.983333333333333+3") == 3);

	return 0;
}
