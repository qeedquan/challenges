#include <stdio.h>
#include <math.h>

typedef long long vlong;

vlong
trailpow(vlong n, vlong k)
{
	static const vlong mod = 1000;

	vlong s;

	if (k < 0)
		return 0;
	if (k == 0)
		return 1;

	s = (n * n) % mod;
	if (k & 1)
		return n * trailpow(s, k / 2) % mod;
	return trailpow(s, k / 2);
}

void
solve(vlong n, vlong k)
{
	vlong t, p;

	t = trailpow(n, k);
	p = pow(10, fmod(k * log10(n), 1)) * 100;
	printf("%lld...%03lld\n", p, t);
}

int
main()
{
	solve(123456, 1);
	solve(123456, 2);

	return 0;
}
