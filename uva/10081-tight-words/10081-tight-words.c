#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double
solve(int k, int n)
{
	int **p, *q;
	int i, j;
	double s, r;

	p = calloc(n + 2, sizeof(*p));
	q = calloc((n + 2) * (k + 2), sizeof(*q));
	if (!p || !q)
		goto error;

	for (i = 0; i < n + 2; i++)
		p[i] = &q[i * (k + 2)];

	for (i = 0; i <= k; i++)
		p[1][i] = 1;

	for (i = 2; i <= n; i++) {
		p[i][0] = p[i - 1][0] + p[i - 1][1];
		p[i][k] = p[i][0];
		for (j = 1; j < k; j++)
			p[i][j] = p[i - 1][j - 1] + p[i - 1][j] + p[i - 1][j + 1];
	}

	s = 0;
	for (i = 0; i <= k; i++)
		s += p[n][i];

	r = (100 * s) / pow(k + 1, n);

	if (0) {
	error:
		r = -1;
	}

	free(p);
	free(q);

	return r;
}

void
test(int k, int n, double r)
{
	double p;

	p = solve(k, n);
	printf("%.6f\n", p);
	assert(fabs(p - r) < 1e-5);
}

int
main()
{
	test(4, 1, 100);
	test(2, 5, 40.74074);
	test(3, 5, 17.38281);
	test(8, 7, 0.10130);

	return 0;
}
