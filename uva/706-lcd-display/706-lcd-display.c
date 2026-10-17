#include <stdio.h>
#include <ctype.h>

void
display(const char *s, int n)
{
	static const char type[5][6] = {
		{ "    " },
		{ "   |" },
		{ "|   " },
		{ "|  |" },
		{ " -- " },
	};

	static const char num[10][5] = {
		{ 4, 3, 0, 3, 4 }, /* 0 */
		{ 0, 1, 0, 1, 0 }, /* 1 */
		{ 4, 1, 4, 2, 4 }, /* 2 */
		{ 4, 1, 4, 1, 4 }, /* 3 */
		{ 0, 3, 4, 1, 0 }, /* 4 */
		{ 4, 2, 4, 1, 4 }, /* 5 */
		{ 4, 2, 4, 3, 4 }, /* 6 */
		{ 4, 1, 0, 1, 0 }, /* 7 */
		{ 4, 3, 4, 3, 4 }, /* 8 */
		{ 4, 3, 4, 1, 4 }  /* 9 */
	};

	int i, j, r, y;
	const char *p;

	for (r = 0; r < 5; r++) {
		y = n;
		if (!(r % 2))
			y = 1;

		for (; y > 0; y--) {
			for (p = s; *p; p++) {
				if (*p == ' ') {
					putchar(' ');
					continue;
				}
				if (!isdigit(*p))
					continue;

				i = num[*p - '0'][r];
				putchar(type[i][0]);
				for (j = 0; j < n; j++)
					putchar(type[i][1]);
				putchar(type[i][3]);

				if (p[1] != '\0')
					putchar(' ');
			}
			puts("");
		}
	}
	puts("");
}

int
main()
{
	display("12345", 2);
	display("67890", 3);

	return 0;
}
