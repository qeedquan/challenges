#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long vlong;

#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))

// https://oeis.org/A001014
const char *
solve(vlong n)
{
	vlong d1, d2;

	if (n < 0)
		return "Ordinary";

	d1 = sqrt(n);
	d2 = cbrt(n);
	while (sqr(d1) < n)
		d1++;
	while (cube(d2) < n)
		d2++;
	if (d1 * d1 == n && d2 * d2 * d2 == n)
		return "Special";
	return "Ordinary";
}

void
test(vlong n, const char *r)
{
	assert(!strcmp(solve(n), r));
}

int
main()
{
	test(1, "Special");
	test(2, "Ordinary");
	test(64, "Special");
	test(100, "Ordinary");
	test(15625, "Special");

	return 0;
}
