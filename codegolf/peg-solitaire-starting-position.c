/*

Write a program/function to output a peg solitaire board in its starting position:

    ● ● ●
    ● ● ●
● ● ● ● ● ● ●
● ● ● ○ ● ● ●
● ● ● ● ● ● ●
    ● ● ●
    ● ● ●
Pegs must be represented as your choice of: ●,x,X,+,#

The central hole must be represented as your choice of ○,o,O,0,_,.

Note there is one space between each two pegs/holes on the same row.

Extra space above, below, or to the right of the board is allowed.

Code golf.

*/

#include <stdio.h>
#include <uchar.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
pegs()
{
	static const char8_t *art[] = {
		u8"    ● ● ●",
		u8"    ● ● ●",
		u8"● ● ● ● ● ● ●",
		u8"● ● ● ○ ● ● ●",
		u8"● ● ● ● ● ● ●",
		u8"    ● ● ●",
		u8"    ● ● ●",
	};

	size_t i;

	for (i = 0; i < nelem(art); i++)
		printf("%s\n", art[i]);
}

int
main()
{
	pegs();
	return 0;
}
