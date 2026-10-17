/*

Task
Given a string as input, generate a "blurred" version of that string.

Input
Your input will be a single-line string of ASCII characters, containing a minimum of 2 alphanumeric characters

Output
A string that is the "blurred" version of the input string.

A blurred string is one where every alphanumeric character from the original string has been paired with the ones adjacent to it, and each pair is separated by a space.

Any non-alphanumeric characters (whitespace, puncuation) in the input string must be ignored when determining adjacency of alphanumeric characters, and they must not included in the blurred string.

There must be no leading or trailing whitespace in the output string.

Examples
Ab -> Ab
Abc -> Ab bc
Abcd -> Ab bc cd
E?h? -> Eh
Blurry vision -> Bl lu ur rr ry yv vi is si io on
We're #1! -> We er re e1
I'm an example! -> Im ma an ne ex xa am mp pl le
This is _not_ legible -> Th hi is si is sn no ot tl le eg gi ib bl le
(a*b*c)+5^-x -> ab bc c5 5x
??a_%,1!=z#@ -> a1 1z

This is code-golf, so fewest bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
blur(const char *s, char *b)
{
	int f, p;

	for (f = p = 0; *s; s++) {
		if (!isalnum(*s))
			continue;

		if (p) {
			if (f)
				*b++ = ' ';
			*b++ = p;
			*b++ = *s;
			f = 1;
		}
		p = *s;
	}
	*b = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	blur(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Ab", "Ab");
	test("Abc", "Ab bc");
	test("Abcd", "Ab bc cd");
	test("E?h?", "Eh");
	test("Blurry vision", "Bl lu ur rr ry yv vi is si io on");
	test("We're #1!", "We er re e1");
	test("I'm an example!", "Im ma an ne ex xa am mp pl le");
	test("This is _not_ legible", "Th hi is si is sn no ot tl le eg gi ib bl le");
	test("(a*b*c)+5^-x", "ab bc c5 5x");
	test("??a_%,1!=z#@", "a1 1z");

	return 0;
}
