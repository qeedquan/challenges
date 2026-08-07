/*

Write a Regex that would test for a valid Swedish personal number (ID).

In Sweden this number is formatted multiple ways (I have no idea why) so you would have to check all these possibilities. Your task is to validate for any of these formats:

YYYYMMDD-XXXX

YYYYMMDD+XXXX

YYYYMMDDXXXX

The first set of digits ('YYYYMMDD') refers to the birth date and the four 'X's at the end are random numbers.

RegExp should test just for people born between year 1900 and 2016. Also consider all months to have at most 31 days (no need to validate February or other months with less).

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
getnum(const char *s, int n)
{
	int i, r;

	for (r = i = 0; i < n && s[i]; i++) {
		if (!isdigit(s[i]))
			return -1;
		r = (10 * r) + (s[i] - '0');
	}
	return r;
}

bool
validate(const char *s)
{
	const char *p;
	int y, m, d, x;

	y = getnum(s, 4);
	if (y < 1900 || y > 2016)
		return false;

	m = getnum(s + 4, 2);
	if (m < 1 || m > 12)
		return false;

	d = getnum(s + 6, 2);
	if (d < 1 || d > 31)
		return false;

	p = s + 8;
	if (*p == '-' || *p == '+')
		p++;

	x = getnum(p, 4);
	if (x < 0 || p[4])
		return false;

	return true;
}

int
main()
{
	assert(validate("190010130044") == true);
	assert(validate("19500220-4941") == true);

	assert(validate("201712204444") == false);
	assert(validate("181712204434") == false);

	return 0;
}
