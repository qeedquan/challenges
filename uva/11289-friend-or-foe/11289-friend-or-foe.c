#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y, z;
} Point;

int
classify(double w[], Point p)
{
	return ((w[0] * p.x) + (w[1] * p.y) + (w[2] * p.z) + w[3]) > 0;
}

double
train(double w[], Point p, int type)
{
	static const double step = 0.5;

	double err;

	err = type - classify(w, p);
	w[0] += err * step * p.x;
	w[1] += err * step * p.y;
	w[2] += err * step * p.z;
	w[3] += err * step;
	return err;
}

void
solve(Point A[], Point B[], size_t n, size_t m)
{
	double w[4];
	size_t i;
	double err;

	memset(w, 0, sizeof(w));
	for (;;) {
		err = 0;
		for (i = 0; i < n; i++)
			err += train(w, A[i], 0);
		for (i = 0; i < m; i++)
			err += train(w, B[i], 1);
		if (err == 0)
			break;
	}
	printf("%.2lf %.2lf %.2lf %.2lf\n", w[0], w[1], w[2], w[3]);
}

int
main()
{
	Point A[] = {
		{ -93, 48, -92 },
		{ -62, 12, -32 },
	};

	Point B[] = {
		{ 51, 98, -61 },
		{ -3, 72, 81 },
		{ 95, 25, 22 },
		{ 89, 43, -99 },
		{ 100, -2, -96 },
		{ -18, 45, -63 },
		{ 36, -21, -8 },
		{ 71, -24, 42 },
	};

	solve(A, B, nelem(A), nelem(B));

	return 0;
}
