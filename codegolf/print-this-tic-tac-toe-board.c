/*

Here is a tic-tac-toe board:

   a     b     c
      |     |
1  -  |  -  |  -
 _____|_____|_____
      |     |
2  -  |  -  |  -
 _____|_____|_____
      |     |
3  -  |  -  |  -
      |     |
Given a set of moves, print the board with the tokens on.

Input will be taken in as moves separated by spaces, with each move being:

First, the token that's going
Next, the letter of the column it is moving on
Last, the number of the row it is moving on
Note that normal tic-tac-toe rules don't matter.

Also, there is no need to print the letters and numbers.

For example, the input Ob2 Xc2 Ob3 Xa1 would result in

     |     |
  X  |  -  |  -
_____|_____|_____
     |     |
  -  |  O  |  X
_____|_____|_____
     |     |
  -  |  O  |  -
     |     |
Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

#include <stdio.h>

int
parse(const char *s)
{
	int b, i, j, m;
	char c[4];

	for (m = 0;; s += 4) {
		if (sscanf(s, "%c%c%c", c, c + 1, c + 2) != 3)
			break;

		if (!(c[0] == 'X' || c[0] == 'O'))
			goto next;
		if (!('a' <= c[1] && c[1] <= 'c'))
			goto next;
		if (!('1' <= c[2] && c[2] <= '3'))
			goto next;

		i = c[2] - '1';
		j = c[1] - 'a';
		b = (i * 3) + j;

		m |= (1 << b);
		if (c[0] == 'X')
			m |= (1 << (9 + b));

	next:
		if (!s[3])
			break;
	}
	return m;
}

void
draw(int m)
{
	static const char board[] =
	    "   a     b     c  \n"
	    "      |     |     \n"
	    "1  -  |  -  |  -  \n"
	    " _____|_____|_____\n"
	    "      |     |     \n"
	    "2  -  |  -  |  -  \n"
	    " _____|_____|_____\n"
	    "      |     |     \n"
	    "3  -  |  -  |  -  \n"
	    "      |     |     \n";

	size_t i;
	char c;
	int b;

	b = 0;
	for (i = 0; (c = board[i]); i++) {
		if (c == '-') {
			if (m & (1 << b))
				c = (m & (1 << (9 + b))) ? 'X' : 'O';
			b += 1;
		}
		printf("%c", c);
	}
	printf("\n");
}

void
tictactoe(const char *s)
{
	draw(parse(s));
}

int
main(void)
{
	tictactoe("Ob2 Xc2 Ob3 Xa1");
	tictactoe("Oa1 Xb1 Oc1 Xa2 Ob2 Xc2 Oa3 Xb3 Oc3");

	return 0;
}
