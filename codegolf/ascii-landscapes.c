/*

Objective: Write a program that generates beautiful (?) ASCII-art landscapes and skylines!

Your program has just one input: a string composed of any combination/repetition of the chars 0123456789abc.

For each input character, output a vertical line composed as follows:

         .
        ..
       ...
      oooo
     ooooo
    OOOOOO
   OOOOOOO
  XXXXXXXX
 XXXXXXXXX
XXXXXXXXXX

0123456789
Letters abc instead are followed by one number n, and draw the vertical line n with respectively 1,2 or 3 holes (spaces) at the bottom.

Examples

The Chrysler Building

Input: 2479742

   .
   .
  ...
  ooo
  ooo
 OOOOO
 OOOOO
XXXXXXX
XXXXXXX
XXXXXXX
The Taj Mahal

Input: 0804023324554233204080

 .                  .
 .                  .
 o                  o
 o        oo        o
 O O     OOOO     O O
 O O  OO OOOO OO  O O
 X X XXXXXXXXXXXX X X
 X X XXXXXXXXXXXX X X
XXXXXXXXXXXXXXXXXXXXXX
The Eiffel Tower

Input: 011a2b3b5c9c9b5b3a2110

      ..
      ..
      ..
      oo
     oooo
     OOOO
    OOOOOO
   XXX  XXX
 XXX      XXX
XXX        XXX
You can assume input is not empty and that it's well-formed.
Any language is accepted, from A+ to Z++.

This is code-golf: the shortest source code wins.
If anything in the rules is not clear, feel free to ask below in the comments.

Have fun, and capture hundred meters high structures in a few bytes!

(and don't forget to include your favourite building in your solution)

P.S.: no, you can't download/access data from the Internet, use your file name as data and all that stuff. Be fair, and use only your code-golf skills.

*/

#include <stdio.h>
#include <ctype.h>

int
iscode(int c)
{
	c = tolower(c);
	return 'a' <= c && c <= 'c';
}

int
at(int c0, int c1, int y)
{
	int xb, xt;

	if (iscode(c0) && isdigit(c1)) {
		xb = c0 - 'a' + 1;
		xt = c1 - '0';
	} else if (isdigit(c0)) {
		xb = 0;
		xt = c0 - '0';
	} else
		return ' ';

	if ((9 - y > xt) || (xb && (9 - y < xb)))
		return ' ';

	if (y < 3)
		return '.';
	if (y < 5)
		return 'o';
	if (y < 7)
		return 'O';
	return 'X';
}

void
landscape(const char *s)
{
	size_t x;
	int y;

	for (y = 0; y < 10; y++) {
		for (x = 0; s[x]; x++) {
			putchar(at(s[x], s[x + 1], y));
			if (iscode(s[x]) && s[x + 1])
				x++;
		}
		putchar('\n');
	}
	printf("\n%s\n", s);
}

int
main(void)
{
	landscape("0123456789");
	landscape("2479742");
	landscape("0804023324554233204080");
	landscape("011a2b3b5c9c9b5b3a2110");
	landscape("08040233245542332040800000247974200000011a2b3b5c9c9b5b3a2110");
	landscape("a1a13443a1a2a3a4a5a6a6a7a7a8a8a8a8a9a9a9a9a9a9a8a8a8a8a7a7a6a6a5a4a4a3a2a13443a1a1");
	landscape("a2a0a0a4a0a06a0a0a4a0a0a2a0a0a4a0a06a0a0a4a0a0a2");

	return 0;
}
