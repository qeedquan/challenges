/*

https://i.stack.imgur.com/PJFZl.gif

The squares are meant to represent the side length's squared, and the areas of a + b = c, just like the Pythagorean theorem says.

This part is what you have to show.

Your task
You will get two integers as input, meant to represent sides a and b of a right triangle (ex. 3, 4).
You will then make squares out of the lengths a, b, and c out of the # character. For example here is 3:
###
###
###
You will then format these into a math equation that explains the particular Pythagorean triplet:
             #####
      ####   #####
###   ####   #####
###   ####   #####
### + #### = #####
Notice how the = and + signs have spaces on both sides and how everything is on the bottom.
You will never get values for a and b that make c non-integral.
This is code-golf so shortest code in bytes wins!
Test Cases
(more coming once I have time, these are really hard to make by hand)

3, 4
             #####
      ####   #####
###   ####   #####
###   ####   #####
### + #### = #####

6, 8
                    ##########
                    ##########
         ########   ##########
         ########   ##########
######   ########   ##########
######   ########   ##########
######   ########   ##########
######   ########   ##########
######   ########   ##########
###### + ######## = ##########

4, 3
             #####
####         #####
####   ###   #####
####   ###   #####
#### + ### = #####

5, 12
                       #############
        ############   #############
        ############   #############
        ############   #############
        ############   #############
        ############   #############
        ############   #############
        ############   #############
#####   ############   #############
#####   ############   #############
#####   ############   #############
#####   ############   #############
##### + ############ = #############

*/

#include <stdio.h>
#include <math.h>

void
visualize(int a, int b)
{
	int x, y, w, h;
	int c, r;

	c = hypot(a, b);
	w = a + b + c + 6;
	h = c;
	printf("%d, %d\n", a, b);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			r = ' ';
			if (x == a + 1 && y == h - 1)
				r = '+';
			else if (x == a + b + 4 && y == h - 1)
				r = '=';
			else if (x < a && y >= c - a)
				r = '#';
			else if (x >= a + 3 && x < a + b + 3 && y >= c - b)
				r = '#';
			else if (x >= a + b + 6)
				r = '#';

			printf("%c", r);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	visualize(3, 4);
	visualize(6, 8);
	visualize(4, 3);
	visualize(5, 12);

	return 0;
}
