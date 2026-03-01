/*

Note to mods, if the title doesn't do justice, change it to whatever, I thought it was funny.

You're tasked with hanging up the lights for this Christmas season, and your family has decided that for it to be a merry Christmas, you need to hang at least 2 Christmas lights on your house. So, your challenge is, given a number 1 < n, output the corresponding number of christmas lights you're going to be hanging according to the following specifications...

Here is the structure of a basic christmas light:

  _?_
 [___]
 /:' \
|::   |
\::.  /
 \::./
  '='
The only uncertain part is the question mark, as depending on where the light lands in the chain, the connection will greatly differ.

For the first light in the chain, you will need to output:

    .--._
  _(_
 [___]
 /:' \
|::   |
\::.  /
 \::./
  '='
For the last light in the chain, you will need to output:

_.--.
    _)_
   [___]
   /:' \
  |::   |
  \::.  /
   \::./
    '='
And for all lights in the middle:

_.--.--._
   _Y_
  [___]
  /:' \
 |::   |
 \::.  /
  \::./
   '='
Example:
N=2:

    .--.__.--.
  _(_        _)_
 [___]      [___]
 /:' \      /:' \
|::   |    |::   |
\::.  /    \::.  /
 \::./      \::./
  '='        '='
N=6:

    .--.__.--.--.__.--.--.__.--.--.__.--.--.__.--.
  _(_       _Y_      _Y_      _Y_      _Y_       _)_
 [___]     [___]    [___]    [___]    [___]     [___]
 /:' \     /:' \    /:' \    /:' \    /:' \     /:' \
|::   |   |::   |  |::   |  |::   |  |::   |   |::   |
\::.  /   \::.  /  \::.  /  \::.  /  \::.  /   \::.  /
 \::./     \::./    \::./    \::./    \::./     \::./
  '='       '='      '='      '='      '='       '='
Credit
ASCII-Art was taken from: http://www.chris.com/ascii/index.php?art=holiday/christmas/other

It was developed by a user named "jgs", who is responsible for around 40% of content on that site.

Rules
Trailing spaces are fine, same with a trailing newline.
There is 1 more space between the first and last bulb from the rest of the chain.
You may only take 1 integer as input, and the output MUST be a string, no arrays.
Your program may have undefined functions for values less than 2.
This is ascii-artcode-golf, lowest byte-count wins.

*/

#include <stdio.h>

void
lights(int n)
{
	enum {
		width = 10,
		height = 8,
	};

	static const char light1[height][width] = {
	    "    .--._",
	    "  _(_    ",
	    " [___]   ",
	    " /:' \\   ",
	    "|::   |  ",
	    "\\::.  /  ",
	    " \\::./   ",
	    "  '='    ",
	};

	static const char light2[height][width] = {
	    "_.--.--._",
	    "   _Y_   ",
	    "  [___]  ",
	    "  /:' \\  ",
	    " |::   | ",
	    " \\::.  / ",
	    "  \\::./  ",
	    "   '='   ",
	};

	static const char light3[height][width] = {
	    "_.--.    ",
	    "    _)_  ",
	    "   [___] ",
	    "   /:' \\ ",
	    "  |::   |",
	    "  \\::.  /",
	    "   \\::./ ",
	    "    '='  ",
	};

	const char *p;
	int i, x, y;

	printf("n=%d\n", n);
	for (y = 0; y < height; y++) {
		for (i = 0; i < n; i++) {
			if (i == 0)
				p = light1[y];
			else if (i == n - 1)
				p = light3[y];
			else
				p = light2[y];

			for (x = 0; x < width; x++)
				putchar(p[x]);
		}
		putchar('\n');
	}
	putchar('\n');
}

int
main(void)
{
	int i;

	for (i = 1; i <= 10; i++)
		lights(i);

	return 0;
}
