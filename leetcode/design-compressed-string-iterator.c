/*

Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	const char *s;
	char c;
	size_t nc;
} RLE;

void
rleinit(RLE *z, const char *s)
{
	memset(z, 0, sizeof(*z));
	z->s = s;
}

bool
rlehasnext(RLE *z)
{
	return z->s[0] || z->nc;
}

int
rlenext(RLE *z)
{
	char *ep;

	while (rlehasnext(z)) {
		if (z->nc) {
			z->nc--;
			return z->c;
		}

		z->c = z->s[0];
		z->nc = strtoul(z->s + 1, &ep, 10);
		z->s = ep;
	}

	return ' ';
}

int
main(void)
{
	RLE z[1];

	rleinit(z, "L1e2t1C1o1d1e1");
	assert(rlenext(z) == 'L');
	assert(rlenext(z) == 'e');
	assert(rlenext(z) == 'e');
	assert(rlenext(z) == 't');
	assert(rlenext(z) == 'C');
	assert(rlenext(z) == 'o');
	assert(rlenext(z) == 'd');
	assert(rlehasnext(z) == true);
	assert(rlenext(z) == 'e');
	assert(rlehasnext(z) == false);
	assert(rlenext(z) == ' ');

	return 0;
}
