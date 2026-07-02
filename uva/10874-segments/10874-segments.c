#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
	int x, y;
} Point;

int
solve(Point *p, size_t n)
{
	int tdpl, tdpr;
	int dpr, dpl;
	int Li, Ri;
	int L, R;
	size_t i;

	L = R = 1;
	dpl = dpr = 0;
	for (i = 0; i < n; i++) {
		Li = p[i].x;
		Ri = p[i].y;
		tdpl = min(dpl + abs(L - Li), dpr + abs(R - Li)) + 1;
		tdpr = min(dpr + abs(R - Ri), dpl + abs(L - Ri)) + 1;
		dpr = tdpl + Ri - Li;
		dpl = tdpr + Ri - Li;
		L = Li;
		R = Ri;
	}
	return min(dpl + n - Li, dpr + n - Ri) - 1;
}

int
main()
{
	Point p[] = {
		{ 2, 6 },
		{ 3, 4 },
		{ 1, 3 },
		{ 1, 2 },
		{ 3, 6 },
		{ 4, 5 },
	};

	assert(solve(p, nelem(p)) == 24);

	return 0;
}
