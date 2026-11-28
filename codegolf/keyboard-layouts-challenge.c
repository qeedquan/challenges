/*

The keyboard layout people commonly use is the QWERTY layout as shown below.

QWERTY
https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/KB_United_States.svg/1000px-KB_United_States.svg.png

But there are also other keyboard layouts:

DVORAK
https://upload.wikimedia.org/wikipedia/commons/thumb/2/25/KB_United_States_Dvorak.svg/1280px-KB_United_States_Dvorak.svg.png

COLEMAK
https://i.stack.imgur.com/cupPt.png

WORKMAN
https://i.stack.imgur.com/b1KV8.png

Your task
Your code will take two inputs: the name of the keyboard layout and a string to transcribe. Your goal is to convert your QWERTY input as if you were typing with the keyboard layout given as first parameter.

Rules
The input format is free, you can use strings, arrays, etc. Moreover, you can use any three distinct values to represent the layouts to reduce your byte count, but they each have to be representable in 10 bytes or less.

You need only to handle the keys with a white background. Specifically, you must transpose the printable ASCII characters from the QWERTY alphabet to one of the other alphabets:

 QWERTY: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
 DVORAK: !_#$%&-()*}w[vz0123456789SsW]VZ@AXJE>UIDCHTNMBRL"POYGK<QF:/\=^{`axje.uidchtnmbrl'poygk,qf;?|+~
COLEMAK: !"#$%&'()*+,-./0123456789Oo<=>?@ABCSFTDHUNEIMKY:QPRGLVWXJZ[\]^_`abcsftdhuneimky;qprglvwxjz{|}~
WORKMAN: !"#$%&'()*+,-./0123456789Ii<=>?@AVMHRTGYUNEOLKP:QWSBFCDXJZ[\]^_`avmhrtgyuneolkp;qwsbfcdxjz{|}~
(Note: this was transcribed by hand by @ETHproductions, so if you see any errors, please point them out!)

Example
DVORAK zZxX as input will give as output ;:qQ

This is code-golf so the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
translate(const char *t, const char *s, char *b)
{
	static const char qwerty[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	static const char dvorak[] = "!_#$%&-()*}w[vz0123456789SsW]VZ@AXJE>UIDCHTNMBRL\"POYGK<QF:/\\=^{`axje.uidchtnmbrl'poygk,qf;?|+~";
	static const char colemak[] = "!\"#$%&'()*+,-./0123456789Oo<=>?@ABCSFTDHUNEIMKY:QPRGLVWXJZ[\\]^_`abcsftdhuneimky;qprglvwxjz{|}~";
	static const char workman[] = "!\"#$%&'()*+,-./0123456789Ii<=>?@AVMHRTGYUNEOLKP:QWSBFCDXJZ[\\]^_`avmhrtgyuneolkp;qwsbfcdxjz{|}~";

	const char *kb, *p;
	size_t i;

	if (!strcmp(t, "DVORAK"))
		kb = dvorak;
	else if (!strcmp(t, "COLEMAK"))
		kb = colemak;
	else if (!strcmp(t, "WORKMAN"))
		kb = workman;
	else
		return NULL;

	for (i = 0; s[i]; i++) {
		b[i] = s[i];

		p = strchr(qwerty, s[i]);
		if (p)
			b[i] = kb[p - qwerty];
	}
	b[i] = '\0';

	return b;
}

void
test(const char *t, const char *s, const char *r)
{
	char b[128];

	translate(t, s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("DVORAK", "zZxX", ";:qQ");

	return 0;
}
