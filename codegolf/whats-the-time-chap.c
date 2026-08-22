/*

I honestly cannot believe that this is not a question yet on Code Golf, but....

Print the local time (with a.m. or p.m.) as a string to the console, preceded by "It's ".

Example:

Run code....
Output:

It's 12:32p.m.
Shortest code wins.

Code away!

*/

#include <stdio.h>
#include <time.h>

void
daytime(void)
{
	char s[80], *m;
	struct tm tm;
	time_t t;

	t = time(NULL);
	localtime_r(&t, &tm);

	m = (tm.tm_hour < 12) ? "a.m" : "p.m.";
	strftime(s, sizeof(s), "%I:%M", &tm);
	printf("It's %s%s.\n", s, m);
}

int
main(void)
{
	daytime();
	return 0;
}
