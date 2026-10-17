#include <stdio.h>
#include <math.h>
#include <float.h>

double
solve(int p, int a, int b, int c, int d, int n)
{
	double tsa, tca;
	double tsb, tcb;
	double s1, s2;
	double c1, c2;
	double t1, t2;
	double f, m, r;
	int i;

	tsa = sin(a);
	tca = cos(a);
	tsb = sin(c);
	tcb = cos(c);
	s1 = sin(a + b);
	c1 = cos(a + b);
	c2 = cos(c + d);
	s2 = sin(c + d);
	m = DBL_MIN;
	r = 0;
	for (i = 0; i < n; i++) {
		f = p * (s1 + c2 + 2);
		if (i)
			r = fmax(r, m - f);
		m = fmax(m, f);

		t1 = (s1 * tca) + (c1 * tsa);
		t2 = (c1 * tca) - (s1 * tsa);
		s1 = t1;
		c1 = t2;

		t1 = (s2 * tcb) + (c2 * tsb);
		t2 = (c2 * tcb) - (s2 * tsb);
		s2 = t1;
		c2 = t2;
	}
	return r;
}

int
main()
{
	printf("%.9f\n", solve(42, 1, 23, 4, 8, 10));
	printf("%.9f\n", solve(100, 7, 615, 998, 801, 3));
	printf("%.9f\n", solve(100, 432, 406, 867, 60, 1000));

	return 0;
}
