/*

An array of real numbers is given. Find the first element of the array whose value does not exceed 2.5.

Input
The first line contains the number of elements in the array n (0<n≤100). The second line contains n real numbers separated by spaces.

Output
Print in one line the index of the first element found and its value, separated by a space, with 2 digits after the decimal point. If there is no such element in the array, print Not Found.

Examples
Input #1
5
6 7.5 2.1 2.0 0

Answer #1
3 2.10
Input #2
5
6 7.5 5.1 7.0 80

Answer #2
Not Found

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(double *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i] <= 2.5) {
			printf("%zu %f\n", i + 1, a[i]);
			return 1;
		}
	}
	printf("Not Found\n");
	return 0;
}

int
main()
{
	double a1[] = { 6, 7.5, 2.1, 2.0, 0 };
	double a2[] = { 6, 7.5, 5.1, 7.0, 80 };

	solve(a1, nelem(a1));
	solve(a2, nelem(a2));
	return 0;
}
