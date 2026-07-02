/*

Description

You are given three n × n matrices A, B and C. Does the equation A × B = C hold true?

Input

The first line of input contains a positive integer n (n ≤ 500) followed by the the three matrices A, B and C respectively. Each matrix's description is a block of n × n integers.

It guarantees that the elements of A and B are less than 100 in absolute value and elements of C are less than 10,000,000 in absolute value.

Output

Output "YES" if the equation holds true, otherwise "NO".

Sample Input

2
1 0
2 3
5 1
0 8
5 1
10 26
Sample Output

YES

Hint

Multiple inputs will be tested. So O(n3) algorithm will get TLE.

Source

POJ Monthly--2007.08.05, qzc

*/

#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <cblas.h>

bool
equal(double *A, double *B, double *C, size_t n)
{
	static const double eps = 1e-8;
	double R[n * n];
	size_t i;

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, R, n);
	for (i = 0; i < n * n; i++) {
		if (fabs(R[i] - C[i]) > eps)
			return false;
	}
	return true;
}

int
main(void)
{
	double A[] = {1, 0, 2, 3};
	double B[] = {5, 1, 0, 8};
	double C[] = {5, 1, 10, 26};

	assert(equal(A, B, C, 2) == true);

	return 0;
}
