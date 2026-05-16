#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef char Grid[6][6];

char kind[11][4][6] = {
	{
	    "10000",
	    "11110",
	    "10000",
	},
	{
	    "10000",
	    "11110",
	    "01000",
	},
	{
	    "10000",
	    "11110",
	    "00100",
	},
	{
	    "10000",
	    "11110",
	    "00010",
	},
	{
	    "01000",
	    "11110",
	    "01000",
	},
	{
	    "01000",
	    "11110",
	    "00100",
	},
	{
	    "11000",
	    "01110",
	    "01000",
	},
	{
	    "11000",
	    "01110",
	    "00100",
	},
	{
	    "11000",
	    "01110",
	    "00010",
	},
	{
	    "11100",
	    "00111",
	    "00000",
	},
	{
	    "11000",
	    "01100",
	    "00110",
	},
};

void
rotate(Grid g)
{
	Grid t;
	int i, j;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
			t[i][j] = g[5 - j][i];
	}

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
			g[i][j] = t[i][j];
	}
}

void
upturn(Grid g)
{
	Grid t;
	int i, j;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
			t[i][j] = g[i][5 - j];
	}

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
			g[i][j] = t[i][j];
	}
}

int
check(Grid g)
{
	int i, j, p, q, k;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			for (k = 0; k < 11; k++) {
				for (p = 0; p < 3; p++) {
					for (q = 0; q < 5; q++) {
						if (kind[k][p][q] == '0')
							continue;
						if (i + p >= 6 || j + q >= 6 || g[i + p][j + q] != kind[k][p][q]) {
							p = 10;
							q = 10;
						}
					}
				}
				if (p == 3)
					return 1;
			}
		}
	}
	return 0;
}

const char *
solve(Grid g)
{
	int i, j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			if (check(g))
				return "correct";
			rotate(g);
		}
		upturn(g);
	}
	return "incorrect";
}

void
test(Grid g, const char *r)
{
	assert(!strcmp(solve(g), r));
}

int
main()
{
	Grid g1 = {
		{ '0', '0', '0', '0', '0', 0 },
		{ '0', '0', '0', '1', '0', '0' },
		{ '0', '0', '0', '1', '0', '0' },
		{ '0', '0', '1', '1', '1', '0' },
		{ '0', '0', '0', '1', '0', '0' },
		{ '0', '0', '0', '0', '0', '0' },
	};

	Grid g2 = {
		{ '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '1', '1', '0' },
		{ '0', '0', '1', '1', '0', '0' },
		{ '0', '0', '0', '1', '1', '0' },
		{ '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0' },
	};

	test(g1, "correct");
	test(g2, "incorrect");

	return 0;
}
