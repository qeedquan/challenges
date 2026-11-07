/*

Programming Puzzles & Code Golf is about to get a new moderator, Dennis! This challenge is a tribute to him and our other active (or recently active) moderators: Doorknob, Martin Büttner, and Chris Jester-Young. The challenge title is meant to be read to the tune of the Pepto Bismol song.

Basically, we're going to treat them all to pizza at The Nineteenth Bite Pizzeria, but we need to make sure they share it fairly because some of the mods are known to be pizza addicts!

The pizzas sold by the pizzeria are all rectangular blocks of text. The width and length of a pizza may be any non-negative integers as long as their product is divisible by four. Each grid space in the block of text pizza represents a slice, so it's always possible to split the slices up into four equal groups.

The mods will collectively order a single pizza, providing its width and length parameters to their server in any reasonable format such as [width],[length]. Just before the pizza arrives at their table, you need to label each slice with the initial of the mod who gets to eat it to ensure they all share fairly. Everyone should get the same number of slices.

E is for Dennis
D is for Doorknob
M is for Martin
C is for Chris
The mods are a little persnickety, however, and require that their respective sets of slices be path-connected, that is, that all their slices can be reached from one another by moving up, down, left, and right, not crossing anyone else's slices (and not moving diagonal). The don't care how you do this as long as it is done.

Once you've accurately labeled each slice, deliver the pizza to the mods with an optional trailing newline.

Your labeler may be a program or a function and can print or return the labeled pizza. The shortest labeler in bites wins.

Examples
Example 1

Order: 4,1

Some Possible Labeled Pizzas:

EDMC
MEDC
CDEM
Example 2

Order: 4,4

Some Possible Labeled Pizzas:

MMMM
CCCC
DDDD
EEEE
DEMC
DEMC
DEMC
DEMC
CCCC
DEEM
DEEM
DDMM
Example 3

Order: 8,3

Some Possible Labeled Pizzas:

MMMMMMCC
DDDDCCCC
DDEEEEEE
DDDCMMMM
DCDCMEEE
DCCCMEEE
Example 4

Order: 20,5

A Possible Labeled Pizza:

DDDDDDDDDDDDMCCCCCCCCCCC
DEEEEEEEEEEDMMMMMMMCCCCC
DEEEEEEEEEEDMMMCCCCCCCCC
DEEEEEEEEEEDMMMMMMMMCCCC
DDDDDDDDDDDDMMMMMMMMMMMC
(The D's here are not simply-connected but that's ok.)

*/

#include <stdio.h>

/*

@Level River St

Many answers here zigzag, but in most cases, just outputting the letters in order (left to right, top to bottom) works fine:

No need to zigzag for heights 1,2 or 4

No need to zigzag for heights greater than 4 (each mod's pizza ration will wrap around.)

Therefore we only actually need to zigzag when the height is 3, and then we only need to reverse the middle row.

As it turns out, Dennis and Doorknob are the only mods on that row. And they can be interchanged by XORing their ASCII codes with 1.

This is handy given that there's no easy way to reverse a string in C.

*/

void
f(int w, int h)
{
	static const char sym[] = "CDEM";

	int c, i, x, y;

	i = (w * h) - 1;
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++, i--) {
			c = sym[(i * 4) / (w * h)];
			if (h == 3 && (i / w == 1))
				c ^= 1;
			putchar(c);
		}
		puts("");
	}
	puts("");
}

int
main()
{
	f(4, 1);
	f(4, 4);
	f(8, 3);
	f(20, 5);
	f(4, 3);
	f(3, 3);

	return 0;
}
