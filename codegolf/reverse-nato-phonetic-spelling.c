/*

NATO Phonetic Spelling is a way to spell out letters so that they're distinguishable over a noisy connection. The mapping of letters (stolen from here) is as follows:

A -> ALFA
B -> BRAVO
C -> CHARLIE
D -> DELTA
E -> ECHO
F -> FOXTROT
G -> GOLF
H -> HOTEL
I -> INDIA
J -> JULIETT
K -> KILO
L -> LIMA
M -> MIKE
N -> NOVEMBER
O -> OSCAR
P -> PAPA
Q -> QUEBEC
R -> ROMEO
S -> SIERRA
T -> TANGO
U -> UNIFORM
V -> VICTOR
W -> WHISKEY
X -> XRAY
Y -> YANKEE
Z -> ZULU
For example, CAT would map to CHARLIE ALFA TANGO. Your challenge, however, is to take a string of letters converted to phonetic spelling and concatenated together, such as CHARLIEALFATANGO, and convert it back to the original CAT.

The input will always be a concatenation of the 26 possible words, and be nonempty. I/O can be either uppercase or lowercase.

This is code-golf, shortest wins!

Testcases
CHARLIE -> C
CHARLIEALFATANGO -> CAT
HOTELECHOLIMALIMAOSCAR -> HELLO
QUEBECUNIFORMECHOBRAVOECHOCHARLIE -> QUEBEC
TANGOECHOSIERRATANGOINDIANOVEMBERGOLF -> TESTING
ALFALIMAFOXTROTALFA -> ALFA
PAPAALFAPAPAALFAPAPAALFAPAPAALFAPAPAALFA -> PAPAPAPAPA
LIMAUNIFORMHOTELWHISKEYCHARLIEOSCARJULIETTGOLFROMEOBRAVOPAPAECHOSIERRAINDIADELTAZULUNOVEMBERKILOALFAXRAYMIKEQUEBECTANGOVICTORFOXTROTYANKEE -> LUHWCOJGRBPESIDZNKAXMQTVFY

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
unnato(const char *src, char *dst)
{
	static const struct symbol {
		const char *id;
		size_t len;
	} symtab[256] = {
		['A'] = { "ALFA", 4 },
		['B'] = { "BRAVO", 5 },
		['C'] = { "CHARLIE", 7 },
		['D'] = { "DELTA", 5 },
		['E'] = { "ECHO", 4 },
		['F'] = { "FOXTROT", 7 },
		['G'] = { "GOLF", 4 },
		['H'] = { "HOTEL", 5 },
		['I'] = { "INDIA", 5 },
		['J'] = { "JULIETT", 7 },
		['K'] = { "KILO", 4 },
		['L'] = { "LIMA", 4 },
		['M'] = { "MIKE", 4 },
		['N'] = { "NOVEMBER", 8 },
		['O'] = { "OSCAR", 5 },
		['P'] = { "PAPA", 4 },
		['Q'] = { "QUEBEC", 6 },
		['R'] = { "ROMEO", 5 },
		['S'] = { "SIERRA", 6 },
		['T'] = { "TANGO", 5 },
		['U'] = { "UNIFORM", 7 },
		['V'] = { "VICTOR", 6 },
		['W'] = { "WHISKEY", 7 },
		['X'] = { "XRAY", 4 },
		['Y'] = { "YANKEE", 6 },
		['Z'] = { "ZULU", 4 },
	};

	const struct symbol *sym;
	char *ptr;

	for (ptr = dst; *src; src += sym->len) {
		sym = &symtab[*src & 0xff];
		if (!sym->id)
			return NULL;
		if (strncmp(src, sym->id, sym->len) != 0)
			return NULL;
		*ptr++ = *src;
	}
	*ptr = '\0';
	return dst;
}

void
test(const char *src, const char *res)
{
	char buf[128], *dst;

	dst = unnato(src, buf);
	assert(dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test("CHARLIE", "C");
	test("CHARLIEALFATANGO", "CAT");
	test("HOTELECHOLIMALIMAOSCAR", "HELLO");
	test("QUEBECUNIFORMECHOBRAVOECHOCHARLIE", "QUEBEC");
	test("TANGOECHOSIERRATANGOINDIANOVEMBERGOLF", "TESTING");
	test("ALFALIMAFOXTROTALFA", "ALFA");
	test("PAPAALFAPAPAALFAPAPAALFAPAPAALFAPAPAALFA", "PAPAPAPAPA");
	test("LIMAUNIFORMHOTELWHISKEYCHARLIEOSCARJULIETTGOLFROMEOBRAVOPAPAECHOSIERRAINDIADELTAZULUNOVEMBERKILOALFAXRAYMIKEQUEBECTANGOVICTORFOXTROTYANKEE", "LUHWCOJGRBPESIDZNKAXMQTVFY");

	return 0;
}
