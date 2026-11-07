/*

Write two functions/programs which take an ASCII code of character (8-bit unsigned integer) and one of them converts char to uppercase and other to lowercase.

That is, they must be equivalent to following functions:

unsigned char toUpper(unsigned char c){
    if (c >= 97 && c <= 122) return c - 32;
    return c;
}
unsigned char toLower(unsigned char c){
    if (c >= 65 && c <= 90) return c + 32;
    return c;
}
However you are not allowed to use branching (ifs, gotos), loops and comparison and logical operators. Recursion, language built-in functions, regular expressions, arrays and objects also not allowed. You may use only arithmetic and bitwise operations on 8-bit unsigned integers.

Score:

1 - for | & ^ ~ >> << operators
1.11 - for + - operators
1.28 - for * operator
1.411 - for / % operators

Answer with lowest total score (for two functions added) wins. If answers with equal score than first (oldest) answer wins.

*/

#include <assert.h>
#include <ctype.h>

/*

ported from @Martin Ender solution

*/

int
xtoupper(int c)
{
	return c - (((c / 97) ^ (c / 123)) << 5);
}

int
xtolower(int c)
{
	return c + (((c / 65) ^ (c / 91)) << 5);
}

int
main(void)
{
	int i;

	for (i = 0; i < 128; i++) {
		assert(toupper(i) == xtoupper(i));
		assert(tolower(i) == xtolower(i));
	}

	return 0;
}
