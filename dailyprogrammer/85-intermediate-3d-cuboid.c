/*

Write a program that outputs simple 3D ASCII art for a cuboid in an oblique perspective, given a length, height, and depth, like this:

$ python 3d.py 20 10 3
   :::::::::::::::::::/
  :::::::::::::::::::/+
 :::::::::::::::::::/++
####################+++
####################+++
####################+++
####################+++
####################+++
####################+++
####################+++
####################++
####################+
####################
(The characters used for the faces (here #, :, and +) are fully up to you, but make sure you don't forget the / on the top-right edge.)

*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
cuboid(int w, int h, int d)
{
	int i;

	printf("(%d, %d, %d)\n", w, h, d);
	for (i = 0; i < d; i++) {
		repeat(" ", d - i);
		repeat(":", w - 1);
		printf("/");
		repeat("+", i);
		printf("\n");
	}
	for (i = 0; i < h - d; i++) {
		repeat("#", w);
		repeat("+", d);
		printf("\n");
	}
	for (i = 0; i < d; i++) {
		repeat("#", w);
		repeat("+", d - i - 1);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	cuboid(20, 10, 3);
	cuboid(4, 4, 4);
	cuboid(1, 2, 3);

	return 0;
}
