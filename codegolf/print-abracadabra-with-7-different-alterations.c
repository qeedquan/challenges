/*

Abracadabra is a magic word. To make it even more magical, let's make several alterations to how it may be written:

Change the casing for any subset of characters; for example: aBrAcAdAbRa
Append an exclamation mark to it: abracadabra!
Change each occurrence of a into a different vowel: ybrycydybry
Change any single consonant letter into a different consonant which doesn't appear in the original word: abracadakra (don't change all occurrences of b into k, only one!)
Change the foreground colour, but not background colour
Change the background colour, but not foreground colour
Use fullwidth characters: ａｂｒａｃａｄａｂｒａ (don't cheat by inserting spaces!)
Output the variants to the screen (or printer) in 8 different lines of text. One variant (not necessarily the first one) should be "base", while all others should differ from it in a single aspect, as described above.

The output may be the same each time your code is run; alternatively, it may be different each time (depending on random numbers or unpredictable values in memory).

If your system can't support some of these alterations (for example, no support for colours on a black-and-white screen; no full-width characters on ASCII-only terminals), use the following replacement alterations:

Text in inverted colours
Blinking text
Different font
Different font size
But please use these only if your system really doesn't support the original alterations!

*/

#include <stdio.h>

void
output()
{
	puts("aBrAcAdAbRa");
	puts("abracadabra!");
	puts("ybrycydybry");
	puts("abracadakra");
	puts("\x1b[36mababracadabra\x1b[0m");
	puts("\x1b[44mababracadabra\x1b[0m");
	puts("ａｂｒａｃａｄａｂｒａ");
}

int
main()
{
	output();
	return 0;
}
