#include <stdio.h>

void
find(const char *a, const char *b, int *p, int l, int r)
{
	int i;

	if (l > r)
		return;

	for (i = l; i <= r; i++) {
		if (b[i] == a[*p])
			break;
	}

	if (i != r + 1) {
		*p += 1;
		find(a, b, p, l, i - 1);
		find(a, b, p, i + 1, r);
		putchar(b[i]);
	}
}

void
solve(int n, const char *a, const char *b)
{
	int p;

	p = 0;
	find(a, b, &p, 0, n - 1);
	puts("");
}

int
main()
{
	solve(3, "xYz", "Yxz");
	solve(3, "abc", "cba");
	solve(6, "ABCDEF", "CBAEDF");

	return 0;
}
