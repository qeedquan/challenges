/*

(inspired by a question over on Code Review)

Suppose two people are playing Hangman, but you've only overheard the game and want to draw the current status.

Given two words as input, where the words each match [A-Z]+ or [a-z]+ (your choice), output the current state of the hangman game as ASCII art, following the below rules.

The first word is the word to be guessed, and the second word is the already-guessed letters. These can be taken as input in any order.
The word to be guessed is guaranteed non-empty, but the already-guessed letters may be empty (i.e., as if it's the start of the game).
The game will always be a valid hangman game (i.e., guessed letters won't be duplicated, letters won't be guessed past the end of the game, you'll only receive letters as input, etc.).
Below the hangman drawing must be the word to be guessed, with _ in place of letters yet unknown, separated by spaces. For example, if the word to be guessed was BOAT, then below the hangman drawing must be _ _ _ _. If the word was BOAT with A guessed, then below the drawing must be _ _ A _.
Below the word to be guessed must be letters already guessed that are not in the word. These can be in any order, and can be separated by any non-alphabetical separator, if so desired.
Here are the states of the hangman game, from initial start to game end. Each wrongly guessed letter advances the state by one. So the first wrongly guessed letter makes the head O appear, the next makes the body | appear, etc.

  +---+
  |   |
      |
      |
      |
      |
=========

  +---+
  |   |
  O   |
      |
      |
      |
=========

  +---+
  |   |
  O   |
  |   |
      |
      |
=========

  +---+
  |   |
  O   |
 /|   |
      |
      |
=========

  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========

  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========

  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
Input
Two strings in any convenient format, with the first guaranteed non-empty.
You can take the input in either order (e.g., word to guess and then guessed letters, or vice versa). Please state in your submission the input order.
Output
The resulting ASCII art representation of the hangman game in progress, as described above, again in any convenient format.

Rules
Leading or trailing newlines or whitespace are all optional, so long as the characters themselves line up correctly.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.
Examples
#1
BOAT and ATG

  +---+
  |   |
  O   |
      |
      |
      |
=========
_ _ A T
G
#2
ZEPPELIN and

  +---+
  |   |
      |
      |
      |
      |
=========
_ _ _ _ _ _ _ _
#3
ZEPPELIN and EATOLINSHR

  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
_ E _ _ E L I N
A T O S H R
#4
RHYTHM and ABCDE

  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
_ _ _ _ _ _
EDCBA
#5
BOAT and ATOB

  +---+
  |   |
      |
      |
      |
      |
=========
B O A T
#6
AIRPLANE and AJKEI

  +---+
  |   |
  O   |
  |   |
      |
      |
=========
A I _ _ _ A _ E
KJ

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
count(const char *s, const char *t, char h[256])
{
	size_t i, r;
	int c;

	memset(h, 0, sizeof(*h) * 256);
	for (i = 0; (c = s[i] & 0xff); i++)
		h[c] |= 0x1;
	for (i = 0; (c = t[i] & 0xff); i++)
		h[c] |= 0x2;

	for (r = i = 0; i < 256; i++)
		r += (h[i] == 0x2);
	return r;
}

void
guy(size_t n)
{
	static const char *art[] = {
	    "    +---+",
	    "    |   |",
	    "    O   |",
	    "   /|\\  |",
	    "   / \\  |",
	    "        |",
	    "=========",
	};

	static const char *mask[] = {
	    "    00000",
	    "    0   0",
	    "    1   0",
	    "   324  0",
	    "   5 6  0",
	    "        0",
	    "000000000",
	};

	size_t x, y;
	char c;

	c = min(n, 6) + '0';
	for (y = 0; y < nelem(art); y++) {
		for (x = 0; art[y][x]; x++) {
			if (c >= mask[y][x])
				printf("%c", art[y][x]);
			else
				printf(" ");
		}
		printf("\n");
	}
}

void
letters(const char *s, const char *t, char h[256])
{
	size_t i;
	int c;

	for (i = 0; (c = s[i] & 0xff); i++) {
		if (h[c] == 0x3)
			printf("%c", s[i]);
		else
			printf("_");

		if (s[i + 1])
			printf(" ");
	}
	printf("\n");

	for (i = 0; (c = t[i] & 0xff); i++) {
		if (h[c] != 0x2)
			continue;

		printf("%c", t[i]);
		if (t[i + 1])
			printf(" ");
	}
	printf("\n\n");
}

void
hangman(const char *s, const char *t)
{

	size_t n;
	char h[256];

	n = count(s, t, h);
	guy(n);
	letters(s, t, h);
}

int
main()
{
	hangman("BOAT", "ATG");
	hangman("ZEPPELIN", "");
	hangman("ZEPPELIN", "EATOLINSHR");
	hangman("RHYTHM", "ABCDE");
	hangman("BOAT", "ATOB");
	hangman("AIRPLANE", "AJKEI");

	return 0;
}
