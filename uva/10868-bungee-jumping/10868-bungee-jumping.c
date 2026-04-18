#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double
sqr(double x)
{
	return x * x;
}

const char *
solve(double K, double L, double S, double W)
{
	static const double G = 9.81;

	double e, v;

	if (L >= S)
		v = sqrt(2 * G * S);
	else {
		e = (W * G * S) - (0.5 * K * sqr(S - L));
		if (e < 0)
			return "Stuck in the air.";
		v = sqrt(e * 2 / W);
	}

	if (v > 10)
		return "Killed by the impact.";
	return "James Bond survives.";
}

void
test(double K, double L, double S, double W, const char *r)
{
	const char *s;

	s = solve(K, L, S, W);
	puts(s);
	assert(!strcmp(s, r));
}

int
main()
{
	test(350, 20, 30, 75, "Killed by the impact.");
	test(375, 20, 30, 75, "James Bond survives.");
	test(400, 20, 30, 75, "James Bond survives.");
	test(425, 20, 30, 75, "James Bond survives.");
	test(450, 20, 30, 75, "Stuck in the air.");
	test(400, 20, 30, 50, "Stuck in the air.");
	test(400, 20, 30, 80, "James Bond survives.");
	test(400, 20, 30, 85, "Killed by the impact.");

	return 0;
}
