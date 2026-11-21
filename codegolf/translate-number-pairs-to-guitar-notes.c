/*

A guitar fretboard diagram looks like this:

  0  1  2  3  4  5  6  7  8  9 10 11 12   <- Fret number (0 means it's open)
|-E--F--F#-G--G#-A--A#-B--C--C#-D--D#-E
|-B--C--C#-D--D#-E--F--F#-G--G#-A--A#-B
|-G--G#-A--A#-B--C--C#-D--D#-E--F--F#-G
|-D--D#-E--F--F#-G--G#-A--A#-B--C--C#-D
|-A--A#-B--C--C#-D--D#-E--F--F#-G--G#-A
|-E--F--F#-G--G#-A--A#-B--C--C#-D--D#-E
As you can see, the first string (from the top) open is an E. The first fret on the first string is an F. The fourth fret on the third string is a B. Note that the first note is the zeroth fret, not the first.

This can be written with numbers on the format string, fret. The strings are numbered from 1 to 6 from top to bottom. The frets are numbered from 0 to 12 from left to right. The first E is therefore 1, 0. Some other examples:

1, 0 --> E
1, 1 --> F
3, 5 --> C
5, 1 --> A#
6, 6 --> A#

Challenge:

Take N pairs of numbers (s and f), and output a delimited note succession.

The input may be on any suitable format. tuples, 2D-matrix, two separate lists, an interweaved list (string,fret,string,fret...) etc.
The output tone should be separated, but the delimiter is optional (comma, space, dash...). The output can be in either upper or lower case.
s (for string) will be in the range [1, 6] (you may choose to have i 0-indexed)
f (for fret) will be in the range [0, 12]
Test cases and examples:

1 4 5 2 1 3   <- String
4 2 6 3 5 1   <- Fret
G# E D# D A G#

6 2 3 1 4 2 3 2 2 2 6 5 2
0 1 2 3 4 5 6 7 8 9 10 11 12
E C A G F# E C# F# G G# D G# B

3 3 3 3 3 3 3 3 3 3 3 3 3   <- String
0 3 5 0 3 6 5 0 3 5 3 0 0   <- Fret
G A# C G A# C# C G A# C A# G G

// The same test case, but different input and output format:
(3,0)(3,3)(3,5)(3,3)(3,6)(3,5)(3,0)(3,3)(3,5)(3,3)(3,0)(3,0)
G,A#,C,G,A#,C#,C,G,A#,C,A#,G,G
Good luck, and happy golfing!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
guitarnote(unsigned s, unsigned f)
{
	static const char notes[6][13][3] = {
	    {"E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E"},
	    {"B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"},
	    {"G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G"},
	    {"D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D"},
	    {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A"},
	    {"E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E"},
	};

	if (s == 0 || s > nelem(notes) || f >= nelem(notes[s - 1]))
		return NULL;
	return notes[s - 1][f];
}

void
test(int s, int f, const char *r)
{
	const char *p;

	p = guitarnote(s, f);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(1, 0, "E");
	test(1, 1, "F");
	test(5, 1, "A#");
	test(6, 6, "A#");

	test(1, 4, "G#");
	test(4, 2, "E");
	test(5, 6, "D#");
	test(2, 3, "D");
	test(1, 5, "A");
	test(3, 1, "G#");

	test(6, 0, "E");
	test(2, 1, "C");
	test(3, 2, "A");
	test(1, 3, "G");
	test(4, 4, "F#");
	test(2, 5, "E");
	test(3, 6, "C#");
	test(2, 7, "F#");
	test(2, 8, "G");
	test(2, 9, "G#");
	test(6, 10, "D");
	test(5, 11, "G#");
	test(2, 12, "B");

	test(3, 0, "G");
	test(3, 3, "A#");
	test(3, 5, "C");
	test(3, 0, "G");
	test(3, 6, "C#");
	test(3, 0, "G");
	test(3, 3, "A#");

	return 0;
}
