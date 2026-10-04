/*

Sometimes when you're lying in bed and reading a message, your phone screen will pop into landscape mode right in the middle of a sentence.
Only being able to read left to right, you find yourself incapacitated, unable to process the text in front of you.

To ensure that this won't happen again, you decide to make every message readable from any angle, whether your phone screen is rotated or mirrored.
To make this happen, each message is printed as a square, with each side of the square containing the message, either in the original order or in reverse.

For backwards compatibility, the top side of the square should be the original message.

To make each message square as compact as possible, the first and last character of the message should be a part of two sides of the square.
This means that the top side reads normally, the bottom side is in reverse, the left side reads top-bottom, and the right side reads bottom-top.

Input
A single string, with 2 or more characters. You should not assume that the string only contains alphanumerical characters or similar.

Output
The Squarification™ of the string. It is permissible to leave some whitespace at the end of each line, and a single newline at the end of the output.

Examples
Input: 'ab'
ab
ba

Input: 'abc'

abc
b b
cba

Input: 'Hello, world!'
Hello, world!
e           d
l           l
l           r
o           o
,           w

w           ,
o           o
r           l
l           l
d           e
!dlrow ,olleH

This challenge looks like A cube of text, but I'm hoping that it's different enough that there will be some clever answers.

As this is code-golf, get ready to trim some bytes!

*/

#include <stdio.h>

void
squarification(const char *s)
{
	int n, m;

	printf("\"%s\"\n", s);
	m = printf("%s\n", s) - 2;
	for (n = 1; m - n > 0; n++)
		printf("%c%*c\n", s[n], m, s[m - n]);
	for (n = m; n >= 0; n--)
		putchar(s[n]);
	printf("\n\n");
}

int
main()
{
	squarification("");
	squarification("ab");
	squarification("abc");
	squarification("Hello, world!");
	squarification("abcdefghijklmnopqrstuvwxyz");
	squarification("golf");
	squarification("a");
	squarification("123");

	return 0;
}
