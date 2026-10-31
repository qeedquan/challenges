/*

Gordon Ramsay shouts. He shouts and swears. There may be something wrong with him.

Anyway, you will be given a string of four words. Your job is to turn them in to Gordon language.

Rules:

Obviously the words should be Caps, Every word should end with '!!!!', Any letter 'a' or 'A' should become '@', Any other vowel should become '*'.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
gordon(const char *s, char *b)
{
	char *p;

	p = b;
	while (*s) {
		while (isspace(*s))
			*p++ = *s++;

		while (*s && !isspace(*s)) {
			*p++ = toupper(*s++);
			if (strchr("EIOU", p[-1]))
				p[-1] = '*';
			else if (p[-1] == 'A')
				p[-1] = '@';
		}
		if (p != b && !isspace(p[-1]))
			p += sprintf(p, "!!!!");
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	gordon(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("What feck damn cake", "WH@T!!!! F*CK!!!! D@MN!!!! C@K*!!!!");
	test("are you stu pid", "@R*!!!! Y**!!!! ST*!!!! P*D!!!!");
	test("i am a chef", "*!!!! @M!!!! @!!!! CH*F!!!!");

	return 0;
}
