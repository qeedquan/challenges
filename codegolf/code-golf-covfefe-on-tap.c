/*

As we all know, negative press covfefe has been conspiring to bring down the American president for some months now.

There's also, definitely, an algorithm in play in that word. Covfe is a refreshing caffeinated beverage, and following the president's remarks it's clear the word can now be appended with successive f's and e's, so long as they are not adjacent to their own letters.

So I wrote some code to generate the inevitable covfefe triangle. The output looks like this:

covfefe
covfefef
covfefefe
covfefefef
covfefefefe
covfefefefef
covfefefefefe
covfefefefefef
covfefefefefefe
covfefefefefefef
covfefefefefefefe
covfefefefefefefef
covfefefefefefefefe
covfefefefefefefefef
covfefefefefefefefefe
covfefefefefefefefefef
covfefefefefefefefefefe
covfefefefefefefefefefef
covfefefefefefefefefefefe
covfefefefefefefefefefefef
covfefefefefefefefefefefefe

So here are the rules:

    Output 21 lines, the first of which should be 'covfefe'.
    Each line must be one character longer than the previous line.
    No f can be horizontally adjacent to another f.
    No e can be horizontally adjacent to another e.

Oh, and have fun!

(I'm also interested to see any other nifty covfefe-related snippets)

*/

#include <stdio.h>

void
covfefe(void)
{
	int i, j;

	for (i = 0; i < 21; i++) {
		printf("covefefe");
		for (j = 0; j < i; j++)
			printf("%c", "fe"[j & 1]);
		printf("\n");
	}
}

int
main(void)
{
	covfefe();
	return 0;
}
