/*

A Rubik's cube has 6 colors: red, orange, yellow, white, blue, and green. Red and orange, yellow and white, and blue and green faces are on opposite sides.

Net of a solved Rubik's cube looks like this:

 Y
BRGO
 W
And the tiles look like this:

      Y Y Y
      Y Y Y
      Y Y Y
B B B R R R G G G O O O
B B B R R R G G G O O O
B B B R R R G G G O O O
      W W W
      W W W
      W W W
Challenge
Given rotations, reversed rotations, or double rotations output what a solved cube will transform to, as ASCII art or as an image (whitespaces aren't necessary, may or may not exist, trailing whitespaces are allowed.).

Input will be rotation (and optional modifier). Rotation notation goes like: U(p), L(eft), F(ront), R(ight), B(ack), D(own); 2 (double), ' or i (inverse).

All normal rotations will be 90° clockwise, inverse ones will be counterclockwise.

Explanation about clockwiseness: Imagine the cube as you're looking at the red face, and the yellow face is at the top. Then rotate the cube so that the face that the program will rotate will face you. This is the way clockwiseness will work. (Except back face, you will rotate the cube horizontally in that case.)

Input
Input will be a list of moves.

Output
An ASCII art that represents the cube or an image of the net of the cube.

Examples
Input: (empty)

Output:

      Y Y Y
      Y Y Y
      Y Y Y
B B B R R R G G G O O O
B B B R R R G G G O O O
B B B R R R G G G O O O
      W W W
      W W W
      W W W
Input: U (up)

Output:

      Y Y Y
      Y Y Y
      Y Y Y
R R R G G G O O O B B B
B B B R R R G G G O O O
B B B R R R G G G O O O
      W W W
      W W W
      W W W
Input: U' or Ui (inverse up)

Output:

      Y Y Y
      Y Y Y
      Y Y Y
O O O B B B R R R G G G
B B B R R R G G G O O O
B B B R R R G G G O O O
      W W W
      W W W
      W W W
Input: U2 (double up)

Output:

      Y Y Y
      Y Y Y
      Y Y Y
G G G O O O B B B R R R
B B B R R R G G G O O O
B B B R R R G G G O O O
      W W W
      W W W
      W W W
Input: L' (inversed left)

Output:

      R Y Y
      R Y Y
      R Y Y
B B B W R R G G G O O Y
B B B W R R G G G O O Y
B B B W R R G G G O O Y
      O W W
      O W W
      O W W
Input: R (right)

Output:

      Y Y R
      Y Y R
      Y Y R
B B B R R W G G G Y O O
B B B R R W G G G Y O O
B B B R R W G G G Y O O
      W W O
      W W O
      W W O
Input: U2 L' D (double up, inverse left, down)

Output:

      O Y Y
      R Y Y
      R Y Y
G B B W O O B B B R R Y
G B B W R R G G G O O Y
O O Y G B B W R R G G G
      R O O
      W W W
      W W W
Rules
No loopholes allowed.
This is code-golf, so shortest code in bytes solving the problem wins.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef int Rubik[12][12];

void
drawside(Rubik r, int s)
{
	int i;

	for (i = 1; i <= 9; i++) {
		switch (i % 3) {
		case 0:
			printf("%c\n", r[s][i]);
			break;
		case 1:
			printf("      %c ", r[s][i]);
			break;
		case 2:
			printf("%c ", r[s][i]);
			break;
		}
	}
}

void
drawbody(Rubik r)
{
	int i, j, k;

	for (k = 1; k <= 3; k++) {
		for (i = 3; i <= 6; i++) {
			for (j = (k * 3) - 2; j <= k * 3; j++)
				printf("%c ", r[(i % 4) + 1][j]);
		}
		printf("\n");
	}
}

void
draw(Rubik r)
{
	drawside(r, 5);
	drawbody(r);
	drawside(r, 6);
	printf("\n");
}

void
move(Rubik f, Rubik t, int a, int b, int c, int d)
{
	t[c][d] = f[a][b];
}

void
movef(Rubik f, Rubik t, int a)
{
	move(f, t, a, 1, a, 3);
	move(f, t, a, 2, a, 6);
	move(f, t, a, 3, a, 9);
	move(f, t, a, 4, a, 2);
	move(f, t, a, 6, a, 8);
	move(f, t, a, 7, a, 1);
	move(f, t, a, 8, a, 4);
	move(f, t, a, 9, a, 7);
}

void
forward(Rubik r)
{
	Rubik t;

	memcpy(t, r, sizeof(t));
	movef(r, t, 1);
	move(r, t, 5, 7, 2, 1);
	move(r, t, 5, 8, 2, 4);
	move(r, t, 5, 9, 2, 7);
	move(r, t, 2, 1, 6, 1);
	move(r, t, 2, 4, 6, 2);
	move(r, t, 2, 7, 6, 3);
	move(r, t, 6, 1, 4, 3);
	move(r, t, 6, 2, 4, 6);
	move(r, t, 6, 3, 4, 9);
	move(r, t, 4, 3, 5, 7);
	move(r, t, 4, 6, 5, 8);
	move(r, t, 4, 9, 5, 9);
	memcpy(r, t, sizeof(t));
}

void
back(Rubik r)
{
	Rubik t;

	memcpy(t, r, sizeof(t));
	movef(r, t, 3);
	move(r, t, 2, 3, 5, 1);
	move(r, t, 2, 6, 5, 2);
	move(r, t, 2, 9, 5, 3);
	move(r, t, 4, 1, 6, 7);
	move(r, t, 4, 4, 6, 8);
	move(r, t, 4, 7, 6, 9);
	move(r, t, 5, 1, 4, 7);
	move(r, t, 5, 2, 4, 4);
	move(r, t, 5, 3, 4, 1);
	move(r, t, 6, 7, 2, 9);
	move(r, t, 6, 8, 2, 6);
	move(r, t, 6, 9, 2, 3);
	memcpy(r, t, sizeof(t));
}

void
left(Rubik r)
{
	Rubik t;

	memcpy(t, r, sizeof(t));
	movef(r, t, 4);
	move(r, t, 1, 1, 6, 1);
	move(r, t, 1, 4, 6, 4);
	move(r, t, 1, 7, 6, 7);
	move(r, t, 3, 3, 5, 7);
	move(r, t, 3, 6, 5, 4);
	move(r, t, 3, 9, 5, 1);
	move(r, t, 5, 1, 1, 1);
	move(r, t, 5, 4, 1, 4);
	move(r, t, 5, 7, 1, 7);
	move(r, t, 6, 1, 3, 9);
	move(r, t, 6, 4, 3, 6);
	move(r, t, 6, 7, 3, 3);
	memcpy(r, t, sizeof(t));
}

void
right(Rubik r)
{
	Rubik t;

	memcpy(t, r, sizeof(t));
	movef(r, t, 2);
	move(r, t, 1, 3, 5, 3);
	move(r, t, 1, 6, 5, 6);
	move(r, t, 1, 9, 5, 9);
	move(r, t, 6, 3, 1, 3);
	move(r, t, 6, 6, 1, 6);
	move(r, t, 6, 9, 1, 9);
	move(r, t, 5, 3, 3, 7);
	move(r, t, 5, 6, 3, 4);
	move(r, t, 5, 9, 3, 1);
	move(r, t, 3, 1, 6, 9);
	move(r, t, 3, 4, 6, 6);
	move(r, t, 3, 7, 6, 3);
	memcpy(r, t, sizeof(t));
}

void
up(Rubik r)
{
	Rubik t;

	memcpy(t, r, sizeof(t));
	movef(r, t, 5);
	move(r, t, 1, 1, 4, 1);
	move(r, t, 1, 2, 4, 2);
	move(r, t, 1, 3, 4, 3);
	move(r, t, 2, 1, 1, 1);
	move(r, t, 2, 2, 1, 2);
	move(r, t, 2, 3, 1, 3);
	move(r, t, 3, 1, 2, 1);
	move(r, t, 3, 2, 2, 2);
	move(r, t, 3, 3, 2, 3);
	move(r, t, 4, 1, 3, 1);
	move(r, t, 4, 2, 3, 2);
	move(r, t, 4, 3, 3, 3);
	memcpy(r, t, sizeof(t));
}

void
down(Rubik r)
{
	Rubik t;

	memcpy(t, r, sizeof(t));
	movef(r, t, 6);
	move(r, t, 1, 7, 2, 7);
	move(r, t, 1, 8, 2, 8);
	move(r, t, 1, 9, 2, 9);
	move(r, t, 2, 7, 3, 7);
	move(r, t, 2, 8, 3, 8);
	move(r, t, 2, 9, 3, 9);
	move(r, t, 3, 7, 4, 7);
	move(r, t, 3, 8, 4, 8);
	move(r, t, 3, 9, 4, 9);
	move(r, t, 4, 7, 1, 7);
	move(r, t, 4, 8, 1, 8);
	move(r, t, 4, 9, 1, 9);
	memcpy(r, t, sizeof(t));
}

void
rotate(Rubik r, const char *s)
{
	size_t i;
	int op;
	int m, n;

	for (i = 0; s[i]; i++) {
		if (isspace(s[i]))
			continue;

		op = s[i];
		n = 1;
		switch (s[i + 1]) {
		case '\'':
		case 'i':
			n = 3;
			i += 1;
			break;
		case '2':
			n = 2;
			i += 1;
			break;
		}

		for (m = 0; m < n; m++) {
			switch (op) {
			case 'F':
				forward(r);
				break;
			case 'B':
				back(r);
				break;
			case 'L':
				left(r);
				break;
			case 'R':
				right(r);
				break;
			case 'U':
				up(r);
				break;
			case 'D':
				down(r);
				break;
			}
		}
	}
}

void
init(Rubik r)
{
	static const char sym[] = " RGOBYW";

	int i, j;

	memset(r, 0, sizeof(Rubik));
	for (i = 1; i <= 7; i++) {
		for (j = 1; j <= 10; j++)
			r[i][j] = sym[i];
	}
}

void
test(const char *s)
{
	Rubik r;

	init(r);
	rotate(r, s);
	printf("\"%s\"\n", s);
	draw(r);
}

int
main()
{
	test("");
	test("U");
	test("U'");
	test("U2");
	test("L'");
	test("R");
	test("U2 L' D");

	return 0;
}
