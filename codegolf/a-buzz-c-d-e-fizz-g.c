/*

A simple FizzBuzz using strings.

Given

1 word or phrase (string)
2 unique characters
Output

The word or phrase with each occurrence of the first character replaced with fizz and each of the second character replaced with buzz

Rules

The first letter in both Fizz and Buzz must remain capitalized
For the rest of the words fizz and buzz, you must match the case of the replaced character (if no case then keep lowercase)
If given characters are not in the phrase, output the original phrase
Test Cases

Given: Hello, h, l
Output: FIZZeBuzzBuzzo

Given: test, a, b
Output: test

Given: PCG rocks!,  , !
PCGFizzrocksBuzz

Given: This
Is
SPARTA!,
, S
Output: ThiBuzzFizzIBuzzFizzBUZZPARTA!

Given: FizzBuzz, a, b
Output: FizzBUZZuzz
This is code-golf so the shortest code, in bytes, wins!

Note

Technically handling the newline case (This Is SPARTA!) is a part of the challenge. However, I will not void an answer for not including it, as it is very challenging or even impossible in some languages.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
fba(const char *s, int c0, int c1, char *b)
{
	size_t i, j;
	int c, u;

	c0 = tolower(c0);
	c1 = tolower(c1);
	for (i = j = 0; s[i]; i++) {
		u = isupper(s[i]);
		c = tolower(s[i]);
		if (c == c0)
			j += sprintf(b + j, (u) ? "FIZZ" : "Fizz");
		else if (c == c1)
			j += sprintf(b + j, (u) ? "BUZZ" : "Buzz");
		else
			b[j++] = s[i];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, int c0, int c1, const char *r)
{
	char b[128];

	fba(s, c0, c1, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Hello", 'h', 'l', "FIZZeBuzzBuzzo");
	test("test", 'a', 'b', "test");
	test("PCG rocks!", ' ', '!', "PCGFizzrocksBuzz");
	test("This\nIs\nSPARTA!", '\n', 'S', "ThiBuzzFizzIBuzzFizzBUZZPARTA!");
	test("FizzBuzz", 'a', 'b', "FizzBUZZuzz");

	return 0;
}
