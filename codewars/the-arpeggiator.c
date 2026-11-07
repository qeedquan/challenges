/*

In music, a scale is made up of seven different values (A through G inclusive) with the ROOT value occuring twice forming the scale's first and eighth (last) note.

So if the root = B, the scale looks like this:

  B C D E F G A B

and if the root = F, the scale looks like this:

  F G A B C D E F

Each scale has an arpeggio made up of it's first, third, fifth and eighth notes.

So the arpeggio for scale root B looks like this:

 B D F B

and the arpeggio for scale root F looks like this:

 F A C F

Write a programme that takes any possible root note and returns it's arpeggio in an array. If the object input isn't a root note, return 'undefined/Nothing'. Watch for capitalization!

Example:

arpeggio("A") == ["A", "C", "E", "A"]
arpeggio("E") == ["E", "G", "B", "E"]
arpeggio("Z") == undefined
arpeggio("a") == undefined

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
arpeggio(int note, char *output)
{
	static const char notes[] = "ABCDEFGABCDEFG";
	static const size_t indices[] = { 0, 2, 4, 7 };

	char *buffer;
	size_t index;
	size_t offset;

	buffer = strchr(notes, note);
	if (!buffer)
		return strcpy(output, "undefined");

	offset = buffer - notes;

	buffer = output;
	for (index = 0; index < nelem(indices); index++)
		*buffer++ = notes[(indices[index] + offset) % (sizeof(notes) - 1)];
	*buffer = '\0';

	return output;
}

void
test(int note, const char *expected)
{
	char output[16];

	arpeggio(note, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test('A', "ACEA");
	test('E', "EGBE");
	test('Z', "undefined");
	test('a', "undefined");

	return 0;
}
