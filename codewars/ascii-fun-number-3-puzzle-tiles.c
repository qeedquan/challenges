/*

Because my other two parts of the serie were pretty well received I decided to do another part.

Puzzle Tiles
You will get two Integer n(width) and m (height) and your task is to draw following pattern. Each line is seperated with '\n'.

Both integers are equal or greater than 1. No need to check for invalid parameters.
There are no whitespaces at the end of each line.
For example, for width = 4 and height = 3, you should draw the following pattern:

   _( )__ _( )__ _( )__ _( )__
 _|     _|     _|     _|     _|
(_   _ (_   _ (_   _ (_   _ (_
 |__( )_|__( )_|__( )_|__( )_|
 |_     |_     |_     |_     |_
  _) _   _) _   _) _   _) _   _)
 |__( )_|__( )_|__( )_|__( )_|
 _|     _|     _|     _|     _|
(_   _ (_   _ (_   _ (_   _ (_
 |__( )_|__( )_|__( )_|__( )_|

For more informations take a look in the test cases!

Series: ASCII Fun
ASCII Fun #1: X-Shape

ASCII Fun #2: Funny Dots

ASCII Fun #3: Puzzle Tiles

*/

#include <stdio.h>

void
output(const char *p, const char *s, int n)
{
	int i;

	printf("%s", p);
	for (i = 0; i < n; i++)
		printf("%s", s);
	puts("");
}

void
puzzletiles(int w, int h)
{
	int y;

	printf("%d %d\n", w, h);
	output("  ", " _( )__", w);
	for (y = 0; y < h; y++) {
		if (!(y & 1)) {
			output(" _|", "     _|", w);
			output("(_", "   _ (_", w);
		} else {
			output(" |_", "     |_", w);
			output("  _)", " _   _)", w);
		}
		output(" |", "__( )_|", w);
	}
	puts("");
}

int
main()
{
	puzzletiles(1, 1);
	puzzletiles(3, 2);
	puzzletiles(4, 3);

	return 0;
}
