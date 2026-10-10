/*

Alphabet Rain
The Task:
The basic premise is to print out the input string and then repeat each character vertically, based on it's (0-indexed) position in the (case-insensitive) alphabet A-Z. A is at location 0 so is not repeated, e is at position 4 so is repeated 4 times, P is at position 15 so is repeated 15 times, ! is not in A-Z so is repeated 0 times, etc.

For clarity, anything that falls outside of the range B-Zb-z, for example digits or special characters, will not be repeated, and thus will only appear on the first line.

This is code-golf, so shortest solution in each language is the winner.

Input:
Input will be in the standard printable ASCII character set, from 32   up to 126 ~.
The input string will be 1 character long or longer.
There will not be any leading or trailing whitespace.
You can take take input as a string ("hello") or list of characters ( ["h", "e", "l", "l", "o"])
Examples:
Input of aaaa gives:

aaaa
Input of abcda gives:

abcda
 bcd
  cd
   d
Input of Programming Puzzles & Code Golf!, gives:

Programming Puzzles & Code Golf!
Progr mming Puzzles   Code Golf
Progr mming Puzzles   Code Golf
Progr mming Puzzles    ode Golf
Progr mming Puzzles    o e Golf
Progr mming Puzzl s    o   Golf
Progr mming Puzzl s    o   Gol
Pro r mmin  Puzzl s    o    ol
Pro r mmin  Puzzl s    o    ol
Pro r mm n  Puzzl s    o    ol
Pro r mm n  Puzzl s    o    ol
Pro r mm n  Puzzl s    o    ol
Pro r mm n  Puzz  s    o    o
Pro r    n  Puzz  s    o    o
Pro r       Puzz  s    o    o
Pr  r       Puzz  s
 r  r        uzz  s
 r  r        uzz  s
             uzz  s
             uzz
             uzz
              zz
              zz
              zz
              zz
              zz
Input of ~|[abc<0>cba]|~, gives:

~|[abc<0>cba]|~
    bc   cb
     c   c
Notes:
standard loopholes apply
output can be a list of strings, but:
extraneous trailing newlines are not allowed (single \n on final line is acceptable)
output can be a list of lists of characters, so long as it looks like it's raining characters
no leading newline
to our Nordic users who have a few extra letters in their "A-Z" alphabet, feel free to support them, but it's not part of the challenge

*/

#include <stdio.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void
rain(const char *s)
{
	size_t c, x, y, w, h;

	h = 1;
	for (w = 0; s[w]; w++) {
		c = tolower(s[w]);
		if (isalpha(c))
			h = max(h, c - 'a' + 1);
	}

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			c = tolower(s[x]);
			if (y == 0 || (isalpha(c) && c - 'a' >= y))
				printf("%c", s[x]);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	rain("aaaa");
	rain("abcda");
	rain("Programming Puzzles & Code Golf!");
	rain("~|[abc<0>cba]|~");
	rain("!@#$%^&*()_");

	return 0;
}
