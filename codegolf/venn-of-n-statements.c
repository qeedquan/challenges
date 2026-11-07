/*

Given a positive integer n, output n 2D bool images with the same width and height such that:

Each image should be 4-connected, i.e. for each two pixels that are true, you can start from one and go up, down, left and right for some times to the other pixel, only passing through true pixels.
Each image should have no holes, i.e. the complement should be 4-connected.
If we choose itself or its complement for each image, their intersection should be non-empty and 4-connected.
Examples (only a finite amount of solutions shown, but there are infinitely many more)

Input: 1

Possible output:

.....
.***.
.**..
..*..
Input: 1

Possible output:

.....
...*.
.....
.....
Input: 2

Possible output:

..... .....
.***. ..**.
..... ..**.
..... .....
Input: 2

Possible output:

..... .....
.**.. ..**.
..**. ..**.
..... .....
Input: 3

Possible output:

..... ..... .....
.**.. ..**. .....
.**.. ..**. .***.
..... ..... .***.
Input: 4

Possible output:

....... ....... ....... .......
.***... ..***.. ....... .......
.***... ..***.. .*****. .......
.***... ..***.. .*****. .*****.
.***... ..***.. ....... .*****.
....... ....... ....... .......
The shortest code in each language wins.

*/

#include <stdio.h>

/*

@Anders Kaseorg

Generates 3×2^n images like these:

..*  ..*  ..*  ..*
.**  ..*  ..*  ..*
..*  .**  ..*  ..*
.**  .**  ..*  ..*
..*  ..*  .**  ..*
.**  ..*  .**  ..*
..*  .**  .**  ..*
.**  .**  .**  ..*
..*  ..*  ..*  .**
.**  ..*  ..*  .**
..*  .**  ..*  .**
.**  .**  ..*  .**
..*  ..*  .**  .**
.**  ..*  .**  .**
..*  .**  .**  .**
.**  .**  .**  .**

*/

void
venn(int n)
{
	int c, i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < (1 << n); j++) {
			c = '.';
			if ((j >> i) & 1)
				c = '*';
			printf(".%c*\n", c);
		}
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		venn(i);

	return 0;
}
