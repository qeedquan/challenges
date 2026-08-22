/*

Your company, Congo Pizza, is the second-largest online frozen pizza retailer. You own a number of international warehouses that you use to store your frozen pizzas, and you need to figure out how many crates of pizzas you can store at each location.

Congo recently standardized its storage containers: all pizzas fit inside a cubic crate, 16-inches on a side. The crates are super tough so you can stack them as high as you want.

Write a function box_capacity() that figures out how many crates you can store in a given warehouse. The function should take three arguments: the length, width, and height of your warehouse (in feet) and should return an integer representing the number of boxes you can store in that space.

For example: a warehouse 32 feet long, 64 feet wide, and 16 feet high can hold 13,824 boxes because you can fit 24 boxes across, 48 boxes deep, and 12 boxes high, so box_capacity(32, 64, 16) should return 13824.

*/

#include <assert.h>

long
boxcap(long l, long w, long h)
{
	long r;

	r = (l * 12) / 16;
	r *= (w * 12) / 16;
	r *= (h * 12) / 16;
	return r;
}

int
main()
{
	assert(boxcap(32, 64, 16) == 13824);
	assert(boxcap(20, 20, 20) == 3375);
	assert(boxcap(80, 40, 20) == 27000);

	assert(boxcap(70, 60, 15) == 25740);
	assert(boxcap(90, 7, 5) == 1005);
	assert(boxcap(53, 21, 13) == 5265);

	return 0;
}
