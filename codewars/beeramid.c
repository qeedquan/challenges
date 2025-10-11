/*

Let's pretend your company just hired your friend from college and paid you a referral bonus. Awesome! To celebrate, you're taking your team out to the terrible dive bar next door and using the referral bonus to buy, and build, the largest three-dimensional beer can pyramid you can. And then probably drink those beers, because let's pretend it's Friday too.

A beer can pyramid will square the number of cans in each level - 1 can in the top level, 4 in the second, 9 in the next, 16, 25...

Complete the beeramid function to return the number of complete levels of a beer can pyramid you can make, given the parameters of:

your referral bonus, and

the price of a beer can

For example:

beeramid(1500, 2); // should === 12
beeramid(5000, 3); // should === 16

*/

#include <assert.h>

int
beeramid(int bonus, int price)
{
	int beers;
	int levels;

	if (price == 0)
		return 0;

	beers = bonus / price;
	for (levels = 1; beers >= levels * levels; levels++)
		beers -= levels * levels;
	return levels - 1;
}

int
main()
{
	assert(beeramid(1500, 2) == 12);
	assert(beeramid(5000, 3) == 16);
	return 0;
}
