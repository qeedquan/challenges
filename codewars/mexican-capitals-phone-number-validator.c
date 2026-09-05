/*

Validate all numbers to make local calls from the capital city at the Mexican United States.

The first two digits are the lada. Lada can only be 55 or 56 for those Mexico City phone numbers.

The first two digits of the phone numbers when dialed locally are known as lada. To make phone numbers more readable some people write the lada between parenthesis. As you will see in further Katas lada concept is actually deeper than area code.

Example

Valid numbers:

(56) 84 65 52
(56) 84 6552
(56) 846552
(56)846552
56 84 65 52
56 84 6552
56 846552
56846552
55 95 64 85
55 95 6485
55 956485
55956485

Non-Valid numbers:

99956485
abcdefgh
(56) 84 6 552

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
match(const char *f, const char **s)
{
	const char *p;

	for (p = *s; *f; f++, p++) {
		switch (*f) {
		case '(':
		case ')':
		case '5':
			if (*p != *f)
				return false;
			break;

		case '6':
			if (*p != '5' && *p != '6')
				return false;
			break;

		case 'x':
			if (!isdigit(*p))
				return false;
			break;
		}
	}

	*s = p;
	return true;
}

const char *
matchany(const char **fs, size_t n, const char *s)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (match(fs[i], &s))
			return s;
	}
	return NULL;
}

bool
valid(const char *s)
{
	static const char *fs0[] = { "(56)", "56" };
	static const char *fs1[] = { "xxxxxx", "xxxx xx", "xx xxxx", "xx xx xx" };

	s = matchany(fs0, nelem(fs0), s);
	if (!s)
		return false;

	if (*s == ' ')
		s++;

	s = matchany(fs1, nelem(fs1), s);
	if (!s)
		return false;

	return *s == '\0';
}

int
main()
{
	assert(valid("(56) 84 65 52") == true);
	assert(valid("(56) 84 6552") == true);
	assert(valid("(56) 846552") == true);
	assert(valid("(56)846552") == true);
	assert(valid("56 84 65 52") == true);
	assert(valid("56 84 6552") == true);
	assert(valid("56 846552") == true);
	assert(valid("56846552") == true);
	assert(valid("55 95 64 85") == true);
	assert(valid("55 95 6485") == true);
	assert(valid("55 956485") == true);
	assert(valid("55956485") == true);

	assert(valid("99956485") == false);
	assert(valid("abcdefgh") == false);
	assert(valid("(56) 84 6 552") == false);

	return 0;
}
