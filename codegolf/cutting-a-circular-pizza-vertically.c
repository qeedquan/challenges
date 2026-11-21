/*

Most people would cut circular pizzas into circular sectors to divide them up evenly, but it's also possible to divide them evenly by cutting them vertically like so, where each piece has the same area (assume the pizza has no crust):

https://i.stack.imgur.com/8vfaT.png

Challenge
Your task is to make a program or function that takes a positive integer n
 where 2≤n≤100
 that represents how many vertical slices a circular pizza with a radius of 100
 will be cut into as input and outputs the horizontal distance from the center of each cut (which will make each slice have the same area) from left to right (or right to left, since the cuts are symmetrical), rounded to the nearest integer.

Note that this will probably require more than just a simple formula.

Rules
Input and output can be in any convenient format.
This is code-golf, so the shortest code in bytes in each language wins.

Test cases
Input	Output
2	[0]
3	[26, 26]
4	[40, 0, 40]
5	[49, 16, 16, 49]
6	[55, 26, 0, 26, 55]
7	[60, 34, 11, 11, 34, 60]
8	[63, 40, 20, 0, 20, 40, 63]
9	[66, 45, 26, 9, 9, 26, 45, 66]
10	[69, 49, 32, 16, 0, 16, 32, 49, 69]
50	[90, 83, 78, 73, 69, 64, 60, 57, 53, 49, 46, 42, 39, 35, 32, 29, 25, 22, 19, 16, 13, 9, 6, 3, 0, 3, 6, 9, 13, 16, 19, 22, 25, 29, 32, 35, 39, 42, 46, 49, 53, 57, 60, 64, 69, 73, 78, 83, 90]
82	[92, 88, 84, 81, 78, 75, 72, 69, 67, 64, 62, 59, 57, 55, 52, 50, 48, 46, 44, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 44, 46, 48, 50, 52, 55, 57, 59, 62, 64, 67, 69, 72, 75, 78, 81, 84, 88, 92]
97	[93, 89, 86, 83, 80, 77, 75, 73, 70, 68, 66, 64, 62, 60, 58, 56, 54, 52, 50, 48, 46, 44, 43, 41, 39, 37, 36, 34, 32, 30, 29, 27, 25, 24, 22, 20, 19, 17, 15, 14, 12, 11, 9, 7, 6, 4, 2, 1, 1, 2, 4, 6, 7, 9, 11, 12, 14, 15, 17, 19, 20, 22, 24, 25, 27, 29, 30, 32, 34, 36, 37, 39, 41, 43, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 73, 75, 77, 80, 83, 86, 89, 93]
100	[93, 90, 86, 83, 81, 78, 76, 73, 71, 69, 67, 64, 62, 60, 59, 57, 55, 53, 51, 49, 47, 46, 44, 42, 40, 39, 37, 35, 34, 32, 30, 29, 27, 25, 24, 22, 21, 19, 17, 16, 14, 13, 11, 9, 8, 6, 5, 3, 2, 0, 2, 3, 5, 6, 8, 9, 11, 13, 14, 16, 17, 19, 21, 22, 24, 25, 27, 29, 30, 32, 34, 35, 37, 39, 40, 42, 44, 46, 47, 49, 51, 53, 55, 57, 59, 60, 62, 64, 67, 69, 71, 73, 76, 78, 81, 83, 86, 90, 93]

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double
slice(double a)
{
	static const double eps = 1e-9;
	double d, p, r;

	p = 0;
	for (;;) {
		r = sqrt(1 - (p * p));
		d = a - (p * r) - asin(p);
		if (d < eps)
			break;
		p += d / (r * 2);
	}
	return (200 * p) + 1;
}

/*

https://mathworld.wolfram.com/Quarter-TankProblem.html (special case of n=4)

@bsoelch

Uses Newton's method to find the inverse of the formula

Integrate[0, h] 2*sqrt(1-h^2) dh = h*sqrt(1-h^2) + asin(h)
for the area of a slice of height h from the center in a circle of radius 1.

*/

void
cut(int n, int *r)
{
	double a;
	int i;

	for (i = 1; i < n; i++) {
		a = fabs((i * 1.0 / n) - 0.5);
		r[i - 1] = slice(a * M_PI) / 2;
	}
}

void
test(int n, int *r)
{
	int x[128];

	cut(n, x);
	assert(!memcmp(x, r, sizeof(*r) * (n - 1)));
}

int
main(void)
{
	int r1[] = {0};
	int r2[] = {26, 26};
	int r3[] = {40, 0, 40};
	int r4[] = {49, 16, 16, 49};
	int r5[] = {55, 26, 0, 26, 55};
	int r6[] = {60, 34, 11, 11, 34, 60};
	int r7[] = {63, 40, 20, 0, 20, 40, 63};
	int r8[] = {66, 45, 26, 9, 9, 26, 45, 66};
	int r9[] = {69, 49, 32, 16, 0, 16, 32, 49, 69};
	int r10[] = {90, 83, 78, 73, 69, 64, 60, 57, 53, 49, 46, 42, 39, 35, 32, 29, 25, 22, 19, 16, 13, 9, 6, 3, 0, 3, 6, 9, 13, 16, 19, 22, 25, 29, 32, 35, 39, 42, 46, 49, 53, 57, 60, 64, 69, 73, 78, 83, 90};
	int r11[] = {92, 88, 84, 81, 78, 75, 72, 69, 67, 64, 62, 59, 57, 55, 52, 50, 48, 46, 44, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 44, 46, 48, 50, 52, 55, 57, 59, 62, 64, 67, 69, 72, 75, 78, 81, 84, 88, 92};
	int r12[] = {93, 89, 86, 83, 80, 77, 75, 73, 70, 68, 66, 64, 62, 60, 58, 56, 54, 52, 50, 48, 46, 44, 43, 41, 39, 37, 36, 34, 32, 30, 29, 27, 25, 24, 22, 20, 19, 17, 15, 14, 12, 11, 9, 7, 6, 4, 2, 1, 1, 2, 4, 6, 7, 9, 11, 12, 14, 15, 17, 19, 20, 22, 24, 25, 27, 29, 30, 32, 34, 36, 37, 39, 41, 43, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 73, 75, 77, 80, 83, 86, 89, 93};
	int r13[] = {93, 90, 86, 83, 81, 78, 76, 73, 71, 69, 67, 64, 62, 60, 59, 57, 55, 53, 51, 49, 47, 46, 44, 42, 40, 39, 37, 35, 34, 32, 30, 29, 27, 25, 24, 22, 21, 19, 17, 16, 14, 13, 11, 9, 8, 6, 5, 3, 2, 0, 2, 3, 5, 6, 8, 9, 11, 13, 14, 16, 17, 19, 21, 22, 24, 25, 27, 29, 30, 32, 34, 35, 37, 39, 40, 42, 44, 46, 47, 49, 51, 53, 55, 57, 59, 60, 62, 64, 67, 69, 71, 73, 76, 78, 81, 83, 86, 90, 93};

	test(2, r1);
	test(3, r2);
	test(4, r3);
	test(5, r4);
	test(6, r5);
	test(7, r6);
	test(8, r7);
	test(9, r8);
	test(10, r9);
	test(50, r10);
	test(82, r11);
	test(97, r12);
	test(100, r13);

	return 0;
}
