/*

In this kata you will have to write a function that takes litres and pricePerLitre (in dollar) as arguments.

Purchases of 2 or more litres get a discount of 5 cents per litre, purchases of 4 or more litres get a discount of 10 cents per litre, and so on every two litres, up to a maximum discount of 25 cents per litre. But total discount per litre cannot be more than 25 cents. Return the total cost rounded to 2 decimal places. Also you can guess that there will not be negative or non-numeric inputs.

Good Luck!

Note
1 Dollar = 100 Cents

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
fuelprice(int litres, double price)
{
	return litres * (price - fmin((litres / 2) * 0.05, 0.25));
}

void
test(int litres, double price, double result)
{
	double value;

	value = fuelprice(litres, price);
	printf("%f\n", value);
	assert(fabs(value - result) < 1e-12);
}

int
main()
{
	test(5, 1.23, 5.65);
	test(8, 2.5, 18.40);
	test(5, 5.6, 27.50);

	return 0;
}
