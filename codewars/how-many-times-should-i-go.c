/*

Lot of museum allow you to be a member, for a certain amount amount_by_year you can have unlimitted acces to the museum.

In this kata you should complete a function in order to know after how many visit it will be better to take an annual pass. The function take 2 arguments annual_price and individual_price.

*/

#include <assert.h>
#include <math.h>

int
times(int annual, int individual)
{
	return ceil(annual * 1.0 / individual);
}

int
main()
{
	assert(times(40, 15) == 3);
	assert(times(30, 10) == 3);
	assert(times(80, 15) == 6);
	return 0;
}
