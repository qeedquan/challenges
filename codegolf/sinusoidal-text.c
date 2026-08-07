/*

Goal: Write a program or function which prints an input string in a sinusoidal shape.

The ASCII sinusoid
Here is one period of the sinusoid:

         .......
      ...       ...
    ..             ..
   .                 .
  .                   .
 .                     .
.                       .                       .
                         .                     .
                          .                   .
                           .                 .
                            ..             ..
                              ...       ...
                                 .......
Note that there is exactly one dot on each column.

Each character in the input string will replace a dot in the shape above, from left to right.
Spaces in the input have to be outputted like normal characters, in place of a dot.
The starting character corresponds to the leftmost dot in the figure above.
This is only one period, inputs can be longer than the number of dots above.
Input
Inputs are ASCII strings that contain only characters between ASCII decimal 32 (space) and ASCII decimal 126 (Tilde ~).
Inputs will always be one line only (no linebreaks).
Inputs can be taken via STDIN, function parameters, command line arguments, or anything similar.
Output
Output must be printed exactly like they are in the test cases given.
Trailing spaces on lines are allowed as long as the length of the line with those trailing spaces does not exceed the length of the longest line (the one with the last character on it).
No leading/trailing line allowed.
Test cases
Input: .................................................
Output:

         .......
      ...       ...
    ..             ..
   .                 .
  .                   .
 .                     .
.                       .                       .
                         .                     .
                          .                   .
                           .                 .
                            ..             ..
                              ...       ...
                                 .......
Input: Programming Puzzles & Code Golf Stack Exchange is a question and answer site for programming puzzle enthusiasts and code golfers. It's 100% free, no registration required.
Output:

         ng Puzz                                         ion and                                         siasts                                          stratio
      mmi       les                                   est        an                                   thu       and                                   egi       n r
    ra              &                               qu             sw                               en              c                                r             eq
   g                                                                 e                                               o                             o                 u
  o                   C                           a                   r                           e                   d                           n                   i
 r                     o                                                                         l                     e                                               r
P                       d                       s                       s                       z                                               ,                       e
                         e                     i                         i                     z                         g                     e                         d
                                                                          t                   u                           o                   e                           .
                           G                 e                             e                 p                             l                 r
                            ol             ng                                f             g                                fe              f
                              f S       cha                                   or        min                                   rs.       00%
                                 tack Ex                                         program                                          It's 1
Input: Short text.
Output:

         t.
      tex
    t
   r
  o
 h
S
Input: The quick brown fox jumps over the lazy dog
Output:

          brown
      ick       fox
    qu              j
                     u
  e                   m
 h                     p
T                       s

                          o
                           v
                            er
                               th       dog
                                 e lazy
Scoring
This is code-golf, so the shortest program or function in bytes wins.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
sineprint(const char *s)
{
	static const char wave[][50] = {
	    "         .......                                 ",
	    "      ...       ...                              ",
	    "    ..             ..                            ",
	    "   .                 .                           ",
	    "  .                   .                          ",
	    " .                     .                         ",
	    ".                       .                       .",
	    "                         .                     . ",
	    "                          .                   .  ",
	    "                           .                 .   ",
	    "                            ..             ..    ",
	    "                              ...       ...      ",
	    "                                 .......         ",
	};

	static const size_t width = nelem(wave[0]) - 1;
	static const size_t height = nelem(wave);

	size_t x, y;
	int c;

	for (y = 0; y < height; y++) {
		for (x = 0; s[x]; x++) {
			c = wave[y][x % width];
			if (c != ' ')
				c = s[x];

			putchar(c);
		}
		putchar('\n');
	}
}

int
main(void)
{
	sineprint(".................................................");
	sineprint("Programming Puzzles & Code Golf Stack Exchange is a question and answer site for programming puzzle enthusiasts and code golfers. It's 100% free, no registration required.");
	sineprint("Short text.");
	sineprint("The quick brown fox jumps over the lazy dog");
	sineprint("Hello, World!");

	return 0;
}
