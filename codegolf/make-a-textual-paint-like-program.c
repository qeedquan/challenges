/*

Write a program/function that can help users make simple drawings by moving a cursor contained within a grid of characters, and by selecting which characters should be at a specific position.

Expected Input and Output
The user will be able to work on an area of 80 x 25 characters and will start at position (0, 0). You must then execute commands given as input, each command represented by a specific character. You can assume that the input will only contain a valid set of commands. Your program must be able to execute the following commands:

w,a,s,d : Move the cursor up, left, down or right if the cursor will still be within the boundaries, do nothing otherwise. Your program must work correctly even if the user tries to leave the drawing area.
0,1,2,3,4 : Replace the character at the cursor's position by the corresponding character :  ░▒▓█.
? : Read the next input character and save it. You can assume that only printable ASCII characters can be inputted (code 32 to 126 inclusive).
! : Read the character at the cursor's position and save it. ! can therefore save printable ASCII characters and  ░▒▓█.
5 : Replace the character at the cursor's position by the last character received with the ? or ! command.
This is code-golf, so the shortest answer in bytes will win.

Test Cases
It will obviously be hard to display the final output, since it requires 25 lines, so these examples will only display the first five lines. Ignore the / and - symbols, they are just here as delimiters for readability.

Input: 1s1s1d2w2w2d3s3s3d4w4w4d3s3s3d2w2w2d1s1s1
Final Output:

░▒▓█▓▒░                                                                         /
░▒▓█▓▒░                                                                         /
░▒▓█▓▒░                                                                         /
                                                                                /
                                                                                /
--------------------------------------------------------------------------------/
Input: 2dsaw!s5s5d5d5d5d5d5d5s5s5a5a5a5a5w5w3w5w5a5a3
Final Output:

▓▒▒                                                                             /
▒ ▒                                                                             /
▒▒▓▒▒▒▒                                                                         /
  ▒   ▒                                                                         /
  ▒▒▒▒▒                                                                         /
--------------------------------------------------------------------------------/
Input: aaaaasd?H5d?e5d?l5d5d?a5d?!5a?o5s4d4aa4a4a4a4
Final Output:

                                                                                /
 Hello!                                                                         /
 ██████                                                                         /
                                                                                /
                                                                                /
--------------------------------------------------------------------------------/

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

enum {
	W = 80,
	H = 25,
};

typedef struct {
	char p[H][W];
	int c, x, y;
} Frame;

int
clamp(int x, int a, int b)
{
	if (x < a)
		x = a;
	else if (x > b)
		x = b;
	return x;
}

void
reset(Frame *f)
{
	memset(f, 0, sizeof(*f));
}

void
paint(Frame *f, const char *s)
{
	for (; *s; s++) {
		switch (*s) {
		case 'w':
			f->y--;
			break;
		case 'a':
			f->x--;
			break;
		case 's':
			f->y++;
			break;
		case 'd':
			f->x++;
			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
			f->p[f->y][f->x] = s[0] - '0';
			break;

		case '?':
			f->c = *(++s);
			break;
		case '!':
			f->c = f->p[f->y][f->x];
			break;

		case '5':
			f->p[f->y][f->x] = f->c;
			break;
		}

		f->x = clamp(f->x, 0, W);
		f->y = clamp(f->y, 0, H);
	}
}

void
draw(Frame *f)
{
	static const unsigned char *sym[] = {
		u8" ",
		u8"░",
		u8"▒",
		u8"▓",
		u8"█",
	};

	int c, x, y;

	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++) {
			c = f->p[y][x];
			if (c < (int)nelem(sym))
				printf("%s", sym[c]);
			else
				printf("%c", c);
		}
		printf("/\n");
	}
	for (x = 0; x < W; x++)
		printf("-");
	printf("\n\n");
}

void
test(const char *s)
{
	Frame f;

	reset(&f);
	paint(&f, s);
	draw(&f);
}

int
main()
{
	test("1s1s1d2w2w2d3s3s3d4w4w4d3s3s3d2w2w2d1s1s1");
	test("2dsaw!s5s5d5d5d5d5d5d5s5s5a5a5a5a5w5w3w5w5a5a3");
	test("aaaaasd?H5d?e5d?l5d5d?a5d?!5a?o5s4d4aa4a4a4a4");

	return 0;
}
