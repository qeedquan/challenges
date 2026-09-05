/*

In chess, Forsyth-Edwards Notation, more commonly called "FEN", is a textual way of transcribing boards. It describes each of the board's eight rows (called "ranks" in chess) from top to bottom from White's perspective. The pieces are written as K (king), Q (queen), R (rook), B (bishop), N (knight), and P (pawn). Black pieces use these letters in lowercase, and white pieces use these letters in uppercase. Empty spaces are indicated by a number from 1 to 8 indicating how many consecutive empty spaces there are. A completely empty rank would be 8, a single black rook in the rightmost column (called "files" in chess) would be 7r, and two white pawns on each end of a row would be PP4PP. Ranks are separated by a /. There is normally other information added, indicating which side is to move, castling and en passant rights, move number, and halfmove clock, but we will ignore them for the purposes of this challenge.

Input
A FEN string, from the command line or STDIN, as you please. You may assume that this string is always valid.

Output
Write to STDOUT a simple ASCII art representation of the board as it would actually appear:

Pieces are represented by their character in FEN
Empty squares are represented by spaces
Pieces and squares are separated by a pipe | and there are pipes on each side of the board
So an empty board, written as 8/8/8/8/8/8/8/8 in FEN, would appear as

| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
The starting position of a chess game is written as rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR, and would appear as

|r|n|b|q|k|b|n|r|
|p|p|p|p|p|p|p|p|
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
| | | | | | | | |
|P|P|P|P|P|P|P|P|
|R|N|B|Q|K|B|N|R|
The final position of Anderssen-Kieseritzky 1851, called "The Immortal Game" in the chess community, is written as r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1, and your program when fed that input would output:

|r| |b|k| | | |r|
|p| | |p|B|p|N|p|
|n| | | | |n| | |
| |p| |N|P| | |P|
| | | | | | |P| |
| | | |P| | | | |
|P| |P| |K| | | |
|q| | | | | |b| |

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char Board[8][8];

int
readfen(Board b, const char *s)
{
	const char *p;
	int r, c;

	memset(b, ' ', 8 * 8);

	r = c = 0;
	for (p = s; *p; p++) {
		if (r >= 8 || (c >= 8 && *p != '/'))
			return -1;

		if (*p == '/') {
			r = r + 1;
			c = 0;
		} else if (strchr("rnbqkp", tolower(*p)))
			b[r][c++] = *p;
		else if (isdigit(*p))
			c += *p - '0';
		else
			return -1;
	}
	return 0;
}

void
display(Board b)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			printf("|%c", b[i][j]);
		printf("|\n");
	}
	printf("\n");
}

void
test(const char *s)
{
	Board b;

	assert(readfen(b, s) >= 0);
	display(b);
}

int
main(void)
{
	test("8/8/8/8/8/8/8/8");
	test("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
	test("r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1");

	return 0;
}
