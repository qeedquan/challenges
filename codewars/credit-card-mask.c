/*

Usually when you buy something, you're asked whether your credit card number, phone number or answer to your most secret question is still correct. However, since someone could look over your shoulder, you don't want that shown on your screen. Instead, we mask it.

Your task is to write a function maskify, which changes all but the last four characters into '#'.

Examples (input --> output):
"4556364607935616" --> "############5616"
     "64607935616" -->      "#######5616"
               "1" -->                "1"
                "" -->                 ""

// "What was the name of your first pet?"
"Skippy" --> "##ippy"
"Nananananananananananananananana Batman!" --> "####################################man!"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
maskify(const char *s, char *b)
{
	int n;
	char *p;

	n = sprintf(b, "%s", s);
	for (p = b; n > 4; n--)
		*p++ = '#';
}

void
test(const char *s, const char *r)
{
	char b[128];

	maskify(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("4556364607935616", "############5616");
	test("64607935616", "#######5616");
	test("1", "1");
	test("", "");
	test("Skippy", "##ippy");
	test("Nananananananananananananananana Batman!", "####################################man!");

	return 0;
}
