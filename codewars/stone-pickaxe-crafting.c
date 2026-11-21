/*

Note: Based off Minecraft, hopefully you atleast know the game!

Story: You want to create a giant mine shaft, but your a little stingy with your iron and diamonds and would not mine out all of the stone with iron or diamond pickaxes. Instead, you rely on less durable but cheaper stone pickaxes! You will need a lot of stone pickaxes though as they break faster than diamond or iron ones, so you need to find out how many stone pickaxes you can craft before you run out of sticks and cobblestones. Unfortunately, your not an organized person, and you leave all of your materials into a single chest with random junk that you need to filter.

Task: Given an array, return the maximum amount of stone pickaxes you can craft before you run out of sticks and cobblestones. Within the array would be a series of strings with the exact names of the materials listed below. If the array has atleast 3 "Cobblestones" and 2 "Sticks" you can craft a singular stone pickaxe. Do not count any materials apart from "Cobblestones", "Sticks" and "Wood". Wood can be converted into 4 sticks!

Here are the materials you would expect in a array:

Sticks
Cobblestone
Stone (These are different from cobblestone and cannot be used to make a stone pickaxe.)
Wool
Dirt
Wood (Can be treated as sticks, typically 4 sticks for 1 wood)
Diamond

Array sizes are randomized and range from 1 - 200 with randomized contents.

Examples:

Array: ["Sticks", "Sticks", "Cobblestone", "Cobblestone", "Cobblestone"]
Returned: 1

Array: ["Wood", "Cobblestone", "Cobblestone", "Cobblestone"]
Returned: 1

Array: []
Returned: 0

Array: ["Sticks", "Wool", "Cobblestone"]
Returned: 0
Good Luck :D

Made by miggycoder, this is my first kata I ever created.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
stonepick(const char **s, size_t n)
{
	size_t i;
	int c0, c1;

	c0 = c1 = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[i], "Wood"))
			c1 += 4;
		else if (!strcmp(s[i], "Sticks"))
			c1 += 1;
		else if (!strcmp(s[i], "Cobblestone"))
			c0 += 1;
	}
	return min(c0 / 3, c1 / 2);
}

int
main()
{
	const char *s1[] = {"Sticks", "Sticks", "Cobblestone", "Cobblestone", "Cobblestone"};
	const char *s2[] = {"Wood", "Cobblestone", "Cobblestone", "Cobblestone"};
	const char *s3[] = {"Wood", "Cobblestone", "Cobblestone"};

	assert(stonepick(s1, nelem(s1)) == 1);
	assert(stonepick(s2, nelem(s2)) == 1);
	assert(stonepick(NULL, 0) == 0);
	assert(stonepick(s3, nelem(s3)) == 0);
	return 0;
}
