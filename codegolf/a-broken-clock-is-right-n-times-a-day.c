/*

You will be provided with a string containing a digital clock. You must determine how many times per day that clock could be correct. You can ignore daylight savings time. You do not know if the clock is in 24 hour time, or if it's even a valid time at all (other than what you can determine from the input).

Input

A string containing a clock. E.g.: 02:30, 2:30, 2:30 PM, 14:30, 02:70, etc.

Can also be an array / list of characters if you prefer.

Output

A single number which is the maximum number of times a clock could display that time in a day, ignoring daylight savings.

Can be returned or printed.

Rules

Standard code-golf scoring.

There are only two categories of clocks: 12 hour clocks, and 24 hour clocks.

A valid 12 hour clock:

May or may not display AM or PM
Will display an hours place between 1-12
Will display a minutes place between 0-59
May or may not pad single digit hours with a leading zero
A valid 24 hour clock:

Will not display AM or PM
Will display an hours place between 0-23
Will display a minutes place between 0-59
May or may not pad single digit hours with a leading zero
For any test case which is not a valid 12 or 24 hour clock, n is 0. For all valid test cases, n is the maximum possible times in 1 day which the clock could be correct.

All test cases (regardless of if valid clocks or not):

Will start with 1-2 digits, followed by a colon :, followed by 2 digits, possibly followed by a space and then AM / PM
Test Cases

Format:
n,clock

2,2:30
2,02:30
1,14:30
1,2:30 PM
1,00:00
1,02:30 AM
0,14:30 PM
0,25:50
0,2:70
0,02:70 PM
0,14:70
0,00:00 AM
0,23:60
0,12:60 PM

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
righto(const char *s)
{
	int h, m, n;
	char p[4];

	n = sscanf(s, "%d:%d %2s", &h, &m, p);
	if (n != 3) {
		n = sscanf(s, "%d:%d", &h, &m);
		p[0] = '\0';
	}
	if (n != 2 && n != 3)
		return 0;

	if (!strcmp(p, "PM"))
		h += 12;
	else if (strcmp(p, "AM") && strcmp(p, ""))
		return 0;

	if (!(0 <= h && h <= 23))
		return 0;
	if (!(0 <= m && m <= 59))
		return 0;
	if (!h && p[0])
		return 0;
	if (p[0])
		return 1;

	if (h && h == ((h + 12) % 12))
		return 2;
	return 1;
}

int
main()
{
	assert(righto("2:30") == 2);
	assert(righto("02:30") == 2);
	assert(righto("14:30") == 1);
	assert(righto("2:30 PM") == 1);
	assert(righto("00:00") == 1);
	assert(righto("02:30 AM") == 1);
	assert(righto("14:30 PM") == 0);
	assert(righto("25:50") == 0);
	assert(righto("2:70") == 0);
	assert(righto("02:70 PM") == 0);
	assert(righto("14:70") == 0);
	assert(righto("00:00 AM") == 0);
	assert(righto("23:60") == 0);
	assert(righto("12:60 PM") == 0);

	return 0;
}
