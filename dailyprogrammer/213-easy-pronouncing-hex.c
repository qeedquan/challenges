/*

Description
The HBO network show "Silicon Valley" has introduced a way to pronounce hex.

Kid: Here it is: Bit… soup. It’s like alphabet soup, BUT… it’s ones and zeros instead of letters.
Bachman: {silence}
Kid: ‘Cause it’s binary? You know, binary’s just ones and zeroes.
Bachman: Yeah, I know what binary is. Jesus Christ, I memorized the hexadecimal
                    times tables when I was fourteen writing machine code. Okay? Ask me
                    what nine times F is. It’s fleventy-five. I don’t need you to tell me what
                    binary is.
Not "eff five", fleventy. 0xF0 is now fleventy. Awesome. Above a full byte you add "bitey" to the name. The hexidecimal pronunciation rules:

HEX PLACE VALUE	WORD
0xA0	“Atta”
0xB0	“Bibbity”
0xC0	“City”
0xD0	“Dickety”
0xE0	“Ebbity”
0xF0	“Fleventy”
0xA000	"Atta-bitey"
0xB000	"Bibbity-bitey"
0xC000	"City-bitey"
0xD000	"Dickety-bitey"
0xE000	"Ebbity-bitey"
0xF000	"Fleventy-bitey"
Combinations like 0xABCD are then spelled out "atta-bee bitey city-dee".

For this challenge you'll be given some hex strings and asked to pronounce them.

Input Description
You'll be given a list of hex values, one per line. Examples:

0xF5
0xB3
0xE4
0xBBBB
0xA0C9
Output Description
Your program should emit the pronounced hex. Examples from above:

0xF5 "fleventy-five"
0xB3 “bibbity-three”
0xE4 “ebbity-four”
0xBBBB “bibbity-bee bitey bibbity-bee”
0xA0C9 “atta-bitey city-nine”

Credit
This challenge was suggested by u/metaconcept. If you have a challenge idea, submit it to r/dailyprogrammer_ideas and we just might use it.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

char *
pronounce(uvlong n, char *b)
{
	static const char *pre[] = {
	    "",
	    "eleventy",
	    "twenty",
	    "thirty",
	    "forty",
	    "fifty",
	    "sixty",
	    "seventy",
	    "eighty",
	    "ninety",
	    "atta",
	    "bibbity",
	    "city",
	    "dickety",
	    "ebbity",
	    "fleventy",
	};

	static const char *suf[] = {
	    "",
	    "one",
	    "two",
	    "three",
	    "four",
	    "five",
	    "six",
	    "seven",
	    "eight",
	    "nine",
	    "a",
	    "bee",
	    "cee",
	    "dee",
	    "eee",
	    "eff",
	};

	int f, i, x;
	char *p;

	*b = '\0';
	p = b;
	f = 0;
	for (i = sizeof(n) - 1; i >= 0; i--) {
		x = (n >> (8 * i)) & 0xFF;
		if (x)
			f = 1;
		else if (!f)
			continue;

		p += sprintf(p, "%s", pre[x >> 4]);
		if ((x >> 4) && (x & 0x0F))
			p += sprintf(p, "-");
		p += sprintf(p, "%s", suf[x & 0x0F]);
		if (i) {
			if (x & 0x0F)
				p += sprintf(p, " ");
			else
				p += sprintf(p, "-");
			p += sprintf(p, "bitey ");
		}
	}
	for (; p != b && p[-1] == ' '; p--)
		p[-1] = '\0';

	return b;
}

void
test(uvlong n, const char *r)
{
	char b[128];

	pronounce(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(0xF5, "fleventy-five");
	test(0xB3, "bibbity-three");
	test(0xE4, "ebbity-four");
	test(0xBBBB, "bibbity-bee bitey bibbity-bee");
	test(0xA0C9, "atta-bitey city-nine");
	test(0xBEF0FF, "bibbity-eee bitey fleventy-bitey fleventy-eff");
	test(0xA0, "atta");
	test(0xB0, "bibbity");
	test(0xC0, "city");
	test(0xD0, "dickety");
	test(0xE0, "ebbity");
	test(0xF0, "fleventy");
	test(0xA000, "atta-bitey");
	test(0xB000, "bibbity-bitey");
	test(0xC000, "city-bitey");
	test(0xD000, "dickety-bitey");
	test(0xE000, "ebbity-bitey");
	test(0xF000, "fleventy-bitey");
	test(0xABCD, "atta-bee bitey city-dee");

	return 0;
}
