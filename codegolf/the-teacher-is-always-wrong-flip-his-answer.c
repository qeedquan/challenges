/*

Your dumb teacher is always wrong, so flip his answer.

Change these responses
True -> False
Yes -> No
0 -> 1
Yeah -> Nope
and vice versa. Keeping punctuation and the first letter's capitalization counts. Only one condition will be passed to the program.

You only need to accept the following test cases:

True <-> False
True. <-> False.
true <-> false
true. <-> false.
Yes <-> No
Yes. <-> No.
yes <-> no
yes. <-> no.
0 <-> 1
Yeah <-> Nope
yeah <-> nope
Yeah. <-> Nope.
yeah. <-> nope.

This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
flippant(const char *s)
{
	static const char *tab[][2] = {
	    {"True", "False"},
	    {"True.", "False."},
	    {"true", "false"},
	    {"true.", "false."},
	    {"Yes", "No"},
	    {"Yes.", "No."},
	    {"yes", "no"},
	    {"yes.", "no."},
	    {"0", "1"},
	    {"Yeah", "Nope"},
	    {"yeah", "nope"},
	    {"Yeah.", "Nope."},
	    {"yeah.", "nope."},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i][0]))
			return tab[i][1];
		if (!strcmp(s, tab[i][1]))
			return tab[i][0];
	}
	return s;
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = flippant(s);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("0", "1");
	test("yeah.", "nope.");

	return 0;
}
