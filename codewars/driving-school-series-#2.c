/*

Fast & Furious Driving School's (F&F) charges for lessons are as below:

Time	Cost
Up to 1st hour	$30
Every subsequent half hour**	$10
** Subsequent charges are calculated by rounding up to nearest half hour.
For example, if student X has a lesson for 1hr 20 minutes, he will be charged $40 (30+10) for 1 hr 30 mins and if he has a lesson for 5 minutes, he will be charged $30 for the full hour.

Out of the kindness of its heart, F&F also provides a 5 minutes grace period. So, if student X were to have a lesson for 65 minutes or 1 hr 35 mins, he will only have to pay for an hour or 1hr 30 minutes respectively.

For a given lesson time in minutes (min) , write a function cost to calculate how much the lesson costs. Input is always > 0.

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

long
costbf(long mins)
{
	long price;

	price = 30;
	mins -= 60;
	while (mins > 5) {
		mins -= 30;
		price += 10;
	}
	return price;
}

long
cost(long mins)
{
	long price, mult;

	price = 30;
	mins -= 60;

	mult = max(mins, 0) / 30;
	price += 10 * mult;
	mins -= 30 * mult;
	if (mins > 5)
		price += 10;

	return price;
}

int
main()
{
	long mins;

	assert(cost(45) == 30);
	assert(cost(63) == 30);
	assert(cost(84) == 40);
	assert(cost(102) == 50);
	assert(cost(273) == 100);

	for (mins = 0; mins <= 500000; mins++)
		assert(cost(mins) == costbf(mins));

	return 0;
}
