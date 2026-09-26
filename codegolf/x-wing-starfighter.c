/*

Today is May 4th, Star Wars day, so here's a Star Wars ASCII-art task. Output this image of an X-Wing starfighter:

\             /
o\           /o
V \(+)___(+)/ V
|  --/ | \--  |
  /(+)\|/(+)\
 /    |||    \
/o     |     o\
 V           V
 |           |

Your output may have any extra whitespace that doesn't effect the representation of the image. You may output a list of lines instead of a string with newlines.

This is code-golf, so shortest answer wins. May the 4th be with you!

(If it's May 5th in your timezone, try Sith TIE-Fighter)

*/

#include <stdio.h>

void
xwing(void)
{
	puts("\\             /");
	puts("o\\           /o");
	puts("V \\(+)___(+)/ V");
	puts("|  --/ | \\--  |");
	puts("  /(+)\\|/(+)\\");
	puts(" /    |||    \\");
	puts("/o     |     o\\");
	puts(" V           V");
	puts(" |           |");
}

int
main(void)
{
	xwing();
	return 0;
}
