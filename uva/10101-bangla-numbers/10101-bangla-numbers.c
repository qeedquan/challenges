#include <stdio.h>

typedef long long vlong;

void
translate(vlong n)
{
	static const vlong units[4] = { 10000000, 100000, 1000, 100 };
	static const char strings[4][6] = { "kuti", "lakh", "hajar", "shata" };

	size_t i;

	for (i = 0; i < 4; i++) {
		if (n >= units[i]) {
			translate(n / units[i]);
			printf(" %s", strings[i]);
			n %= units[i];
		}
	}

	if (n)
		printf(" %lld", n);
}

void
solve(vlong n)
{
	if (n < 1)
		printf("%lld", n);
	else
		translate(n);
	puts("");
}

int
main()
{
	solve(23764);
	solve(45897458973958);

	return 0;
}
