/*

The purpose of this kata is to work out just how many bottles of duty free whiskey you would have to buy such that the saving over the normal high street price would effectively cover the cost of your holiday.

You will be given the high street price (normPrice), the duty free discount (discount) and the cost of the holiday.

For example, if a bottle cost £10 normally and the discount in duty free was 10%, you would save £1 per bottle. If your holiday cost £500, the answer you should return would be 500.

All inputs will be integers. Please return an integer. Round down.

*/

#include <assert.h>

int
dutyfree(int price, int discount, int holiday)
{
	return 100 * holiday / (price * discount);
}

int
main()
{
	assert(dutyfree(12, 50, 1000) == 166);
	assert(dutyfree(17, 10, 500) == 294);
	assert(dutyfree(24, 35, 3000) == 357);
	assert(dutyfree(1400, 35, 10000) == 20);
	assert(dutyfree(700, 26, 7000) == 38);

	return 0;
}
