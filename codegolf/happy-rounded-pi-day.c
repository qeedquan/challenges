/*

To celebrate Rounded Pi Day, you must take advantage of today's date to make a program that takes in a circle's diameter and outputs its circumference by multiplying the diameter by 3.1416, where 3.1416 must be obtained using today's date.

Input 3
Output 9.4248
etc.
Does not take the date as input. You do not have to use all components of the date but the digits of pi must come from formatting a Date object or using a date object to obtain it. The answers so far look good.

Not sure what else to specify. All the answers so far meet what I was expecting.

My constraint was that you must use components of the date to come up with Pi. You can of course use the components, multiply by 0 then add 3.1416, but that's boring and wastes precious chars!

Shortest code wins!

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

double
pi(double x)
{
	char s[32];
	struct tm tm;

	memset(&tm, 0, sizeof(tm));
	tm.tm_mon = 2;
	tm.tm_mday = 14;
	tm.tm_year = 15;

	strftime(s, sizeof(s), "%m.%d%y", &tm);
	return atof(s) * x;
}

int
main()
{
	printf("%f\n", pi(3));
	return 0;
}
