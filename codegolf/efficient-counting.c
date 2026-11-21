/*

When I was a kid, and wanted to count the dollar bills in my life savings, I would count out loud:

one, two, three, four, five, six, seven, eight, nine, ten;
eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty;
twenty-one, twenty-two, twenty-three, twenty-four, twenty-five...

Eventually I got tired of pronouncing each of these multi-syllable numbers. Being mathematically minded, I created a much more efficient method of counting:

one, two, three, four, five, six, seven, eight, nine, ten;
one, two, three, four, five, six, seven, eight, nine, twenty;
one, two, three, four, five, six, seven, eight, nine, thirty...

As you can see, I would only pronounce the digit(s) that have changed from the previous number. This has the added advantage that it's considerably more repetitive than the English names for numbers, and therefore requires less brainpower to compute.

Challenge
Write a program/function which takes in a positive integer and outputs/returns how I would count it: that is, the right-most non-zero digit and all trailing zeroes.

Examples
   1    1
   2    2
  10   10
  11    1
  29    9
  30   30
  99    9
 100  100
 119    9
 120   20
 200  200
 409    9
1020   20
A full list of test-cases shouldn't be necessary. This is A274206 on OEIS.

Rules
Your entry must theoretically work for all positive integers, ignoring precision and memory issues.
Input and output must be in decimal.
You may choose to take input and/or output as a number, a string, or an array of digits.
Input is guaranteed to be a positive integer. Your entry can do anything for invalid input.
This is code-golf, so the shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// http://oeis.org/A274206
uvlong
efficient(uvlong n)
{
	uvlong p, v;

	p = 1;
	for (v = 0; n > 0; n /= 10) {
		v = n % 10;
		if (v)
			break;

		p *= 10;
	}
	return v * p;
}

int
main(void)
{
	static const uvlong tab[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 1, 2, 3,
		4, 5, 6, 7, 8, 9, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 40, 1, 2, 3, 4, 5, 6,
		7, 8, 9, 50, 1, 2, 3, 4, 5, 6, 7, 8, 9, 60, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		70, 1, 2, 3, 4, 5, 6, 7, 8, 9, 80
	};

	uvlong i;

	assert(efficient(0) == 0);
	assert(efficient(1) == 1);
	assert(efficient(2) == 2);
	assert(efficient(10) == 10);
	assert(efficient(11) == 1);
	assert(efficient(29) == 9);
	assert(efficient(30) == 30);
	assert(efficient(99) == 9);
	assert(efficient(100) == 100);
	assert(efficient(119) == 9);
	assert(efficient(120) == 20);
	assert(efficient(200) == 200);
	assert(efficient(409) == 9);
	assert(efficient(1020) == 20);

	for (i = 0; i < nelem(tab); i++)
		assert(efficient(i + 1) == tab[i]);

	return 0;
}
