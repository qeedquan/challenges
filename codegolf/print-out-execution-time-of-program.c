/*

Challenge
Write a complete program that prints out the time it took to execute a certain part of itself. That part must include a process whose total number of operations (and therefore execution time) is dependent on a user-substituted numeric value - this can be denoted in any way in your code (uppercase N for example) and doesn't count as a byte.

Unlike many code golf challenges, this one is a valid use case - in environments that allow executing code from command line, you may want to have a short code snippet to roughly compare performance across different systems.

Rules
Execution time is denoted as a nonnegative integer or decimal value, followed by the corresponding time unit (let's accept ns, µs/us, ms, s, m and h). A space between the number and unit is optional, more spaces are also allowed (but not newline characters).
Output must include the execution time exactly once. There can be additional text around it, as long as no part of it could be matched with the execution time itself. This allows using standard functions for timing code execution that may use various formats for printing out the execution time.
Output goes to STDOUT. Anything in STDERR is disregarded.
You can import any standard libraries before the actual code, without any cost to the total number of bytes, but you are not allowed to change the library name in the import declaration.
Do not just use sleep to control the execution time, as that does not increase the number of operations (and also doesn't work as a performance benchmark). The execution time must also depend on the user-substituted value linearly, exponentially or polynomially (before you ask, a constant polynomial doesn't count).
Scoring
This is code golf, so the shortest answer in bytes wins.

Example
This is an unnecessarily long program written in Python:

import time

start_time = time.time()

for i in range(N):
    pass

end_time = time.time()

print("%fs" % (end_time - start_time))
Program description:

imports the standard time library (this adds no bytes to the code size)
stores the current time in seconds
loops N times, does nothing each iteration
stores the time after the loop
prints the time difference in the correct format

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

typedef struct {
	struct timespec start;
	struct timespec end;
} Prof;

void
profbegin(Prof *p)
{
	clock_gettime(CLOCK_MONOTONIC, &p->start);
}

void
profend(Prof *p)
{
	clock_gettime(CLOCK_MONOTONIC, &p->end);
}

void
profsum(Prof *p)
{
	printf("Start: %jd %jd\n", (intmax_t)p->start.tv_sec, (intmax_t)p->start.tv_nsec);
	printf("End:   %jd %jd\n", (intmax_t)p->end.tv_sec, (intmax_t)p->end.tv_nsec);
}

int
main()
{
	Prof p[1];
	long i, N;
	int x;

	N = 1000000;
	profbegin(p);
	srand(1);
	x = 0;
	for (i = 0; i < N; i++)
		x ^= rand();
	profend(p);
	profsum(p);

	return 0;
}
