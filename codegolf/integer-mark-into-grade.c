/*

Given a positive integer (0 and above, no maximum), convert it into a grade following these rules:

A = 100+
B = 90 - 99
C = 80 - 89
D = 70 - 79
E = 60 - 69
F = 59 and less.
This felt a little boring, so make the grade a + if it's 7,8 or 9 and a - if it's 0,1 or 2. Ignore this for the F and A cases.

An example:

Input:

65
Output:

E
Test cases:

0  -> F
20 -> F
65 -> E
72 -> D-
75 -> D
80 -> C-
99 -> B+
102 -> A
864 -> A
No trailing spaces. One newline after output is fine, but keep it consistent. Functions and full programs are both fine.

This is code golf, so shortest code wins. This was inspired by an Ask Ubuntu question, How to write a shell script to assign letter grades to numeric ranges?. The answers are in bash and python, so slightly spoilers.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
grade(int n)
{
	static const struct Rank {
		int score;
		const char *mark;
	} tab[] = {
	    {100, "A"},
	    {97, "B+"},
	    {93, "B"},
	    {90, "B-"},
	    {87, "C+"},
	    {83, "C"},
	    {80, "C-"},
	    {77, "D+"},
	    {73, "D"},
	    {70, "D-"},
	    {67, "E+"},
	    {63, "E"},
	    {60, "E-"},
	    {59, "F"},
	};

	const struct Rank *r;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		r = tab + i;
		if (n >= r->score)
			break;
	}
	return r->mark;
}

void
test(int n, const char *r)
{
	const char *b;

	b = grade(n);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0, "F");
	test(20, "F");
	test(65, "E");
	test(72, "D-");
	test(75, "D");
	test(80, "C-");
	test(99, "B+");
	test(102, "A");
	test(864, "A");

	return 0;
}
