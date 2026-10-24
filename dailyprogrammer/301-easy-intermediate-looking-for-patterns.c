/*

Description
You will be given a sequence that of letters and you must match with a dictionary. The sequence is a pattern of equal letters that you must find.

E.G.

Pattern:
XXYY means that you have a word that contains a sequence of 2 of the same letters followed by again 2 of the same letts

succeed <- matches
succes <- no match

XYYX means we have a word with at least for letters where you have a sequence of a letter, followed by 2 letters that are the same and then again the first letter

narrate <- matches
hodor <- no match
Formal Inputs & Outputs
Input description
Input 1
XXYY
Input 2
XXYYZZ
Input 3
XXYYX
Output description
The words that match in de dictionary

Output 1
aarrgh
aarrghh
addressee
addressees
allee
allees
allottee
allottees
appellee
appellees
arrowwood
arrowwoods
balloon
ballooned
ballooning
balloonings
balloonist
balloonists
balloons
barroom
barrooms
bassoon
bassoonist
bassoonists
bassoons
belleek
belleeks
...
Output 2
bookkeeper
bookkeepers
bookkeeping
bookkeepings
Output 3
addressees
betweenness
betweennesses
colessees
fricassees
greenness
greennesses
heelless
keelless
keenness
keennesses
lessees
wheelless
Output can vary if you use a different dictionary

Notes/Hints
As dictionary you can use the famous enable1 or whatever dictionary you want.

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

Credits go to my professor, for giving me the idea.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
	int index;
	char assignments[256];
} State;

bool
match(const char *pattern, const char *string)
{
	State states[256];
	size_t numstate;
	size_t current;
	char *assignment;
	int symbol;

	for (numstate = 0; *string; string++) {
		memset(&states[numstate], 0, sizeof(states[numstate]));
		numstate += 1;

		for (current = 0; current < numstate; current++) {
			symbol = pattern[states[current].index++];
			if (!symbol)
				return true;

			assignment = states[current].assignments + symbol;
			if (*assignment && *assignment != *string)
				states[current--] = states[--numstate];
			else
				*assignment = *string;
		}
	}
	return false;
}

void
usage()
{
	fprintf(stderr, "usage: <pattern> <dictionary>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	const char *pattern;
	FILE *file;
	char line[128];

	if (argc < 3)
		usage();

	pattern = argv[1];
	file = fopen(argv[2], "r");
	if (!file) {
		fprintf(stderr, "Failed to open dictionary: %s", strerror(errno));
		return 1;
	}

	while (fgets(line, sizeof(line), file)) {
		if (match(pattern, line))
			fputs(line, stdout);
	}
	fclose(file);

	return 0;
}
