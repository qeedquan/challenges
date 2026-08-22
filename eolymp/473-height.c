/*

Your acquaintance, farmer Vasyl, wants to purchase a plot of land but has specific requirements.
He wants to ensure that in spring, the melting snow does not accumulate anywhere on the plot.
For proper drainage, no point on the plot should be completely surrounded by higher points on each side.

You need to help Vasyl write a program that, given the heights of points, determines whether water will accumulate.
You have simplified the task: the heights are analyzed along a line passing through the plot.
The first version of the program considers exactly 5 points.

Input
The input consists of five lines, each containing a single integer between 1 and 100.

Output
Print "yes" if there is exactly one maximum among these numbers, and every other number is strictly less than all numbers between it and the maximum.
Otherwise, print "no".

Examples
Input #1
1
2
3
4
5

Answer #1
yes

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
solve(int x[5])
{
	if (x[0] == x[1] && x[1] == x[2] && x[2] == x[3] && x[3] == x[4])
		return "yes";
	if (x[0] >= x[1] && x[2] >= x[1])
		return "no";
	if (x[1] >= x[2] && x[3] >= x[2])
		return "no";
	if (x[2] >= x[3] && x[4] >= x[3])
		return "no";
	return "yes";
}

void
test(int x[5], const char *r)
{
	const char *p;

	p = solve(x);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	int x1[] = { 1, 2, 3, 4, 5 };

	test(x1, "yes");

	return 0;
}
