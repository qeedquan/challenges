/*

Consider the following ASCII image of five concentric anti-aliased ASCII aureoles:

                 ........
            .@..............@.
        .....                .....
      .@..    ...@@@@@@@@...    ..@.
    .@.    ..@@..        ..@@..    .@.
   .@.   .@@.    ........    .@@.   .@.
  .@    @@    .@@@@@..@@@@@.    @@    @.
 .@    @.   .@@.          .@@.   .@    @.
 @.   @@   @@.   @@@@@@@@   .@@   @@   .@
.@   .@   .@.   @@@.  .@@@   .@.   @.   @.
.@   @@   @@   @@   @@   @@   @@   @@   @.
.@   @@   @@   @@   @@   @@   @@   @@   @.
.@   .@   .@.   @@@.  .@@@   .@.   @.   @.
 @.   @@   @@.   @@@@@@@@   .@@   @@   .@
 .@    @.   .@@.          .@@.   .@    @.
  .@    @@    .@@@@@..@@@@@.    @@    @.
   .@.   .@@.    ........    .@@.   .@.
    .@.    ..@@..        ..@@..    .@.
      .@..    ...@@@@@@@@...    ..@.
        .....                .....
            .@..............@.
                 ........
You must write a program to draw a given subset of the above circles in as few characters as possible.

The input is either five booleans in your choice of formatting (be it 1 1 1 1 1 or [False, True, False, False, True]), with the first boolean corresponding to the inner-most circle, or an integer where the least-significant bit corresponds to the inner circle (e.g. 1 0 0 1 1 is equivalent to 25).

Output for 1 1 1 1 1/31: see above.

Output for 1 0 1 0 1/21:

                 ........
            .@..............@.
        .....                .....
      .@..                      ..@.
    .@.                            .@.
   .@.           ........           .@.
  .@          .@@@@@..@@@@@.          @.
 .@         .@@.          .@@.         @.
 @.        @@.              .@@        .@
.@        .@.                .@.        @.
.@        @@        @@        @@        @.
.@        @@        @@        @@        @.
.@        .@.                .@.        @.
 @.        @@.              .@@        .@
 .@         .@@.          .@@.         @.
  .@          .@@@@@..@@@@@.          @.
   .@.           ........           .@.
    .@.                            .@.
      .@..                      ..@.
        .....                .....
            .@..............@.
                 ........
Output for 0 0 0 1 0/8 (note the leading whitespace):

              ...@@@@@@@@...
           ..@@..        ..@@..
         .@@.                .@@.
        @@                      @@
       @.                        .@
      @@                          @@
     .@                            @.
     @@                            @@
     @@                            @@
     .@                            @.
      @@                          @@
       @.                        .@
        @@                      @@
         .@@.                .@@.
           ..@@..        ..@@..
              ...@@@@@@@@...
The aureoles themselves must be exactly as presented above. However, trailing whitespace is optional. Also, if some outer aureoles are missing, it is up to you whether your program outputs the leading empty lines or the trailing empty lines.

*/

#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
aureoles(int n)
{
	static const char art[][42] = {
	    "                 ........                 ",
	    "            .@..............@.            ",
	    "        .....                .....        ",
	    "      .@..    ...@@@@@@@@...    ..@.      ",
	    "    .@.    ..@@..        ..@@..    .@.    ",
	    "   .@.   .@@.    ........    .@@.   .@.   ",
	    "  .@    @@    .@@@@@..@@@@@.    @@    @.  ",
	    " .@    @.   .@@.          .@@.   .@    @. ",
	    " @.   @@   @@.   @@@@@@@@   .@@   @@   .@ ",
	    ".@   .@   .@.   @@@.  .@@@   .@.   @.   @.",
	    ".@   @@   @@   @@   @@   @@   @@   @@   @.",
	    ".@   @@   @@   @@   @@   @@   @@   @@   @.",
	    ".@   .@   .@.   @@@.  .@@@   .@.   @.   @.",
	    " @.   @@   @@.   @@@@@@@@   .@@   @@   .@ ",
	    " .@    @.   .@@.          .@@.   .@    @. ",
	    "  .@    @@    .@@@@@..@@@@@.    @@    @.  ",
	    "   .@.   .@@.    ........    .@@.   .@.   ",
	    "    .@.    ..@@..        ..@@..    .@.    ",
	    "      .@..    ...@@@@@@@@...    ..@.      ",
	    "        .....                .....        ",
	    "            .@..............@.            ",
	    "                 ........                 ",
	};

	static const char mask[][42] = {
	    "                 55555555                 ",
	    "            555555555555555555            ",
	    "        55555                55555        ",
	    "      5555    44444444444444    5555      ",
	    "    555    444444        444444    555    ",
	    "   555   4444    33333333    4444   555   ",
	    "  55    44    33333333333333    44    55  ",
	    " 55    44   3333          3333   44    55 ",
	    " 55   44   333   22222222   333   44   55 ",
	    "55   44   333   2222  2222   333   44   55",
	    "55   44   33   22   11   22   33   44   55",
	    "55   44   33   22   11   22   33   44   55",
	    "55   44   333   2222  2222   333   44   55",
	    " 55   44   333   22222222   333   44   55 ",
	    " 55    44   3333          3333   44    55 ",
	    "  55    44    33333333333333    44    55  ",
	    "   555   4444    33333333    4444   555   ",
	    "    555    444444        444444    555    ",
	    "      5555    44444444444444    5555      ",
	    "        55555                55555        ",
	    "            555555555555555555            ",
	    "                 55555555                 ",
	};

	int x, y, w, h;
	int b, c;

	w = nelem(art[0]);
	h = nelem(art);

	printf("n=%d\n", n);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			b = mask[y][x];
			c = ' ';
			if (isdigit(b) && (n & (1 << (b - '1'))))
				c = art[y][x];
			printf("%c", c);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	aureoles(31);
	aureoles(21);
	aureoles(8);

	return 0;
}
