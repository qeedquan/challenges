/*

I need help making a brick road to go beside my brick wall!

\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \
 \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__
__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\
\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \
 \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__
__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\
\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \
 \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__
__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\
\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \__\  \
This road is 10 characters long and 70 characters wide, seems familiar right?

We have to stay efficient with this road as well, no input and lowest byte count in some code that produces this pattern in an output wins!

This code-golf puzzle isn't the same as the predecessor mentioned above, as the output requires a different approach rather than just simply outputting what it asks (because the pattern is offscured and not exactly the same). It was purposefully included like this for the puzzle to match the theme of my page and also include a higher difficulty for the user (the original was very simple for some). This was mentioned below in the comments.

*/

#include <stdio.h>

void
brickroad()
{
	static const char sym[] = "\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\__\\  \\";

	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = i * 2; j < 70; j++)
			putchar(sym[j]);
		for (j = 4; j < (i * 3) + 4 - i; j++)
			putchar(sym[j]);
		putchar('\n');
	}
}

int
main()
{
	brickroad();
	return 0;
}
