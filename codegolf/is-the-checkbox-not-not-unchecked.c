/*

Doing code review, I stumbled upon the following code, that tests the status of a checkbox:

if (!isNotUnchecked()) { ... }
I had to brainstorm for 30 minutes to find out what actual checkbox status the code was expecting. Please write me a program that can simplify these silly expressions!

The program should accept as input a string representing the expression to simplify (for example: !isNotUnchecked()). The program should output a logically equivalent simplified expression, either isChecked() or !isChecked().

The method name in the input expression always starts with is, contains 0..n Not, and ends with Checked() or Unchecked(). The method can be prefixed by any number of !.

Examples
isChecked() => isChecked()
isUnchecked() => !isChecked()
isNotChecked() => !isChecked()
!isNotChecked() => isChecked()
!!!isNotNotUnchecked() => isChecked()

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
simplify(const char *s, char *b)
{
	size_t i, l, p;

	strcpy(b, s);

	i = 0;
	while (s[i] == '!')
		i++;

	p = i & 1;
	if (strncmp(s + i, "is", 2))
		return b;
	s += 2;

	while (!strncmp(s + i, "Not", 3)) {
		i += 3;
		p ^= 1;
	}

	if (!strcmp(s + i, "Unchecked()"))
		p ^= 1;
	else if (strcmp(s + i, "Checked()"))
		return b;

	l = 0;
	if (p & 1)
		l += sprintf(b + l, "!");
	sprintf(b + l, "isChecked()");

	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	simplify(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("isChecked()", "isChecked()");
	test("isUnchecked()", "!isChecked()");
	test("isNotChecked()", "!isChecked()");
	test("!isNotChecked()", "isChecked()");
	test("!!!isNotNotUnchecked()", "isChecked()");

	return 0;
}
