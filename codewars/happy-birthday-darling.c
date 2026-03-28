/*

As you may know, once some people pass their teens, they jokingly only celebrate their 20th or 21st birthday, forever. With some maths skills, that's totally possible - you only need to select the correct number base!

For example, if they turn 32, that's exactly 20 - in base 16... Already 39? That's just 21, in base 19!

Your task is to translate the given age to the much desired 20 (or 21) years, and indicate the number base, in the format specified below.

Note: input will be always > 21

Examples:
32  -->  "32? That's just 20, in base 16!"
39  -->  "39? That's just 21, in base 19!"

Hint: if you don't know (enough) about numeral systems and radix, just observe the pattern!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
womensage(int age, char *output)
{
	sprintf(output, "%d? That's just %d, in base %d!", age, 20 + (age & 1), age / 2);
	return output;
}

void
test(int age, const char *expected)
{
	char output[128];

	womensage(age, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(32, "32? That's just 20, in base 16!");
	test(39, "39? That's just 21, in base 19!");

	return 0;
}
