/*

Challenge
Given a number x and a precision e, find the lowest positive integer q such that x can be approximated as a fraction p / q within precision e.

In other words, find the lowest positive integer q such that there exists an integer p such that abs(x - p/q) < e.

Input
The pair (x, e) where x is a floating-point number, and e is a positive floating-point number.
Alternatively, a pair (x, n) where n is a nonnegative integer; then e is implicitly defined as 10**(-n) or 2**(-n), meaning n is the precision in number of digits/bits.
Restricting x to positive floating-point is acceptable.

Output
The denominator q, which is a positive integer.

Test cases
Whenever e > 0.5 ------------------------> 1 because x ≈ an integer
Whenever x is an integer ----------------> 1 because x ≈ itself
(3.141592653589793, 0.2) ------------> 1 because x ≈ 3
(3.141592653589793, 0.0015) --------> 7 because x ≈ 22/7
(3.141592653589793, 0.0000003) ---> 113 because x ≈ 355/113
(0.41, 0.01) -------------------------------> 12 for 5/12 or 5 for 2/5, see Rules below

Rules
This is code-golf, the shortest code wins!
Although the input is "a pair", how to encode a pair is unspecified
The type used for x must allow a reasonable precision
Floating-point precision errors can be ignored as long as the algorithm is correct. For instance, the output for (0.41, 0.01) should be 12 for 5/12, but the output 5 is acceptable because 0.41-2/5 gives 0.009999999999999953

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

/*

@xnor

We want to check that x is within ±ϵ of a multiple of 1/q, that is, it falls within the interval (−ϵ,ϵ) modulo 1/q.
To do this, we take x+ϵ, reduce it modulo 1/q, and check if the result is at most 2ϵ.

*/

int
approximate(double x, double e)
{
	int i;

	for (i = 1; i < INT_MAX; i++) {
		if (fmod((x + e) * i, 1) < (2 * e * i))
			break;
	}
	return i;
}

int
main(void)
{
	assert(approximate(3.141592653589793, 0.5) == 1);
	assert(approximate(3, 0.1) == 1);
	assert(approximate(3.141592653589793, 0.2) == 1);
	assert(approximate(3.141592653589793, 0.0015) == 7);
	assert(approximate(3.141592653589793, 0.0000003) == 113);
	assert(approximate(0.41, 0.01) == 12);

	return 0;
}