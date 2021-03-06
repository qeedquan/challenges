/*

The Fibonacci sequence, as you know, is generated by iterative addition of the sum of the last two elements of the sequence to the end of the sequence, starting with [0, 1].

Fibonacci = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …]

The iccanobiF sequence (see Resources tab for more info) is generated in a similar way — except that the digits of the last two elements should first be reversed,
then added together, then added to the sequence. Single-digit numbers are unaffected, so the first 8 elements are identical to the Fibonacci sequence:

iccanobiF = [0, 1, 1, 2, 3, 5, 8, 13]

The next element is the sum of the reverse of 8 (still 8), and the reverse of 13 — 31 (8 + 31 = 39).

iccanobiF = [0, 1, 1, 2, 3, 5, 8, 13, 39]

The next element is 31 + 93 = 124

iccanobiF = [0, 1, 1, 2, 3, 5, 8, 13, 39, 124]

And so on.

Create a function that takes a number n and returns the difference between the nth iccanobiF number and the nth Fibonacci number.
Examples

iccMinusFib(4) ➞ 0
// For all n < 9, the difference is zero.

iccMinusFib(9) ➞ 18

iccMinusFib(18) ➞ 790920

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

long long
revll(long long n)
{
	long long v, s;

	s = 1;
	if (n < 0) {
		s = -1;
		n = -n;
	}

	v = 0;
	for (;;) {
		v += n % 10;
		n /= 10;
		if (n == 0)
			break;
		v *= 10;
	}
	return v * s;
}

long long
iccminusfib(long long n)
{
	long long i, a, b, c, d, r, s;

	r = s = 0;
	a = c = 0;
	b = d = 1;
	for (i = 2; i < n; i++) {
		r = a + b;
		s = revll(c) + revll(d);
		a = b;
		b = r;
		c = d;
		d = s;
	}
	return s - r;
}

int
main(void)
{
	assert(iccminusfib(4) == 0LL);
	assert(iccminusfib(9) == 18LL);
	assert(iccminusfib(11) == 459LL);
	assert(iccminusfib(20) == 9675657LL);
	assert(iccminusfib(33) == 171358911LL);
	assert(iccminusfib(18) == 790920LL);
	assert(iccminusfib(49) == 996434352243LL);
	assert(iccminusfib(31) == 93535758LL);

	return 0;
}
