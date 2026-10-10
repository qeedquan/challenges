/*

Create a program that, given a name as input, will generate a Valentine’s day greeting card featuring that name, with its source code also having a Valentine’s day theme. The greeting can be either ASCII art or a generated picture.

Additional conditions:

The source code has to look like something Valentine's day themed (like a heart, or a poem or anything. Be creative)
All code and related assets need to fit into your answer.
You can use network connections, but you can only download this page (in case this question acquires multiple pages you can download them as well). You can use the StackApps API if you want to.
The "has to look like something Valentine's day themed" rule also applies to anything you try to use from this page (if using network connections).
No other external files are permitted.
You can use the standard library of your language, but no external packages are allowed.
Other restrictions:

None. This is a popularity contest.
Scoring:

Each visible vote (= upvotes minus downvotes) is worth 10 points
For every two upvote on a comment on your answer you get 1 points
Answer having the most score will be accepted on Valentine's day (14 Feb 2014)
**This contest is now closed, thanks for participating! ** You can still add answers if you'd like though

*/

#include <stdio.h>

void
gen(const char *name)
{
	printf("Dear %s:\n", name);
	puts("Constants are red, variables are blue.");
	puts("If love had a syntax, I'd highlight you.");
}

int
main()
{
	gen("Dayz");
	return 0;
}
