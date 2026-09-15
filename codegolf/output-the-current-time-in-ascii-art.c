/*

Challenge
Your task is to output the time (in 12 hour time) in ascii art.

All characters that will be used are as follows:

  ___    __   ___    ____    _  _     _____     __    ______
 / _ \  /_ | |__ \  |___ \  | || |   | ____|   / /   |____  |
| | | |  | |    ) |   __) | | || |_  | |__    / /_       / /
| | | |  | |   / /   |__ <  |__   _| |___ \  | '_ \     / /
| |_| |  | |  / /_   ___) |    | |    ___) | | (_) |   / /
 \___/   |_| |____| |____/     |_|   |____/   \___/   /_/

   ___     ___
  / _ \   / _ \                                _
 | (_) | | (_) |   __ _ _ __    _ __ _ __     (_)
  > _ <   \__, |  / _` | '  \  | '_ \ '  \     _
 | (_) |    / /   \__,_|_|_|_| | .__/_|_|_|   (_)
  \___/    /_/                 |_|
(For each number/symbol individually, consult this gist).

You will receive input in an array of the form:

[hours, minutes, 'am/pm']. For example, [4, 57, 'am'], with single quotes only used for am/pm
or "hours-minutes-am/pm". For example, "4-56-am"
or [hours, 'minutes', 'am/pm'] for languages that cannot handle leading zeroes on numbers. For example, [4, '07', 'am']
You may use either input method.

Output will be in the form 1  2 : 5  9 am, where there is one initial space, two spaces between each number (in the gist, each number already has one space on each side), one space between : (colon) and the neighbouring numbers, and one space between the last number and am/pm, with an optional leading and/or trailing newline. All spaces are between the right-most point of the symbol on the left and the left-most point of the symbol on the right.

Implicit output is allowed.

Lowest byte size wins.

The am/pm are to be aligned such that the bottom of the p in pm is aligned with the bottom of the rest of the output, that is, the undercore denoting the top of am/pm starts on the third line down (not counting a leading newline).

The colon is to be aligned such that it's first character (an underscore) starts on the second line down (not counting a leading newline).

For minutes < 10, output the minutes with a leading 0 (you should receive this in the input). For example, [8, 04, 'pm'] -> 8 : 0  4 pm.

You must not fetch the data for the numbers from a library or external resource. All data must be contained within the program.

For example, for the input [12, 47, 'am'], the output would be as follows:

  __    ___          _  _      ______
 /_ |  |__ \    _   | || |    |____  |
  | |     ) |  (_)  | || |_       / /   __ _ _ __
  | |    / /    _   |__   _|     / /   / _` | '  \
  | |   / /_   (_)     | |      / /    \__,_|_|_|_|
  |_|  |____|          |_|     /_/
(If you see any edge cases that you can't decide what to do with, please post in comments and I will add them to examples).

*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void
uncompress(char *dst)
{
	static const char enc[] =
	    "!1`2!3`1!2`1!4`2!4`!1`!4`4!4`1!3`5!4`2!4`2!35^!`!]!1^`!}!}"
	    "`1!]!1}`2!]!1}!}1!}!2}!`3}!2^!^!2}`3!1}!2^!`!]!2^!`!]!31`!"
	    "}!}!}!}!1}!}!3*!}!2`1*!}!}!}1!}`!1}!}`1!3^!^`!6^!^!2}!)`*!"
	    "}!}!)`*!}!2`1!`!`!`1!3`!`1!`!`1!4)`*}!}!}!}!1}!}!2^!^!2}`1"
	    "!=!1}`1!2`}!}`2!]!1}!(`!]!4^!^!4?!`!=!2]`1-!}!1^!`a!}!(!1]"
	    "!1}!(`!]!(!1]!4`!}!}`}!}!1}!}!1^!^`!2`2*!}!3}!}!3`2*!}!}!)`"
	    "*!}!2^!^!4}!)`*!}!3^!^!2]`1-`}`}`}`}!}!/`1^`}`}`}!2)`*!]`2"
	    "^!2}`}!}`3}!}`3^!4}`}!2}`3^!2]`2^!2^`^!6]`2^!3^`^!16}`}!14";

	const char *src;
	char sym, val;

	src = enc;
	while (*src) {
		if (isdigit(*src)) {
			val = *src++ - '0';
			if (isdigit(*src))
				val = (val * 10) + (*src++ - '0');

			while (val--)
				*dst++ = sym;
		} else {
			sym = '0';
			if (*src != '^')
				sym = *src;

			src++;
			*dst++ = sym;
		}
	}
}

// ported from @jdt solution
int
timeart(int hour, int minute, const char *period)
{
	static const char offs[] = "8578988998>?3";
	static char syms[1024];
	static bool once;

	char buf[128], *ptr;
	char endchar;
	int start, end;
	int line;
	int n;

	if (!once) {
		uncompress(syms);
		once = true;
	}

	if (hour < 0 || hour > 12 || minute < 0 || minute > 59)
		return -1;

	if (!strcmp(period, "am"))
		endchar = ':';
	else if (!strcmp(period, "pm"))
		endchar = ';';
	else
		return -1;

	snprintf(buf, sizeof(buf), "%02d<%02d%c", hour, minute, endchar);

	for (line = 0; line < 666; line += 111) {
		for (ptr = buf; *ptr; ptr++) {
			start = line;
			for (n = 0; n < *ptr - '0'; n++)
				start += offs[n] - '0';

			end = offs[n] - '0';
			for (n = start; n < start + end; n++)
				putchar(syms[n] - 1);
		}
		putchar('\n');
	}

	return 0;
}

int
main()
{
	int totalhour, hour, minute;
	const char *period;

	for (totalhour = 0; totalhour < 24; totalhour++) {
		for (minute = 0; minute < 60; minute++) {
			hour = totalhour;
			period = "am";
			if (hour >= 12) {
				hour -= 12;
				period = "pm";
			}
			if (hour == 0)
				hour = 12;

			timeart(hour, minute, period);
		}
	}

	return 0;
}
