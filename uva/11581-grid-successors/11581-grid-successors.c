#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef int mat3[3][3];

bool
zero(mat3 m)
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (m[i][j] > 0)
				return false;
		}
	}
	return true;
}

void
f(mat3 m)
{
	mat3 h;

	h[0][0] = (m[0][1] + m[1][0]) % 2;
	h[0][1] = (m[0][0] + m[1][1] + m[0][2]) % 2;
	h[0][2] = (m[0][1] + m[1][2]) % 2;

	h[1][0] = (m[0][0] + m[1][1] + m[2][0]) % 2;
	h[1][1] = (m[0][1] + m[1][0] + m[1][2] + m[2][1]) % 2;
	h[1][2] = (m[1][1] + m[0][2] + m[2][2]) % 2;

	h[2][0] = (m[2][1] + m[1][0]) % 2;
	h[2][1] = (m[2][0] + m[1][1] + m[2][2]) % 2;
	h[2][2] = (m[2][1] + m[1][2]) % 2;

	memcpy(m, h, sizeof(h));
}

int
solve(mat3 m)
{
	int r;

	for (r = -1; r < INT_MAX; r++) {
		if (zero(m))
			return r;
		f(m);
	}
	return -1;
}

int
main()
{
	mat3 m1 = {
		{ 1, 1, 1 },
		{ 1, 0, 0 },
		{ 0, 0, 1 },
	};

	mat3 m2 = {
		{ 1, 0, 1 },
		{ 0, 0, 0 },
		{ 1, 0, 1 },
	};

	mat3 m3 = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
	};

	assert(solve(m1) == 3);
	assert(solve(m2) == 0);
	assert(solve(m3) == -1);

	return 0;
}
