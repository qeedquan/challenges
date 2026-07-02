/*

When you look at movie ratings, you usually see it as decimal numbers representing average of all viewers' votes. While it is very informative, it's not very visually appealing. That's what stars, or in our case- moons, are created for.

Your task is to transform decimal number rating, which is in range 0-10, into 5-moons scale. Your final rating should be rounded to "0.5" (nearest half moon). Input is always valid.

Write a function which returns valid rating represented as moons ('o','c','x') in single string.
You are given the following values preloaded (remember, since I can't use unicode characters, moons in brackets are here just to improve your imagination):

https://imgur.com/qjjZ55g

More examples in test cases.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const char *
moonrating(double rating)
{
	int value;

	value = fmin(fmax(round(rating), 0), 10);
	switch (value) {
	case 0:
		return "xxxxx";
	case 1:
		return "cxxxx";
	case 2:
		return "oxxxx";
	case 3:
		return "ocxxx";
	case 4:
		return "ooxxx";
	case 5:
		return "oocxx";
	case 6:
		return "oooxx";
	case 7:
		return "ooocx";
	case 8:
		return "oooox";
	case 9:
		return "ooooc";
	default:
		return "ooooo";
	}
}

int
main()
{
	assert(!strcmp(moonrating(1), "cxxxx"));
	assert(!strcmp(moonrating(7.2), "ooocx"));
	assert(!strcmp(moonrating(5.9), "oooxx"));

	return 0;
}
