#include <assert.h>
#include <stdio.h>
#include <string.h>

int
nowin(int X, int Y, int Z, int A, int B, int C)
{
	int r;

	r = (X > A);
	r += (Y > B);
	r += (Z > C);
	return r < 2;
}

int
solve(int A, int B, int C, int X, int Y)
{
	char used[64];
	int i;

	memset(used, 0, sizeof(used));
	used[A] = used[B] = used[C] = used[X] = used[Y] = 1;

	for (i = 1; i <= 52; i++) {
		if (used[i])
			continue;
		if (nowin(X, Y, i, A, B, C))
			continue;
		if (nowin(X, i, Y, A, B, C))
			continue;
		if (nowin(Y, X, i, A, B, C))
			continue;
		if (nowin(Y, i, X, A, B, C))
			continue;
		if (nowin(i, X, Y, A, B, C))
			continue;
		if (nowin(i, Y, X, A, B, C))
			continue;
		return i;
	}
	return -1;
}

int
main()
{
	assert(solve(28, 51, 29, 50, 52) == 30);
	assert(solve(50, 26, 19, 10, 27) == -1);
	assert(solve(10, 20, 30, 24, 26) == 21);
	assert(solve(46, 48, 49, 47, 50) == 51);

	return 0;
}
