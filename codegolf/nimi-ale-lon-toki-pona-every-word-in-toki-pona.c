/*

"nimi ale lon toki pona" is a song by YouTuber jan Misali which lists 137 common words in the constructed language Toki Pona. This challenge is not a duplicate of "How high can you count?" or "Alphabet printing challenge" because instead of numbers or single characters, it outputs random (to many programming languages) strings of 13 different characters.

So here is the challenge:

You have to write as many programs/snippets as you can, each outputting/returning a Toki Pona word listed in the song, in sequential order. For example, the first program/snippet will print mi, the next sina, and so on, up until and including kijetesantakalu.

However, you are not allowed to reuse any character between programs, whitespace included. For example, if your first program is echo mi (Bash), no e, c, h, o, m, i or spaces   are allowed in any of your other programs.

The winner of this challenge is the first submission to print all 137 words. However, if no such submission is posted in four weeks, the submission which prints the most words wins, ties go to the earliest submission with the most words.

Rules:

You can only use a single language for every word, no polyglots.
Leading and trailing spaces (U+0020), tabs (U+0009) and newlines (U+000A and U+000C) are allowed.
You can disregard stderr, as long as the correct output is returned to stdout.
Words must be in all lowercase, so MI is not allowed.
The programs/snippets must be independent, meaning that each must be valid when run individually with nothing else (for example, console.log(a); (JavaScript) is not allowed because var a="mi"; must be prepended to it for the code to work)
You can include functions in your program/snippet, but the whole program/snippet should work when run by itself, so a=function(){console.log("mi");}; (also JavaScript) is bad, but a=function(){console.log("mi");};a(); is good.
All your programs/snippets must be at least 1 byte long.

To save time, the 137 words are:

mi
sina
ni
ona
olin
musi
suwi
pona
li
e
la
pi
o
anu
en
seme
ijo
kule
lukin
kalama
kute
ala
wan
tu
mute
soweli
akesi
pipi
waso
kala
loje
jelo
laso
supa
linja
insa
selo
ko
kiwen
kon
telo
sewi
anpa
sinpin
monsi
jan
meli
mije
tonsi
supa
poka
nasin
kulupu
poki
sitelen
nimi
lipu
toki
lete
seli
suli
lili
kasi
pan
moku
kili
kama
open
awen
pini
wile
esun
mani
kipisi
pana
jo
lanpan
tenpo
weka
jaki
ale
meso
pilin
uta
unpa
oko
ken
sin
namako
soko
len
taso
walo
pimeja
mu
wawa
a
monsuta
n
kin
misikeke
epiku
kokosila
pu
ku
kijetesantakalu

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
output(void)
{
	static const char *words[] = {
	    "mi",
	    "sina",
	    "ni",
	    "ona",
	    "olin",
	    "musi",
	    "suwi",
	    "pona",
	    "li",
	    "e",
	    "la",
	    "pi",
	    "o",
	    "anu",
	    "en",
	    "seme",
	    "ijo",
	    "kule",
	    "lukin",
	    "kalama",
	    "kute",
	    "ala",
	    "wan",
	    "tu",
	    "mute",
	    "soweli",
	    "akesi",
	    "pipi",
	    "waso",
	    "kala",
	    "loje",
	    "jelo",
	    "laso",
	    "supa",
	    "linja",
	    "insa",
	    "selo",
	    "ko",
	    "kiwen",
	    "kon",
	    "telo",
	    "sewi",
	    "anpa",
	    "sinpin",
	    "monsi",
	    "jan",
	    "meli",
	    "mije",
	    "tonsi",
	    "supa",
	    "poka",
	    "nasin",
	    "kulupu",
	    "poki",
	    "sitelen",
	    "nimi",
	    "lipu",
	    "toki",
	    "lete",
	    "seli",
	    "suli",
	    "lili",
	    "kasi",
	    "pan",
	    "moku",
	    "kili",
	    "kama",
	    "open",
	    "awen",
	    "pini",
	    "wile",
	    "esun",
	    "mani",
	    "kipisi",
	    "pana",
	    "jo",
	    "lanpan",
	    "tenpo",
	    "weka",
	    "jaki",
	    "ale",
	    "meso",
	    "pilin",
	    "uta",
	    "unpa",
	    "oko",
	    "ken",
	    "sin",
	    "namako",
	    "soko",
	    "len",
	    "taso",
	    "walo",
	    "pimeja",
	    "mu",
	    "wawa",
	    "a",
	    "monsuta",
	    "n",
	    "kin",
	    "misikeke",
	    "epiku",
	    "kokosila",
	    "pu",
	    "ku",
	    "kijetesantakalu",
	};

	size_t i;

	for (i = 0; i < nelem(words); i++)
		printf("%s\n", words[i]);
}

int
main(void)
{
	output();
	return 0;
}
