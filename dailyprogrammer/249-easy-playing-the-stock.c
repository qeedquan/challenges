/*

Description
Let's assume I'm playing the stock market - buy low, sell high. I'm a day trader, so I want to get in and out of a stock before the day is done, and I want to time my trades so that I make the biggest gain possible.

The market has a rule that won't let me buy and sell in a pair of ticks - I have to wait for at least one tick to go buy. And obviously I can't buy in the future and sell in the past.

So, given a list of stock price ticks for the day, can you tell me what trades I should make to maximize my gain within the constraints of the market? Remember - buy low, sell high, and you can't sell before you buy.

Input Description
You'll be given a list of stock prices as a space separated list of 2 decimal floats (dollars and cents), listed in chronological order. Example:

19.35 19.30 18.88 18.93 18.95 19.03 19.00 18.97 18.97 18.98
Output Description
Your program should emit the two trades in chronological order - what you think I should buy at and sell at. Example:

18.88 19.03
Challenge Input
9.20 8.03 10.02 8.08 8.14 8.10 8.31 8.28 8.35 8.34 8.39 8.45 8.38 8.38 8.32 8.36 8.28 8.28 8.38 8.48 8.49 8.54 8.73 8.72 8.76 8.74 8.87 8.82 8.81 8.82 8.85 8.85 8.86 8.63 8.70 8.68 8.72 8.77 8.69 8.65 8.70 8.98 8.98 8.87 8.71 9.17 9.34 9.28 8.98 9.02 9.16 9.15 9.07 9.14 9.13 9.10 9.16 9.06 9.10 9.15 9.11 8.72 8.86 8.83 8.70 8.69 8.73 8.73 8.67 8.70 8.69 8.81 8.82 8.83 8.91 8.80 8.97 8.86 8.81 8.87 8.82 8.78 8.82 8.77 8.54 8.32 8.33 8.32 8.51 8.53 8.52 8.41 8.55 8.31 8.38 8.34 8.34 8.19 8.17 8.16
Challenge Output
8.03 9.34

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
best(double *tick, size_t ntick, double win[2])
{
	size_t i, j;

	win[0] = win[1] = 0;
	if (ntick < 2)
		return;

	for (i = 0; i < ntick - 2; i++) {
		for (j = i + 2; j < ntick; j++) {
			if (tick[j] - tick[i] > win[1] - win[0]) {
				win[0] = tick[i];
				win[1] = tick[j];
			}
		}
	}
}

void
test(double *tick, size_t ntick, double expected[2])
{
	static const double eps = 1e-6;

	double win[2];

	best(tick, ntick, win);
	printf("%.3f %.3f\n", win[0], win[1]);
	assert(fabs(win[0] - expected[0]) < eps);
	assert(fabs(win[1] - expected[1]) < eps);
}

int
main()
{
	double tick1[] = {19.35, 19.30, 18.88, 18.93, 18.95, 19.03, 19.00, 18.97, 18.97, 18.98};
	double tick2[] = {9.20, 8.03, 10.02, 8.08, 8.14, 8.10, 8.31, 8.28, 8.35, 8.34, 8.39, 8.45, 8.38, 8.38, 8.32, 8.36, 8.28, 8.28, 8.38, 8.48, 8.49, 8.54, 8.73, 8.72, 8.76, 8.74, 8.87, 8.82, 8.81, 8.82, 8.85, 8.85, 8.86, 8.63, 8.70, 8.68, 8.72, 8.77, 8.69, 8.65, 8.70, 8.98, 8.98, 8.87, 8.71, 9.17, 9.34, 9.28, 8.98, 9.02, 9.16, 9.15, 9.07, 9.14, 9.13, 9.10, 9.16, 9.06, 9.10, 9.15, 9.11, 8.72, 8.86, 8.83, 8.70, 8.69, 8.73, 8.73, 8.67, 8.70, 8.69, 8.81, 8.82, 8.83, 8.91, 8.80, 8.97, 8.86, 8.81, 8.87, 8.82, 8.78, 8.82, 8.77, 8.54, 8.32, 8.33, 8.32, 8.51, 8.53, 8.52, 8.41, 8.55, 8.31, 8.38, 8.34, 8.34, 8.19, 8.17, 8.16};
	double tick3[] = {19.35, 19.31, 18.99, 28.99, 19.03, 19.00, 18.90, 18.90, 18.91};

	double expected1[] = {18.88, 19.03};
	double expected2[] = {8.03, 9.34};
	double expected3[] = {19.31, 28.99};

	test(tick1, nelem(tick1), expected1);
	test(tick2, nelem(tick2), expected2);
	test(tick3, nelem(tick3), expected3);

	return 0;
}
