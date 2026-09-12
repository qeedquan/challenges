/*

Create a BCD binary clock in ASCII. As implied, it shall display time in six columns of dots:

https://upload.wikimedia.org/wikipedia/commons/thumb/2/27/Binary_clock.svg/480px-Binary_clock.svg.png

(source: Wikimedia Commons)

Each column is a binary-coded digit, reading hours, minutes and seconds from left to right. Hours are given in 24-hour format.

The time to display is read from the command-line or from stdin (whichever fits better). If empty, the current time should be used instead.

Output size is a little constrained here and we can only fit two lines of text. So you are required to put the dots into only two lines. The characters ., : and ' come in handy here.

Input

The time to display in ISO-8601 format, i.e. HH:MM:SS without fractional seconds. Mandatory 24-hour format. Input can be empty in which case the current time will be used.

Output

Two lines with represent the BCD binary clock as in the image above. Each line is exactly six characters long and the only allowed characters are space, period, colon and apostrophe.

Winner

Shortest code by byte count wins. In a tie, the solution posted first wins.

Sample input 1


(empty)

Sample output 1

     .
''. ::
Sample input 2

17:59:20
Sample output 2

 ..'
.:..'
Sample input 3

01:08:01
Sample output 3

   '
 .   .

*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int
parseclock(const char *t, int *h, int *m, int *s)
{
	struct tm tm;
	char b[32];
	time_t t0;

	if (t == NULL || !strcmp(t, "")) {
		t0 = time(NULL);
		localtime_r(&t0, &tm);
		snprintf(b, sizeof(b), "%d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
		t = b;
	}

	if (sscanf(t, "%02d:%02d:%02d", h, m, s) != 3)
		return -1;
	return 0;
}

void
makeindex(int i[2][6], int h, int m, int s)
{
	int n;

	i[0][0] = (h / 10) >> 2;
	i[0][1] = (h % 10) >> 2;
	i[0][2] = (m / 10) >> 2;
	i[0][3] = (m % 10) >> 2;
	i[0][4] = (s / 10) >> 2;
	i[0][5] = (s % 10) >> 2;
	i[1][0] = h / 10;
	i[1][1] = h % 10;
	i[1][2] = m / 10;
	i[1][3] = m % 10;
	i[1][4] = s / 10;
	i[1][5] = s % 10;

	for (n = 0; n < 6; n++) {
		i[0][n] &= 3;
		i[1][n] &= 3;
	}
}

void
drawclock(int i[2][6])
{
	static const char sym[] = " .':";

	char l0[7], l1[7];
	int n;

	for (n = 0; n < 6; n++) {
		l0[n] = sym[i[0][n]];
		l1[n] = sym[i[1][n]];
	}
	l0[6] = '\0';
	l1[6] = '\0';

	puts(l0);
	puts(l1);
	puts("");
}

int
bcdclock(const char *t)
{
	int i[2][6];
	int h, m, s;

	if (parseclock(t, &h, &m, &s) < 0)
		return -1;

	makeindex(i, h, m, s);
	drawclock(i);
	return 0;
}

int
main()
{
	bcdclock("17:59:20");
	bcdclock("01:08:01");

	return 0;
}
