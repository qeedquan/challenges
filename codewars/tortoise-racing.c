/*

Two tortoises named A and B must run a race. A starts with an average speed of 720 feet per hour. Young B knows she runs faster than A, and furthermore has not finished her cabbage.

When she starts, at last, she can see that A has a 70 feet lead but B's speed is 850 feet per hour. How long will it take B to catch A?

More generally: given two speeds v1 (A's speed, integer > 0) and v2 (B's speed, integer > 0) and a lead g (integer > 0) how long will it take B to catch A?

The result will be an array [hour, min, sec] which is the time needed in hours, minutes and seconds (round down to the nearest second) or a string in some languages.

If v1 >= v2 then return nil, nothing, null, None or {-1, -1, -1} for C++, C, Go, Nim, Pascal, COBOL, Erlang, [-1, -1, -1] for Perl,[] for Kotlin or "-1 -1 -1" for others.

Examples:
(form of the result depends on the language)

race(720, 850, 70) => [0, 32, 18] or "0 32 18"
race(80, 91, 37)   => [3, 21, 49] or "3 21 49"
Note:
See other examples in "Your test cases".

In Fortran - as in any other language - the returned string is not permitted to contain any redundant trailing whitespace: you can use dynamically allocated character strings.

** Hints for people who don't know how to convert to hours, minutes, seconds:

Tortoises don't care about fractions of seconds
Think of calculation by hand using only integers (in your code use or simulate integer division)
or Google: "convert decimal time to hours minutes seconds"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
race(int speed1, int speed2, int lead, int result[3])
{
	double seconds;
	int hours;
	int minutes;

	if (speed1 >= speed2) {
		result[0] = result[1] = result[2] = -1;
		return;
	}

	seconds = (lead * 3600.0) / (speed2 - speed1);
	minutes = seconds / 60;
	hours = minutes / 60;

	result[0] = hours;
	result[1] = minutes - (60 * hours);
	result[2] = seconds - (60 * result[1]) - (3600 * hours);
}

void
test(int speed1, int speed2, int lead, int expected[3])
{
	int result[3];

	race(speed1, speed2, lead, result);
	printf("%d %d %d\n", result[0], result[1], result[2]);
	assert(!memcmp(result, expected, sizeof(result)));
}

int
main()
{
	int expected1[] = {0, 32, 18};
	int expected2[] = {3, 21, 49};
	int expected3[] = {-1, -1, -1};
	int expected4[] = {2, 11, 15};

	test(720, 850, 70, expected1);
	test(80, 91, 37, expected2);
	test(820, 81, 550, expected3);
	test(386, 434, 105, expected4);

	return 0;
}
