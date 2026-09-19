/*

The RULES
Each submission must be a full program.
The program takes no input and prints the time in milliseconds until Trump leaves office to the standard output.
So pretty much the title.
Write a program that shows the time until the expiration of Trump's presidential term in milliseconds.
Submissions are scored in bytes.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef long long vlong;

vlong
timeframe()
{
	struct timespec tp;
	struct tm tm;
	time_t t;
	vlong ms;

	clock_gettime(CLOCK_REALTIME, &tp);
	memset(&tm, 0, sizeof(tm));
	tm.tm_hour = 12;
	tm.tm_mon = 1;
	tm.tm_mday = 20;
	tm.tm_year = 129;
	t = mktime(&tm);

	ms = 0;
	if (tp.tv_sec < t) {
		ms += (t - tp.tv_sec) * 1000;
		ms += tp.tv_nsec / 1000000;
	}

	return ms;
}

int
main()
{
	printf("%lld\n", timeframe());
	return 0;
}
