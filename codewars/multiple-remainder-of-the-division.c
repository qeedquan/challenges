/*

Your task it to return true if the fractional part (rounded to 1 digit) of the result (a / b) exists, more than 0 and is multiple of n. Otherwise return false. (For Python return True or False)

All arguments are positive digital numbers.

Rounding works like toFixed() method. (if more than...5 rounds up)

Find examples below:


isMultiple(5, 2, 3) -> false // 2.5 -> 5 is not multiple of 3
isMultiple(5, 3, 4) -> false // 1.7 -> 7 is not multiple of 4
isMultiple(5, 4, 3) -> true // 1.3 -> 3 is multiple of 3
isMultiple(666, 665, 2) -> false // 1.0 -> return false

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long ulong;

bool
ismultiple(ulong a, ulong b, ulong n)
{
	double i;
	ulong m;

	if (b == 0 || n == 0)
		return false;

	m = round(modf((a * 1.0) / b, &i) * 10);
	if (m < 1 || m > 9)
		return false;

	return !(m % n);
}

int
main()
{
	assert(ismultiple(5, 2, 3) == false);
	assert(ismultiple(5, 3, 4) == false);
	assert(ismultiple(5, 4, 3) == true);
	assert(ismultiple(666, 665, 2) == false);
	assert(ismultiple(3691401, 1892272, 5) == false);

	return 0;
}
