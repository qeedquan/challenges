/*

The goal of this challenge is to compute one kind of numerology digit from strings containing characters and numbers.

The input may be through any convenient method (standard input, arguments, separated file).
The input may contain any printable ASCII chars, but only alphanumerical (A-Z, a-z, and 0-9) have to be considered.
The output must be a digit between 1 and 9 or a star * if no letter and no digit where found... (or even 0 if input contain any number of 0 and nothing else but this doesn't matter).
Letter values are mapped in this way:

1  2  3  4  5  6  7  8  9
a  b  c  d  e  f  g  h  i
j  k  l  m  n  o  p  q  r
s  t  u  v  w  x  y  z
The numerology digit is computed by adding each value of string, then repeat until there is only one digit. Sample for 13579, Hello, world!, 00 0 00, !@#$%^&*();, and 3.141592:

13579 => 1 + 3 + 5 + 7 + 9 = 25 => 2 + 5 = 7
Hello, world! => 8 + 5 + 3 + 3 + 6 + 5 + 6 + 9 + 3 + 4 = 52 => 5 + 2 = 7
00 0 00 => 0 + 0 + 0 + 0 + 0 = 0
!@#$%^&*(); => *
  => *
3.141592 => 3 + 1 + 4 + 1 + 5 + 9 + 2 = 25 => 2 + 5 = 7
3.1415926535897932384 =>
 3 + 1 + 4 + 1 + 5 + 9 + 2 + 6 + 5 + 3 + 5 + 8 + 9 + 7 + 9 + 3 + 2 + 3 + 8 + 4
 = 97 => 9 + 7 = 16 => 1 + 6 = 7
(This is great, most of this samples give 7! But it's just sample ;)

Some more tests:

Bob  => 2 + 6 + 2 = 10 => 1 + 0 = 1
Charlie => 3 + 8 + 1 + 9 + 3 + 9 + 5 = 38 => 3 + 8 = 11 => 1 + 1 = 2
Anna => 1 + 5 + 5 + 1 = 12 => 1 + 2 = 3
Fana => 6 + 1 + 5 + 1 = 13 => 1 + 3 = 4
Gregory => 7 + 9 + 5 + 7 + 6 + 9 + 7 = 50 => 5 + 0 = 5
Denis => 4 + 5 + 5 + 9 + 1 = 24 => 2 + 4 = 6
Erik => 5 + 9 + 9 + 2 = 25 => 2 + 5 = 7
Helen => 8 + 5 + 3 + 5 + 5 = 26 => 2 + 6 = 8
Izis => 9 + 8 + 9 + 1 = 27 => 2 + 7 = 9

This is a code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
map(const char *s, int *f)
{
	static const int tab[256] = {
	    ['1'] = 1,
	    ['a'] = 1,
	    ['j'] = 1,
	    ['s'] = 1,

	    ['2'] = 2,
	    ['b'] = 2,
	    ['k'] = 2,
	    ['t'] = 2,

	    ['3'] = 3,
	    ['c'] = 3,
	    ['l'] = 3,
	    ['u'] = 3,

	    ['4'] = 4,
	    ['d'] = 4,
	    ['m'] = 4,
	    ['v'] = 4,

	    ['5'] = 5,
	    ['e'] = 5,
	    ['n'] = 5,
	    ['w'] = 5,

	    ['6'] = 6,
	    ['f'] = 6,
	    ['o'] = 6,
	    ['x'] = 6,

	    ['7'] = 7,
	    ['g'] = 7,
	    ['p'] = 7,
	    ['y'] = 7,

	    ['8'] = 8,
	    ['h'] = 8,
	    ['q'] = 8,
	    ['z'] = 8,

	    ['9'] = 9,
	    ['i'] = 9,
	    ['r'] = 9,
	};

	size_t i;
	int c, r;

	r = *f = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]) & 0xff;
		r += tab[c];
		*f = *f || isalpha(c) || isdigit(c);
	}
	return r;
}

int
digitsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

int
numerology(const char *s)
{
	int f, v;

	v = map(s, &f);
	if (f == 0)
		return '*';

	while (v >= 10)
		v = digitsum(v);
	return v;
}

int
main(void)
{
	assert(numerology("13579") == 7);
	assert(numerology("Hello, world!") == 7);
	assert(numerology("00 0 00") == 0);
	assert(numerology("!@#$%^&*();") == '*');
	assert(numerology("3.141592") == 7);
	assert(numerology("3.1415926535897932384") == 7);

	assert(numerology("Bob") == 1);
	assert(numerology("Charlie") == 2);
	assert(numerology("Anna") == 3);
	assert(numerology("Fana") == 4);
	assert(numerology("Gregory") == 5);
	assert(numerology("Denis") == 6);
	assert(numerology("Erik") == 7);
	assert(numerology("Helen") == 8);
	assert(numerology("Izis") == 9);

	return 0;
}
