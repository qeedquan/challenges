/*

Create two functions:

The first is isOdd() to check if a given number is odd using bitwise operator.
The second is isEven() to check if a given input is even using regular expressions.
IMPORTANT
The use of the modulo (%) operator is not allowed.

Examples
isOdd(3) ➞ "Yes"
// Use Bitwise Operator

isOdd(58) ➞ "No"
// Use Bitwise Operator

isEven("0") ➞ "Yes"
// Use Regular Expression

isEven("-99") ➞ "No"
// Use Regular Expression

Notes
Input will only be integers (positive/negative/zero).
For the second function, input will be numbers in string.
For more info on regular expressions, check the Resources tab.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

bool
isodd(int n)
{
	return (n & 1) != 0;
}

bool
iseven(int n)
{
	regex_t re;
	char s[8];
	int r;

	if (regcomp(&re, "^[02468]$", REG_EXTENDED))
		return false;

	snprintf(s, sizeof(s), "%d", abs(n) % 10);
	r = regexec(&re, s, 0, NULL, 0);
	regfree(&re);

	return r == 0;
}

int
main()
{
	int i;

	for (i = -10000; i <= 10000; i++) {
		if (i & 1) {
			assert(isodd(i) == true);
			assert(iseven(i) == false);
		} else {
			assert(isodd(i) == false);
			assert(iseven(i) == true);
		}
	}
	return 0;
}
