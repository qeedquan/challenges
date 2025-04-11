/*

This is inspired by one of Downgoat's questions in Sandbox, where I suggested that he include April 31 as Pi day for people who use day/month format, only for him to inform me that there is no April 31!

Given a date string in month/day format that might be invalid, output the correct date using rollover. (First rollover the month, then rollover the day).

Examples:

"15/43" - This reads as the 43rd day of the 15th month. First, we roll over the month to the next year, so we end up with 3 (March). Now, since March only has 31 days, we rollover the extra days to April, so we output the actual date as "4/12" (April 12th).

"3/16" - This is a valid date (March 16th). Return it as is.

"12/64" - Ah, so many fond memories from December 64th... December has 31 days, January has 31 days, so what I really mean is "2/2" (February 2nd).

"19/99" - First, the 19 becomes a 7 (July). July has 31 days, August has 31 days, September has 30 days, so the output is "10/7" (October 7th).

"1/99999" - A year has 365 days. 99999 (mod 365) = 354. The 354 day of the year is "12/20".

"9999999/10" - Apparently, 9999999 (mod 12) = 3, so this is "3/10" (March 10th).

Criteria:

Input month is an integer > 0. Input day is an integer > 0. Year never needs to be specified, as such there are no leap years to deal with.

Update:

As I think it would overly simplify the challenge, calendar functions, such as those in the Java Calendar class, are banned. Date parsing/formatting functions are still allowed though.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

char *
calendar(const char *s, char *b)
{
	static const uvlong days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	uvlong m, d;

	if (sscanf(s, "%llu/%llu", &m, &d) != 2 || m == 0)
		return NULL;

	m = (m - 1) % 12;
	while (d > days[m]) {
		d -= days[m];
		m = (m + 1) % 12;
	}

	sprintf(b, "%llu/%llu", m + 1, d);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	calendar(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("15/43", "4/12");
	test("3/16", "3/16");
	test("12/64", "2/2");
	test("19/99", "10/7");
	test("1/99999", "12/20");
	test("9999999/10", "3/10");

	return 0;
}
