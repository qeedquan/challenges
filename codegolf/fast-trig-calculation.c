/*

Fast Trigonometry Calculations
Your task is to create a program which can calculate the sine, cosine and tangent of an angle in degrees.

Rules
No built-in trigonometry functions (not even secant, cosecant and cotangent if your language has them).
You may use lookup tables, but their total size must not exceed 3000 members (for all of the three operations put together). Please make it read the tables from a file (e.g. trig.lookup) so they don't confuse the code.
No network access.
You must correctly round your output as explained below. Don't use floor or ceiling.
You may use any method to calculate the values, for example continued fractions, as long as it is correct to 7 significant figures.
Your code must be able to time itself. Exclude the file I/O operations from your time - so just time the function(s) that do(es) the trig and any rounding.
I must be able to run your code. Please post a link to a freely available compiler/interpreter and give the instructions needed to compile/run the code (e.g. what options to pass to GCC).
Standard loopholes apply.
Input Format
Read from a file called trig.in unless your language doesn't support file I/O.
Angles are between 0 and 360 inclusive.
Input will consist of angles to ten significant figures in decimal digits, separated by new lines. For example:
90.00000000
74.54390000
175.5000000

Output Format
For each angle supplied, you must output its sine, cosine and tangent to 7 significant figures, separated by spaces, on a single line. Use "scientific notation", e.g. 1.745329E-5 for tan 0.001 or 1.000000E+0 for sin 90.
Denote infinity or NaN by n, for example the output for 90.00000000 should be 1.000000 0.000000 n.
If the input is three angles separated by newlines, your output should consist of three lines, each containing the sine, cosine and tangent.
You may not output anything else.
Output to a file called trig.out unless your language does not support file I/O.
Scoring
fastest-code. The challenge is to write a program which computes these three values as quickly as possible. Fastest time wins.
Everyone will receive the same test input of many angles.
Times will be recorded on my machine.
Your score is the average of three runs on the same input (you can't save anything in between runs obviously).
Compiling time not included. This challenge is more about the method used than the language. (If someone could point me to how I would exclude compilation time for languages such as Java, I'd be very grateful)
My machine is an Ubuntu 14.04 install. The processor's stats are on Pastebin (obtained by running cat /proc/cpuinfo).
I will edit your time into your answer when I've tested it.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

// Cordic in 32 bit signed fixed point math
// Function is valid for arguments in range -pi/2 -- pi/2
// for values pi/2--pi: value = half_pi-(theta-half_pi) and similarly for values -pi---pi/2
//
//  1.0 = 1073741824
//  1/k = 0.6072529350088812561694
//  pi = 3.1415926536897932384626
// Constants
#define cordic_1K 0x26DD3B6A
#define half_pi 0x6487ED51
#define MUL 1073741824.000000
#define CORDIC_NTAB 32

static const int cordic_ctab[] = {
    0x3243F6A8,
    0x1DAC6705,
    0x0FADBAFC,
    0x07F56EA6,
    0x03FEAB76,
    0x01FFD55B,
    0x00FFFAAA,
    0x007FFF55,
    0x003FFFEA,
    0x001FFFFD,
    0x000FFFFF,
    0x0007FFFF,
    0x0003FFFF,
    0x0001FFFF,
    0x0000FFFF,
    0x00007FFF,
    0x00003FFF,
    0x00001FFF,
    0x00000FFF,
    0x000007FF,
    0x000003FF,
    0x000001FF,
    0x000000FF,
    0x0000007F,
    0x0000003F,
    0x0000001F,
    0x0000000F,
    0x00000008,
    0x00000004,
    0x00000002,
    0x00000001,
    0x00000000,
};

// https://www.dcs.gla.ac.uk/~jhw/cordic/
void
cordic(int theta, int *s, int *c, int n)
{
	int k, d, tx, ty, tz;
	int x, y, z;

	x = cordic_1K;
	y = 0;
	z = theta;
	if (n > CORDIC_NTAB)
		n = CORDIC_NTAB;
	for (k = 0; k < n; ++k) {
		d = (z >= 0) ? 0 : -1;
		tx = x - (((y >> k) ^ d) - d);
		ty = y + (((x >> k) ^ d) - d);
		tz = z - ((cordic_ctab[k] ^ d) - d);
		x = tx;
		y = ty;
		z = tz;
	}
	*c = x;
	*s = y;
}

int
main(void)
{
	double p;
	int s, c;
	int i;

	for (i = 0; i < 50; i++) {
		p = (i / 50.0) * M_PI / 2;
		cordic((p * MUL), &s, &c, 32);
		printf("%+f %+f | %+f %+f\n", s / MUL, c / MUL, sin(p), cos(p));
	}
	return 0;
}
