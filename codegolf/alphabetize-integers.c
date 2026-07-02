/*

For a given set of numbers, put them in alphabetical order when they are spelled out (i.e. 1: one, 2: two, 90: ninety, 19: nineteen).
Your code should work for the range [-999999, 999999]. Output must have a delimiter between numbers.
A space will work, as will a space and a comma as shown in the examples below.
Input can be an array of integers, a string of delimited numbers, or however you see fit.
All integers are assumed to be unique.

Numbers are not hyphenated for the purposes of this challenge and spaces are alphabetized before any other characters.
Negative numbers are assumed to be expressed by using the word minus.
For example, four would precede four thousand and the number -40 would be sorted using the string minus forty.
Assume all numbers will be solely comprised of number words and no conjunctions (e.g. use two thousand forty two instead of two thousand and forty two).

Test Cases
Single Digit Integers:

Input:

1, 2, 3, 4, 5
Output:

5, 4, 1, 3, 2
Multiple Digit Integers:

Input:

-1002, 5, 435012, 4, 23, 81, 82
Output:

81, 82, 5, 4, 435012, -1002, 23
Spaces between words, no hyphens, commas or "and":

Input:

6, 16, 60, 64, 600, 6000, 60000, 60004, 60008, 60204, 60804
Output:

6, 600, 6000, 16, 60, 64, 60000, 60008, 60804, 60004, 60204
Remember, this is code-golf, so the code with the fewest bytes wins. No loopholes allowed!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / (sizeof(x[0])))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

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
		l += snprint(b + l, n - l, "minus ");
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
			l += snprint(b + l, n - l, " ");

		if (t >= 100) {
			l += snprint(b + l, n - l, "%s hundred", num[t / 100]);
			t %= 100;
			if (t != 0)
				l += snprint(b + l, n - l, " ");
		}

		if (t >= 20) {
			l += snprint(b + l, n - l, "%s", tens[t / 10 - 2]);
			if (t % 10)
				l += snprint(b + l, n - l, " %s", num[t % 10]);
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

int
cmp(const void *a, const void *b)
{
	char s[256], t[256];
	vlong x, y;

	x = *(vlong *)a;
	y = *(vlong *)b;

	spellout(s, sizeof(s), x);
	spellout(t, sizeof(t), y);

	return strcmp(s, t);
}

void
aisort(vlong *a, size_t n)
{
	qsort(a, n, sizeof(*a), cmp);
}

void
dump(vlong *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");
}

void
test(vlong *a, size_t n, vlong *r)
{
	aisort(a, n);
	dump(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	vlong a1[] = {1, 2, 3, 4, 5};
	vlong r1[] = {5, 4, 1, 3, 2};

	vlong a2[] = {-1002, 5, 435012, 4, 23, 81, 82};
	vlong r2[] = {81, 82, 5, 4, 435012, -1002, 23};

	vlong a3[] = {6, 16, 60, 64, 600, 6000, 60000, 60004, 60008, 60204, 60804};
	vlong r3[] = {6, 600, 6000, 16, 60, 64, 60000, 60008, 60804, 60004, 60204};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);

	return 0;
}
