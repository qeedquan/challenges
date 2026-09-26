#include <stdio.h>
#include <string.h>

char screen[10][10];
int x, y;
int over;

void
reset()
{
	memset(screen, ' ', sizeof(screen));
	x = y = 0;
	over = 1;
}

void
control(char c)
{
	switch (c) {
	case 'b':
		y = 0;
		break;
	case 'c':
		memset(screen, ' ', sizeof(screen));
		break;
	case 'd':
		if (x < 9)
			x++;
		break;
	case 'e':
		memset(&screen[x][y], ' ', 9 - y + 1);
		break;
	case 'h':
		x = y = 0;
		break;
	case 'i':
		over = 0;
		break;
	case 'l':
		if (y > 0)
			y--;
		break;
	case 'o':
		over = 1;
		break;
	case 'r':
		if (y < 9)
			y++;
		break;
	case 'u':
		if (x > 0)
			x--;
		break;
	}
}

void
print(char c)
{
	if (!over && y < 9) {
		memmove(&screen[x][y + 1], &screen[x][y], 9 - y);
	}
	screen[x][y] = c;
	if (y < 9)
		y++;
}

void
display()
{
	int i, j;

	printf("+----------+\n");
	for (i = 0; i <= 9; i++) {
		printf("|");
		for (j = 0; j <= 9; j++) {
			printf("%c", screen[i][j]);
		}
		printf("|\n");
	}
	printf("+----------+\n");
}

void
interpret()
{
	char buf[1024];
	int len;
	int cas;
	int i, n;

	cas = 1;
	for (;;) {
		fgets(buf, sizeof(buf), stdin);
		if (sscanf(buf, "%d", &n) != 1)
			break;

		if (n == 0)
			break;

		reset();
		for (; n; n--) {
			fgets(buf, sizeof(buf), stdin);
			len = strlen(buf) - 1;
			for (i = 0; i < len; i++) {
				if (buf[i] == '^') {
					if (buf[i + 1] == '^') {
						print('^');
						i += 1;
					} else if (buf[i + 1] >= '0' && buf[i + 1] <= '9') {
						x = buf[i + 1] - '0';
						y = buf[i + 2] - '0';
						i += 2;
					} else {
						control(buf[i + 1]);
						i += 1;
					}
				} else {
					print(buf[i]);
				}
			}
		}
		printf("Case %d\n", cas++);
		display();
	}
}

int
main()
{
	interpret();
	return 0;
}
