/*

Description

You are given a car odometer which displays the miles traveled as an integer. The odometer has a defect, however: it proceeds from the digit 3 to the digit 5, always skipping over the digit 4. This defect shows up in all positions (the one's, the ten's, the hundred's, etc.). For example, if the odometer displays 15339 and the car travels one mile, odometer reading changes to 15350 (instead of 15340).
Input

Each line of input contains a positive integer in the range 1..999999999 which represents an odometer reading. (Leading zeros will not appear in the input.) The end of input is indicated by a line containing a single 0. You may assume that no odometer reading will contain the digit 4.
Output

Each line of input will produce exactly one line of output, which will contain: the odometer reading from the input, a colon, one blank space, and the actual number of miles traveled by the car.

Sample Input

13
15
2003
2005
239
250
1399
1500
999999
0

Sample Output

13: 12
15: 13
2003: 1461
2005: 1462
239: 197
250: 198
1399: 1052
1500: 1053
999999: 531440

Source

Rocky Mountain 2005

*/

#include <assert.h>

long
reading(long n)
{
	long i, r, v;

	r = 0;
	for (i = 1; n > 0; n /= 10) {
		v = n % 10;
		if (v >= 4)
			v--;

		r += v * i;
		i *= 9;
	}
	return r;
}

int
main(void)
{
	assert(reading(13) == 12);
	assert(reading(15) == 13);
	assert(reading(2003) == 1461);
	assert(reading(2005) == 1462);
	assert(reading(239) == 197);
	assert(reading(250) == 198);
	assert(reading(1399) == 1052);
	assert(reading(1500) == 1053);
	assert(reading(999999L) == 531440L);

	return 0;
}
