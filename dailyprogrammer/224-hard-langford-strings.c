/*

Description
A "Langford string of order N" is defined as follows:

The length of the string is equal to 2*N

The string contains the the first N letters of the uppercase English alphabet, with each letter appearing twice

Each pair of letters contain X letters between them, with X being that letter's position in the alphabet (that is, there is one letter between the two A's, two letters between the two B's, three letters between the two C's, etc)

An example will make this clearer. These are the only two possible Langford strings of order 3:

BCABAC
CABACB
Notice that for both strings, the A's have 1 letter between them, the B's have two letters between them, and the C's have three letters between them. As another example, this is a Langford string of order 7:

DFAGADCEFBCGBE
It can be shown that Langford strings only exist when the order is a multiple of 4, or one less than a multiple of 4.

Your challenge today is to calculate all Langford strings of a given order.

Formal inputs & outputs
Inputs
You will be given a single number, which is the order of the Langford strings you're going to calculate.

Outputs
The output will be all the Langford strings of the given order, one per line. The ordering of the strings does not matter.

Note that for the second challenge input, the output will be somewhat lengthy. If you wish to show your output off, I suggest using a service like gist.github.com or hastebin and provide a link instead of pasting them directly in your comments.

Sample input & output
Input
3
Output
BCABAC
CABACB
Challenge inputs
Input 1
4
Input 2
8
Bonus
For a bit of a stiffer challenge, consider this: there are more than 5 trillion different Langford strings of order 20. If you put all those strings into a big list and sorted it, what would the first 10 strings be?

Notes
If you have a suggestion for a challenge, head on over to r/dailyprogrammer_ideas and we might use it in the future!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void
langford(char *s, char *u, int n, int i)
{
	int j;

	if (i >= 2 * n) {
		puts(s);
		return;
	}
	if (s[i]) {
		langford(s, u, n, i + 1);
		return;
	}

	for (j = 1; j <= n && i + j + 1 < 2 * n; j++) {
		if (u[j - 1] || s[i + j + 1])
			continue;

		u[j - 1] = s[i] = s[i + j + 1] = 'A' + j - 1;
		langford(s, u, n, i + 1);
		u[j - 1] = s[i] = s[i + j + 1] = 0;
	}
}

int
solve(int n)
{
	char *u, *s;
	int r;

	if (n < 1)
		return 0;

	r = 0;
	u = calloc(n, sizeof(*u));
	s = calloc((2 * n) + 1, sizeof(*s));
	if (!u || !s)
		goto error;

	langford(s, u, n, 0);

	if (0) {
	error:
		r = -errno;
	}

	free(u);
	free(s);
	return r;
}

void
usage()
{
	fprintf(stderr, "usage: <n>\n");
	exit(2);
}

int
main(int argc, char **argv)
{
	int n;

	if (argc != 2)
		usage();

	n = atoi(argv[1]);
	solve(n);
	return 0;
}
