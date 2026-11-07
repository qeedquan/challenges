#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int D[][3], size_t n)
{
	int L, W, H, V;
	int MAXH, MAXV;
	size_t i;

	MAXV = 0;
	MAXH = 0;
	for (i = 0; i < n; i++) {
		L = D[i][0];
		W = D[i][1];
		H = D[i][2];
		V = L * W * H;
		if (H > MAXH || (H == MAXH && V > MAXV)) {
			MAXH = H;
			MAXV = V;
		}
	}
	return MAXV;
}

int
main()
{
	int D1[][3] = {
		{ 3, 4, 5 },
		{ 12, 1, 5 },
		{ 20, 10, 4 },
	};

	int D2[][3] = {
		{ 3, 4, 5 },
		{ 20, 30, 5 },
		{ 1, 2, 4 },
	};

	assert(solve(D1, nelem(D1)) == 60);
	assert(solve(D2, nelem(D2)) == 3000);

	return 0;
}
