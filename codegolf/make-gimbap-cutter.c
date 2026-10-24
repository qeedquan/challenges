/*

Gimbap(김밥) is Korean food, somewhat looks like sushi roll.

Here is Korean emoticon represent Gimbap : @))))))))))

Your quest is make ASCII Gimbap cutter.

Rule
Input is string made with only @ and ).

Output cuts every valid Gimbap with ), and then add   @ between them. So for example @)) to @) @).

Valid Gimbap starts with @ and followed by any amount of ).

If there is no valid Gimbap, output is blank.

Input and output
Input | Output
@))))) | @) @) @) @) @)
@))))))) | @) @) @) @) @) @) @)
@))@))) | @) @) @) @) @)
@) | @)
)) |
@ |
@@)@@@))) | @) @) @) @)
@)@)@)) | @) @) @) @)
@@@)) | @) @)
))@) | @)
Winning condition
This is code-golf, so shortest code wins.

from sandbox
https://codegolf.meta.stackexchange.com/questions/2140/sandbox-for-proposed-challenges/17750#17750

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
cutter(const char *s, char *b)
{
	size_t i, n;
	char *p;

	for (i = 0; s[i]; i++) {
		if (s[i] != ')')
			break;
	}

	for (n = 0; s[i]; i++)
		n += (s[i] == ')');

	p = b;
	for (i = 0; i < n; i++)
		p += sprintf(p, "@) ");
	if (p != b)
		p--;
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	cutter(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("@)))))", "@) @) @) @) @)");
	test("@)))))))", "@) @) @) @) @) @) @)");
	test("@))@)))", "@) @) @) @) @)");
	test("@)", "@)");
	test("))", "");
	test("@", "");
	test("@@)@@@)))", "@) @) @) @)");
	test("@)@)@))", "@) @) @) @)");
	test("@@@))", "@) @)");
	test("))@)", "@)");

	return 0;
}
