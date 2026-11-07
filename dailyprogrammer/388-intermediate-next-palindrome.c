/*

A palindrome is a whole number that's the same when read backward in base 10, such as 12321 or 9449.

Given a positive whole number, find the smallest palindrome greater than the given number.

nextpal(808) => 818
nextpal(999) => 1001
nextpal(2133) => 2222

For large inputs, your solution must be much more efficient than incrementing and checking each subsequent number to see if it's a palindrome.
Find nextpal(3^39) before posting your solution. Depending on your programming language, it should take a fraction of a second.

(This is a repost of Challenge #58 [intermediate], originally posted by u/oskar_s in May 2012.)

*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

int
intlen(uvlong n)
{
	int r;

	for (r = 0; n > 0; r++)
		n /= 10;
	return r;
}

uvlong
revint(uvlong n)
{
	uvlong r;
	int len;
	int shift;
	int i;

	len = intlen(n);
	if (len == 1)
		return n;

	r = 0;
	for (i = 0; i < len; i++) {
		shift = (i == 0) ? 1 : pow(10, i);
		r += ((n / shift) % 10) * pow(10, len - i - 1);
	}
	return r;
}

// https://oeis.org/A262038 (related)
uvlong
nextpal(uvlong n)
{
	uvlong first;
	uvlong r;
	int len;
	int halflen;
	int digits;

	if (n < 9)
		return n + 1;

	if (n == 9)
		n += 1;

	len = intlen(n);
	halflen = (len / 2) + (len & 1);

	first = n / pow(10, len - halflen);
	digits = pow(10, len / 2);
	if (digits < 10)
		digits = 10;

	r = first * digits;
	r += revint(first) % digits;

	if (r > n)
		return r;

	r = (first + 1) * digits;
	r += revint(first + 1) % digits;
	return r;
}

int
main()
{
	assert(nextpal(123) == 131);
	assert(nextpal(808) == 818);
	assert(nextpal(999) == 1001);
	assert(nextpal(2133) == 2222);
	assert(nextpal(51223) == 51315);
	assert(nextpal(51203) == 51215);
	assert(nextpal(4052555153018976267) == 4052555153515552504);

	return 0;
}
