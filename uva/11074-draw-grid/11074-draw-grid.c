#include <stdio.h>

void
draw_wall(int t)
{
	int i;

	for (i = 0; i < t; i++)
		putchar('*');
}

void
draw_cell(int s)
{
	int i;

	for (i = 0; i < s; i++)
		putchar('.');
}

void
draw_cells(int t, int s, int n)
{
	int i, j;

	for (i = 0; i < s; i++) {
		draw_wall(t);
		for (j = 0; j < n; j++) {
			draw_cell(s);
			draw_wall(t);
		}
		putchar('\n');
	}
}

void
draw_separator(int t, int s, int n)
{
	int i, j, len;

	len = (n + 1) * t + n * s;
	for (i = 0; i < t; i++) {
		for (j = 0; j < len; j++)
			putchar('*');
		putchar('\n');
	}
}

void
solve(int s, int t, int n)
{
	int i;

	draw_separator(t, s, n);
	for (i = 0; i < n; i++) {
		draw_cells(t, s, n);
		draw_separator(t, s, n);
	}
	putchar('\n');
}

int
main()
{
	solve(3, 3, 3);
	solve(2, 3, 4);

	return 0;
}
