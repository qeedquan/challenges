/*

Description

Soundex coding groups together words that appear to sound alike based on their spelling. For example, "can" and "khawn", "con" and "gone" would be equivalent under Soundex coding.
Soundex coding involves translating each word into a series of digits in which each digit represents a letter:
      1 represents B, F, P, or V

      2 represents C, G, J, K, Q, S, X,  or Z

      3 represents D or T

      4 represents L

      5 represents M or N

      6 represents R

The letters A, E, I, O, U, H, W, and Y are not represented in Soundex coding, and repeated letters with the same code digit are represented by a single instance of that digit. Words with the same Soundex coding are considered equivalent.

Input

Each line of input contains a single word, all upper case, less than 20 letters long.

Output

For each line of input, produce a line of output giving the Soundex code.

Sample Input

KHAWN
PFISTER
BOBBY

Sample Output

25
1236
11

Source

Waterloo local 1999.09.25

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
soundex(const char *s, char *b)
{
	static const char tab[256] = {
	    ['B'] = '1',
	    ['F'] = '1',
	    ['P'] = '1',
	    ['V'] = '1',

	    ['C'] = '2',
	    ['G'] = '2',
	    ['J'] = '2',
	    ['K'] = '2',
	    ['Q'] = '2',
	    ['S'] = '2',
	    ['X'] = '2',
	    ['Z'] = '2',

	    ['D'] = '3',
	    ['T'] = '3',

	    ['L'] = '4',

	    ['M'] = '5',
	    ['N'] = '5',

	    ['R'] = '6',
	};

	size_t i, j;
	int c, p;

	p = 0;
	for (i = j = 0; s[i]; i++) {
		c = tab[s[i] & 0xff];
		if (c && c != p)
			b[j++] = c;
		p = c;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	soundex(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("KHAWN", "25");
	test("PFISTER", "1236");
	test("BOBBY", "11");

	return 0;
}
