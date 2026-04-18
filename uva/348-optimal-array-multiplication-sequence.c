/*

Given two arrays A and B, we can determine the array C = A B using the standard definition of matrix multiplication:

C[i, j] = Sum[k] A[i, k] * B[k, j]

The number of columns in the A array must be the same as the number of rows in the B array.
Notationally, let’s say that rows(A) and columns(A) are the number of rows and columns, respectively,
in the A array. The number of individual multiplications required to compute the entire C array
(which will have the same number of rows as A and the same number of columns as B) is then rows(A)
columns(B) columns(A). For example, if A is a 10 × 20 array, and B is a 20 × 15 array, it will take
10 × 15 × 20, or 3000 multiplications to compute the C array.
To perform multiplication of more than two arrays we have a choice of how to proceed. For example,
if X, Y , and Z are arrays, then to compute X Y Z we could either compute (X Y ) Z or X (Y Z).
Suppose X is a 5 × 10 array, Y is a 10 × 20 array, and Z is a 20 × 35 array. Let’s look at the number
of multiplications required to compute the product using the two different sequences:
(X Y ) Z
• 5 × 20 × 10 = 1000 multiplications to determine the product (XY ), a 5 × 20 array.
• Then 5 × 35 × 20 = 3500 multiplications to determine the final result.
• Total multiplications: 4500.
X (Y Z)
• 10 × 35 × 20 = 7000 multiplications to determine the product (Y Z), a 10 × 35 array.
• Then 5 × 35 × 10 = 1750 multiplications to determine the final result.
• Total multiplications: 8750.
Clearly we’ll be able to compute (X Y ) Z using fewer individual multiplications.
Given the size of each array in a sequence of arrays to be multiplied, you are to determine an
optimal computational sequence. Optimality, for this problem, is relative to the number of individual
multiplications required.

Input
For each array in the multiple sequences of arrays to be multiplied you will be given only the dimensions
of the array. Each sequence will consist of an integer N which indicates the number of arrays to be
multiplied, and then N pairs of integers, each pair giving the number of rows and columns in an array;
the order in which the dimensions are given is the same as the order in which the arrays are to be
multiplied. A value of zero for N indicates the end of the input. N will be no larger than 10.

Output
Assume the arrays are named A1, A2, . . . , AN. Your output for each input case is to be a line containing
a parenthesized expression clearly indicating the order in which the arrays are to be multiplied. Prefix
the output for each case with the case number (they are sequentially numbered, starting with 1). Your
output should strongly resemble that shown in the samples shown below. If, by chance, there are
multiple correct sequences, any of these will be accepted as a valid answer.

Sample Input
3
1 5
5 20
20 1
3
5 10
10 20
20 35
6
30 35
35 15
15 5
5 10
10 20
20 25
0

Sample Output
Case 1: (A1 x (A2 x A3))
Case 2: ((A1 x A2) x A3)
Case 3: ((A1 x (A2 x A3)) x ((A4 x A5) x A6))

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int **
alloc(size_t n)
{
	int **p, *q;
	size_t i;

	p = calloc(n, sizeof(*p));
	q = calloc(n * n, sizeof(*q));
	if (!p || !q)
		goto error;

	for (i = 0; i < n; i++)
		p[i] = &q[i * n];

	if (0) {
	error:
		free(p);
		free(q);
		p = NULL;
	}
	return p;
}

void
destroy(int **p)
{
	if (p) {
		free(p[0]);
		free(p);
	}
}

void
show(int **p, size_t i, size_t j)
{
	if (i == j) {
		printf("A%zu", i);
		return;
	}

	printf("(");
	show(p, i, p[i][j]);
	printf(" x ");
	show(p, p[i][j] + 1, j);
	printf(")");
}

void
print(int **p, size_t n)
{
	show(p, 1, n);
	printf("\n");
}

int **
optimize(int *A, size_t n)
{
	size_t i, j, k, l;
	int **c, **p;
	int v;

	c = alloc(n + 1);
	p = alloc(n + 1);
	if (!c || !p)
		goto error;

	for (l = 2; l <= n; l++) {
		for (i = 1; i <= n + 1 - l; i++) {
			j = i + l - 1;
			c[i][j] = INT_MAX;
			for (k = i; k < j; k++) {
				v = c[i][k] + c[k + 1][j];
				v += A[i - 1] * A[k] * A[j];
				if (v < c[i][j]) {
					c[i][j] = v;
					p[i][j] = k;
				}
			}
		}
	}

	if (0) {
	error:
		destroy(p);
		p = NULL;
	}
	destroy(c);

	return p;
}

int
solve(int *A, size_t n)
{
	int **p;

	p = optimize(A, n);
	if (!p)
		return -1;
	print(p, n);
	destroy(p);
	return 0;
}

int
main()
{
	int A1[] = { 1, 5, 20, 1 };
	int A2[] = { 5, 10, 20, 35 };
	int A3[] = { 30, 35, 15, 5, 10, 20, 25 };

	solve(A1, nelem(A1) - 1);
	solve(A2, nelem(A2) - 1);
	solve(A3, nelem(A3) - 1);

	return 0;
}
