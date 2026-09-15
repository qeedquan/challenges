/*

Welcome to BBC Casting. We need a program that we can use to select a new actor to play The Doctor on Doctor Who. In the spirit of the show, your program will perform a regeneration from one actor's name to the next.

We will test your program by running through the 13 names of actors who have already played The Doctor and then run it another 13 times. We will pass the output from one call as the input to the next in a loop.

Detailed Requirements

Your program will take a string as its only input and output a single string. It must not store any state between calls or use any additional resources outside of the program.
If the input is your starting string, your program must return "William Hartnell", the first name on the list.
You should select and document any string you wish to use as the starting string, as long as it isn't the name of a listed actor. My example below uses an empty string.
If the input string is an actor's name (other than the last), your program must return the next name on the list following the name inputted.
For any other inputs, behavior of your program is undefined.
The list of actors below is incomplete. You must complete the list by selecting 13 more names of actors you feel would be good at playing The Doctor.
Each extra name must be of a professional actor with an IMDB page.
The extra names returned by your program must be the actors' names exactly as listed on IMDB, including case, accents and diacritics.
The completed list of 26 actors must be 26 distinct individuals with distinct names.
You may interpret input and output according to the constraints of your language's execution environment. (Parameters, quotes, end-of-lines, stdin/out, encoding etc.)
Shortest conforming program wins. Normal code-golf rules apply.
You may use someone else's list of actors. If you do, give appropriate credit and share the glory. (Finding a list of actors that would compress well might be part of the challenge.)
The first half of the list of names is as follows. These strings must be output exactly as shown, preserving case including the extra capital letter in "McCoy" and "McGann".

William Hartnell
Patrick Troughton
Jon Pertwee
Tom Baker
Peter Davison
Colin Baker
Sylvester McCoy
Paul McGann
John Hurt
Christopher Eccleston
David Tennant
Matt Smith
Peter Capaldi
For example:

YourProgram("") returns "William Hartnell".
YourProgram("William Hartnell") returns "Patrick Troughton".
YourProgram("Patrick Troughton") returns "Jon Pertwee".
// 10 more.
YourProgram("Peter Capaldi") returns "Pauley Perrette".
YourProgram("Pauley Perrette") returns "Nathan Fillion".
// 12 more.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
who(const char *s)
{
	static const char *actors[] = {
	    "",
	    "William Hartnell",
	    "Patrick Troughton",
	    "Jon Pertwee",
	    "Tom Baker",
	    "Peter Davison",
	    "Colin Baker",
	    "Sylvester McCoy",
	    "Paul McGann",
	    "John Hurt",
	    "Christopher Eccleston",
	    "David Tennant",
	    "Matt Smith",
	    "Peter Capaldi",

	    "Pauley Perrette",
	    "Nathan Fillion",
	    "Emma Watson",
	    "Patrick Stewart",
	    "Ian McKellen",
	    "Benedict Cumberbatch",
	    "Tom Hiddleston",
	    "Sean Connery",
	    "Hugh Laurie",
	    "Daniel Radcliffe",
	    "Rupert Grint",
	    "Gary Oldman",
	    "Simon Pegg",
	    "Keira Knightley",
	    "Liam Neeson",
	};

	size_t i;

	for (i = 0; i < nelem(actors); i++) {
		if (!strcmp(s, actors[i]))
			break;
	}
	return actors[(i + 1) % nelem(actors)];
}

int
main()
{
	assert(!strcmp(who(""), "William Hartnell"));
	assert(!strcmp(who("William Hartnell"), "Patrick Troughton"));
	assert(!strcmp(who("Patrick Troughton"), "Jon Pertwee"));
	assert(!strcmp(who("Peter Capaldi"), "Pauley Perrette"));
	assert(!strcmp(who("Pauley Perrette"), "Nathan Fillion"));
	assert(!strcmp(who("Liam Neeson"), ""));

	return 0;
}
