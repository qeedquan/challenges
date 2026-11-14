/*

Given two strings: a string s and an alphabet a, implement string projection in the shortest code possible.

String projection returns a string o that contains the characters in s that are in a. The order of the characters in o must match the order of characters in s. So if s = "abcd" and a = "12da34", o = "ad", since only "ad" is shared between s and a.

You will need to handle when a is empty (outputs empty string, since no character in s can match empty string).

Test Cases
"string", "alphabet" => "output"
-------------------------------
"abcd", "12da34" => "ad"
"hello, world!", "aeiou" => "eoo"
"hello, world!", "abcdefghijklmnopqrstuvwxyz" => "helloworld"
"Hello, World!", "abcdefghijklmnopqrstuvwxyz" => "elloorld" (case sensitivity)
"Hello, World!", "abcdef" => "ed"
"Hello, World!", "!,. \n\t" => ", !" (newline, tab)
"172843905", "abc123" => "123"
"fizzbuzz", "" => ""
"fizzbuzz", "fizzbuzz" => "fizzbuzz"
"", "fizzbuzz" => ""
"fizzbuzz", "zzzzz" => "zzzz"
"", "" => "" (two empty strings)

Winning Criteria
This is code-golf, so shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
strproj(const char *s, const char *p, char *b)
{
	int h[256];
	size_t i, j;

	memset(h, 0, sizeof(h));
	for (i = 0; p[i]; i++)
		h[p[i] & 0xff] = 1;

	for (i = j = 0; s[i]; i++) {
		if (h[s[i] & 0xff])
			b[j++] = s[i];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *p, const char *r)
{
	char b[128];

	strproj(s, p, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abcd", "12da34", "ad");
	test("hello, world!", "aeiou", "eoo");
	test("hello, world!", "abcdefghijklmnopqrstuvwxyz", "helloworld");
	test("Hello, World!", "abcdefghijklmnopqrstuvwxyz", "elloorld");
	test("Hello, World!", "abcdef", "ed");
	test("Hello, World!", "!,. \n\t", ", !");
	test("172843905", "abc123", "123");
	test("fizzbuzz", "", "");
	test("fizzbuzz", "fizzbuzz", "fizzbuzz");
	test("", "fizzbuzz", "");
	test("fizzbuzz", "zzzzz", "zzzz");
	test("", "", "");

	return 0;
}
