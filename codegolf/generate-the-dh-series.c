/*

https://www.smbc-comics.com/comic/puzzle-time

I see from this SMBC comic that Zach Weinersmith is offering a generous 14 points to anybody who can find a way of generating the following series:

0, 1, 4, -13, -133, 52, 53, -155
Now, we all know that there are infinite ways of generating any given numeric series, so Zach is clearly just giving those points away. But what's the shortest code that will do it?

I'll be particularly impressed if anyone can beat 25 bytes, particularly in a non-golfing language, since that's what it takes to write the following reference implementation in Python:

0,1,4,-13,-133,52,53,-155
The output can be in whichever format works best for you:

a program that spits out plaintext representation of signed decimal numbers
an expression that evaluates to a static sequence of numeric objects with these values (as in my Python example)
an expression for f(n) that returns the nth value of the sequence. You can choose a zero-based or one-based convention for n as you wish and need not worry what the expression produces subsequent to the known elements. (By "expression" here, I mean let's not count the characters in the function prototype itself, and let's say you can assume n is pre-initialized.)
Longer sequences (including infinite sequences) are permitted provided the first 8 elements match Weinersmith's DH Series above. The ninth and subsequent elements, if present, can be anything at all.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
seq(unsigned n)
{
	static const int tab[] = {0, 1, 4, -13, -133, 52, 53, -155};

	return tab[n % nelem(tab)];
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 8; i++)
		printf("%d ", seq(i));
	printf("\n");

	return 0;
}
