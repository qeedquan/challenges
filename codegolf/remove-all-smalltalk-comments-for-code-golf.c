/*

Take a line of input (function arguments or stdin, etc.).
Remove comments in it, where a comment starts and ends with ".
Do not remove comments in string literals, which start and end with '. String literals do not contain escapes, because smalltalk has nice, easily lexable syntax ;).
Output this string.
The number of "s not inside strings and the number of 's not in comments in the input are both guaranteed to be even.
Because removing comments makes programs more golfy, this is code-golf: shortest code per language wins.

Examples
input => output

123 => 123
1"2"3 => 13
1""23 => 123
'12' => '12'
'1"2'3"" => '1"2'3
'1"2"3' => '1"2"3'
a"1'2'3"a => aa
"a"b"c" => b
'a'b'c' => 'a'b'c'
a'"'b'"'c => a'"'b'"'c
a"'"b"'"c => abc

Regex is boring as usual. Try something new, or answer in smalltalk!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
eatcom(const char *s)
{
	size_t i;

	if (s[0] != '"')
		return 0;

	i = 1;
	for (;;) {
		if (!s[i])
			break;
		if (s[i++] == '"')
			break;
	}
	return i;
}

size_t
eatcode(const char *s, char *b)
{
	size_t i;

	b[0] = s[0];
	if (s[0] == '\0')
		return 0;
	if (s[0] != '\'')
		return 1;

	for (i = 1; s[i]; i++) {
		b[i] = s[i];
		if (s[i] == '\'') {
			i++;
			break;
		}
	}
	return i;
}

char *
uncom(const char *s, char *b)
{
	size_t i, j, n;

	i = j = 0;
	while (s[i]) {
		i += eatcom(s + i);
		n = eatcode(s + i, b + j);
		i += n;
		j += n;
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	uncom(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("123", "123");
	test("1\"2\"3", "13");
	test("1\"\"23", "123");
	test("'12'", "'12'");
	test("'1\"2'3\"\"", "'1\"2'3");
	test("'1\"2\"3'", "'1\"2\"3'");
	test("a\"1'2'3\"a", "aa");
	test("\"a\"b\"c\"", "b");
	test("'a'b'c'", "'a'b'c'");
	test("a'\"'b'\"'c", "a'\"'b'\"'c");
	test("a\"'\"b\"'\"c", "abc");
	test("", "");

	return 0;
}
