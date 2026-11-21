#include <stdio.h>
#include <string.h>

void
color(int g[3][3], int x, int y)
{
	static const int dx[5] = { 0, 1, -1, 0, 0 };
	static const int dy[5] = { 0, 0, 0, 1, -1 };

	int i, tx, ty;

	for (i = 0; i < 5; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3)
			continue;

		g[tx][ty]++;
	}
}

void
print(int g[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (j)
				putchar(' ');
			printf("%d", g[i][j] % 10);
		}
		puts("");
	}
	puts("");
}

void
solve(const char *s)
{
	int g[3][3];
	int c;

	memset(g, 0, sizeof(g));
	for (; *s; s++) {
		if ('a' <= *s && *s <= 'z') {
			c = *s - 'a';
			color(g, c / 3, c % 3);
		}
	}
	print(g);
}

int
main()
{
	solve("cd");
	solve("");
	solve("cdifbgah");

	return 0;
}
