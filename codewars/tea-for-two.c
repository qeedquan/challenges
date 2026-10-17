/*

Tea for two!

Given a string or number write a function tea42 that takes as input a string or number and returns a string where every '2' charcter or digit has been replaced with a t.

tea42('coffee') //should return 'coffee'
tea42('tea') //should return 'tea'
tea42('2ea') //should return 'tea'
tea42(9022) //should return '90tt'
tea42(5676765) //should return '5676765'
tea42('2u2u') //should return 'tutu'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
tea42(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if (b[i] == '2')
			b[i] = 't';
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	tea42(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("coffee", "coffee");
	test("tea", "tea");
	test("2ea", "tea");
	test("9022", "90tt");
	test("5676765", "5676765");
	test("2u2u", "tutu");
	return 0;
}
