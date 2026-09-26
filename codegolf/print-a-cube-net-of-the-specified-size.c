/*

Challenge
Given a size s, print a cube net of that size made of hash symbols (#) and spaces ().

Examples:

1:
  #
# # #
  #
  #

2:
    # #
    # #
# # # # # #
# # # # # #
    # #
    # #
    # #
    # #

3:
      # # #
      # # #
      # # #
# # # # # # # # #
# # # # # # # # #
# # # # # # # # #
      # # #
      # # #
      # # #
      # # #
      # # #
      # # #
The net can actually be any valid cube net that can fold into a cube, for example these:

    # #
    # #
# # # # # # # #
# # # # # # # #
    # #
    # #

    # # # #
    # # # #
    # #
    # #
    # #
    # #
# # # #
# # # #

Rules
The resulting net must be geometrically valid (foldable into a cube)
Standard loopholes forbidden
Read the rules carefully
This is code-golf, shortest answer wins, but will not be selected

*/

#include <stdio.h>

void
pound(int w, int h)
{
	int x, y;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("# ");
		puts("");
	}
}

/*

@xnor

Prints this net, chosen for being left-justified:

# #
# #
# # # # # # # #
# # # # # # # #
# #
# #

The lines have n or 4*n copies of '# '. For each of 1,4,1, we print n times that many copies, done n times for n lines. Having an exec loop inside a for loop seems wasteful, but I didn't see better.

*/

void
cubenet(int n)
{
	printf("n=%d\n", n);
	pound(n, n);
	pound(4 * n, n);
	pound(n, n);
	puts("");
}

int
main()
{
	int i;

	for (i = 1; i <= 4; i++)
		cubenet(i);

	return 0;
}
