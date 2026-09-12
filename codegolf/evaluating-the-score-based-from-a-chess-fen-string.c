/*

Forsyth–Edwards Notation (FEN) is a standard notation for describing a particular board position of a chess game. Your challenge is to evaluate the score using the FEN string. This is an example of a FEN string:

5k2/ppp5/4P3/3R3p/6P1/1K2Nr2/PP3P2/8
Using this string, you can calculate the material score for each color with the following score table:

p / P = Pawn = 1 point
n / N = Knight = 3 points
b / B = Bishop = 3 points
r / R = Rook = 5 points
q / Q = Queen = 9 points
k / K = King, these don't have any points because every legal position contains a king for each side
White pieces are designated using upper-case letters ("PNBRQK") while black pieces use lowercase ("pnbrqk"). Empty squares are noted using digits 1 through 8 (the number of empty squares), and "/" separates ranks.

From the example FEN string, we can calculate the material scores for each side:

For black:

5k2/ppp5/4P3/3R3p/6P1/1K2Nr2/PP3P2/8

All the black pieces left: p + p + p + p + r, this is a total of 9

For white:

5k2/ppp5/4P3/3R3p/6P1/1K2Nr2/PP3P2/8

All the white pieces left: P + R + P + N + P + P + P, this is a total of 13

The final score is determined with the following formula: White score - Black score = Final score, so for the example the final score would be: 13 - 9 = 4

Example :

Input:

5k2/ppp5/4P3/3R3p/6P1/1K2Nr2/PP3P2/8
Output:

4

All code-golf rules apply here, the solution with the least amount of bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
fenscore(const char *s)
{
	size_t i;
	int w, b, *p;

	w = b = 0;
	for (i = 0; s[i]; i++) {
		p = (isupper(s[i])) ? &w : &b;
		switch (tolower(s[i])) {
		case 'p':
			*p += 1;
			break;
		case 'n':
		case 'b':
			*p += 3;
			break;
		case 'r':
			*p += 5;
			break;
		case 'q':
			*p += 9;
			break;
		}
	}
	return w - b;
}

int
main(void)
{
	assert(fenscore("5k2/ppp5/4P3/3R3p/6P1/1K2Nr2/PP3P2/8") == 4);

	return 0;
}
