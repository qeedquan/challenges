/*

I hope this picture looks familiar to you.

https://i.sstatic.net/Egmke.png

It's one of Pacman's ghosts in his "vulnerable" state, after Pacman has eaten a power pill.

The challenge
Picture our ghost in a little frame, using ASCII art. At normal scale (more about this later), each square in the above image should correspond to one character, and the frame should have a one-character separation up and down, and a two-character separation to the left and right of the ghost:

####################
#                  #
#       ####       #
#     ########     #
#    ##########    #
#   ############   #
#   ############   #
#   ###  ##  ###   #
#  ####  ##  ####  #
#  ##############  #
#  ##############  #
#  ##  ##  ##  ##  #
#  # ##  ##  ## #  #
#  ##############  #
#  ## ###  ### ##  #
#  #   ##  ##   #  #
#                  #
####################
But this doesn't look very pretty. # may not be the best choice for the active pixels. Besides, character cells are not square, which makes our friend look more ghostly than he already is.

So, to have more flexibility, the picture will change according to three input parameters:

Character to be used for active pixels;
Horizontal scale factor;
Vertical scale factor.
For example, with %, 4, 2 the ouput would be the better looking picture

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%                                                                        %%%%
%%%%                                                                        %%%%
%%%%                            %%%%%%%%%%%%%%%%                            %%%%
%%%%                            %%%%%%%%%%%%%%%%                            %%%%
%%%%                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                    %%%%
%%%%                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                    %%%%
%%%%                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                %%%%
%%%%                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                %%%%
%%%%            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            %%%%
%%%%            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            %%%%
%%%%            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            %%%%
%%%%            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            %%%%
%%%%            %%%%%%%%%%%%        %%%%%%%%        %%%%%%%%%%%%            %%%%
%%%%            %%%%%%%%%%%%        %%%%%%%%        %%%%%%%%%%%%            %%%%
%%%%        %%%%%%%%%%%%%%%%        %%%%%%%%        %%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%        %%%%%%%%        %%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%        %%%%%%%%        %%%%%%%%        %%%%%%%%        %%%%
%%%%        %%%%%%%%        %%%%%%%%        %%%%%%%%        %%%%%%%%        %%%%
%%%%        %%%%    %%%%%%%%        %%%%%%%%        %%%%%%%%    %%%%        %%%%
%%%%        %%%%    %%%%%%%%        %%%%%%%%        %%%%%%%%    %%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        %%%%
%%%%        %%%%%%%%    %%%%%%%%%%%%        %%%%%%%%%%%%    %%%%%%%%        %%%%
%%%%        %%%%%%%%    %%%%%%%%%%%%        %%%%%%%%%%%%    %%%%%%%%        %%%%
%%%%        %%%%            %%%%%%%%        %%%%%%%%            %%%%        %%%%
%%%%        %%%%            %%%%%%%%        %%%%%%%%            %%%%        %%%%
%%%%                                                                        %%%%
%%%%                                                                        %%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Rules
All builtins allowed.

Inputs are taken in any reasonable format and any order. The first input above (character for active pixels) is guaranteed to be a printable ASCII character (codes 32 to 126).

Trailing space after each line or trailing newlines after last line are acceptable.

Code golf, fewest bytes wins.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
ghost(int c, int W, int H)
{
	static const char art[18][21] = {
		"####################",
		"#                  #",
		"#       ####       #",
		"#     ########     #",
		"#    ##########    #",
		"#   ############   #",
		"#   ############   #",
		"#   ###  ##  ###   #",
		"#  ####  ##  ####  #",
		"#  ##############  #",
		"#  ##############  #",
		"#  ##  ##  ##  ##  #",
		"#  # ##  ##  ## #  #",
		"#  ##############  #",
		"#  ## ###  ### ##  #",
		"#  #   ##  ##   #  #",
		"#                  #",
		"####################",
	};

	int x, y, w, h;

	w = nelem(art[0]) - 1;
	h = nelem(art);
	for (y = 0; y < h * H; y++) {
		for (x = 0; x < w * W; x++) {
			if (art[y / H][x / W] != ' ')
				printf("%c", c);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	ghost('%', 4, 2);
	ghost('+', 1, 1);

	return 0;
}
