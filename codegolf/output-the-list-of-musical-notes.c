/*

This task is simple: Write a program or function that outputs the list of all musical notes (using English note names) from A♭ to G♯.

All notes without a name consisting of a single letter (i.e. black notes on a musical keyboard) should have their name printed twice, once as the sharp of a note, once as the flat of one. Sharp or flat notes that can be described with a single letter, like B♯ (C) or F♭ (E) should not be outputted.

Here is an example of the output:

Ab, A, A#, Bb, B, C, C#, Db, D, D#, Eb, E, F, F#, Gb, G, G#

Specifications
The program or function must not take any input.

The notes may be printed in any order, and in any list output permitted by our standard I/O rules

The sharp and flat Unicode symbols (♯/♭) may be substituted with b and #

As always, Standard loopholes are forbidden.

As this is code-golf, the smallest program, in bytes, wins.

*/

#include <stdio.h>

int
main(void)
{
	puts("Ab, A, A#, Bb, B, C, C#, Db, D, D#, Eb, E, F, F#, Gb, G, G#");
	return 0;
}
