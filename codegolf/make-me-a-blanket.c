/*

I want a blanket that looks like this. Each strip goes over, under, over, under. Can you print it?

\\\\////\\\\////\\\\////\\\\////\\\\////\\\\////
 \\////  \\////  \\////  \\////  \\////  \\////
  ////    ////    ////    ////    ////    ////
 ////\\  ////\\  ////\\  ////\\  ////\\  ////\\
////\\\\////\\\\////\\\\////\\\\////\\\\////\\\\
\//  \\\\//  \\\\//  \\\\//  \\\\//  \\\\//  \\\
\\    \\\\    \\\\    \\\\    \\\\    \\\\    \\
\\\  //\\\\  //\\\\  //\\\\  //\\\\  //\\\\  //\
\\\\////\\\\////\\\\////\\\\////\\\\////\\\\////
 \\////  \\////  \\////  \\////  \\////  \\////
  ////    ////    ////    ////    ////    ////
 ////\\  ////\\  ////\\  ////\\  ////\\  ////\\
////\\\\////\\\\////\\\\////\\\\////\\\\////\\\\
\//  \\\\//  \\\\//  \\\\//  \\\\//  \\\\//  \\\
\\    \\\\    \\\\    \\\\    \\\\    \\\\    \\
\\\  //\\\\  //\\\\  //\\\\  //\\\\  //\\\\  //\
\\\\////\\\\////\\\\////\\\\////\\\\////\\\\////
 \\////  \\////  \\////  \\////  \\////  \\////
  ////    ////    ////    ////    ////    ////
 ////\\  ////\\  ////\\  ////\\  ////\\  ////\\
////\\\\////\\\\////\\\\////\\\\////\\\\////\\\\
\//  \\\\//  \\\\//  \\\\//  \\\\//  \\\\//  \\\
\\    \\\\    \\\\    \\\\    \\\\    \\\\    \\
\\\  //\\\\  //\\\\  //\\\\  //\\\\  //\\\\  //\
Trailing spaces at the end of each line and trailing newlines are acceptable.

Remember, this is code-golf, so the code with the fewest bytes wins.

*/

#include <stdio.h>

// Ported from @xnor solution
void
blanket(int n)
{
	static const char sym[] = " \\// \\/\\\\";

	int i, x, y;

	for (y = 0; y < n; y++) {
		for (x = 0; x < 2 * n; x++) {
			i = ((y - x - 1) >> 2) & 1;
			i ^= ((y + x) >> 1) & 2;
			i ^= (y & 4);
			printf("%c", sym[i]);
		}
		printf("\n");
	}
}

int
main(void)
{
	blanket(24);
	return 0;
}