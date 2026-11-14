/*

Inspired by this X post.
https://x.com/climagic/status/1838590601576542715

Write a program or function that takes a string as input and prints or otherwise renders the text with each word in a random color, e.g.:
https://i.sstatic.net/XSS85Ecg.png

The input will be a string of printable ASCII characters.

For our purposes a word is a contiguous sequence of non-whitespace characters. Whitespace characters are, at a minimum: Space, tab, and newline. (You may optionally count characters such as vertical tab, form feed, and carriage return—i.e. those in many regular expression engines' [[:space]] classes—as whitespace.) All whitespace characters must be preserved in the output.

Output may be colored text in any environment (such as a terminal or HTML page) or an image (see Rules).

At least 16 distinct colors must be possible. It is not a requirement that the possible colors be evenly distributed but it should be likely that various hues and shades are represented in the result.

The output must have a chance of being different each time the program or function is run with the same input.

Any background color is allowed.

Solutions must include a working demo or a screenshot of sample output.

Rules
Default I/O rules and standard rules apply. Standard loopholes are forbidden.

For image output default image I/O rules apply.

This is code-golf; shortest solution in bytes wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void
colorize(const char *str)
{
	static const char fmt[] = "\x1b[38;5;%dm";

	size_t i;

	printf(fmt, rand() & 0xff);
	for (i = 0; str[i]; i++) {
		printf("%c", str[i]);
		if (isspace(str[i]))
			printf(fmt, rand() & 0xff);
	}
}

int
main()
{
	static const char lines[] =
	    "Welcome to\n"
	    "\n"
	    "Code Golf\n"
	    "and\n"
	    "Coding Challenges\n"
	    "Stack Exchange!\n"
	    "\n"
	    "This is a site for recreational programming\n"
	    "competitions, not general programming\n"
	    "questions. Challenges must have an objective\n"
	    "scoring criterion, and it is highly\n"
	    "recommended to first post proposed\n"
	    "challenges in the Sandbox.\n";

	srand(time(NULL));
	colorize(lines);

	return 0;
}
