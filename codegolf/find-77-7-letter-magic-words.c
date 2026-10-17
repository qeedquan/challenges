/*

A magic word is a word whose Braille spelling contains precisely 26 dots (because the Morse code alphabet can be circularly encoded within). For example:

 ⠎ ⠝ ⠥ ⠛ ⠛ ⠇ ⠽ snuggly
 ⠏ ⠕ ⠇ ⠽ ⠛ ⠕ ⠝ polygon
 ⠝ ⠥ ⠛ ⠛ ⠑ ⠞ ⠽ nuggety
 ⠽ ⠕ ⠛ ⠓ ⠥ ⠗ ⠞ yoghurt
are all magic words.

Objective: Craft a program to identify 77 such magic words and output the word along with its Braille spelling.

*/

#include <stdio.h>
#include <uchar.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
output()
{
	static const char8_t *syms[][2] = {
		{ u8"⠃⠥⠞⠽⠗⠽⠇", u8"BUTYRYL" },
		{ u8"⠉⠗⠽⠏⠞⠕⠝", u8"CRYPTON" },
		{ u8"⠙⠽⠊⠝⠛⠇⠽", u8"DYINGLY" },
		{ u8"⠙⠽⠎⠇⠕⠛⠽", u8"DYSLOGY" },
		{ u8"⠑⠝⠞⠗⠕⠏⠽", u8"ENTROPY" },
		{ u8"⠑⠏⠊⠛⠽⠝⠽", u8"EPIGYNY" },
		{ u8"⠑⠏⠕⠝⠽⠍⠽", u8"EPONYMY" },
		{ u8"⠑⠞⠓⠽⠝⠽⠇", u8"ETHYNYL" },
		{ u8"⠋⠗⠕⠺⠎⠞⠽", u8"FROWSTY" },
		{ u8"⠋⠥⠗⠗⠕⠺⠽", u8"FURROWY" },
		{ u8"⠛⠇⠽⠝⠙⠕⠝", u8"GLYNDON" },
		{ u8"⠛⠕⠇⠙⠺⠽⠝", u8"GOLDWYN" },
		{ u8"⠛⠗⠑⠛⠕⠗⠽", u8"GREGORY" },
		{ u8"⠛⠗⠊⠵⠵⠇⠽", u8"GRIZZLY" },
		{ u8"⠛⠗⠕⠺⠝⠥⠏", u8"GROWNUP" },
		{ u8"⠛⠗⠥⠍⠏⠓⠽", u8"GRUMPHY" },
		{ u8"⠛⠥⠝⠝⠑⠗⠽", u8"GUNNERY" },
		{ u8"⠛⠥⠝⠏⠕⠗⠞", u8"GUNPORT" },
		{ u8"⠛⠥⠝⠞⠕⠺⠝", u8"GUNTOWN" },
		{ u8"⠛⠥⠞⠞⠑⠗⠽", u8"GUTTERY" },
		{ u8"⠛⠽⠍⠏⠊⠝⠛", u8"GYMPING" },
		{ u8"⠛⠽⠏⠎⠞⠑⠗", u8"GYPSTER" },
		{ u8"⠓⠽⠍⠝⠕⠙⠽", u8"HYMNODY" },
		{ u8"⠅⠗⠽⠏⠞⠕⠝", u8"KRYPTON" },
		{ u8"⠅⠗⠽⠞⠗⠕⠝", u8"KRYTRON" },
		{ u8"⠇⠕⠛⠓⠞⠽⠝", u8"LOGHTYN" },
		{ u8"⠇⠽⠊⠝⠛⠇⠽", u8"LYINGLY" },
		{ u8"⠍⠁⠗⠞⠽⠗⠽", u8"MARTYRY" },
		{ u8"⠍⠥⠞⠞⠕⠝⠽", u8"MUTTONY" },
		{ u8"⠍⠽⠕⠇⠕⠛⠽", u8"MYOLOGY" },
		{ u8"⠍⠽⠎⠞⠑⠗⠽", u8"MYSTERY" },
		{ u8"⠝⠕⠝⠚⠥⠗⠽", u8"NONJURY" },
		{ u8"⠝⠥⠛⠛⠑⠞⠽", u8"NUGGETY" },
		{ u8"⠝⠥⠝⠝⠑⠗⠽", u8"NUNNERY" },
		{ u8"⠝⠥⠞⠞⠑⠗⠽", u8"NUTTERY" },
		{ u8"⠏⠓⠽⠞⠕⠝⠎", u8"PHYTONS" },
		{ u8"⠏⠕⠇⠽⠛⠕⠝", u8"POLYGON" },
		{ u8"⠏⠕⠇⠽⠝⠽⠊", u8"POLYNYI" },
		{ u8"⠏⠕⠝⠽⠊⠝⠛", u8"PONYING" },
		{ u8"⠏⠕⠞⠞⠑⠗⠽", u8"POTTERY" },
		{ u8"⠏⠕⠥⠇⠞⠗⠽", u8"POULTRY" },
		{ u8"⠏⠕⠧⠑⠗⠞⠽", u8"POVERTY" },
		{ u8"⠏⠕⠵⠎⠕⠝⠽", u8"POZSONY" },
		{ u8"⠏⠗⠕⠛⠑⠝⠽", u8"PROGENY" },
		{ u8"⠏⠗⠕⠞⠓⠽⠇", u8"PROTHYL" },
		{ u8"⠏⠗⠕⠞⠽⠇⠎", u8"PROTYLS" },
		{ u8"⠏⠗⠽⠎⠊⠝⠛", u8"PRYSING" },
		{ u8"⠏⠥⠛⠛⠑⠗⠽", u8"PUGGERY" },
		{ u8"⠏⠥⠗⠏⠕⠗⠞", u8"PURPORT" },
		{ u8"⠏⠽⠗⠕⠛⠑⠝", u8"PYROGEN" },
		{ u8"⠏⠽⠗⠕⠏⠥⠎", u8"PYROPUS" },
		{ u8"⠏⠽⠗⠗⠓⠥⠎", u8"PYRRHUS" },
		{ u8"⠏⠽⠗⠗⠕⠇⠎", u8"PYRROLS" },
		{ u8"⠟⠥⠁⠗⠞⠵⠽", u8"QUARTZY" },
		{ u8"⠗⠓⠽⠞⠕⠝⠎", u8"RHYTONS" },
		{ u8"⠗⠕⠝⠽⠕⠝⠎", u8"RONYONS" },
		{ u8"⠗⠕⠺⠏⠕⠗⠞", u8"ROWPORT" },
		{ u8"⠗⠕⠽⠎⠞⠕⠝", u8"ROYSTON" },
		{ u8"⠗⠥⠛⠛⠕⠺⠝", u8"RUGGOWN" },
		{ u8"⠎⠏⠇⠥⠗⠛⠽", u8"SPLURGY" },
		{ u8"⠎⠏⠗⠊⠛⠛⠽", u8"SPRIGGY" },
		{ u8"⠎⠏⠗⠊⠝⠛⠽", u8"SPRINGY" },
		{ u8"⠎⠏⠽⠗⠊⠝⠛", u8"SPYRING" },
		{ u8"⠎⠟⠥⠊⠝⠝⠽", u8"SQUINNY" },
		{ u8"⠎⠟⠥⠊⠝⠞⠽", u8"SQUINTY" },
		{ u8"⠎⠞⠗⠊⠝⠛⠽", u8"STRINGY" },
		{ u8"⠎⠞⠗⠊⠏⠏⠽", u8"STRIPPY" },
		{ u8"⠎⠽⠝⠞⠓⠕⠝", u8"SYNTHON" },
		{ u8"⠞⠊⠞⠞⠥⠏⠽", u8"TITTUPY" },
		{ u8"⠞⠕⠛⠛⠑⠗⠽", u8"TOGGERY" },
		{ u8"⠞⠕⠏⠕⠝⠽⠍", u8"TOPONYM" },
		{ u8"⠞⠕⠗⠟⠥⠑⠽", u8"TORQUEY" },
		{ u8"⠞⠕⠞⠞⠑⠗⠽", u8"TOTTERY" },
		{ u8"⠞⠗⠑⠽⠝⠕⠗", u8"TREYNOR" },
		{ u8"⠞⠗⠕⠞⠽⠇⠎", u8"TROTYLS" },
		{ u8"⠞⠗⠥⠭⠞⠕⠝", u8"TRUXTON" },
		{ u8"⠞⠗⠽⠊⠝⠛⠎", u8"TRYINGS" },
	};

	size_t i;

	for (i = 0; i < nelem(syms); i++)
		printf("%s %s\n", syms[i][0], syms[i][1]);
}

int
main()
{
	output();
	return 0;
}
