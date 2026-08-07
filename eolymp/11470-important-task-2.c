/*

Write a program that outputs a set of characters according to the example output.

Input
No input data.

Output
Output the specified set of characters to the standard output stream.

Examples
Input #0
Answer #0
  *
  *
  *
  *
*****
 ***
  *

*/

#include <stdio.h>

void
solve()
{
	static const char *art =
	    "  *  \n"
	    "  *  \n"
	    "  *  \n"
	    "  *  \n"
	    "*****\n"
	    " *** \n"
	    "  *  \n";

	printf("%s", art);
}

int
main()
{
	solve();
	return 0;
}
