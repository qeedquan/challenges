#include <stdio.h>
#include <math.h>

int
love(const char *s)
{
	int r;
	size_t i;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			r += s[i] - 'a' + 1;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			r += s[i] - 'A' + 1;
	}

	r %= 9;
	if (r == 0)
		r = 9;
	return r;
}

double
solve(const char *s1, const char *s2)
{
	double r1, r2;

	r1 = love(s1);
	r2 = love(s2);
	return fmin(r1 / r2, r2 / r1) * 100;
}

int
main()
{
	printf("%.2f %%\n", solve("saima", "shanto"));
	printf("%.2f %%\n", solve("Pakistan", "India"));
	printf("%.2f %%\n", solve("USA", "USSR"));

	return 0;
}
