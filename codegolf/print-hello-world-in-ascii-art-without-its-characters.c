/*

Your mission is to write a program that prints "Hello World!". Simple?

The text must be human readable and should not be "|-| € |_ |_ 0 // 0 |? |_ |) \./" or something like that.

The program should not contain:

Newline character
Any characters in the string "Hello World!" including whitespace (whitespace outside strings is allowed)
Graphics (it must be run on text console (or master boot record in text mode)
Number constants that represent chars (Ascii-values, Hex chars)
Any simple tricks that create above numbers (ex. 36*2 or 176/2-1 (72, ASCII code of "H") )
Non-ASCII chars
Web request
User input
Over 1000 chars
Random numbers
It can contain:

Ascii-art
system calls that do not return letters (a-z and A-Z)
h, e, l, o, w, r, d and ! chars outside strings or equal datatypes
It is possible and allowed to change line by going over line max width (program must detect that itself). Linux command

stty size
may help.

Fewer chars are better.

Basically, write 'Hello World' in Ascii Art.

*/

#include <stdio.h>

int
main(void)
{
	puts("|-| € |_ |_ 0 // 0 |? |_ |) \\./");
	return 0;
}
