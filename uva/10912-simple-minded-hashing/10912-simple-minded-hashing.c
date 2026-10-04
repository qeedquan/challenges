#include <assert.h>
#include <stdio.h>
#include <string.h>

void
build(int lut[27][27][352])
{
	int i, j, k;

	memset(lut, 0, 27 * 27 * 352 * sizeof(int));

	lut[0][0][0] = 1;
	for (i = 1; i <= 26; i++) {
		for (j = 0; j <= i; j++) {
			for (k = 0; k < 352; k++) {
				lut[i][j][k] = lut[i - 1][j][k];
				if (j > 0 && k >= i)
					lut[i][j][k] += lut[i - 1][j - 1][k - i];
			}
		}
	}
}

int
solve(int L, int S)
{
	static int lut[27][27][352];
	static int once;

	if (!once) {
		build(lut);
		once = 1;
	}

	if (L < 0 || S < 0 || L > 26 || S > 351)
		return 0;
	return lut[26][L][S];
}

int
main()
{
	assert(solve(3, 10) == 4);
	assert(solve(2, 3) == 1);

	return 0;
}
