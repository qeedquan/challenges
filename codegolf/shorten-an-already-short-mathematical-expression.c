/*

For once, I was doing some real work, updating old code, and bumped into an expression that is equivalent to what would be written as πx + ex in good old-fashioned math. I thought it would be possible to write it shorter than it was written in the language I work with (APL), and therefore present this very simple challenge:

Write a function or program that (by any means) accepts zero or more numbers, and returns (by any means) the result of the above expression for x = each of the given numbers with at least 3 significant digits for each result.

If your language does not have π and/or e, use the values 3.142 and 2.718.

Scoring is number of bytes, so preface your answer with # LanguageName, 00 bytes.

Standard loop-holes are not allowed.

Edit: Now the solution I came up with, ○+*, has been found. The original code was (○x)+*x.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
f(double x)
{
	return (x * M_PI) + exp(x);
}

int
main()
{
	double x;

	for (x = 0; x <= 10; x += 1)
		printf("%f\n", f(x));

	return 0;
}
