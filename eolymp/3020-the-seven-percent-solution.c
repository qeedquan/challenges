/*

Uniform Resource Identifiers (or URIs) are strings like http://icpc.baylor.edu/icpc/, mailto:foo@bar.org, ftp://127.0.0.1/pub/linux, or even just readme.txt that are used to identify a resource, usually on the Internet or a local computer. Certain characters are reserved within URIs, and if a reserved character is part of an identifier, it must be percent-encoded by replacing it with a percent sign followed by two hexadecimal digits representing the ASCII code of the character. A table of seven reserved characters and their encodings is shown below. Your job is to write a program that can percent-encode a string of characters.

Input
The input consists of one or more strings, each from 1 to 79 characters long and on a line by itself, followed by a line containing only # that signals the end of the input. The character # is used only as an end-of-input marker and will not appear anywhere else in the input. A string may contain spaces, but not at the beginning or end of the string, and there will never be two or more consecutive spaces.

Output
For each input string, replace every occurrence of a reserved character in the table above by its percent-encoding, exactly as shown, and output the resulting string on a line by itself. Note that the percent-encoding for an asterisk is

Examples

Input #1
Happy Joy Joy!
http://icpc.baylor.edu/icpc/
plain_vanilla
(**)
?
the 7% solution
#

Answer #1
Happy%20Joy%20Joy%21
http://icpc.baylor.edu/icpc/
plain_vanilla
%28%2a%2a%29
?
the%207%25%20solution

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
solve(const char *src, char *dst)
{
	for (; *src; src++) {
		switch (*src) {
		case ' ':
			dst += sprintf(dst, "%%20");
			break;
		case '!':
			dst += sprintf(dst, "%%21");
			break;
		case '$':
			dst += sprintf(dst, "%%24");
			break;
		case '%':
			dst += sprintf(dst, "%%25");
			break;
		case '(':
			dst += sprintf(dst, "%%28");
			break;
		case ')':
			dst += sprintf(dst, "%%29");
			break;
		case '*':
			dst += sprintf(dst, "%%2a");
			break;
		default:
			*dst++ = *src;
			break;
		}
	}
	*dst = '\0';
}

void
test(const char *src, const char *res)
{
	char dst[128];

	solve(src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test("Happy Joy Joy!", "Happy%20Joy%20Joy%21");
	test("http://icpc.baylor.edu/icpc/", "http://icpc.baylor.edu/icpc/");
	test("plain_vanilla", "plain_vanilla");
	test("(**)", "%28%2a%2a%29");
	test("?", "?");
	test("the 7% solution", "the%207%25%20solution");

	return 0;
}
