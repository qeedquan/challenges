/*

Given a string of printable ASCII, count the dots.

The following characters have one dot each: i j . ; ! ?. This character has two dots: :. No other characters have dots.

Rules
Default I/O rules and standard rules apply. Standard loopholes are forbidden.

This is code-golf; shortest solution in bytes wins.

Test cases
Input                                   Output
Sphinx of black quartz, judge my vow!      3
Lorem ipsum: dolor sit amet?               5
Programming Puzzles & Code Golf            1
ij.;!?:                                    8
pericardiomediastinitis                    6
formaldehydesulphoxylate                   0
<empty string>                             0

This question has 58 dots.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
count(const char *s)
{
	size_t c, i;

	for (c = i = 0; s[i]; i++) {
		if (strchr("ij.;!?", s[i]))
			c += 1;
		else if (s[i] == ':')
			c += 2;
	}
	return c;
}

int
main()
{
	assert(count("Sphinx of black quartz, judge my vow!") == 3);
	assert(count("Lorem ipsum: dolor sit amet?") == 5);
	assert(count("Programming Puzzles & Code Golf") == 1);
	assert(count("ij.;!?:") == 8);
	assert(count("pericardiomediastinitis") == 6);
	assert(count("formaldehydesulphoxylate") == 0);
	assert(count("") == 0);

	return 0;
}
