#include <stdio.h>
#include <math.h>

typedef long long vlong;

void
solve(vlong L, vlong H, vlong K)
{
	static const double eps = 1e-6;

	double e, t, v;
	vlong i;

	e = t = 0;
	for (i = H; i >= L; i--) {
		v = log10(i) * K;
		e = fmax(e, floor(v));
	}

	for (i = H; i >= L; i--) {
		v = log10(i) * K - e;
		t += pow(10, v);
	}

	for (; t >= 1; t /= 10)
		e += 1;

	if (fabs(t) < eps && e == 0)
		e = 1;

	printf("%.6lfe%010lld\n", t, (vlong)e);
}

int
main()
{
	solve(1, 10, 10);
	solve(10, 15, 100);

	return 0;
}
