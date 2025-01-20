/*

Back to basics...
As a teacher at the local primary (grade?) school, you need a way to teach your class their times tables. At your disposal, you have hundred squares and a load of red pens. You need to also be able to show your class the correct answers quickly.

Now, you're clever enough to write a program that can do times tables, but can you draw them on a hundred square?

The challenge
Output a hundred square to stdout or equivalent using ansi-escape codes to shade in numbers which are multiples of the input.

Output a 10x10 grid containing the numbers 1-100.
It doesn't matter the alignment of 2 digit numbers in each box as long as it's consistant
For 1 digit numbers, you may pad to 2 digits and use the same formatting as 2 digit numbers or centered in the middle of the box.
If the number in the box is a multiple of the input, colour the entire box red.
This means the whole box, not just the number part
For example, given the input 3, print the given hundred square

https://i.sstatic.net/TbcJh.png

This is code golf so the shortest answer in bytes wins!

*/

#include <stdio.h>

// ported from @Glen O solution
int
output(int n)
{
	static const char red[] = "\x1b[;;41m";
	static const char normal[] = "\x1b[m";

	int v, x, y;

	printf("N=%d\n", n);
	if (n < 1)
		return -1;

	for (y = 1; y <= 10; y++) {
		if (!(y % n))
			printf("%s+---", red);
		else
			printf("+%s---", normal);
	}
	printf("+%s\n", normal);

	for (y = 0; y < 10; y++) {
		for (x = 1; x <= 10; x++) {
			v = (y * 10) + x;
			if (!(v % n))
				printf("%s|%-3d", red, v);
			else
				printf("|%s%-3d", normal, v);
		}
		printf("|%s\n", normal);

		for (x = 1; x <= 10; x++) {
			v = (y * 10) + x;
			if (!(v % n) || (!((v + 10) % n) && y < 9))
				printf("%s+---", red);
			else
				printf("+%s---", normal);
		}
		printf("+%s\n", normal);
	}
	printf("\n");

	return 0;
}

int
main()
{
	int i;

	for (i = 1; i <= 32; i++)
		output(i);

	return 0;
}
