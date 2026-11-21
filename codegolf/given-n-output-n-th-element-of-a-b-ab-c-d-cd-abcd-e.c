/*

Consider the following list:

expected = [
'A',
'B',
'AB',
'C',
'D',
'CD',
'ABCD',
'E',
'F',
'EF',
'G',
'H',
'GH',
'EFGH',
'ABCDEFGH',
'I',
'J',
'IJ',
'K',
'L',
'KL',
'IJKL',
'M',
'N',
'MN',
'O',
'P',
'OP',
'MNOP',
'IJKLMNOP',
'ABCDEFGHIJKLMNOP',
...
]
Here's one way to look at it - you're learning how to write Chinese characters and want to learn increasingly big chunks of them, rehearsing them as you go. You start with A, then go with B, then there's already a sequence that is a pair of two so you combine it. Then you go with C and D, make another pair, practice it. Then you rehearse: ABCD. Then the same goes with E up to H, then rehearse: ABCDEFGH. The list is infinite.

The goal is to generate and print out an n-th element of this list, indexes going up from zero. Assume that after 'Z', you get 'A' again.

The winning criteria is source code length.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://oeis.org/A182105

@Arnauld

Based upon a construction by Donald Knuth. Related OEIS entry: A182105.

How?
This is a two-stage recursive function.


We first build the sequence (un,vn) defined as (u1,v1)=(1,1) and:
(un+1, vn+1)={(un+1,1)   if (un AND -un)=vn
              (un, 2*vn) otherwise

During the second pass, we build the list [un-vn,un-vn+1,…,un] and eventually return it.

*/

void
con(unsigned n, char *b)
{
	unsigned i, x, y;
	char *p;

	x = 0;
	y = 1;
	for (i = 0; i < n; i++) {
		x ^= y - x;
		y += x / y;
	}

	p = b;
	for (i = x; i < y; i++)
		*p++ = 'A' + (i % 26);
	*p = '\0';
}

int
main()
{
	static const char *tab[] = {
	    "A",
	    "B",
	    "AB",
	    "C",
	    "D",
	    "CD",
	    "ABCD",
	    "E",
	    "F",
	    "EF",
	    "G",
	    "H",
	    "GH",
	    "EFGH",
	    "ABCDEFGH",
	    "I",
	    "J",
	    "IJ",
	    "K",
	    "L",
	    "KL",
	    "IJKL",
	    "M",
	    "N",
	    "MN",
	    "O",
	    "P",
	    "OP",
	    "MNOP",
	    "IJKLMNOP",
	    "ABCDEFGHIJKLMNOP",
	};

	char b[128];
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		con(i, b);
		printf("%s\n", b);
		assert(!strcmp(b, tab[i]));
	}

	return 0;
}
