#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define TAU (2 * M_PI)

void
draw(int N, int L, double x, double y)
{
	double t;
	int i;

	t = 0;
	for (i = 0; i < N; i++) {
		printf("%.6lf %.6lf\n", x, y);
		x += L * cos(t);
		y += L * sin(t);
		t += TAU / N;
	}
	printf("\n");
}

int
main()
{
	draw(4, 5, 0, 0);
	draw(5, 5, 0, 0);

	return 0;
}
