#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
solve(int L, int C, int r1, int r2)
{
	int SL, D;
	int R, R2;
	int xy1, xy2;

	SL = min(L, C);
	if ((r1 + r1 > SL) || (r2 + r2 > SL))
		return 'N';

	xy1 = (C - r2 - r1);
	xy2 = (L - r2 - r1);

	R = r1 + r2;
	D = (xy1 * xy1) + (xy2 * xy2);
	R2 = R * R;

	return (D < R2) ? 'N' : 'S';
}

int
main()
{
	assert(solve(11, 9, 2, 3) == 'S');
	assert(solve(7, 8, 3, 2) == 'N');
	assert(solve(10, 15, 3, 7) == 'N');
	assert(solve(8, 9, 3, 2) == 'S');

	return 0;
}
