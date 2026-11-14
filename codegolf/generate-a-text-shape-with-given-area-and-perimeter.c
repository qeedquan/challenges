/*

Write a function/program to generate an ASCII art shape with a given area and perimeter, using # and   (space) characters.

Each # character has an area of 1, and each side has a length of 1. So this shape has an area of 3 and a perimeter of 8.

#
##
Input
An area (>=1) and a perimeter (>=4). You don't need to handle cases for which there is no solution.

Output
A single shape consisting of # characters that touch each other horizontally or vertically, left-padded with space characters. Shapes must not contain holes. Extra whitespace anywhere is fine. There will often be multiple solutions; you must return any one of these.

Scoring
Code golf.

Sample data
In these examples, area is the first parameter.

2,6:

##
4,8:

##
##
4,10:

####
5,12:

# #
###
10,22:

##########
10,14

####
###
###
14,30

#
########
       ####
          #

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@Jitse

A perimeter p can be achieved by placing all squares in a partially filled rectangle with size floor(p/4) by ceil(p/4).

*/

void
gen(int a, int p)
{
	int x, y, w, h;

	printf("a=%d p=%d\n", a, p);
	h = p / 4;
	for (y = 0; y < h; y++) {
		w = min((p + 2) / 4, a - (p / 4) - ((p - 1) / 4 * y) + 1);
		w = max(w, 1);
		for (x = 0; x < w; x++)
			printf("#");
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	gen(3, 8);
	gen(2, 6);
	gen(4, 8);
	gen(4, 10);
	gen(5, 12);
	gen(10, 22);
	gen(10, 14);
	gen(14, 30);

	return 0;
}
