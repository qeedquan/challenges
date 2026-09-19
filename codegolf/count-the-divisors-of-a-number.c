/*

Introduction
This is a very simple challenge: simply count the divisors of a number. We've had a similar but more complicated challenge before, but I'm intending this one to be entry-level.

The Challenge
Create a program or function that, given one strictly positive integer N, outputs or returns how many divisors it has, including 1 and N.

Input: One integer > 0. You may assume that the number can be represented in your language's native numeric type.

Output: The number of positive integer divisors it has, including 1 and the number itself.

Submissions will be scored in bytes. You may find this website handy, though you may use any reasonable method for generating your byte count.

This is code-golf, so the lowest score wins!

Edit: It looks like FryAmTheEggman's 5-byte Pyth answer is the winner! Feel free to submit new answers, though; if you can get something shorter, I'll change the accepted answer.

Test Cases
ndiv(1) -> 1
ndiv(2) -> 2
ndiv(12) -> 6
ndiv(30) -> 8
ndiv(60) -> 12
ndiv(97) -> 2
ndiv(100) -> 9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A000005
int
divs(int n)
{
	int c, i;

	c = 0;
	for (i = n; i > 0; i--) {
		if (!(n % i))
			c += 1;
	}
	return c;
}

int
main()
{
	static const int tab[] = {
		1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2,
		8, 3, 4, 4, 6, 2, 8, 2, 6, 4, 4, 4, 9, 2, 4, 4, 8, 2, 8, 2, 6, 6, 4,
		2, 10, 3, 6, 4, 6, 2, 8, 4, 8, 4, 4, 2, 12, 2, 4, 6, 7, 4, 8, 2, 6, 4,
		8, 2, 12, 2, 4, 6, 6, 4, 8, 2, 10, 5, 4, 2, 12, 4, 4, 4, 8, 2, 12, 4,
		6, 4, 4, 4, 12, 2, 6, 6, 9, 2, 8, 2, 8
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(divs(i + 1) == tab[i]);

	assert(divs(1) == 1);
	assert(divs(2) == 2);
	assert(divs(12) == 6);
	assert(divs(30) == 8);
	assert(divs(60) == 12);
	assert(divs(97) == 2);
	assert(divs(100) == 9);

	return 0;
}
