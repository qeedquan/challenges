#include <stdio.h>

int
pack(const char *s)
{
	int b[4], c[4], g[4];
	int m, i;
	const char *l;

	if (sscanf(s, "%d %d %d %d %d %d %d %d %d", &b[1], &g[1], &c[1], &b[2], &g[2], &c[2], &b[3], &g[3], &c[3]) != 9)
		return -1;

	m = b[2] + b[3] + c[1] + c[3] + g[1] + g[2];
	l = "BCG";

	i = b[2] + b[3] + g[1] + g[3] + c[1] + c[2];
	if (i < m) {
		m = i;
		l = "BGC";
	}

	i = c[2] + c[3] + b[1] + b[3] + g[1] + g[2];
	if (i < m) {
		m = i;
		l = "CBG";
	}

	i = c[2] + c[3] + g[1] + g[3] + b[1] + b[2];
	if (i < m) {
		m = i;
		l = "CGB";
	}

	i = g[2] + g[3] + b[1] + b[3] + c[1] + c[2];
	if (i < m) {
		m = i;
		l = "GBC";
	}

	i = g[2] + g[3] + c[1] + c[3] + b[1] + b[2];
	if (i < m) {
		m = i;
		l = "GCB";
	}

	printf("%s %d\n", l, m);
	return 0;
}

int
main()
{
	pack("1 2 3 4 5 6 7 8 9");
	pack("5 10 5 20 10 5 10 20 10");

	return 0;
}
