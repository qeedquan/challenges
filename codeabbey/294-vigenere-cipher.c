/*

We've already seen that Caesar's Cipher could be easily broken with the analysis of letter frequencies.

Vigenere's algorithm brings improvement. We choose not just a single shift value, but small array of such values (let us call it key), and then each next letter of the original text is shifted by the next value from the key.

Of course if the key is very long (especially, as long as the original text itself) the system becomes unbrekable. However in practice the key is usually short enough (represented by some word) and we wrap to its beginning after reaching the end - thus the algorithm is imperfect.

So let's assume that:

the key is given by some word, which is converted to array of shift values using letter numbers in alphabet, e.g. cab becomes [2, 0, 1];
for every letter of the original text shift value is chosen as key[i % k] where i is the index in the original text and k is the length of the key.
Before we try to break it, let's write the implementation of this algorithm, to make sure we understand it properly.

Input data the first line contains the text to be encoded, only small latin letters with no spaces.
The second line contains the key.

Answer should give the encrypted text.

Example:

input data:
attackatdusk
cab

answer:
ctucclctewsl

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
encrypt(char *buf, const char *key)
{
	const char *keyp;

	if (!*key)
		return;

	for (keyp = key; *buf; buf++) {
		if (!('a' <= *buf && *buf <= 'z'))
			continue;

		if (!*keyp)
			keyp = key;

		*buf = (*buf - 'a') + (*keyp - 'a');
		*buf = 'a' + (*buf % 26);
		keyp += 1;
	}
}

void
test(const char *txt, const char *key, const char *res)
{
	char buf[32];

	strcpy(buf, txt);
	encrypt(buf, key);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test("attackatdusk", "cab", "ctucclctewsl");
	return 0;
}
