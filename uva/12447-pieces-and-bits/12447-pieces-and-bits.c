#include <stdio.h>

#define bit(x) (1 << (x))

void
solve(int n)
{
	int i, r, t;

	r = 0;
	t = 0;
	for (;;) {
		printf("%d\n", r);
		for (i = 0; i < n; i++) {
			if (!((t >> i) & 1))
				break;
		}
		if (i == n)
			break;
		r = (bit(n) - 1) ^ r ^ bit(i);
		t += 1;
	}
	printf("\n");
}

int
main()
{
	solve(2);

	return 0;
}
