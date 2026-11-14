#!/usr/bin/env python3

r"""

Your task is to accept as input two "ASCII Art"s, and align each piece of art next to each other horizontally.

For example, say you have two strings, "abc\ndef" and "123\n456". You need to align them horizontally to produce the string "abc123\ndef456". I'm calling this "aligning horizontally" because while the inputs, when printed, look like this:

abc
def
and:

123
456
The output, when printed, will look like this:

abc123
def456
Note how one input is placed next to the other.

Input
Input will be strings, and can be as two separate arguments, or as a sequence of strings.

The characters in the arts will have decimal codes in the range 32-126 (inclusive).

It's fine to support an arbitrary number of arts to align instead of just two (but obviously you must support at least two).

You can assume that each art will have the same dimensions, and that they will contain at least one line.

You must be able to support at least 100x100 character arts.

To align with conventions on the site, the argument order does not matter. It does not matter which art is on the left or right.

Output
Output will be the aligned arts as mentioned above, either returned or output to the stdout.

Any trailing whitespace in optional.

There must be no visual separator between the aligned arts.

Input and output arts must be \n or \r delimited strings. It would be overly trivial to allow 2D-arrays.

Submissions may be functions or full programs.

Test Cases:

"abc\ndef", "123\n456" -> "abc123\ndef456".

"qwertyuiop\n asdfghjkl", "Some other\nTextFiller" -> "qwertyuiopSome other\n asdfghjklTextFiller"

"  *  \n *** \n*****\n *** \n  *  \n", "  +  \n  +  \n+++++\n  +  \n  +  \n" -> "  *    +  \n ***   +  \n*****+++++\n ***   +  \n  *    +  \n"

"""

# Ported from @Riker solution
def align(text):
    return '\n'.join(map(str.__add__, *map(str.splitlines, text)))

def main():
    print(align(["abc\ndef", "123\n456"]))
    print(align(["qwertyuiop\n asdfghjkl", "Some other\nTextFiller"]))
    print(align(["  *  \n *** \n*****\n *** \n  *  \n", "  +  \n  +  \n+++++\n  +  \n  +  \n"]))

main()
