/*

As in, the 5 speed transmission from the original VW Golf GTI.

Print the transmission pattern in as few bytes as possible.

Yes I know this isn't what it actually looks like but the GTI 5 speed shift knob pattern is a lot worse.

1  3  5
|  |  |
|--|--|
|  |  |
2  4  R

*/

#include <stdio.h>

void
transmission(void)
{
	puts("1  3  5");
	puts("|  |  |");
	puts("|--|--|");
	puts("|  |  |");
	puts("2  4  R");
}

int
main(void)
{
	transmission();
	return 0;
}
