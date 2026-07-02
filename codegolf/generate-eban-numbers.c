/*

(Continuing on the number sequences code-golf, here is an interesting sequence)

Eban Numbers (A006933) are the sequence of numbers whose names (in English) do not contain the letter "e" (i.e., "e" is "banned")

The first few numbers in the sequence are:

2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56
Given an integer n, via function argument or STDIN, return the first n terms of the Eban Numbers (in numbers) .

Since some answers will involve some sort of string check for character e, assume that the maximum value of n can be such that the nth Eban number is less than 1 Quadrillion.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define nelem(x) (sizeof(x) / (sizeof(x[0])))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return min(size, n);
}

char *
spellout(char *b, size_t n, long x)
{
	static const char *num[] = {
	    "zero",
	    "one",
	    "two",
	    "three",
	    "four",
	    "five",
	    "six",
	    "seven",
	    "eight",
	    "nine",
	    "ten",
	    "eleven",
	    "twelve",
	    "thirteen",
	    "fourteen",
	    "fifteen",
	    "sixteen",
	    "seventeen",
	    "eighteen",
	    "nineteen",
	};
	static const char *tens[] = {
	    "twenty",
	    "thirty",
	    "forty",
	    "fifty",
	    "sixty",
	    "seventy",
	    "eighty",
	    "ninety",
	};
	static const char *mag[] = {
	    "thousand",
	    "million",
	    "billion",
	    "trillion",
	    "quadrillion",
	    "quintillion",
	    "sextillion",
	    "septillion",
	};
	char s[80];
	size_t l;
	int i, m, t, r, o;

	m = snprint(s, sizeof(s), "%ld", x);
	l = 0;

	i = 0;
	if (s[i] == '-') {
		l += snprint(b + l, n - l, "negative ");
		m--;
		i++;
	}

	o = 0;
	for (;;) {
		t = 0;
		switch ((r = m % 3)) {
		case 0:
			t += (s[i++] - '0') * 100;
			// fallthrough
		case 2:
			t += (s[i++] - '0') * 10;
			// fallthrough
		case 1:
			t += s[i++] - '0';
			break;
		}

		if (t != 0 && o)
			l += snprint(b + l, n - l, ", ");

		if (t >= 100) {
			l += snprint(b + l, n - l, "%s hundred", num[t / 100]);
			t %= 100;
			if (t != 0)
				l += snprint(b + l, n - l, " ");
		}

		if (t >= 20) {
			l += snprint(b + l, n - l, "%s", tens[t / 10 - 2]);
			if (t % 10)
				l += snprint(b + l, n - l, "-%s", num[t % 10]);
		} else if (!(r == 0 && t == 0) || (!o && t != 0))
			l += snprint(b + l, n - l, "%s", num[t]);

		m -= (r == 0) ? 3 : r;
		if (m <= 0)
			break;

		if (t != 0)
			l += snprint(b + l, n - l, " %s", mag[m / 3 - 1]);
		o = 1;
	}

	return b;
}

// https://oeis.org/A006933
bool
iseban(long x)
{
	char b[1024];

	spellout(b, sizeof(b), x);
	return strchr(b, 'e') == NULL;
}

void
gen(long *r, size_t n)
{
	size_t m;
	long i;

	m = 0;
	for (i = 0; m < n; i++) {
		if (iseban(i))
			r[m++] = i;
	}
}

int
main(void)
{
	static const long tab[] = {2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56, 60, 62, 64, 66, 2000, 2002, 2004, 2006, 2030, 2032, 2034, 2036, 2040, 2042, 2044, 2046, 2050, 2052, 2054, 2056, 2060, 2062, 2064, 2066, 4000, 4002, 4004, 4006, 4030, 4032, 4034, 4036, 4040, 4042, 4044, 4046, 4050, 4052, 4054, 4056, 4060, 4062, 4064, 4066, 6000};

	long v[128];

	gen(v, nelem(tab));
	assert(!memcmp(v, tab, sizeof(tab)));

	return 0;
}
