/*

You are trapped in this 5x5 labyrinth - each room is labelled from 1 to 25 and the exit is in room 1.

https://i.stack.imgur.com/3pa3s.png

You are given as input the room you are currently in. Your task is to output the shortest sequence of moves (north, east, south, west) needed to reach room 1.

Moves can be output in any format you wish (list, string, array...) as long as you use the characters n,w,e,s.

Here are all the test cases:

1 => empty string/list
2 => w
3 => ww
4 => swwnw
5 => wswwnw
6 => seenwnw
7 => nw
8 => wnw
9 => wwnw
10 => swwnwnw
11 => eenwnw
12 => enwnw
13 => nwnw
14 => wnwnw
15 => wwnwnw
16 => enenwnw
17 => nenwnw
18 => wnenwnw
19 => nwnwnw
20 => wnwnwnw
21 => nenenwnw
22 => enwnenwnw
23 => nwnenwnw
24 => wnwnenwnw
25 => nwnwnwnw

Shortest answer in bytes wins!

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
escape(unsigned n)
{
	static const char *seq[] = {
	    "",
	    "w",
	    "ww",
	    "swwnw",
	    "wswwnw",
	    "seenwnw",
	    "nw",
	    "wnw",
	    "wwnw",
	    "swwnwnw",
	    "eenwnw",
	    "enwnw",
	    "nwnw",
	    "wnwnw",
	    "wwnwnw",
	    "enenwnw",
	    "nenwnw",
	    "wnenwnw",
	    "nwnwnw",
	    "wnwnwnw",
	    "nenenwnw",
	    "enwnenwnw",
	    "nwnenwnw",
	    "wnwnenwnw",
	    "nwnwnwnw",
	};

	if (n == 0 || n > nelem(seq))
		return NULL;
	return seq[n - 1];
}

int
main(void)
{
	unsigned i;

	for (i = 1; i <= 25; i++)
		printf("%u %s\n", i, escape(i));

	return 0;
}
