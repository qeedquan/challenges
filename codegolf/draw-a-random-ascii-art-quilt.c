/*

For this challenge, an ASCII art quilt will be a block of text 24 characters wide and 18 lines tall, containing the characters =-<>/\ in a quilt-like pattern that is horizontally and vertically symmetrical.

Example quilt:

========================
------------------------
//\\//\\\//\/\\///\\//\\
<<><<>>>>><<>><<<<<>><>>
/\\/\\\\/\/\/\/\////\//\
------------------------
/\/////\\///\\\//\\\\\/\
\///\/\/\\\\////\/\/\\\/
\///\/\/\\\\////\/\/\\\/
/\\\/\/\////\\\\/\/\///\
/\\\/\/\////\\\\/\/\///\
\/\\\\\//\\\///\\/////\/
------------------------
\//\////\/\/\/\/\\\\/\\/
<<><<>>>>><<>><<<<<>><>>
\\//\\///\\/\//\\\//\\//
------------------------
========================
All quilts have the same form:

They are always 24 by 18.
The top line (line 1) and bottom line (line 18) are = all the way across.
Lines 2, 6, 13 and 17 are - all the way across.
Lines 4 and 15 are the same random horizontally symmetric pattern of < and >.
All other lines (3, 5, 7, 8, 9, 10, 11, 12, 14, 16) are filled with / and \ in a completely random way such that the entire quilt remains horizontally and vertically symmetric.
Notice that when folding the quilt exactly in half, either vertically or horizontally, the shapes of the characters exactly match up. Don't get this confused with the characters themselves matching up. e.g. line 3 and line 16 are not identical, they are vertical mirror images.

Challenge
Write a program or function that will print or return a random ASCII art quilt.

Due to the many hardcoded lines and the symmetry, the only real randomness comes from the first 12 characters on lines 3, 4, 5, 7, 8, 9:

The first 12 characters on line 4 should be able to be any length 12 string of the characters < and >.
The first 12 characters on lines 3, 5, 7, 8, 9 should be able to be any length 12 string of the characters / and \ (independent of each other).
These random strings are then mirrored accordingly to make the entire quilt.
The shortest answer in bytes wins. Tiebreaker is earlier post.

You may use pseudorandom number generators. (No, you don't need to prove that all 12 char string of <> or /\ can be generated with you language's PRNG.)

The output may optionally contain a trailing newline, but no trailing spaces or other characters besides what's necessary for the quilt.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char pic[18][24];
	int width;
	int height;
} FB;

void
draw(FB *fb)
{
	int x, y;

	for (y = 0; y < fb->height; y++) {
		for (x = 0; x < fb->width; x++)
			printf("%c", fb->pic[y][x]);
		printf("\n");
	}
}

void
hfill(FB *fb, int y, int c)
{
	int x;

	for (x = 0; x < fb->width; x++)
		fb->pic[y][x] = c;
}

void
hline(FB *fb, int y0, int y1, const char *pat)
{
	int i, x;

	for (x = 0; x <= fb->width / 2; x++) {
		i = rand() & 1;

		fb->pic[y0][x] = pat[i];
		fb->pic[y1][x] = pat[i];

		fb->pic[y0][fb->width - 1 - x] = pat[i ^ 1];
		fb->pic[y1][fb->width - 1 - x] = pat[i ^ 1];
	}
}

void
vline(FB *fb, int y0, int y1, const char *pat)
{
	int i, x;

	for (x = 0; x <= fb->width / 2; x++) {
		i = rand() & 1;

		fb->pic[y0][x] = pat[i];
		fb->pic[y1][x] = pat[i ^ 1];

		fb->pic[y1][fb->width - 1 - x] = pat[i];
		fb->pic[y0][fb->width - 1 - x] = pat[i ^ 1];
	}
}

void
paint(FB *fb)
{
	static const char pat1[] = "<>";
	static const char pat2[] = "/\\";

	hfill(fb, 0, '=');
	hfill(fb, 17, '=');

	hfill(fb, 1, '-');
	hfill(fb, 5, '-');
	hfill(fb, 12, '-');
	hfill(fb, 16, '-');

	hline(fb, 3, 14, pat1);

	vline(fb, 2, 15, pat2);
	vline(fb, 4, 13, pat2);
	vline(fb, 6, 11, pat2);
	vline(fb, 7, 10, pat2);
	vline(fb, 8, 9, pat2);
}

void
quilt(void)
{
	FB fb = {
	    .width = 24,
	    .height = 18,
	};

	paint(&fb);
	draw(&fb);
}

int
main(void)
{
	srand(time(NULL));
	quilt();
	return 0;
}
