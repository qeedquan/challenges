/*

COBOL is a very old language, at the time of writing it is 58 years old. It is so old, in fact, that it has a very interesting quirk: the first six characters of each line are comments.

Why is this, you ask? Well, those 6 characters were intended to be used as line numbers, back in the day where programs weren't completely digital and typed out on a computer.

In addition, the seventh character could only be part of a very small set (it is usually * to comment out the line or a space to separate the line number from the code)

But what if you're on a more digital system, and you just want the raw program?

The comment system
There are two types of comments in COBOL: line comments and the aforementioned "line number" comments.

Uncommenting line numbers is simple: just take the first seven (six plus a single space) characters off each line.

000000 apple
000001 banana
celery donuts
would become:

apple
banana
donuts
Line comments make it a bit more difficult. A line comment is started with an asterisk * placed in the seventh character position on the line, like so:

000323* this is a comment
This is not a line comment:

*00000 this isn't a comment
To uncomment a line comment, just remove the whole line.

An example commented "program":

000000 blah blah
000001* apples
000002 oranges?
000003* yeah, oranges.
000*04 love me some oranges
The uncommented version:

blah blah
oranges?
love me some oranges
In other words, to uncomment a string, remove the first six characters of each line, then return all but the first character of every line that does not begin with a star.

The challenge
Create a program or function that takes a commented program and returns its uncommented variant.

Clarifications
Asterisks (*) will never be found anywhere outside the first seven characters on a line (we're not asking you to verify syntax)
Each line will always have at least 7 characters.
You may assume the seventh character is always an asterisk or a space.
Input or output may be a matrix or list.
Only printable ASCII characters (plus newline) must be handled.
You may output with a trailing newline. You may also assume that the input will have a trailing newline, if you so choose.
Scoring
Since this is code-golf, the answer with the least bytes wins!

DISCLAIMER: I do not actually know COBOL and do not claim to. If any of the claims about COBOL I have made in this question are incorrect, I take no responsibility.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
uncomment(const char **lines, size_t nlines)
{
	const char *line;
	size_t lineno;
	size_t index;

	for (lineno = 0; lineno < nlines; lineno++) {
		line = lines[lineno];

		index = 0;
		while (index < 6 && line[index])
			index++;
		if (index != 6 || line[index] == '*')
			continue;

		printf("%s\n", line + index + 1);
	}
}

int
main()
{
	static const char *lines1[] = {
	    "000000 apple",
	    "000001 banana",
	    "celery donuts",
	};
	static const char *lines2[] = {
	    "000000 blah blah",
	    "000001* apples",
	    "000002 oranges?",
	    "000003* yeah, oranges.",
	    "000*04 love me some oranges",
	};

	uncomment(lines1, nelem(lines1));
	uncomment(lines2, nelem(lines2));

	return 0;
}
