/*

Here's an interesting challenge...

I want you to golf code that when executed will allow your input to be converted to mimic output as though you were typing on a DVORAK keyboard layout.

The aim is to mimic the US Simplified Dvorak Keyboard (US:SDK)

https://i.stack.imgur.com/4DZzN.png

In comparison, here is the standard US QWERTY layout:

https://i.stack.imgur.com/Idvny.png

The keyboard emulation must work for both uppercase and lower case letters as well as shifted keys, for example, if I tapped the q (unshifted) key on my keyboard, the Dvorak code should pop out a ' character on the screen. If I were to tap the c (unshifted) button I should get a j (also unshifted) in response, C (shifted) would get J (shifted) and so on...

I am only concentrating of course on the white keys in the diagram above. Tabs, Caps and the other grey keys should work as per normal...

Any questions? Not for now? Good...

I will not allow external resources that already have the layout encoded already, I will not have any files brought in that can encode the layout. The code MUST be QWERTY INPUT -> (DVORAK RE-CODING) -> DVORAK OUTPUT in nature. No silly Esolangs that are theoretical or just say something like "This program will take QWERTY input and recode it in DVORAK. This is the program." or crap like that... Take this challenge seriously... So Brainfuck coders, I welcome you.

Please note, this is NOT a string conversion program. For every QWERTY key you press, the corresponding DVORAK character must be outputted...

Shortest code wins...

*/

#include <stdio.h>

void
translate(FILE *in, FILE *out)
{
	static const char tab[] = "_#$%&-()*}w[vz0123456789SsW]VZ@AXJE>UIDCHTNMBRL\"POYGK<QF:/\\=^{`axje.uidchtnmbrl'poygk,qf?|+~";

	int ch;

	while ((ch = fgetc(in)) != EOF) {
		if (ch > 33)
			ch = tab[ch - 34];
		fputc(ch, out);
	}
}

int
main(void)
{
	translate(stdin, stdout);
	return 0;
}
