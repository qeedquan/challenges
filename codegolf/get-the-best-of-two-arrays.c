/*

You will be given two arrays of floating-point numbers. Your task is to pair the corresponding elements of the two arrays, and get the maximum of each pair. However, if the two corresponding elements are equal, you must take their sum instead.

For example, given the lists [1, 3, 3.2, 2.3] and [3, 1, 3.2, 2.6], you must do the following:

Pair the elements (or zip): [[1, 3], [3, 1], [3.2, 3.2], [2.3, 2.6]].

Go through each pair and apply the process above: [3, 3, 6.4, 2.6].

Specs
The arrays / lists will always have equal length. They may however be empty.

The numbers they contain will always fit your language's capabilities, as long as you do not abuse that. They may be positive, zero or negative, you must handle all types.

If it helps you reduce your byte count, you may also take the length of the lists as input.

Rules
This is code-golf, so shortest answer in bytes wins.
Standard input and output rules apply. You may take input (and output) in any reasonable format.
Default Loopholes are forbidden.
Test Cases
Array_1, Array_2 -> Output

[], [] -> []
[1, 2, 3], [1, 3, 2] -> [2, 3, 3]
[1, 3, 3.2, 2.3], [3, 1, 3.2, 2.6] -> [3, 3, 6.4, 2.6]
[1,2,3,4,5,5,7,8,9,10], [10,9,8,7,6,5,4,3,2,1] -> [10, 9, 8, 7, 6, 10, 7, 8, 9, 10]
[-3.2, -3.2, -2.4, 7, -10.1], [100, -3.2, 2.4, -7, -10.1] -> [100, -6.4, 2.4, 7, -20.2]

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(double *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%.1f ", a[i]);
	printf("\n");
}

void
solve(double *a, double *b, size_t n, double *r)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i] == b[i])
			r[i] = a[i] + b[i];
		else
			r[i] = fmax(a[i], b[i]);
	}
}

void
test(double *a, double *b, size_t n)
{
	double r[128];

	solve(a, b, n, r);
	dump(r, n);
}

int
main()
{
	double a1[] = { 1, 2, 3 };
	double b1[] = { 1, 3, 2 };

	double a2[] = { 1, 3, 3.2, 2.3 };
	double b2[] = { 3, 1, 3.2, 2.6 };

	double a3[] = { 1, 2, 3, 4, 5, 5, 7, 8, 9, 10 };
	double b3[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	double a4[] = { -3.2, -3.2, -2.4, 7, -10.1 };
	double b4[] = { 100, -3.2, 2.4, -7, -10.1 };

	test(a1, b1, nelem(a1));
	test(a2, b2, nelem(a2));
	test(a3, b3, nelem(a3));
	test(a4, b4, nelem(a4));

	return 0;
}
