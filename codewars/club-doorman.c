/*

INTRODUCTION
The Club Doorman will give you a word. To enter the Club you need to provide the right number according to provided the word.

Every given word has a doubled letter, like 'tt' in lettuce.

To answer the right number you need to find the doubled letter's position of the given word in the alphabet and multiply this number per 3.

It will be given only words with one doubled letter.


EXAMPLE

Lettuce is the given word. 't' is the doubled letter and it's position is 20 in the alphabet.


The answer to the Club Doorman is 20 * 3 = 60


TASK
The function passTheDoorMan with a given string word shall return the right number.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
doorman(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] == s[i + 1])
			return (tolower(s[i]) - 'a' + 1) * 3;
	}
	return -1;
}

int
main()
{
	assert(doorman("Lettuce") == 60);
	return 0;
}
