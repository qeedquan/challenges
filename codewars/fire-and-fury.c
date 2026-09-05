/*

The President's phone is broken
He is not very happy.

The only letters still working are uppercase E, F, I, R, U, Y.

An angry tweet is sent to the department responsible for presidential phone maintenance.

Kata Task
Decipher the tweet by looking for words with known meanings.

FIRE = "You are fired!"
FURY = "I am furious."
If no known words are found, or unexpected letters are encountered, then it must be a "Fake tweet."

Notes
The tweet reads left-to-right.
Any letters not spelling words FIRE or FURY are just ignored
If multiple of the same words are found in a row then plural rules apply -
FIRE x 1 = "You are fired!"
FIRE x 2 = "You and you are fired!"
FIRE x 3 = "You and you and you are fired!"
etc...
FURY x 1 = "I am furious."
FURY x 2 = "I am really furious."
FURY x 3 = "I am really really furious."
etc...
Examples
ex1. FURYYYFIREYYFIRE = "I am furious. You and you are fired!"
ex2. FIREYYFURYYFURYYFURRYFIRE = "You are fired! I am really furious. You are fired!"
ex3. FYRYFIRUFIRUFURE = "Fake tweet."

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
next(const char *input, size_t *fire, size_t *fury)
{
	*fire = *fury = 0;
	while (input) {
		input = strchr(input, 'F');
		if (!input)
			break;

		if (!strncmp(input, "FIRE", 4)) {
			if (*fury)
				break;
			*fire += 1;
			input += 4;
		} else if (!strncmp(input, "FURY", 4)) {
			if (*fire)
				break;
			*fury += 1;
			input += 4;
		} else
			input += 1;
	}
	return input;
}

char *
yell(char *output, const char *prefix, const char *body, const char *suffix, size_t count)
{
	size_t index;

	if (count == 0)
		return output;

	output += sprintf(output, "%s ", prefix);
	for (index = 1; index < count; index++)
		output += sprintf(output, "%s ", body);
	output += sprintf(output, "%s ", suffix);

	return output;
}

void
firefury(const char *input, char *output)
{
	size_t fire, fury;
	char *buffer;

	buffer = output;
	for (;;) {
		input = next(input, &fire, &fury);
		if (!fire && !fury)
			break;
		else if (fire)
			buffer = yell(buffer, "You", "and you", "are fired!", fire);
		else
			buffer = yell(buffer, "I am", "really", "furious.", fury);
	}

	if (buffer != output)
		buffer[-1] = '\0';
	else
		strcpy(buffer, "Fake tweet.");
}

void
test(const char *input, const char *expected)
{
	char output[128];

	firefury(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("FURYYYFIREYYFIRE", "I am furious. You and you are fired!");
	test("FIREYYFURYYFURYYFURRYFIRE", "You are fired! I am really furious. You are fired!");
	test("FYRYFIRUFIRUFURE", "Fake tweet.");

	return 0;
}
