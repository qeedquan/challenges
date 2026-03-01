/*

Adding tip to a restaurant bill in a graceful way can be tricky, thats why you need make a function for it.

The function will receive the restaurant bill (always a positive number) as an argument. You need to 1) add at least 15% in tip, 2) round that number up to an elegant value and 3) return it.

What is an elegant number? It depends on the magnitude of the number to be rounded. Numbers below 10 should simply be rounded to whole numbers. Numbers 10 and above should be rounded like this:

10 - 99.99... ---> Round to number divisible by 5

100 - 999.99... ---> Round to number divisible by 50

1000 - 9999.99... ---> Round to number divisible by 500

And so on...

Good luck!

Examples
 1  -->    2
 7  -->    9
12  -->   15
86  -->  100

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
tip(double bill)
{
	int total, tenth, modulus;
	int result;

	total = ceil(bill * 1.15);
	tenth = floor(log10(total)) - 1;
	modulus = 5 * pow(10, tenth);

	result = total;
	if (total > 10 && modulus && (total % modulus))
		result = modulus * ceil(total * 1.0 / modulus);
	return result;
}

int
main()
{
	assert(tip(1) == 2);
	assert(tip(7) == 9);
	assert(tip(12) == 15);
	assert(tip(86) == 100);

	assert(tip(1.09) == 2);
	assert(tip(7) == 9);
	assert(tip(11.99) == 15);

	return 0;
}
