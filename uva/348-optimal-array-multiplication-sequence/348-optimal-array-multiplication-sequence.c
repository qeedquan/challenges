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
