/*

Write a function or program that takes two words as input and outputs variants of the popular English tongue-twister "How much wood would a woodchuck chuck if a woodchuck could chuck wood?".

The output will use the first word four times

How much wood would a woodchuck chuck if a woodchuck could chuck wood?
and the second word four times

How much wood would a woodchuck chuck if a woodchuck could chuck wood?
with the rest of the output being the same for any inputs.

How muchwoodwould awoodchuckchuckif awoodchuckcouldchuckwood?
The input and output can be in any format that your language reasonably recognizes as dealing with strings of text. The output must be exactly in the indicated format, including capitalization, spaces and lack thereof, and the ending question mark. An optional trailing newline is acceptable.

Ideally your code will handle input containing any printable ASCII characters. However, it is permitted to restrict the input to reasonable subsets of printable ASCII; just indicate this in your answer. Handling larger character sets is of course fine.

Example input-output pairs:

"wood", "chuck"
"How much wood would a woodchuck chuck if a woodchuck could chuck wood?"

"ground", "hog"
"How much ground would a groundhog hog if a groundhog could hog ground?"

"bar", "keep"
"How much bar would a barkeep keep if a barkeep could keep bar?"

"money", "belt"
"How much money would a moneybelt belt if a moneybelt could belt money?"

"rain", "fall"
"How much rain would a rainfall fall if a rainfall could fall rain?"

"hair", "cut"
"How much hair would a haircut cut if a haircut could cut hair?"

"green", "house"
"How much green would a greenhouse house if a greenhouse could house green?"

"jabber", "wock"
"How much jabber would a jabberwock wock if a jabberwock could wock jabber?"

"pine", "apple"
"How much pine would a pineapple apple if a pineapple could apple pine?"

"Rob", "Lowe"
"How much Rob would a RobLowe Lowe if a RobLowe could Lowe Rob?"

"code", "golf"
"How much code would a codegolf golf if a codegolf could golf code?"

"fish", ""
"How much fish would a fish  if a fish could  fish?"

"", "fish"
"How much  would a fish fish if a fish could fish ?"

"", ""
"How much  would a   if a  could  ?"

"  ", "     "
"How much    would a               if a         could         ?"

"would a", "how much"
"How much would a would a would ahow much how much if a would ahow much could how much would a?"
This is code-golf, so fewest bytes wins. Answers are welcome in all languages, even if some other language can do it in fewer bytes.

(Inspired by this meme, which uses one input pair better than this rigid pattern does....)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
twist(const char *w1, const char *w2, char *b)
{
	sprintf(b, "How much %s would a %s%s %s if a %s%s could %s %s?", w1, w1, w2, w2, w1, w2, w2, w1);
	return b;
}

void
test(const char *w1, const char *w2, const char *r)
{
	char b[128];

	twist(w1, w2, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("wood", "chuck", "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
	test("ground", "hog", "How much ground would a groundhog hog if a groundhog could hog ground?");
	test("bar", "keep", "How much bar would a barkeep keep if a barkeep could keep bar?");
	test("money", "belt", "How much money would a moneybelt belt if a moneybelt could belt money?");
	test("rain", "fall", "How much rain would a rainfall fall if a rainfall could fall rain?");
	test("hair", "cut", "How much hair would a haircut cut if a haircut could cut hair?");
	test("green", "house", "How much green would a greenhouse house if a greenhouse could house green?");
	test("jabber", "wock", "How much jabber would a jabberwock wock if a jabberwock could wock jabber?");
	test("pine", "apple", "How much pine would a pineapple apple if a pineapple could apple pine?");
	test("Rob", "Lowe", "How much Rob would a RobLowe Lowe if a RobLowe could Lowe Rob?");
	test("code", "golf", "How much code would a codegolf golf if a codegolf could golf code?");
	test("fish", "", "How much fish would a fish  if a fish could  fish?");
	test("", "fish", "How much  would a fish fish if a fish could fish ?");
	test("", "", "How much  would a   if a  could  ?");
	test("  ", "     ", "How much    would a               if a         could         ?");
	test("would a", "how much", "How much would a would a would ahow much how much if a would ahow much could how much would a?");

	return 0;
}
