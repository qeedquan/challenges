/*

Imagine we want to output some line chart, representing the change of some value (like temperature or stock price) over sequence of days - but we have only text output (either alpha numeric display or printer). This was a common situation years ago - but even nowadays such problem happens when printing to text files, some kinds of electronics displays, POS-terminal paper slips etc.

Let's try to do this - for given sequence of values, print a chart in exactly 10 lines. Some auto-scaling needs to be done, of course: find the minimum and maximum value, and divide range between them into 10 equal subranges. For each value put an asterisk higher or lower, according to your subranges boundaries.

Input
The first line gives N - total amount of values.
The next line has these N values, space separated.

Answer should provide the chart in 10 lines, as explained above.

Example

input (long line wrapped):
74
10.184 8.835 6.928 4.656 2.396 0.500 -1.644 -3.687 -5.399 -6.562 -6.999 -6.603 -5.380 -3.479 -1.217 0.912
    2.087 3.558 5.642 7.811 9.644 10.773 10.938 10.055 8.270 5.969 3.732 2.236 1.728 0.295 -1.842 -4.134
    -6.005 -6.949 -6.673 -5.204 -2.929 -0.512 1.304 1.996 2.435 3.942 6.207 8.607 10.406 10.994 10.127
    8.063 5.502 3.321 2.169 1.984 1.381 -0.282 -2.719 -5.180 -6.762 -6.813 -5.265 -2.720 -0.181 1.467
    1.987 2.072 2.852 4.735 7.363 9.795 10.977 10.327 8.108 5.325 3.139 2.141

output:
*                   ****                    ***                    ***
 *                 *    *                  *   *                      *
  *               *      *                *                       *
   *                                     *      *                *     *
    *           **        **            *        **            **       **
     *         *            **        **           **        **
              *                      *               *      *
      *                       *     *                 *    *
       *     *                 *                       *
        *****                   ****                    ***

*/

#include <stdio.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
linechart(double *x, size_t n)
{
	double x0, x1, dx;
	double b0, b1;
	size_t i, j;

	x0 = DBL_MAX;
	x1 = -DBL_MAX;
	for (i = 0; i < n; i++) {
		x0 = fmin(x0, x[i]);
		x1 = fmax(x1, x[i]);
	}
	dx = (x1 - x0) / 10;

	for (i = 1; i <= 10; i++) {
		b0 = x0 + (dx * (10 - i));
		b1 = x0 + (dx * (10 - i + 1));
		for (j = 0; j < n; j++) {
			if (b0 <= x[j] && x[j] <= b1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int
main()
{
	double x1[] = {
		10.184, 8.835, 6.928, 4.656, 2.396, 0.500, -1.644, -3.687,
		-5.399, -6.562, -6.999, -6.603, -5.380, -3.479, -1.217, 0.912,
		2.087, 3.558, 5.642, 7.811, 9.644, 10.773, 10.938, 10.055, 8.270,
		5.969, 3.732, 2.236, 1.728, 0.295, -1.842, -4.134, -6.005, -6.949,
		-6.673, -5.204, -2.929, -0.512, 1.304, 1.996, 2.435, 3.942, 6.207,
		8.607, 10.406, 10.994, 10.127, 8.063, 5.502, 3.321, 2.169, 1.984,
		1.381, -0.282, -2.719, -5.180, -6.762, -6.813, -5.265, -2.720, -0.181, 1.467,
		1.987, 2.072, 2.852, 4.735, 7.363, 9.795, 10.977, 10.327, 8.108, 5.325,
		3.139, 2.141
	};

	linechart(x1, nelem(x1));

	return 0;
}
