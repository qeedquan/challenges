/*

You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:

    event1 = [startTime1, endTime1] and
    event2 = [startTime2, endTime2].

Event times are valid 24 hours format in the form of HH:MM.

A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).

Return true if there is a conflict between two events. Otherwise, return false.

Example 1:

Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
Output: true
Explanation: The two events intersect at time 2:00.

Example 2:

Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
Output: true
Explanation: The two events intersect starting from 01:20 to 02:00.

Example 3:

Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
Output: false
Explanation: The two events do not intersect.

Constraints:

    evnet1.length == event2.length == 2.
    event1[i].length == event2[i].length == 5
    startTime1 <= endTime1
    startTime2 <= endTime2
    All the event times follow the HH:MM format.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	char start[8];
	char end[8];
} Event;

int
str2time(const char *s)
{
	int h, m;

	if (sscanf(s, "%02d:%02d", &h, &m) != 2)
		return -1;
	if (!(0 <= h && h < 24) || !(0 <= m && m < 60))
		return -1;
	return (h * 60) + m;
}

bool
conflict(Event *a, Event *b)
{
	int a0, a1;
	int b0, b1;

	a0 = str2time(a->start);
	a1 = str2time(a->end);
	b0 = str2time(b->start);
	b1 = str2time(b->end);

	if (a0 < 0 || a1 < 0 || b0 < 0 || b1 < 0)
		return true;

	return a0 <= b1 && b0 <= a1;
}

int
main(void)
{
	Event a1 = {"01:15", "02:00"};
	Event b1 = {"02:00", "03:00"};

	Event a2 = {"01:00", "02:00"};
	Event b2 = {"01:20", "03:00"};

	Event a3 = {"10:00", "11:00"};
	Event b3 = {"14:00", "15:00"};

	assert(conflict(&a1, &b1) == true);
	assert(conflict(&a2, &b2) == true);
	assert(conflict(&a3, &b3) == false);

	return 0;
}
