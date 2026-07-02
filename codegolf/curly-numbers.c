/*

In the esoteric programming language Curly, programs consist solely of curly braces {} and semicolons ;. Despite this humble toolset, Curly has literals that can represent any nonnegative integer. The format is a little hard for the uninitiated to read, though, so let's write some code to do the conversion for us.

Format of numbers
Curly numbers are structured according to the following rules:

Adding a semicolon adds one to the number.
A number enclosed in curly braces is multiplied by four.
Curly-brace groups may be nested but not concatenated. Braces must match properly.
Semicolons outside a set of curly braces must come afterward, not before.
To avoid ambiguity in parsing, a number must always start with a curly brace.
Some examples:

{;;}     2*4 = 8
{{;};};  (1*4+1)*4+1 = 21
{};;;    0*4+3 = 3
(Note that rule 5 means the numbers 0 to 3 must start with an empty pair of curly braces.)

And some invalid examples:

{{;}{;;}}  Curly brace groups side-by-side, not nested
{;}}       Unmatched brace
{;{;}}     Semicolon before curly-brace group
;;;        Number does not start with curly brace
Here's a BNF grammar for Curly numbers:

<number> ::= "{" <inner> "}" <semis>
<inner>  ::= <semis>
           | <number>
<semis>  ::= ";" <semis>
           | ""
Numbers like {;;;;} (more than 3 semicolons in a row) or {{};} (unnecessary empty brace groups) are called improper Curly numbers. They obey the above grammar and can be evaluated in the usual way, but they are also capable of shorter representations (for the above examples, {{;}} and {;} respectively).

The challenge
Write a program or function that inputs/receives a string. If the string is a nonnegative decimal integer, output/return the proper (i.e. shortest possible) Curly representation for that integer. If the string is a Curly number, output/return its decimal representation.

Input can be received via STDIN, command-line argument, or function parameter. It must be a string; that is, you may not write a function that accepts strings for Curly numbers but integers for decimal numbers.

Output can be printed to STDOUT or returned from the function. A function may return an integer when appropriate, or it may return strings in all situations.

Your program does not have to handle bad input (Curly numbers that break the formatting rules, floating point numbers, negative integers, random text), and it is not required to handle improper Curly numbers (but see below). Input will consist only of printable ASCII characters.

Scoring
The shortest code in bytes wins. If your program can do both of the following:

correctly handle improper Curly numbers, and
when given a Curly number, ignore any extra characters that aren't {};
then subtract 10% from your score. (Integer input will never have extraneous characters, even for the bonus.)

Test cases
Input       Output
{;;}        8
{{;};};     21
{};;;       3
{{{{;}}};}  260
{}          0
4           {;}
17          {{;}};
1           {};
0           {}
96          {{{;};;}}
For the bonus:

{};;;;;     5
{{;;;;};;}  72
c{u;r;l}y;! 9
42{;} ;;;;  8

Note: Curly is not yet implemented. But if this question does well, I may develop it further.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
curly(int n, char *b)
{
	int i;
	char *p;

	p = b;
	*p++ = '{';
	*p++ = '}';
	for (i = 0; i < n; i++)
		*p++ = ';';
	*p = '\0';
	return b;
}

int
uncurly(const char *s)
{
	size_t i, n;
	int *p, r;

	p = calloc(strlen(s) + 1, sizeof(*p));
	if (!p)
		goto error;

	for (i = n = 0; s[i]; i++) {
		switch (s[i]) {
		case '{':
			p[++n] = 0;
			break;

		case '}':
			if (n == 0)
				goto error;

			p[n - 1] += p[n] * 4;
			n--;
			break;

		case ';':
			p[n]++;
			break;
		}
	}
	r = p[0];

	if (0) {
	error:
		r = -1;
	}
	free(p);

	return r;
}

int
main(void)
{
	char b[4096];
	int i, n;

	assert(uncurly("{;;}") == 8);
	assert(uncurly("{{;};};") == 21);
	assert(uncurly("{};;;") == 3);
	assert(uncurly("{{{{;}}};}") == 260);
	assert(uncurly("{}") == 0);
	assert(uncurly("{;}") == 4);
	assert(uncurly("{{;}};") == 17);
	assert(uncurly("{};") == 1);
	assert(uncurly("{{{;};;}}") == 96);

	assert(uncurly("{};;;;;") == 5);
	assert(uncurly("{{;;;;};;}") == 72);
	assert(uncurly("c{u;r;l}y;!") == 9);
	assert(uncurly("42{;} ;;;;") == 8);

	n = sizeof(b) / 2;
	for (i = 0; i < n; i++) {
		curly(i, b);
		assert(uncurly(b) == i);
	}

	return 0;
}
