/*

Task
Your task is to produce string that contains average characters of string. First character of result would be average character of first character (which is first character) and second character average of two first characters and so on.

What is average character?
Strings are arrays of bytes. Average character of string can be found by calculating the average of the ASCII values of characters in string and taking corresponding ASCII character.

For example string "Hello!" can be written as byte sequence 72 101 108 108 111 33. Average of ascii values is 533/6 = 88.833... and when it's rounded to nearest integer we get 89 which is ascii code for captial letter Y.

Rules
You can assume that input contains only printable ASCII characters
Input can be read from stdin or as command line arguments or as function arguments
Output must be stdout. If your program is function, you can also return the string you would otherwise print.
It must be whole program or function, not snippet
Standard loopholes apply
Integers are rounded by function floor(x+0.5) or similar function.
How do I win?
This is code-golf, so shortest answer (in bytes) in wins.

Examples
Hello! → HW^adY
test → tmop
42 → 43
StackExchange → Sdccd_ccccddd

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
avc(const char *s, char *b)
{
	double v;
	size_t i;

	v = 0;
	for (i = 0; s[i]; i++) {
		v += s[i];
		b[i] = round(v / (i + 1));
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	avc(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello!", "HW^adY");
	test("test", "tmop");
	test("42", "43");
	test("StackExchange", "Sdccd_ccccddd");

	return 0;
}
