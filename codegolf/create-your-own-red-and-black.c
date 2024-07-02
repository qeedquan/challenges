/*

In the musical rendition of Les Miserables, a song appears called "Red and Black." Here is part of that song:

Red - the blood of angry men!

Black - the dark of ages past!

Red - a world about to dawn!

Black - the night that ends at last!

Source.

Your task is to turn input into a resounding "Red and Black" anthem.

Input
Text delimited by newlines, or a similar suitable text input. For example,

The blood of angry men!
The dark of ages past!
A world about to dawn!
The night that ends at last!
Empty input is undefined (out of scope).

Output
If the length (number of lines, or length of input array, or similar) of the input is odd, either output nothing or output falsey. Your submission may not output errors or attempt to output the correct output.

Otherwise, turn the input into a Red/Black lyric. Turn any uppercase letters at the start of a line to lowercase. Add Red plus a delimiter to the front of odd lines, and Black plus a (visible) delimiter to the front of even lines. The delimiter must also be surrounded in spaces, so the output looks uncrowded (and ungolfed ;) ).

You now have your output.

Test Cases
Output delimiter is -.

In:
The blood of angry men!
The dark of ages past!
A world about to dawn!
The night that ends at last!

Out:
Red - the blood of angry men!
Black - the dark of ages past!
Red - a world about to dawn!
Black - the night that ends at last!

In:
test test
1
[][][]
BBB

Out:
Red - test test
Black - 1
Red - [][][]
Black - bBB

In:
I feel my soul on fire!
The color of desire!
The color of despair!
Out:
falsey OR nothing

In:
Red - I feel my soul on fire!
Black - My world if she's not there!

Out:
Red - red - I feel my soul on fire!
Black - black - My world if she's not there!

*/

#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
redblack(const char **s, size_t n)
{
	static const char *header[] = {"Red", "Black"};

	size_t i;
	const char *p;

	if (n & 1)
		return;

	for (i = 0; i < n; i++) {
		p = s[i];
		printf("%s - ", header[i & 1]);
		if (p[0])
			printf("%c%s\n", tolower(p[0]), p + 1);
	}
	printf("\n");
}

int
main()
{
	const char *s1[] = {
	    "The blood of angry men!",
	    "The dark of ages past!",
	    "A world about to dawn!",
	    "The night that ends at last!",
	};

	const char *s2[] = {
	    "test test",
	    "1",
	    "[][][]",
	    "BBB",
	};

	const char *s3[] = {
	    "I feel my soul on fire!",
	    "The color of desire!",
	    "The color of despair!",
	};

	const char *s4[] = {
	    "Red - I feel my soul on fire!",
	    "Black - My world if she's not there!",
	};

	redblack(s1, nelem(s1));
	redblack(s2, nelem(s2));
	redblack(s3, nelem(s3));
	redblack(s4, nelem(s4));

	return 0;
}
