/*

Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 1e-5 of the actual value will be accepted as correct.

Example 1:


Input: hour = 12, minutes = 30
Output: 165
Example 2:


Input: hour = 3, minutes = 30
Output: 75
Example 3:


Input: hour = 3, minutes = 15
Output: 7.5


Constraints:

1 <= hour <= 12
0 <= minutes <= 59

*/

#include <assert.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

double
angleclock(unsigned h, unsigned m)
{
	double ha, ma;
	double d;

	ha = ((h % 12) + (m / 60.0)) * 30;
	ma = m * 6;
	d = fabs(ha - ma);
	return min(d, 360 - d);
}

int
main(void)
{
	assert(angleclock(12, 30) == 165);
	assert(angleclock(3, 30) == 75);
	assert(angleclock(3, 15) == 7.5);

	return 0;
}
