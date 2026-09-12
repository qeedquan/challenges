/*

Given no input, output the following:

 _
| ~-_
| o  ~-_
| ~     ~-_
|    ＼~~~~~~
|  *   ＼
|        ＼
|~~~~~~~~~~＼
Note the backslashes are actually ＼, which is U+FF3C

Trailing whitespace is allowed, however leading whitespace is not.

This is code-golf so fewest bytes in each language wins!

*/

#include <stdio.h>

void
nepal(void)
{
	puts(" _");
	puts("| ~-_");
	puts("| o  ~-_");
	puts("| ~     ~-_");
	puts("|    ＼~~~~~~");
	puts("|  *   ＼");
	puts("|        ＼");
	puts("|~~~~~~~~~~＼");
}

int
main(void)
{
	nepal();
	return 0;
}
