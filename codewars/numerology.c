/*

In numerology, every number has a certain meaning that expresses someones connection to the universe! This single digit integer can be calculated by adding up every digit in the birthdate: year, month, and date.

Task
Calculate the single integer digit by adding up every digit in the birthdate: month, date, full year, from left to right (MMDDYYYY). If the sum is greater or equal to 10, add up the two digits of the sum.

You will be passed in a Date object corresponding to your language.

Example
For example, with date '06/14/2010'

=> 06142010

sum	digits left	action

0	06142010	0+0
0	6142010	0+6
6	142010	6+1
7	42010	7+4
11	2010	1+1 (sum is greater or equal to 10)
2	2010	2+2
4	010	4+0
4	10	4+1
5	0	5+0
5	done

So, what is your number?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
numerology(const char *s)
{
	static const char fmt[] = "dd/dd/dddd";

	size_t i;
	int r;

	r = 0;
	for (i = 0; fmt[i]; i++) {
		switch (fmt[i]) {
		case 'd':
			if (!isdigit(s[i]))
				return -1;

			r += s[i] - '0';
			if (r >= 10)
				r = (r / 10) + (r % 10);
			break;

		default:
			if (s[i] != fmt[i])
				return -1;
			break;
		}
	}
	return r;
}

int
main()
{
	assert(numerology("10/13/1964") == 7);
	assert(numerology("01/02/2008") == 4);
	assert(numerology("06/14/2010") == 5);
	assert(numerology("02/04/2010") == 9);
	return 0;
}
