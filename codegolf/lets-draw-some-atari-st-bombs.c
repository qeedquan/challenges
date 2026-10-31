/*

The Atari ST was a rather popular personal computer from the mid 80's to early 90's era, powered by a Motorola 68000 microprocessor. On this machine, the default behavior of the operating system for uncaught CPU exceptions was to display a row of bombs on the screen, as shown in the following picture:

https://i.sstatic.net/CwMSk.png

Source: https://commons.wikimedia.org/wiki/File:Row_of_bombs.png
NB: Depending on the OS version, the bomb graphics may vary slightly. But let's take this one as reference.

The number of bombs depends on the exception vector, the most common ones being:

($008) Bus Error : 2 bombs
($00c) Address Error : 3 bombs
($010) Illegal Instruction : 4 bombs
Goal
Your goal is to write a program or function that prints or outputs an ASCII art of such Atari ST bombs.

Input
An integer representing the number of bombs to display. Your code must support the most common values: 2, 3 and 4. Supporting less and/or more bombs is fine, but it is neither required nor subject to a bonus.

Output
The original bomb consists of a 16x16 pixel tile, represented here in both ASCII and binary:

....##..........    0000110000000000
.#.#..#.........    0101001000000000
.......#........    0000000100000000
#..#....#.......    1001000010000000
..#...#####.....    0010001111100000
......#####.....    0000001111100000
....#########...    0000111111111000
...###########..    0001111111111100
...###########..    0001111111111100
..#############.    0011111111111110
..########.####.    0011111111011110
...#######.###..    0001111111011100
...######.####..    0001111110111100
....#########...    0000111111111000
.....#######....    0000011111110000
.......###......    0000000111000000
In this challenge, each ASCII bomb must be stretched to twice its original width for a better rendering. Therefore, it will consist of 16 rows of 32 characters, using ## for 'ON' pixels and two spaces for 'OFF' pixels. All bomb tiles must be put side by side. Leading spaces are forbidden. Trailing spaces are also forbidden, except the ones that are actually part of the bomb tile (i.e. the 31st and 32nd columns) which must be present. You may include no more than one leading line-break and no more than one trailing line-break.

Example
Below is the reference output for two bombs, where mandatory line-breaks are marked as \n and tolerated extra line-breaks are marked as (\n):

(\n)
        ####                            ####                    \n
  ##  ##    ##                    ##  ##    ##                  \n
              ##                              ##                \n
##    ##        ##              ##    ##        ##              \n
    ##      ##########              ##      ##########          \n
            ##########                      ##########          \n
        ##################              ##################      \n
      ######################          ######################    \n
      ######################          ######################    \n
    ##########################      ##########################  \n
    ################  ########      ################  ########  \n
      ##############  ######          ##############  ######    \n
      ############  ########          ############  ########    \n
        ##################              ##################      \n
          ##############                  ##############        \n
              ######                          ######            (\n)
(Of course, other line-break formats such as \r or \r\n may be used just as well.)

Rules
This is code-golf, so the shortest answer in bytes wins. Standard loopholes are forbidden.

*/

#include <stdio.h>

void
bombs(int n)
{
	static const char art[16][16] = {
	    "....##..........",
	    ".#.#..#.........",
	    ".......#........",
	    "#..#....#.......",
	    "..#...#####.....",
	    "......#####.....",
	    "....#########...",
	    "...###########..",
	    "...###########..",
	    "..#############.",
	    "..########.####.",
	    "...#######.###..",
	    "...######.####..",
	    "....#########...",
	    ".....#######....",
	    ".......###......",
	};

	static const int size = sizeof(*art);

	int c, x, y;

	for (y = 0; y < size; y++) {
		for (x = 0; x < size * n; x++) {
			c = art[y][x % size];
			if (c == '.')
				c = ' ';
			printf("%c", c);
		}
		printf("\n");
	}
}

int
main()
{
	int i;

	for (i = 1; i <= 4; i++)
		bombs(i);

	return 0;
}
