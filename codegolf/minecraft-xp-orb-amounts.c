/*

In the video game Minecraft, the player can obtain experience points (XP) from various activities. In the game, these are provided as XP "orbs" of various sizes, each of which give the player various amounts of XP. The possible orbs are shown in the image below, along with the smallest and largest amount of XP that orb can contain:

https://i.stack.imgur.com/Q8Tq4.png

https://minecraft.wiki/w/Experience#Experience_orbs

In this challenge, you should output (as a finite sequence) the minimum units of XP that these orbs can contain; specifically, output the sequence

-32768
3
7
17
37
73
149
307
617
1237
2477
Standard loopholes are forbidden. As this is code-golf, the shortest program wins.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
xporb(void)
{
	static const int tab[] = {-32768, 3, 7, 17, 37, 73, 149, 307, 617, 1237, 2477};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%d\n", tab[i]);
}

int
main(void)
{
	xporb();
	return 0;
}
