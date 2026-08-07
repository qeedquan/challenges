/*

Your task is to create a program that is to mimic Big Ben (Twitter).
https://twitter.com/big_ben_clock

Task
Whenever a new hour has begun (according to your computer's local time or UTC), you have to output BONG repeated hour times (with a space between the words). For example, when it's 3 o' clock, you have to output BONG BONG BONG. The time format follows the 12-hour time format, ie after 12 o' clock, we have 1 and not 13. The program/function must run forever.

Example:

don't output stuff inside the brackets

(start: 00:34 for example)
BONG               (01:00)
BONG BONG          (02:00)
(...)
BONG BONG BONG BONG BONG BONG BONG BONG BONG BONG BONG BONG (12:00)
BONG               (01:00 again)
(...)
(it continues forever)

Rules
Each series of BONGs must be separated by a newline
Leading/trailing newlines are allowed
However leading/trailing spaces are not allowed
The submission must run forever
Your output may be printed ±3 seconds from the beginning of the hour
You may not assume the program to be run at any specific hour

This is code-golf, so the program with the shortest bytecount wins!

*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>

struct tm
gettime(void)
{
	struct tm tm;
	time_t t;

	t = time(NULL);
	localtime_r(&t, &tm);
	return tm;
}

void
bong(int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("BONG");
		if (i + 1 < n)
			printf(" ");
	}
	printf("\n");
}

void
tictoc(void)
{
	struct tm t0, t1;
	int n;

	t0 = gettime();
	printf("Started at %02d:%02d\n", t0.tm_hour, t0.tm_min);
	for (;;) {
		t1 = gettime();
		if (t0.tm_hour != t1.tm_hour) {
			n = t1.tm_hour % 12;
			if (n == 0)
				n = 12;

			bong(n);

			t0 = t1;
		}
		sleep(1);
	}
}

int
main(void)
{
	tictoc();
	return 0;
}
