/*

Your task is to print the following:

I have a pen
I have an apple
Uh! Apple pen!

I have a pen
I have pineapple
Uh! Pineapple pen!

Apple pen...
Pineapple pen...
Uh! Pen Pineapple Apple Pen!
Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

#include <stdio.h>

void
output()
{
	static const char *poem[] = {
	    "I have a pen",
	    "I have an apple",
	    "Uh! Apple pen!",
	    "",
	    "I have a pen",
	    "I have pineapple",
	    "Uh! Pineapple pen!",
	    "",
	    "Apple pen...",
	    "Pineapple pen...",
	    "Uh! Pen Pineapple Apple Pen!",
	    NULL,
	};

	size_t i;

	for (i = 0; poem[i]; i++)
		puts(poem[i]);
}

int
main()
{
	output();
	return 0;
}
