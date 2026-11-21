/*

Upon receiving month and year in YYYYMM format, generate output of the corresponding calendar month for that year.

For example the input 201312 should generate the following output:

Mo Tu We Th Fr Sa Su
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31

Only trick is, NO native calendar generating functions... so Linux clones, no "cal" function... Muahahahahah!

PS: The calendar must start out with Monday as the left-most day, this is to ensure that the output is like the "cal" function, but does not output like "cal", which has Sunday as its left-most day...

Smallest code size wins.

*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dayadd(struct tm *tm)
{
	time_t t;

	tm->tm_hour = 0;
	tm->tm_min = 0;
	tm->tm_sec = 0;
	tm->tm_mday++;
	t = mktime(tm);
	gmtime_r(&t, tm);
}

int
calendar(const char *s)
{
	static const char wday[][4] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

	struct tm tm;
	time_t t;
	size_t i, w;
	int d, m, y;

	if (sscanf(s, "%04d%02d", &y, &m) != 2)
		return -1;

	for (i = 0; i < nelem(wday); i++)
		printf("%2s ", wday[i]);
	printf("\n");

	memset(&tm, 0, sizeof(tm));
	tm.tm_year = y - 1900;
	tm.tm_mon = m - 1;
	tm.tm_mday = 1;

	t = mktime(&tm);
	gmtime_r(&t, &tm);

	w = (tm.tm_wday == 0) ? 6 : tm.tm_wday - 1;
	for (i = 0; i < w; i++)
		printf("%3s", " ");

	for (d = 1; d <= 31; d++) {
		printf("%2d ", d);
		if (++w >= nelem(wday)) {
			printf("\n");
			w = 0;
		}

		dayadd(&tm);
		if (m != tm.tm_mon + 1)
			break;
	}

	printf("\n\n");
	return 0;
}

int
main(void)
{
	calendar("200001");
	calendar("200103");
	calendar("201312");
	calendar("200102");

	return 0;
}
