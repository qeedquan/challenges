/*

Ptolemy's Almagest contains a table of chords that effectively served as the world's only comprehensive trigonometric table for over a millennium. In modern form it looks like this:

https://en.wikipedia.org/wiki/Ptolemy%27s_table_of_chords

The table has 360 lines, each in the following format:

An angle θ in degrees, ranging from ½° to 180° inclusive in ½° increments.
The chord length subtended by θ in a circle of radius 60. This length is equal to c(θ)=120*sin(θ/2) and is given as three numbers: the integer part comes first and the first and second sexagesimal (base 60) digits follow.
A "sixtieths" column used for linear interpolation, giving (c(θ+1/2∘)−c(θ))/30. This follows a similar format to the chords column but lists three sexagesimal digits; the integer part is always 0 and has been omitted in the table above for brevity (it was written out in the original). Also note that 0 appears in this column at 180° instead of a negative value as the formula would imply.

Task
Output all 360 lines of the table, each containing seven numbers – without the zero integer parts of the sixtieths column – as described above:

0.5 [0, 31, 25] [1, 2, 50]
1.0 [1, 2, 50] [1, 2, 50]
1.5 [1, 34, 15] [1, 2, 49]
2.0 [2, 5, 39] [1, 2, 49]
2.5 [2, 37, 4] [1, 2, 49]
3.0 [3, 8, 28] [1, 2, 48]
3.5 [3, 39, 53] [1, 2, 48]
4.0 [4, 11, 17] [1, 2, 47]
...
176.5 [119, 56, 39] [0, 1, 47]
177.0 [119, 57, 32] [0, 1, 30]
177.5 [119, 58, 17] [0, 1, 14]
178.0 [119, 58, 54] [0, 0, 58]
178.5 [119, 59, 23] [0, 0, 41]
179.0 [119, 59, 44] [0, 0, 25]
179.5 [119, 59, 56] [0, 0, 8]
180.0 [120, 0, 0] [0, 0, 0]

The separation between lines and between numbers in a line must be clear, but is otherwise unrestricted. Rounding in the last sexagesimal place should be to the nearest integer – this makes the table to be output here not exactly correspond with Ptolemy's original, i.e. the first and last lines should match the code block above.

This is code-golf; fewest bytes wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180)

double
angle(double x)
{
	return (120 * sin(deg2rad(x / 2))) * 3600;
}

void
chord(double x, double c[3])
{
	double a, y, z, w;

	a = 3600;
	y = floor(x / a);
	z = floor((x - y * a) / 60);
	w = x - (y * a) - (z * 60);

	c[0] = y;
	c[1] = z;
	c[2] = w;
}

void
table(void)
{
	double c[3], cs[3];
	double x, x0, x1;
	int i;

	for (i = 1; i <= 360; i++) {
		x = i * 0.5;
		x0 = angle(x);
		x1 = fmax(angle(x + 0.5) - angle(x), 0) * 2;

		x0 = round(x0);
		x1 = round(x1);

		chord(x0, c);
		chord(x1, cs);

		printf("%.1f [%.0f %.0f %.0f] [%.0f %.0f %.0f]\n",
		       x, c[0], c[1], c[2], cs[0], cs[1], cs[2]);
	}
}

int
main(void)
{
	table();
	return 0;
}
