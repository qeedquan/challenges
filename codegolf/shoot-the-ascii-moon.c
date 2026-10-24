/*

(Previously on "Print the __ without using __" ... this one and this one)

The game of Hearts has a popular scoring variant called "Shooting the Moon," whereby instead of trying to not acquire penalty cards (and thus penalty points), as is the usual gameplay strategy, if you acquire all of the penalty cards you actually score the best that round. We're going to apply that same logic to some code golf.

The ASCII printable characters (plus space) are, in order

!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
Let's divide these into three groups:

Alphanumeric:

0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Symbolic (or non-alphanumeric)

!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
and the space character.

Your task is to use the alphanumeric characters to print the symbolic characters (in any order), with the following restrictions:

The program/function should take no input and output to STDOUT (or equivalent).
You can use a symbolic character in your source code for a penalty of +5 per unique character.
Using the same character more than once does not increase your penalty (e.g., you can use [ 25 times and only get one +5 penalty)
Whitespace (including tabs and newlines) in the output or the source code is completely optional. Leading, trailing, inline - no penalties or bonuses. They still count for bytes in source code as usual.
If you manage to use all 32 symbolic characters in your code, you get a bonus of -100 points for Shooting the Moon instead of any penalties.
If you manage to use all 32 symbolic and all 62 alphanumeric characters in your code, you instead get a bonus of -250 points for Shooting the Sun instead of any penalties.
Characters inside literal strings, literal characters, or comments do not count for the bonus or the penalty. (E.g., a Foo program of something like "!#$%..." would be allowed, but would not get the bonus or penalty points for the characters inside the literal).
Literal string or comment delimiters do count, however, so something like // !#$*... would count the initial / for penalty/bonus calculations.
Yes, this rules out languages like Whitespace or the like, where everything not whitespace is treated as a comment. Bummer.
Scoring is bytes of code + penalty(ies) + bonus(es), lowest score wins. Negative scores are possible.
Example scores:
50 bytes code + (5 unique symbolic characters)*5 penalty each = 75 points

200 bytes code + (32 unique symbolic characters)*0 penalty each + (-250 bonus for shooting the sun) = -50 points

*/

#include <stdio.h>

int
main()
{
	puts("{\"''!$%&()*+,-./:;<=>?@[\\]^_`|~#}");
	return 0;
}
