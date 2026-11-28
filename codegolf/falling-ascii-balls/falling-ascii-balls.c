/*

Input
You are given a 2D map with balls and ground in it. It looks like this:

  1         5          2
                 3
     4


__________________________
Each number is a ball, and the _ is ground level. The underscore _ character is not allowed in any other line than ground level line. There are only spaces, newlines and digits 0-9 allowed above ground level. You cannot assume that last line is the ground level - empty lines below ground level are allowed. You can also add spaces, to fill empty lines, if that does help you.

Balls can have numbers from 0 to 9, can be placed above each other, but not under ground. The ball's numbers will be unique.

Assume that each character is one meter.

Get map from pastebin!
https://paste.ubuntu.com/17848771/
Test case 1 - should output something like this
https://paste.ubuntu.com/17854204/
Test case 2 - should produce same results as first map
https://paste.ubuntu.com/17854273/

Challenge
Your challenge is to read a map like that from a file or from stdin — you are allowed to use cat balls.txt | ./yourexecutable — and output velocity of each ball when it hits the ground.

Here's the formula for velocity:
v = sqrt(2 * h * g)

Assume that h is the line number difference between the ground's line number, and the ball's line number, and that g equals 10m/s^2.

Output
You should output each balls number and velocity in m/s at ground level. For example N - Vm/s, where N is ball number and V is its velocity. You can also output an array if you want.

Happy coding! :)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

void
sim(FILE *fp)
{
	static const double G = 10;

	size_t h[256];
	size_t l;
	int c;

	memset(h, 0, sizeof(h));
	l = 0;
	for (;;) {
		c = fgetc(fp);
		if (c == EOF || c == '_')
			break;

		if (c == '\n')
			l += 1;
		h[c] = l;
	}

	for (c = '0'; c <= '9'; c++) {
		if (h[c])
			printf("%c %f\n", c, sqrt((l - h[c]) * 2 * G));
	}
}

void
usage()
{
	fprintf(stderr, "usage: <file>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
		usage();

	fp = fopen(argv[1], "r");
	if (!fp) {
		fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
		return 1;
	}

	sim(fp);
	fclose(fp);

	return 0;
}
