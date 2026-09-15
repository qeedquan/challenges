/*

Given two input integers, a >= 4 and b >= 2, output an ASCII square of size a x a. The twist is the square must be constructed of b 3 x 3 squares formed like the following:

###
# #
###
You can use any ASCII printable character (except whitespace) to construct the smaller squares. I'm using # for visibility and consistency.

The first b square is always placed in the upper-left, and the remaining b squares must be as evenly spaced as possible, going clockwise, around the larger square. The overall a x a square size is calculated in characters based on the center of the b squares.

Here's an example for a=7 and b=3. Note the numbers around the outside are not part of the output, just used to illustrate the construction.

   1234567
  ###
1 # #       1
2 ###   ### 2
3       # # 3
4       ### 4
5           5
6   ###     6
7   # #     7
    ###
   1234567
The first b square is placed in the upper-left corner. In the remaining possible areas on the perimeter of a x a, we need to place two more b squares. Note how the smaller squares are staggered -- how they're spaced as evenly as possible around the larger square. If a potential b square could be in one of two spaces, your code can pick either and does not need to be deterministic.

Here's another diagram explaining the spacing. I've drawn the a square with -+| and marked the center of the smaller b squares with *. If we count clockwise around the outside of the a square, we have 7 characters between the first and second centers -----+|, 7 between the second and third |||+---, and again 7 between the third and first -+|||||. This lines up mathematically as well, since we have 24 total characters making up the a square, minus 3 for the center of the b squares, must mean we have 7 characters between the centers. And, since the upper-left b square is fixed, this is the most evenly spaced arrangement possible.

   1234567
  ###
1 #*-----+  1
2 #|#   #|# 2
3  |    #*# 3
4  |    #|# 4
5  |     |  5
6  |###  |  6
7  +-*---+  7
    ###
   1234567
Input
A two integers in any convenient format, a >= 4 and b >= 2.
You can take the input in either order -- your choice.
The input is guaranteed to be such that no b squares will overlap.
Output
The resulting ASCII art representation of the squares.

Rules
Leading or trailing newlines or whitespace are all optional, so long as the characters themselves line up correctly.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.
Examples
(note these are just examples, and depending upon how your code rounds the placement you may have slightly different output)

a=4, b=4
######
# ## #
######
######
# ## #
######

a=4, b=2
###
# #
###
   ###
   # #
   ###

a=7, b=4
###   ###
# #   # #
###   ###



###   ###
# #   # #
###   ###

a=5, b=3
###
# #
### ###
    # #
 ######
 # #
 ###

a=7, b=3
###
# #
###   ###
      # #
      ###

  ###
  # #
  ###

a=7, b=5
###  ###
# #  # #
###  ###


###   ###
# ##### #
#### ####
   ###

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ported from @Seth solution
int
squares(int a, int b)
{
	char *s, *p;
	int i, j;
	int x, y;

	printf("a=%d, b=%d\n", a, b);
	if (a < 1)
		return -1;

	a += 3;
	s = calloc(1, a * a * 2);
	if (!s)
		return -1;

	for (i = 0; i <= a; i++)
		sprintf(s + (i * a), "%*s\n", a - 1, " ");

	for (i = 0; i < b; i++) {
		j = ((a - 4) * i * 4) / b;
		for (x = y = 1; j > 0; j--) {
			if (y > 1 && x < 2)
				y--;
			else if (y > a - 4)
				x--;
			else if (x > a - 4)
				y++;
			else
				x++;
		}

		p = s + (y - 1) * a + x - 1;
		memmove(p, "###", 3);

		p += a;
		memmove(p, "# #", 3);

		p += a;
		memmove(p, "###", 3);
	}
	printf("%s\n", s);

	free(s);
	return 0;
}

int
main()
{
	squares(4, 4);
	squares(4, 2);
	squares(7, 4);
	squares(5, 3);
	squares(7, 3);
	squares(7, 5);

	return 0;
}
