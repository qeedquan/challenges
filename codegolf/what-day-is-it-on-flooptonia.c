/*

You are a space tourist on your way to planet Flooptonia! The flight is going to take another 47,315 years, so to pass the time before you're cryogenically frozen you decide to write a program to help you understand the Flooptonian calendar.

Here is the 208-day long Flooptonian calendar:

Month       Days    Input Range
Qupu        22      [0-22)
Blinkorp    17      [22-39)
Paas        24      [39-63)
Karpasus    17      [63-80)
Floopdoor   1       [80]
Dumaflop    28      [81-109)
Lindilo     32      [109-141)
Fwup        67      [141-208)

Challenge
Your program, given an integer day in the year (range [0-208)) is to output the corresponding day of the month and name of the month (e.g. 13 Dumaflop).

There is an exception, however: Floopdoor a special time for Flooptonians that apparently deserves its own calendar page. For that reason, Floopdoor isn't written with a day (i.e. the output is Floopdoor, not 1 Floopdoor).

Test Cases
0   => 1 Qupu
32  => 11 Blinkorp
62  => 24 Paas
77  => 15 Karpasus
80  => Floopdoor
99  => 19 Dumaflop
128 => 20 Lindilo
207 => 67 Fwup

Rules
You must write a complete program.
You can assume that the input is always valid.
Your output may have a trailing newline but must otherwise be free of any extra characters. The case should also match the provided examples.
You may use date/time functions.
Code length is to be measured in bytes.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
date(int d, char *b)
{
	static const struct Entry {
		char month[16];
		int start;
		int end;
	} tab[] = {
	    {"Qupu", 0, 21},
	    {"Blinkorp", 22, 38},
	    {"Paas", 39, 62},
	    {"Karpasus", 63, 79},
	    {"Floopdoor", 80, 80},
	    {"Dumaflop", 81, 108},
	    {"Lindilo", 109, 140},
	    {"Fwup", 141, 207},
	};

	const struct Entry *c;
	size_t i, l;

	for (i = 0; i < nelem(tab); i++) {
		c = tab + i;
		if (!(c->start <= d && d <= c->end))
			continue;

		l = 0;
		if (c->start != c->end)
			l += sprintf(b + l, "%d ", d - c->start + 1);
		sprintf(b + l, "%s", c->month);
		return b;
	}
	return NULL;
}

void
test(int d, const char *r)
{
	char b[128], *p;

	p = date(d, b);
	assert(p);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(0, "1 Qupu");
	test(32, "11 Blinkorp");
	test(62, "24 Paas");
	test(77, "15 Karpasus");
	test(80, "Floopdoor");
	test(99, "19 Dumaflop");
	test(128, "20 Lindilo");
	test(207, "67 Fwup");

	return 0;
}
