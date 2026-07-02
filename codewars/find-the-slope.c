/*

Given an array of 4 integers
[a,b,c,d] representing two points (a, b) and (c, d), return a string representation of the slope of the line joining these two points.

For an undefined slope (division by 0), return  undefined  . Note that the "undefined" is case-sensitive.

   a:x1
   b:y1
   c:x2
   d:y2


Assume that [a,b,c,d] and the answer are all integers (no floating numbers!).
Slope: https://en.wikipedia.org/wiki/Slope

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
slope(int p[4], char *b)
{
	if (p[0] == p[2])
		sprintf(b, "undefined");
	else
		sprintf(b, "%d", (p[3] - p[1]) / (p[2] - p[0]));
	return b;
}

void
test(int p[4], const char *r)
{
	char b[32];

	slope(p, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	int p1[] = { 19, 3, 20, 3 };
	int p2[] = { -7, 2, -7, 4 };
	int p3[] = { 10, 50, 30, 150 };
	int p4[] = { 15, 45, 12, 60 };
	int p5[] = { 10, 20, 20, 80 };
	int p6[] = { -10, 6, -10, 3 };

	test(p1, "0");
	test(p2, "undefined");
	test(p3, "5");
	test(p4, "-5");
	test(p5, "6");
	test(p6, "undefined");

	return 0;
}
