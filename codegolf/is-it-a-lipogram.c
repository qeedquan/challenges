/*

A lipogram is a block of words that omits a particular symbol. Right now, I am avoiding our fifth symbol of 26 that commonly show up. You should know by now what I am omitting. If not, look up "lipogram" and you will know.

Your Task
With a char, a blank, and a following string (blanks may show up in this; with only ASCII 32-126 chars) in input, output falsy if this char is in input string, truthy if not. This char that you must look for will always fit in two spans: "A" to "Z" or "a" to "z" (ASCII 65-90, 97-122). Do not distinguish capitals and non-capitals. Also, don't worry about blanks or punctuation symbols. Both programs and functions satisfy. Also, you may split input char and string into two args for programs or functions, and string as first arg is okay.

Illustrations
Truthy
e This is a lipogram.
a You need to consider other letters too.
E Capitals also count.

Falsy
e This sentence is not a lipogram (for e).
t This particular letter is surprisingly hard.
A You don't need to care about any non-alphabetic symbols.
Non-lipogrammed version
A lipogram is a series of words that leaves out a letter. I left out the letter "e" above.

Your task is to take a character and a string (which may include spaces) as input, separated by a space or newline, and output falsy if the character is in the string, and truthy otherwise. You may assume the string is composed solely of printable ASCII characters (char codes 32-126). The character will always be in the English alphabet, and there is no difference between lowercase and uppercase. The character will not be a space or symbol. You may write a program or a function. For either, you may take the character and string as separate arguments, and the string may come first.

*/

#include <assert.h>
#include <string.h>

bool
lipogram(int c, const char *s)
{
	return !strchr(s, c) && !strchr(s, c ^ ' ');
}

int
main()
{
	assert(lipogram('e', "This is a lipogram.") == true);
	assert(lipogram('a', "You need to consider other letters too.") == true);
	assert(lipogram('E', "Capitals also count.") == true);

	assert(lipogram('e', "This sentence is not a lipogram (for e).") == false);
	assert(lipogram('t', "This particular letter is surprisingly hard.") == false);
	assert(lipogram('A', "You don't need to care about any non-alphabetic symbols.") == false);

	return 0;
}
