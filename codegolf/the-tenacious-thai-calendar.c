/*

In the Thai calendar the year 2017 corresponds to 2560. The Thai calendar is always 543 years ahead of the Gregorian calendar.

Observant coders will note that 2560 is equal to 29*5, in other words it has 10 prime factors.
This will not happen again for another 896 years! We call a year tenacious if it has exactly ten prime factors.

Write a program which outputs a truthy value if the current year using the Thai calendar, based on the system clock, is tenacious, and a falsey value otherwise.

Test cases:

If the program is run during 2017, true
If the program is run during any of the years 2018 to 2912, false
If the program is run during 2913, true (2913 + 543 = 27 * 33)

*/

#include <assert.h>
#include <stdbool.h>

bool
tenacious(int y)
{
	int c, i, n;

	y += 543;
	n = y;
	c = 0;
	for (i = 2; i < n; i++) {
		for (; y % i == 0; y /= i)
			c++;
	}
	return c == 10;
}

int
main(void)
{
	int i;

	assert(tenacious(2017) == true);
	assert(tenacious(2913) == true);

	for (i = 2018; i <= 2912; i++)
		assert(tenacious(i) == false);

	return 0;
}
