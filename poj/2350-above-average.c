/*

Description

It is said that 90% of frosh expect to be above average in their class. You are to provide a reality check.

Input

The first line of standard input contains an integer C, the number of test cases. C data sets follow. Each data set begins with an integer, N, the number of people in the class (1 <= N <= 1000). N integers follow, separated by spaces or newlines, each giving the final grade (an integer between 0 and 100) of a student in the class.

Output

For each case you are to output a line giving the percentage of students whose grade is above average, rounded to 3 decimal places.

Sample Input

5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

Sample Output

40.000%
57.143%
33.333%
66.667%
55.556%

Source

Waterloo local 2002.09.28

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
above(int *a, size_t n)
{
	double c, m;
	size_t i;

	if (n == 0)
		return 0;

	c = 0;
	m = 0;

	for (i = 0; i < n; i++)
		m += a[i];
	m /= n;

	for (i = 0; i < n; i++) {
		if (a[i] > m)
			c++;
	}
	return (c * 100) / n;
}

void
test(int *a, size_t n, double r)
{
	double v;

	v = above(a, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	int a1[] = {50, 50, 70, 80, 100};
	int a2[] = {100, 95, 90, 80, 70, 60, 50};
	int a3[] = {70, 90, 80};
	int a4[] = {70, 90, 81};
	int a5[] = {100, 99, 98, 97, 96, 95, 94, 93, 91};

	test(a1, nelem(a1), 40);
	test(a2, nelem(a2), 57.143);
	test(a3, nelem(a3), 33.333);
	test(a4, nelem(a4), 66.667);
	test(a5, nelem(a5), 55.556);

	return 0;
}
