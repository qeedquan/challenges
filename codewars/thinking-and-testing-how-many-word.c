/*

No Story

No Description

Only by Thinking and Testing

Look at result of testcase, guess the code!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
testit(const char *s)
{
	static const char word[] = "word";

	const char *w;
	size_t c;

	c = 0;
	for (w = word; *s; s++) {
		if (tolower(*s) == *w) {
			w++;
			if (!*w) {
				c += 1;
				w = word;
			}
		}
	}
	return c;
}

void
test(const char *s, size_t r)
{
	assert(testit(s) == r);
}

int
main()
{
	test("word", 1);
	test("hello world", 1);
	test("I love codewars.", 0);
	test("My cat waiting for a dog.", 1);
	test("We often read book, a word hidden in the book.", 2);
	test("When you in order to do something by a wrong way, your heart will missed somewhere.", 2);
	test("This sentence have one word.", 1);
	test("This sentence have two word, not one word.", 2);
	test("One word + one word = three word ;-)", 3);
	test("Can you find more word for me?", 1);

	return 0;
}
