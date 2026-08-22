/*

Recently (okay, December 2023, I'm a little late) there's been a meme going around about a program checking if a 32-bit unsigned integer is even or odd using four billion if statements:

if num == 0:
    print("even")
if num == 1:
    print("odd")
if num == 2:
    print("even")
...
if num == 4294967294:
    print("even")
if num == 4294967295:
    print("odd")
Today, you'll be writing a program/function that outputs something similar to this. Your code should take no input and output source code, in the same language, for a function or program that takes an unsigned 32-bit integer (0 ≤ n ≤ 4294967295) and outputs/returns either "even" if the input is even and "odd" otherwise. For clarity, I'll use "program" for the rest of this post, but everything here also applies to function submissions.

Specifically, the resulting program should be divisible into a "header", 4294967296 "segments", and a "footer", such that concatenating the header, the i+1th segment, and the footer results in a program that:

When given i, prints either "even" or "odd" depending on i's parity
When given any unsigned 32-bit integer that's not i, does something else - this can include crashing, printing nothing, or printing anything else, as long as it doesn't print only "odd" or "even".
For example, with the following C code:

#include <stdlib.h>
int main(int argc, char* argv[]) {
    unsigned int number = atoi(argv[1]);
    if (number == 0)
        printf("even\n");
    if (number == 1)
        printf("odd\n");
    if (number == 2)
        printf("even\n");
    // etc etc
    if (number == 4294967294)
        printf("even\n");
    if (number == 4294967295)
        printf("odd\n");
}
Here, the #include <stdlib.h>; int main(int argc, char* argv[]) { unsigned int number = atoi(argv[1]); is the header, the } is the footer, and the if (number == 2) printf("even\n"); are the segments. Concatenating e.g. the 136th segment with the header and footer results in the following:

#include <stdlib.h>
int main(int argc, char* argv[]) {
    unsigned int number = atoi(argv[1]);
    if (number == 135)
        printf("odd\n");
}
which indeed prints "odd" if given 135 and outputs nothing otherwise.

Here's an example of a generating program in Python.

As per standard I/O, "even" / "odd" may be output with any (including none) amount of leading/trailing whitespace. It's fine if, due to program size/memory/language limitations (e.g. Java source files being at most 1GB), the resulting program doesn't compile, as long as it works in theory.

This is code-golf, the shortest generating program wins!

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

void
gen()
{
	uint64_t i;

	puts("void f(uint32_t n) {");
	for (i = 0; i <= UINT32_MAX; i++) {
		printf("\tif (n == %" PRIu64 ")\n", i);
		if (i & 1)
			puts("\t\tputs(\"odd\");");
		else
			puts("\t\tputs(\"even\");");
	}
	puts("}");
}

int
main()
{
	gen();
	return 0;
}
