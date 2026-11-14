/*

In the previous project, you created a low-pass filter, and the first project, you created an averaging filter. We will now introduce a simple recursive averaging low-pass filter.

Given a value 0<α<1, the output of a signal is given by

y[n]=αx[n]+(1−α)y[n−1]

meaning that the next output is created by taking a weighted average of of the current value and the previous output.

Enter a value of alpha: 0.5
Enter a file name: data.txt

For example, if the input file contains the following ten numbers:

0.396
0.193
0.0224
0.800
0.428
0.843
0.412
0.996
0.386
0.695
your output will be:

0.198
0.1955
0.10895
0.454475
0.4412375
0.64211875
0.527059375
0.7615296875
0.57376484375
0.634382421875
If your input file is a constant value, this filter does not change that value—it allows a constant function to go through unchanged.

On the other hand, if you give it an alternating input:

 1
-1
 1
-1
 1
-1
 1
-1
 1
-1
 1
-1
 1
-1
you will notice something odd about the output:

 0.5
-0.25
 0.375
-0.3125
 0.34375
-0.328125
 0.3359375
-0.33203125
 0.333984375
-0.3330078125
 0.33349609375
-0.333251953125
 0.3333740234375
-0.33331298828125

You will note that it allows the high frequency to go through, but it attenuates that signal by a factor of 1/3

Exercise: How is the alternating signal affected if the value of α is closer to 1, and how is the signal affected if the value of α is closer to 0?

Thus, this filter is another example of a low-pass filter.

Infinite impulse response filters
This filter is said to have a infinite impulse response, meaning that if you give it a single "1", the effect on the output never ends; it may be diminished, but it never really disappears.

0
1
0
0
0
0
0
0
0
0

the output will be:

0
0.5
0.25
0.125
0.0625
0.03125
0.015625
0.0078125
0.00390625
0.001953125

References
For further reading on this filter, please see this excellent web site:

zipcpu.com

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
usage(void)
{
	fprintf(stderr, "usage: <alpha> [file]\n");
	exit(2);
}

void
filter(FILE *fp, double a)
{
	double x, y;

	y = 0;
	while (fscanf(fp, "%lf", &x) == 1) {
		y = (a * x) + (1 - a) * y;
		printf("%f\n", y);
	}
}

int
main(int argc, char *argv[])
{
	FILE *fp;
	double a;

	if (argc < 2)
		usage();

	a = atof(argv[1]);
	fp = stdin;
	if (argc >= 3)
		fp = fopen(argv[2], "rb");

	if (!fp)
		fatal("Failed to open file: %s", strerror(errno));

	filter(fp, a);
	fclose(fp);
	return 0;
}
