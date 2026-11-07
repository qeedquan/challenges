/*

Everyone is familiar with Roman numerals but have you ever tried to do basic arithmetic using them? This problem is about using Roman numerals for simple addition and subtraction problems.

Most people know that the seven symbols have the following values: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500 and M = 1000. There is a standard form for Roman numbers. This ensures that there is a unique representation for each of the numbers from 1 to 3999 inclusive. If you are unsure of the standard form definition there is a very clear explanation on Wikipedia at https://en.wikipedia.org/wiki/Roman_numerals.

The problems set, including the answers, will all use numbers in the range 1 to 3999. Only correct answers given in standard form will be accepted.

The first line of the problem will be a single integer N denoting the number of test cases. Each of the following N lines will hold a simple addition or subtraction, with the numbers given in Roman standard form. For each of these problems you must find the correct answer, also in Roman standard form. Give these answers, separated by spaces, as a single string.

Example:

input:
4
MMMDCCCLXXI - MMMCCCIII
DC + CCXLI
MMMCCCLIV - MMCCCXXXIX
MCXCVI + MCMLXXXII

answer:
DLXVIII DCCCXLI MXV MMMCLXXVIII

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
	const char *prefix;
	int value;
} Numeral;

const Numeral *
match(const Numeral *p, size_t n, const char *s)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (!strcmp(s, p[i].prefix))
			return &p[i];
	}
	return NULL;
}

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
itor(char *b, size_t n, unsigned x)
{
	static const struct {
		const char *sym;
		unsigned val;
	} tab[] = {
		{ "I", 1 },
		{ "IV", 4 },
		{ "V", 5 },
		{ "IX", 9 },
		{ "X", 10 },
		{ "XL", 40 },
		{ "L", 50 },
		{ "XC", 90 },
		{ "C", 100 },
		{ "CD", 400 },
		{ "D", 500 },
		{ "CM", 900 },
		{ "M", 1000 },
	};

	size_t i, l;

	l = 0;
	l += snprint(b + l, n - l, "");

	for (i = nelem(tab) - 1;; i--) {
		while (x >= tab[i].val) {
			l += snprint(b + l, n - l, tab[i].sym);
			x -= tab[i].val;
		}
		if (i == 0)
			break;
	}

	return b;
}

int
rtoi(const char *s)
{
	static const Numeral num2[] = {
		{ "IV", 4 },
		{ "IX", 9 },
		{ "XL", 40 },
		{ "XC", 90 },
		{ "CD", 400 },
		{ "CM", 900 },
	};

	static const Numeral num1[] = {
		{ "I", 1 },
		{ "V", 5 },
		{ "X", 10 },
		{ "L", 50 },
		{ "C", 100 },
		{ "D", 500 },
		{ "M", 1000 },
	};

	const Numeral *p;
	size_t i;
	char b[3];
	int n;

	n = 0;
	for (i = 0; s[i]; i++) {
		b[0] = s[i];
		b[1] = s[i + 1];
		b[2] = '\0';

		if ((p = match(num2, nelem(num2), b))) {
			n += p->value;
			i++;
			continue;
		}

		b[1] = '\0';
		if ((p = match(num1, nelem(num1), b)))
			n += p->value;
	}
	return n;
}

char *
solve(const char *x, int op, const char *y, char *b, size_t n)
{
	int r;

	r = 0;
	switch (op) {
	case '+':
		r = rtoi(x) + rtoi(y);
		break;
	case '-':
		r = rtoi(x) - rtoi(y);
		break;
	case '*':
		r = rtoi(x) * rtoi(y);
		break;
	case '/':
		r = rtoi(x) / rtoi(y);
		break;
	case '%':
		r = rtoi(x) % rtoi(y);
		break;
	}
	return itor(b, n, r);
}

void
test(const char *x, int op, const char *y, const char *r)
{
	char b[128];

	solve(x, op, y, b, sizeof(b));
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("MMMDCCCLXXI", '-', "MMMCCCIII", "DLXVIII");
	test("DC", '+', "CCXLI", "DCCCXLI");
	test("MMMCCCLIV", '-', "MMCCCXXXIX", "MXV");
	test("MCXCVI", '+', "MCMLXXXII", "MMMCLXXVIII");

	return 0;
}
