/*

This one is inspired by an actual problem my friend had to deal with recently. Unfortunately, its a little bit keyboard-locale specific, so if you don't happen to use a us-EN layout keyboard you might want to get a picture of one.

The en-us keyboard layout pictured here is one common layout for keys. There are character-generating keys such as '1' and 'q', as well as modifier keys like 'ctrl' and 'shift', and 'caps-lock'

If one were to press every one of the character-generating keys in order from top to bottom left-to-right, you would get the following string:

`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./
plus the whitespace characters TAB,RETURN,SPACE.

Your job is to write a function that takes in a character representing a keypress, as well as a boolean for each 'modifier' key like ctrl,alt,shift,and caps lock, and converts it properly into the ascii character for which the key gets output.

For example, my python implementation keytochar(key='a',caps=True) returns 'A'. However, keytochar(key='a',caps=True,shift=True) returns 'a'.

BONUS: Read in a string containing a record of keypresses and output them to the correct string. A status key change is indicated by a ^ character..if a ^ character is detected, then the next character is either an 's' or 'S' for shift pressed or shift released, respectively, a 'c' or 'C' for caps on or caps off respectively, and a 't' 'T' for control down or up, and 'a' 'A' for alt down or up.

For example on the bonus, given the input

^sm^Sy e-mail address ^s9^Sto send the ^s444^S to^s0^S is ^cfake^s2^Sgmail.com^C
you should output

My e-mail address (to send the $$$ to) is FAKE@GMAIL.COM

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
translate(const char *input, char *output)
{
	static const char symbols[] = ")!@#$%^&*(";

	int shift, caps;
	int ch, mod;
	size_t index;
	char *buf;

	buf = output;
	shift = 0;
	caps = 0;
	for (index = 0; input[index]; index++) {
		ch = input[index];
		if (ch == '^') {
			mod = tolower(input[++index]);
			if (mod == 's')
				shift = !shift;
			else if (mod == 'c')
				caps = !caps;
			else if (mod == '\0')
				break;

			continue;
		}

		if (isdigit(ch) && shift)
			ch = symbols[ch - '0'];
		else if (shift ^ caps)
			ch = toupper(ch);

		*buf++ = ch;
	}
	*buf = '\0';

	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	translate(input, output);
	printf("%s\n", output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("^sm^Sy e-mail address ^s9^Sto send the ^s444^S to^s0^S is ^cfake^s2^Sgmail.com^C", "My e-mail address (to send the $$$ to) is FAKE@GMAIL.COM");
	test("hello, world", "hello, world");

	return 0;
}
