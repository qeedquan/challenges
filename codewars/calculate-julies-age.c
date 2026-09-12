/*

Julie is x years older than her brother, and she is also y times as old as him.

Given x and y calculate Julie's age using the function age(x, y).

For example:

Age(6, 3) // returns 9
Note also that x can be negative, and y can be a decimal.

Age(-15, 0.25) // returns 5
That is, Julie is 15 years younger and 0.25 times the age of her brother.

Do not concern yourself with the imperfections inherent in dividing by floating point numbers, as your answer will be rounded. Also, for the sake of simplicity, Julie is never the same age as her brother.

*/

#include <assert.h>
#include <math.h>

int
age(double x, double y)
{
	return round((x * y) / (y - 1));
}

int
main()
{
	assert(age(6, 3) == 9);
	assert(age(-15, 0.25) == 5);
	return 0;
}
