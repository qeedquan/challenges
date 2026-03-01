/*

XKCD #99, with the title "Binary Heart" shows a simple image of ones and zeros, with some digits colored red.

https://i.stack.imgur.com/Lc6Fu.jpg

The red heart is visible to the naked eye, but the message hidden in the binary sequence is not. If you remove all the spaces and newlines and interpret the binary sequence as 8 bit ASCII-code, you'll end up with the message:

iloveyOuilOveyouiloveyOuilOveyOuiloveyouilOveyouilOveyOuilOv
Cute right?

Pssst... The string isn't a pure string repetition.

Your challenge is to create this binary image with 21 digits across, and 23 digits down. There should be exactly one space between each digit in each row, and one newline for each new row. Note that the last bits are only the beginning of the letter e, since 21*23 isn't divisible by 8. You need those bits correct too.

The function or program should not take any input. Leading and trailing spaces and newlines are accepted.

The result of your code should look like this:

0 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0 0 1 1 0 1
1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 0 1 0 1 0 1
1 1 1 0 0 1 0 1 0 0 1 1 1 1 0 1 1 1 0 1 0
1 0 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0 0 1 0 0
1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 0 1 0 1 0
1 1 1 1 0 0 1 0 1 1 0 1 1 1 1 0 1 1 1 0 1
0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0 0 1 1
0 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 0 1 0 1
0 1 1 1 1 0 0 1 0 1 0 0 1 1 1 1 0 1 1 1 0
1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0 0 1
0 0 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 0 1 0
1 0 1 1 1 1 0 0 1 0 1 0 0 1 1 1 1 0 1 1 1
0 1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0 0
1 1 0 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 0 1
0 1 0 1 1 1 1 0 0 1 0 1 1 0 1 1 1 1 0 1 1
1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0
0 1 0 0 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 0
1 0 1 0 1 1 1 1 0 0 1 0 1 1 0 1 1 1 1 0 1
1 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 1 0
0 0 1 0 0 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0
0 1 0 1 0 1 1 1 1 0 0 1 0 1 0 0 1 1 1 1 0
1 1 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 1
0 0 0 1 0 0 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1

This is code golf, so the shortest answer (in bytes) wins.

*/

#include <stdio.h>

void
love(void)
{
	static const char words[] = "iloveyOuilOveyouiloveyOuilOveyOuiloveyouilOveyouilOveyOuilOv";
	static const int width = 21;

	size_t i;
	int b, x;

	x = 0;
	for (i = 0; words[i]; i++) {
		for (b = 7; b >= 0; b--) {
			if (words[i] & (1 << b))
				printf("1");
			else
				printf("0");

			x += 1;
			if (x < width)
				printf(" ");
			else {
				printf("\n");
				x = 0;
			}
		}
	}
	printf("0 1 1\n");
}

int
main(void)
{
	love();
	return 0;
}
