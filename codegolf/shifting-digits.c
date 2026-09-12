/*

Given a string representing a number and the base that number is in, shift each positional value upward, wrapping back to zero if the value cannot increase. You will never be provided invalid input, nor a base larger than 36.

For example, you may be provided ['5f6', '16'], which represents the number 1526 in base 16. The expected output in that case would be '607' (1543 in base 16).

Input
program: separate lines from STDIN: '5f6\n16'
function: a tuple or array: f(['5f6', '16']) or f(['5f6', 16])
function: two arguments f('5f6', '16') or f('5f6', 16)
Output
program: to STDOUT: 607
function: returned as a string: '607'
Test cases
['5f6', '16']
'607'

['abc', '36']
'bcd'

['1', '1'] or ['0', '1']
'1' or '0'

['9540', '10']
'0651' or '651'

['001', '2']
'110'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
inc(int c, int p, char *r)
{
	static const char sym[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int n;

	if ('0' <= c && c <= '9')
		n = c - '0';
	else if ('a' <= c && c <= 'z')
		n = c - 'a' + 10;
	else if ('A' <= c && c <= 'Z')
		n = c - 'A' + 10;
	else
		return -1;

	if (n > p || p > 36)
		return -1;

	n = (n + 1) % p;
	*r = sym[n];
	if (isupper(c))
		*r = toupper(*r);
	return 0;
}

int
shift(const char *s, int p, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (inc(s[i], p, &b[i]) < 0)
			return -1;
	}
	b[i] = '\0';
	return 0;
}

void
test(const char *s, int p, const char *r)
{
	char b[128];

	assert(shift(s, p, b) >= 0);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("5f6", 16, "607");
	test("abc", 36, "bcd");
	test("1", 1, "0");
	test("9540", 10, "0651");
	test("001", 2, "110");

	return 0;
}
