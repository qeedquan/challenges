/*

It's well known that Brainf*ck is very bad at Kolmogorov-complexity problems, for example, it requires around 100 characters just to print "Hello world".

However, there might be texts where Brainf*ck is just very good at.

Your task is now to write a program that takes no input, and it displays the following:

☺
That is, a smiley face (ASCII 1, if you browser does not render it).

Brainf*ck can do it in 2 characters.

+.
Try to find a language that beats it!

We assume your console can actually display that character (or your font has it, etc.).

Shortest code wins. If there are more of the same length, the first wins, but I'll upvote the others as well.

EDIT: I'm very sorry, I did not think the first post arrives this soon. A quick edit: the language has to be Turing-complete!

*/

#include <stdio.h>

int
main()
{
	printf("%s\n", u8"☺");
	return 0;
}
