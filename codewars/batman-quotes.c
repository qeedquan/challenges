/*

Batman & Robin have gotten into quite a pickle this time. The Joker has mixed up their iconic quotes and also replaced one of the characters in their names, with a number. They need help getting things back in order.

Implement the getQuote method which takes in an array of quotes, and a string comprised of letters and a single number (e.g. "Rob1n") where the number corresponds to their quote indexed in the passed in array.

Return the quote along with the character who said it:

getQuote(["I am vengeance. I am the night. I am Batman!", "Holy haberdashery, Batman!", "Let's put a smile on that faaaceee!"], "Rob1n")
  // =>  "Robin: Holy haberdashery, Batman!

Hint: You are guaranteed that the number in the passed in string is placed somewhere after the first character of the string. The quotes either belong to "Batman", "Robin", or "Joker".

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
getindex(const char *str)
{
	for (; *str; str++) {
		if (isdigit(*str))
			return atoi(str);
	}
	return 0;
}

char *
getquote(const char **quotes, const char *hero, char *output)
{
	int index;

	index = getindex(hero);
	switch (hero[0]) {
	case 'B':
		sprintf(output, "Batman: %s", quotes[index]);
		break;
	case 'R':
		sprintf(output, "Robin: %s", quotes[index]);
		break;
	case 'J':
		sprintf(output, "Joker: %s", quotes[index]);
		break;
	}
	return output;
}

void
test(const char **quotes, const char *hero, const char *expected)
{
	char output[64];

	getquote(quotes, hero, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	const char *quotes[] = {
		"I am vengeance. I am the night. I am Batman!",
		"Holy haberdashery, Batman!",
		"Let's put a smile on that faaaceee!",
	};

	test(quotes, "Rob1n", "Robin: Holy haberdashery, Batman!");

	return 0;
}
