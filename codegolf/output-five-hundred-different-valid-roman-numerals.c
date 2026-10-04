/*

Output any 500 different valid Roman numerals in the range 1 to 3999, in uppercase. Code golf.

*/

#include <stdio.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

// ported from @Jonathan Allan solution
void
output()
{
	static const char sym[] = "DCLXVI ";

	int c, i, j, k, l, m;

	for (i = 0; i < 500; i++) {
		m = 2;
		j = i;
		for (c = 0; sym[c]; c++) {
			k = mod(-j - 1, m);
			for (l = 0; l < k; l++)
				putchar(sym[c]);
			j /= m;
			m ^= 6;
		}
		putchar('\n');
	}
}

int
main()
{
	output();
	return 0;
}
