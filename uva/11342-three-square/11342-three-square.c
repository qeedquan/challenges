#include <stdio.h>
#include <math.h>

int
solve(int n, int r[3])
{
	int a, b, c, c2;

	for (a = 0; (a * a) < n; a++) {
		for (b = a; (b * b) + (a * a) < n; b++) {
			c2 = n - (a * a) - (b * b);
			if (c2 < 0)
				continue;

			c = sqrt(c2);
			if (c * c == c2) {
				r[0] = a;
				r[1] = b;
				r[2] = c;
				return 1;
			}
		}
	}
	return 0;
}

void
test(int n)
{
	int r[3];

	if (solve(n, r))
		printf("%d %d %d\n", r[0], r[1], r[2]);
	else
		printf("-1\n");
}

int
main()
{
	test(13);
	test(15);
	test(17);

	return 0;
}
