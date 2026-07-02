/*

"Y.M.C.A." is a popular disco song by the Village People that has a well-known dance. Write the shortest program to output the capital letters "Y", "M", "C", and "A" synchronized to the song's chorus.

Generally, one letter goes on each line sent to standard output. This primarily is to simplify programs subject to the output buffering of the C standard library (printing a newline flushes the output buffer), so you may omit any or all of these newlines if such omission would make your program shorter.

Your program, which is started at the same time as the music, must output the letter "Y" within 0.125 s of each of these times after starting (in seconds; I determined these from the music video posted on YouTube).

 45.766   49.611   60.889
 64.661  109.816  113.591
124.810  128.687  173.830
177.620  188.950  192.724
204.013  207.739  219.057
The letters "M", "C", and "A" respectively come 0.930 s, 1.395 s, and 1.628 s after each "Y". For testing purposes, these relative times are converted into absolute times by adding them to the time of the preceding "Y".

I have written a test program and corresponding example program in C that assume a newline follows each letter (although this is not a rule of competition). It is written for Linux and will not work on Windows without using Cygwin. If you cannot test your submission using the test program, at least check your submission against the YouTube video.

If your submission requires a special command-line option to behave properly, that command-line option counts when calculating your score. However, any interpreter startup time does not count against you, and the test program can be modified to accommodate that if necessary.

Although I doubt one exists, I must say that using a programming language function or library designed specifically for this task is prohibited.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
millisleep(long ms)
{
	struct timespec tp;
	int r;

	tp.tv_sec = ms / 1000;
	tp.tv_nsec = (ms % 1000) * 1000000L;

	do {
		r = clock_nanosleep(CLOCK_MONOTONIC, 0, &tp, &tp);
	} while (r && errno == EINTR);

	return r;
}

void
wait(double t)
{
	millisleep(t * 1000);
}

void
ymca()
{
	static const double beats[] = {45.8, 2.1, 9.5, 2, 43.4, 2, 9.5, 2.1, 43.4, 2, 9.6, 2, 9.5, 2, 9.6};
	static const double subbeats[] = {.1, .9, .5, .2};
	static const char lyrics[] = "YMCA";

	size_t i, j;

	for (i = 0; i < 15 * nelem(beats); i++) {
		wait(beats[i % nelem(beats)]);
		for (j = 0; j < nelem(subbeats); j++) {
			wait(subbeats[j]);
			printf("%c\n", lyrics[j]);
		}
	}
}

int
main()
{
	ymca();
	return 0;
}
