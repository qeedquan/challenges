/*

The cuckoo bird pops out of the cuckoo clock and chimes once on the quarter hour, half hour, and three-quarter hour.
At the beginning of each hour (1-12), it chimes out the hour.
Given the current time and a number n, determine the time when the cuckoo bird has chimed n  times.

Input Parameters:
initial_time - a string in the format "HH:MM", where 1 ≤ HH ≤ 12 and 0 ≤ MM ≤ 59, with leading 0’s if necessary.
n - an integer representing the target number of chimes, with 1 <= n <= 200.

Return Value: The time when the cuckoo bird has chimed n  times - a string in the same format as initial_time.

If the cuckoo bird chimes at initial_time, include those chimes in the count.
If the nth chime is reached on the hour, report the time at the start of that hour (i.e. assume the cuckoo finishes chiming before the minute is up).

Example: "03:38", 19   should return "06:00".
Explanation: It chimes once at "03:45", 4 times at "04:00", once each at "04:15", "04:30", "04:45", 5 times at "05:00", and once each at "05:15", "05:30", "05:45".
At this point it has chimed 16 times, so the 19th chime occurs when it chimes 6 times at "06:00".

Source: International Collegiate Programming Contest, North Central North American Regional, 2023.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
getchimes(int hour, int minute)
{
	if (minute % 15 != 0)
		return 0;
	if (minute != 0)
		return 1;
	return (hour > 12) ? 1 : hour;
}

char *
cuckooclock(const char *input, int chimes, char *output)
{
	int hour, minute;
	int count;

	if (sscanf(input, "%d:%d", &hour, &minute) != 2)
		return NULL;

	count = 0;
	while (count < chimes) {
		count += getchimes(hour, minute);
		if (count >= chimes)
			break;

		minute = (minute + 1) % 60;
		if (minute == 0)
			hour = (hour % 12) + 1;
	}

	sprintf(output, "%02d:%02d", hour, minute);
	return output;
}

void
test(const char *input, int chimes, const char *expected)
{
	char output[32];

	assert(cuckooclock(input, chimes, output));
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("07:22", 1, "07:30");
	test("12:22", 2, "12:45");
	test("01:30", 2, "01:45");
	test("04:01", 10, "05:30");
	test("03:38", 19, "06:00");

	test("10:00", 1, "10:00");
	test("10:00", 10, "10:00");
	test("10:00", 11, "10:15");
	test("10:00", 13, "10:45");
	test("10:00", 20, "11:00");

	test("12:30", 1, "12:30");
	test("12:30", 2, "12:45");
	test("12:30", 3, "01:00");
	test("12:30", 4, "01:15");
	test("09:53", 50, "02:30");

	test("08:17", 113, "08:00");
	test("08:17", 114, "08:15");
	test("08:17", 115, "08:30");
	test("08:17", 150, "11:00");
	test("08:17", 200, "05:45");

	return 0;
}
