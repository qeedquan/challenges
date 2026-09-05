/*

In calculus, the derivative of a mathematical function defines the rate at which it changes. The derivative of a function f(x) can be marked as f'(x), and these can sometimes be abbreviated to f and f'.

The derivative of the product of two functions fg is f'g + g'f. The derivative of three fgh is f'gh + fg'h + fgh'. In general, the derivative of a product of any number of functions is the sum of the product of all but one, multiplied by the derivative of the remaining one, for each individual function.

Your challenge is to take a string of distinct alphabetical characters and transform it into its derivative. No spacing or simplification is required, and terms separated by + may be in any order. The string will contain at least two characters.

This is code-golf, so the shortest code wins!

Testcases
abc -> a'bc+ab'c+abc'
de -> d'e+de'
longabcdef -> l'ongabcdef+lo'ngabcdef+lon'gabcdef+long'abcdef+longa'bcdef+longab'cdef+longabc'def+longabcd'ef+longabcde'f+longabcdef'
short -> s'hort+sh'ort+sho'rt+shor't+short'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
diffprod(const char *s, char *b)
{
	size_t i, j, k;

	for (i = k = 0; s[i]; i++) {
		for (j = 0; s[j]; j++) {
			b[k++] = s[j];
			if (j == i)
				b[k++] = '\'';
		}
		if (s[i + 1])
			b[k++] = '+';
	}
	b[k] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	diffprod(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abc", "a'bc+ab'c+abc'");
	test("de", "d'e+de'");
	test("longabcdef", "l'ongabcdef+lo'ngabcdef+lon'gabcdef+long'abcdef+longa'bcdef+longab'cdef+longabc'def+longabcd'ef+longabcde'f+longabcdef'");
	test("short", "s'hort+sh'ort+sho'rt+shor't+short'");

	return 0;
}
