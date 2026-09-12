/*

Befunge is a 2-dimensional programming language, with an instruction pointer (IP). In Befunge-98, the ; character tells the IP to skip characters up until the next ; (Let us call it skipping mode when the IP is skipping characters). Here is an example:

"This part is read into the stack" ; this part is not ; @
I would like to generate a w wide, h high comment outline for a Befunge-98 program. This means that an IP in normal mode (not in string mode nor in skipping mode) should enter the comment, skip over the comment and then exit in normal mode, no matter which row or column it arrives from. Additionally, the outline must be at most one character thick. That is, the bounding box of the entire comment (including outline) must be no more than w+2 wide and no more than h+2 high.

Example
If w = 5, h = 3 then a valid comment outline would be:

;;;;;;
;     ;
;     ;
;     ;
 ;;;;;;
Note that this would not be a valid comment outline:

;;;;;;;
;     ;
;     ;
;     ;
;;;;;;;
This is because in the first column, the IP would enter in normal mode, but exit in skipping mode, potentially skipping crucial code. (The same thing would happen in the 7th column, 1st row and 5th row)

This is not valid either:






This would result in the comment being interpreted as code.

Challenge
Write a program or function that, given a width and height as input, outputs any valid Befunge-98 comment outline for that size. The width and height are guaranteed to be at least 1.

You must output in spaces, semicolons and line breaks, unless your chosen programming language is unable to
You may have trailing whitespace, however they can only be spaces and line breaks
Each line may have trailing spaces
You may alternatively take input as w+2 and h+2 instead of w and h
You may also mix between the two e.g. you can input w+2 and h
As stated above, the width of the outline must be at most 1
There must be a w by h area inside the outline made of only spaces
More examples
w = 2, h = 2

;;;;
;  ;
;  ;
;;;;
w = 3, h = 2

 ;;;;
;   ;
;   ;
 ;;;;
w = 2, h = 3

 ;;
;  ;
;  ;
;  ;
;;;;
w = 5, h = 1

;;;;;;
;     ;
 ;;;;;;

*/

#include <stdio.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
outline(int w, int h)
{
	int y;

	printf("%dx%d\n", w, h);
	repeat(";", w | 1);
	for (y = 0; y < h; y++) {
		printf(";\n;");
		repeat(" ", w);
	}
	printf(";\n");
	repeat(" ", h % 2);
	repeat(";", w + mod(~h, 2) + mod(~(w ^ h), 2));
	printf("\n\n");
}

int
main()
{
	outline(5, 3);
	outline(2, 2);
	outline(3, 2);
	outline(2, 3);
	outline(5, 1);
	return 0;
}
