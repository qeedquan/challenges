/*

Your challenge is to write a program that takes input from stdin, creates a set of 1 to ncolors and outputs them on stdout, formatted as a 6-digit-hex value with a prefixed #.

The starting color should have following values (in a hsv colorspace) (pesudocode)
h=rand(), s=0.5, v=0.95.
Every subsequent color should have its hue value increased by
1/Φ
After every 5th color, the saturation and value for the forthcoming colors should be
saturation - increased by 0.1
value - decreased by 0.2
e.g.

Color  #    h         s       v
       1  0.5        0.5     0.95
       2  0.118...   0.5     0.95
      11  0.680...   0.7     0.55
Input

Your program shall receive an Integer nas input (stdin), which defines the number of colors, to be generated. Where 0 < n < 16

Output

On each call, the hues' start value should be different from the last call (Don't just take the same random start number on every call)
Output should be on stdout with one color per line.
The array shall contain n different hex codes.
The hex codes should be prefixed with a "#" and be padded with a "0", such that you always get a 7 character string like "#FFFFFF"
Additional Rules

The use of built in functions/tools/etc for the following conversions is forbidden
HSV->RGB
RGB->HEX representation of RGBa function which specifically converts rgb to hex, generic tools like sprintf are ok.
HSV->HEX representation of RGBjust to make sure...
Scoring

The size of your code in bytes.

Test Cases(result of rand() in parantheses)

3 (0.35389856481924653) ->
    #79f388
    #f3798e
    #79b1f3

8 (0.763850917108357) ->
    #c079f3
    #79f39d
    #f37979
    #4c6ec0
    #90c04c
    #c04cb1
    #4cc0ac
    #c08b4c

15 (0.10794945224188268) ->
    #f3c879
    #a479f3
    #79f381
    #f37995
    #79b8f3
    #aac04c
    #b44cc0
    #4cc092
    #c0704c
    #4f4cc0
    #448c2a
    #8c2a61
    #2a7e8c
    #8c7e2a
    #612a8c
for a visualization of the codes, you can paste your output here

I will change the accepted Answer, as soon as new appear

*/

#include <stdio.h>
#include <math.h>

#define PHI 1.618033988749895

void
hsv2rgb(double *r, double *g, double *b, double h, double s, double v)
{
	double c, hp, x, m;

	c = v * s;
	hp = fmod(h / 60.0, 6);
	x = c * (1 - fabs(fmod(hp, 2) - 1));
	m = v - c;

	if (0 <= hp && hp < 1) {
		*r = c;
		*g = x;
		*b = 0;
	} else if (1 <= hp && hp < 2) {
		*r = x;
		*g = c;
		*b = 0;
	} else if (2 <= hp && hp < 3) {
		*r = 0;
		*g = c;
		*b = x;
	} else if (3 <= hp && hp < 4) {
		*r = 0;
		*g = x;
		*b = c;
	} else if (4 <= hp && hp < 5) {
		*r = x;
		*g = 0;
		*b = c;
	} else if (5 <= hp && hp < 6) {
		*r = c;
		*g = 0;
		*b = x;
	} else {
		*r = 0;
		*g = 0;
		*b = 0;
	}

	*r += m;
	*g += m;
	*b += m;
}

void
colorset(int n, double h)
{
	double s, v;
	double r, g, b;
	int i;

	printf("n=%d (%f)\n", n, h);
	s = 0.5;
	v = 0.95;
	for (i = 1; i <= n; i++) {
		hsv2rgb(&r, &g, &b, h * 360, s, v);
		r *= 256;
		g *= 256;
		b *= 256;

		printf("#%02x%02x%02x\n", (int)r, (int)g, (int)b);

		h = fmod(h + (1 / PHI), 1);
		if (!(i % 5)) {
			s += 0.1;
			v -= 0.2;
		}
	}
	printf("\n");
}

int
main()
{
	colorset(3, 0.35389856481924653);
	colorset(8, 0.763850917108357);
	colorset(15, 0.10794945224188268);

	return 0;
}
