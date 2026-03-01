/*

Show the random result of a dice toss if done with a cube shaped die, in ASCII.

$ dice
should result in one of

-----
|   |
| o |
|   |
-----

-----
|o  |
|   |
|  o|
-----

-----
|o  |
| o |
|  o|
-----

-----
|o o|
|   |
|o o|
-----

-----
|o o|
| o |
|o o|
-----

-----
|o o|
|o o|
|o o|
-----

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dice(void)
{
	static const int lut[] = {0x10, 0x101, 0x111, 0x145, 0x155, 0x16d};

	int b, i, j, n;

	n = rand() % nelem(lut);
	puts("-----");
	for (i = 0; i < 3; i++) {
		printf("|");
		for (j = 0; j < 3; j++) {
			b = (i * 3) + j;
			if (lut[n] & (1 << b))
				printf("o");
			else
				printf(" ");
		}
		puts("|");
	}
	puts("-----");
}

int
main(void)
{
	srand(time(NULL));
	dice();
	return 0;
}
