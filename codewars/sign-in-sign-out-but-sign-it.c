/*

the goal of this kata is to create a sign function. sign(n) should return the sign of a number n, indicating whether the number is positive, negative, zero or NaN.

The function may return 1, -1, 0 or NaN representing "positive number", "negative number", "zero" or NaNrespectively.

If a string argument may be converted to number then sign should return the sign of this number.

###Example

sign(3)     //  1
sign(-3)    // -1
sign("-3")  // -1
sign(0)     //  0
sign(NaN)   // NaN
sign("foo") // NaN
sign()      // NaN

###Single-element-array Arrays of 1 element may be coerced to numbers or strings. eg:

2*[5]   // -> 10
2*['5'] // -> 10
10-[5]  // ->  5
10+[5]  // -> 105 !!

The sign function will treat "single-element-arrays" as Javascript used to do, ie as number if possible.

Then:

sign([42])  // ->  1
sign([-42]) // -> -1
sign([0])   // ->  0
sign([4,2]) // -> NaN (only 1 element arrays are coercible)

//...and...
sign(['42'])  // ->  1
sign(['-42']) // -> -1
sign(['0'])   // ->  0
sign(['4','2']) // -> NaN
###Note: Math.sign() is an experimental part of the ECMAScript 6 proposal. So if implemented, it will be de disabled.

*/

#include <assert.h>
#include <math.h>

double
sign(double x)
{
	if (x == 0)
		return 0;
	if (isnan(x))
		return NAN;
	return copysign(1, x);
}

int
main()
{
	assert(sign(3) == 1);
	assert(sign(-3) == -1);
	assert(sign(0) == 0);
	assert(isnan(sign(NAN)));
	assert(sign(INFINITY) == 1);
	assert(sign(-INFINITY) == -1);

	return 0;
}
