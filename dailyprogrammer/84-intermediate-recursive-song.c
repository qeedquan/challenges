/*

Like many people who program, I got started doing this because I wanted to learn how to make video games.

As a result, my first ever 'project' was also my first video game. It involved a simple text adventure I called "The adventure of the barren moor"

Now that I'm an adult, I've decided to put some money into actually producing it as a real game (not really). I've hired a team of singers to sing the theme song.

The theme song is very simple: Its a rhyming ditty called "The barren moor" with a repeating recursive verses similar to the twelve days of christmas.
We shamelessly ripped off the lyrics of The rattlin bog except instead of "Hi Ho the rattlin bog" we say "Hi Ho the barren moor", etc,
and replace "moor" for "bog" everywhere else it's appropriate.
Also, instead of "A rare X, a rattlin' X" we have "A bare X, a barren X" in each verse.

Write a program that can print the full text the song "The barren moor".

*/

#include <stdio.h>

void
song()
{
	static const char *chorus =
	    "Hi ho, the barren moor,\n"
	    "The moor down in the valley-o,\n"
	    "Hi ho, the barren moor,\n"
	    "The moor down in the valley-o.\n";

	static const char *grammar[] = {
		"in", "on", "on", "on", "on", "in", "in", "on", "on", "on", "on"
	};

	static const char *words[] = {
		"moor", "tree", "branch", "twig", "leaf", "nest", "egg", "bird", "wing", "feather", "flea", "rash"
	};

	const char *opening;
	int verse, line;

	opening = "Now";
	for (verse = 1; verse < 12; verse++) {
		puts(chorus);
		printf("%s %s that %s there was a %s,\n", opening, grammar[verse - 1], words[verse - 1], words[verse]);
		printf("A rare %s, a barren %s,\n", words[verse], words[verse]);
		for (line = verse; line > 0; line--)
			printf("The %s %s the %s,\n", words[line], grammar[line - 1], words[line - 1]);
		printf("And the moor down in the valley-o.\n\n");

		opening = "And";
	}
	puts(chorus);
}

int
main()
{
	song();
	return 0;
}
