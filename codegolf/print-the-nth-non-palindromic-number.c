/*

A palindromic number (in case you don't know) is a number which reads the same backwards and forwards (example, 11).
The first 15 non-palindromic numbers are: 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26. This is A029742.
I constantly need these numbers, but my sticky note pad is very small, so your code must be as short as possible.

Rules
Each submission must be a full program or function (e.g. in C, you can't just define a function without headers, but you can define a function WITH necessary headers ).
If it is possible, provide a link to a site where your program can be tested.
Your program must not write anything to STDERR.
You can take input as an argument or from STDIN (or the closest alternative in your language).
Programs are scored according to bytes. The usual character set is UTF-8, if you are using another please specify.
Standard loopholes are forbidden.

Test Cases
1
==> 10

-----

5
==> 15

-----

12
==> 23

Scoring
This is code-golf, so least bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
rev(uvlong n)
{
	uvlong r;

	for (r = 0; n > 0; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

// https://oeis.org/A029742
int
nonpalindrome(uvlong n)
{
	return n != rev(n);
}

uvlong
gen(uvlong n, uvlong *r)
{
	uvlong i, l;

	for (i = l = 0; i <= n; i++) {
		if (nonpalindrome(i))
			r[l++] = i;
	}
	return l;
}

int
main(void)
{
	static const uvlong tab[] = {10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 100, 102, 103, 104, 105, 106, 107};

	uvlong val[128];

	gen(tab[nelem(tab) - 1], val);
	assert(!memcmp(val, tab, sizeof(tab)));

	return 0;
}
