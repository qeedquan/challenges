#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
str2mon(const char *s)
{
	static const char *lut[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};

	size_t i;

	for (i = 0; i < nelem(lut); i++) {
		if (!strcmp(s, lut[i]))
			return i + 1;
	}
	return -1;
}

int
solve(const char *t1, const char *t2)
{
	char s1[16], s2[16];
	int m1, d1, y1;
	int m2, d2, y2;
	int r;

	if (sscanf(t1, "%15s %d, %d", s1, &d1, &y1) != 3)
		return -1;
	if (sscanf(t2, "%15s %d, %d", s2, &d2, &y2) != 3)
		return -1;

	m1 = str2mon(s1);
	m2 = str2mon(s2);
	if (m1 < 0 || m2 < 0)
		return -1;

	if (m1 > 2)
		y1++;
	if (m2 < 2 || (m2 == 2 && d2 < 29))
		y2--;

	r = (y2 / 4) - (y1 - 1) / 4;
	r -= (y2 / 100) - (y1 - 1) / 100;
	r += (y2 / 400) - (y1 - 1) / 400;
	return r;
}

int
main()
{
	assert(solve("January 12, 2012", "March 19, 2012") == 1);
	assert(solve("August 12, 2899", "August 12, 2901") == 0);
	assert(solve("August 12, 2000", "August 12, 2005") == 1);
	assert(solve("February 29, 2004", "February 29, 2012") == 3);

	return 0;
}
