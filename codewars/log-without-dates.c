/*

You will be given an array of events, which are represented by strings. The strings are dates in HH:MM:SS format.

It is known that all events are recorded in chronological order and two events could not occur in the same second. Define the minimum number of days during which the log is written.

Example:

Input -> ["00:00:00", "00:01:11", "02:15:59", "23:59:58", "23:59:59"]
Output -> 1

Input -> ["12:12:12"]
Output -> 1

Input -> ["12:00:00", "23:59:59", "00:00:00"]
Output -> 2

Good luck

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
next(const char *l)
{
	int h, m, s;

	sscanf(l, "%d:%d:%d", &h, &m, &s);
	if (!(0 <= s && s <= 59))
		return -1;
	if (!(0 <= m && m <= 59))
		return -1;
	if (!(0 <= h && h <= 23))
		return -1;
	return (h * 3600) + (m * 60) + s;
}

int
checklogs(const char **l, size_t n)
{
	int d0, d1, r;
	size_t i;

	if (n == 0)
		return 0;

	if ((d0 = next(l[0])) < 0)
		return -1;

	r = 1;
	for (i = 1; i < n; i++) {
		if ((d1 = next(l[i])) < 0)
			return -1;

		if (d1 <= d0)
			r += 1;
		d0 = d1;
	}
	return r;
}

int
main()
{
	const char *l1[] = { "00:00:00", "00:01:11", "02:15:59", "23:59:58", "23:59:59" };
	const char *l2[] = { "12:12:12" };
	const char *l3[] = { "12:00:00", "23:59:59", "00:00:00" };
	const char *l4[] = { "12:00:00", "12:00:00", "00:00:00" };

	assert(checklogs(l1, nelem(l1)) == 1);
	assert(checklogs(l2, nelem(l2)) == 1);
	assert(checklogs(l3, nelem(l3)) == 2);
	assert(checklogs(l4, nelem(l4)) == 3);
	assert(checklogs(NULL, 0) == 0);

	return 0;
}
