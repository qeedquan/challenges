/*

In the previous project, you created an averaging filter. We will now introduce a simple low-pass filter. To understand the purpose of such a filter, we must first understand frequencies.

Every signal can be thought of as either in the:

time domain, meaning that it is a succession of values that change over time; or frequency domain, meaning that it is a combination of singles, each with a specific frequency.
For example, when you hear a flute play, you can think of the sound as it is produced, and each time a note is played, your ear responds to the changes over time.
Alternatively, suppose you play a middle C on a flute. But you don't just hear a middle C; if you listen carefully, you will also hear at approximately half the intensity, a C one octave higher, and you will also hear at approximately half that intensity, then next higher G and C. This combination of frequencies is what makes a flute sound different from, for example, a saxophone.

For a saxophone, playing a middle C also allows you to hear a much louder C one octave higher, but while the next higher G is at the same intensity as that of the flute, the next higher C is less intense.

Understanding the combination of frequencies allows music synthesizers to artificially recreate the sound of most instruments, and even create sounds that no physical musical instrument makes.

Now, you also understand that there are high frequencies and low frequencies. A low-pass filter is a filter that ignores high frequencies while allowing low frequencies to pass through.

A simple low-pass filter is to wait for one value to come, and after the next, the calculated value is the sum of the current value plus the most recent value. Like the previous program, this program will read a text file:

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

0.589
0.2154
0.8224
1.228
1.271
1.255
1.408
1.382
1.081

To understand why this is a low-pass filter, you will notice that if your input file is a constant value, this filter amplifies that constant value by a factor of two:

0.396
0.396
0.396
0.396
0.396

your output will be:

0.792
0.792
0.792
0.792

If, however, you give it an input file that alternates between positive and negative, the highest frequency you can get, the output is zero:

 0.396
-0.396
 0.396
-0.396
 0.396

your output will be:

0
0
0
0

Now, if you have a signal that combines a constant signal and an alternating signal, the constant signal is amplified by a factor of two, while the alternating signal is eliminated. This file contains the values 0.473 ± 0.081, but the output will simply be double the first value:

0.554
0.392
0.554
0.392
0.554

and your output will be:

0.946
0.946
0.946
0.946

Let us now pick a frequency that has a larger period:

 0
 0.865
-0.865
 0
 0.865
-0.865
 0
 0.865
-0.865
 0
.865

The output is:

 0.865
 0
-0.865
 0.865
 0
-0.865
 0.865
 0
-0.865
 0.865

 You will note that this is the output signal multiplied by -1 and delayed, but neither amplified nor attenuated.

Finite impulse response filters
This filter is said to have a finite impulse response, meaning that if you give it a single "1", the effect on the output ends after a fixed number of steps—in this case, two. Given this input file:

0
0
1
0
0
0
the output will be:

0
1
1
0
0
An averaging filter is also a finite-impulse response. If your averaging filter averaged the five most recent values, the output of

0
0
0
0
0
1
0
0
0
0
0
0
the output will be:

0
0.2
0.2
0.2
0.2
0.2
0.2
0
0
After five steps, the effect of the single "1" is lost.

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
lowpass(FILE *fp)
{
	double x, xp;

	if (fscanf(fp, "%lf", &xp) != 1)
		return;

	while (fscanf(fp, "%lf", &x) == 1) {
		printf("%f\n", x + xp);
		xp = x;
	}
}

int
main(int argc, char *argv[])
{
	FILE *fp;

	fp = stdin;
	if (argc >= 2)
		fp = fopen(argv[1], "rb");

	if (!fp)
		fatal("Failed to open file: %s", strerror(errno));

	lowpass(fp);
	fclose(fp);
	return 0;
}
