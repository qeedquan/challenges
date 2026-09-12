/*

Task
Fix the code to pass all the tests. Unfortunately, you can only modify ONE line of code :(

Rules
Usually, the changes you make are limited to one line. Please don't complain that you can't write your own code, because this is a bugfix kata. Also, don't complain that the initial code is too messy. That's why you need to do the task ;-)

You can do the following operations:

1 - Replace the existing characters.
2 - Add the character at the end of the line.

You should not Add a new line or Delete a line.

The overall difference of the modified code is less than 5 characters.

Example
Some exmples of modify operations:

var hello = "word"   <--- initial code
                 xxx  <--- 3 characters modified
var hello = "world"  <--- modified code

var hello = "world"  <--- initial code
             x     x  <--- 2 characters modified
var hello = 'world'  <--- modified code

var hello = "world"  <--- initial code
     xxxxxxxxxxxxxxxx <--- don't try to insert chars at the middle
var  hello = "world" <--- modified code

var hell = "world"   <--- initial code
          xxxxxxxxxx  <--- 10 characters modified
var hello = "world"  <--- bad way
         x            <--- 1 characters modified
var hello= "world"   <--- better way

*/

#include <stdio.h>

int
make(int step)
{
	switch (step) {
	case 5:
		return 'P';
	case 4:
		return 'i';
	case 3:
	case 2:
		return 'z';
	case 1:
		return 'a';
	}
	return 0;
}

void
makepizza(int pieces, char *result)
{
	int step;

	for (; pieces > 0; pieces--) {
		for (step = 5; step >= 1; step--)
			*result++ = make(step);
	}
	*result = '\0';
}

int
main()
{
	char result[128];
	int pieces;

	for (pieces = 1; pieces <= 5; pieces++) {
		makepizza(pieces, result);
		puts(result);
	}
	return 0;
}
