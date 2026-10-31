/*

Challenge
I think everyone of us heard of URL encoding mechanism - it's basically everywhere.

Given an URLEncoded string on stdin, decode it, and output the decoded form to stdout.

The encoding is very simple, + or %20 is representing space. Every percent followed by two hex digits (uppercase or lowercase) has to be replaced with ASCII character code of this number.

Related, but it's the other way round

Example
100%25+working
=>
100% working

%24+%26+%3C+%3E+%3F+%3B+%23+%3A+%3D+%2C+%22+%27+%7E+%2B+%25
=>
$ & < > ? ; # : = , " ' ~ + %

%414243
=>
A4243
Test case that fails:

%24%XY+%%%
   ^~~~~~~
=>
$
Rules
Loopholes are forbidden.
If your programming language has built-in function to decode the URL, using it (the function) is forbidden.
Assume ASCII character set. No Unicode and all that stuff.
This is a code-golf, so the answer with the fewest bytes used to accomplish the task wins.
Please include a link to an online interpreter for your code.
Your program has to decode until EOF or an error (eg. percent without valid hex digits - %xy) is spotted (you can safetly terminate).
If anything is unclear, please let me know down in the comments.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long
hex(const char *str)
{
	char buf[3];

	buf[0] = str[0];
	buf[1] = str[1];
	buf[2] = '\0';
	return strtol(buf, NULL, 16);
}

char *
decode(const char *src, char *dst)
{
	char *buf;

	for (buf = dst; *src; src++) {
		if (src[0] == '%' && src[1] && src[2]) {
			*buf++ = hex(src + 1);
			src += 2;
		} else if (src[0] == '+')
			*buf++ = ' ';
		else
			*buf++ = *src;
	}
	*buf = '\0';
	return dst;
}

void
test(const char *src, const char *res)
{
	char dst[128];

	decode(src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test("100%25+working", "100% working");
	test("%24+%26+%3C+%3E+%3F+%3B+%23+%3A+%3D+%2C+%22+%27+%7E+%2B+%25", "$ & < > ? ; # : = , \" ' ~ + %");
	test("%414243", "A4243");
	test("%24%XY+%%%", "$");

	return 0;
}
