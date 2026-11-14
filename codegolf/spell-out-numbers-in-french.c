/*

There was a challenge to convert a number to its numeral in English, but that was too straightforward. Given a number 0–100, your task is to output the corresponding numeral in French. The French numeral system has a more complex logic behind it compared to the English one:

Number  Numeral
---------------
 0      zéro (note the accent)
 1      un
 2      deux
 3      trois
 4      quatre
 5      cinq
 6      six
 7      sept
 8      huit
 9      neuf
10      dix
11      onze
12      douze
13      treize
14      quatorze
15      quinze
16      seize
17      dix-sept (literally ten seven)
18      dix-huit
19      dix-neuf
20      vingt
21      vingt et un (no hyphens)
22      vingt-deux
...
30      trente
...
40      quarante
...
50      cinquante
...
60      soixante
...
70      soixante-dix (literally sixty ten)
71      soixante et onze
...
80      quatre-vingts (note the s; literally four twenties)
81      quatre-vingt-un (note the hyphens)
...
90      quatre-vingt-dix
91      quatre-vingt-onze
...
99      quatre-vingt-dix-neuf (4*20+10+9)
100     cent
For a complete list, follow http://quizlet.com/996950/ (http://www.webcitation.org/6RNppaJx0).

Further rules/explanations
There will always be a hyphen between words EXCEPT when the number ends in 1.
When the number ends in 1, the word et (meaning and) is added before the un or onze. (31 = trente et un)
However, 81 and 91 are formatted the same as the other numbers. (81 = quatre-vingt-un)
At 60, the system switches from base 10 to base 20.
There are some minor discrepancies across the web about this; refer to the list linked above for questions.
Loopholes that are forbidden by default are not allowed.
Using an external source such as a website, as well as any libraries, APIs, functions, or the like that convert numbers to numerals or translate to French are not allowed.
This is code-golf, so the answer with the fewest bytes wins.
If available, please link to an online compiler to allow for easy testing of your code.
Input
Input shall be taken from however your language takes input. (STDIN, command line, etc.)
Input will be a single string, consisting of a whole number between 0 and 100 inclusive (leading zeroes optional).
You can assume the input will always be well-formed.
Output
The result shall be output to the most convenient method for your language. (STDOUT, dialog box, etc.)
Case does not matter in the output.
Examples
Test your code against these:

Input  Output
-------------
0      zéro
18     dix-huit
51     cinquante et un
80     quatre-vingts
91     quatre-vingt-onze
99     quatre-vingt-dix-neuf

*/

#include <stdio.h>

const char *
french(int n)
{
	static const char *tab[] = {
		[0] = "Zéro",
		[1] = "Un",
		[2] = "Deux",
		[3] = "Trois",
		[4] = "Quatre",
		[5] = "Cinq",
		[6] = "Six",
		[7] = "Sept",
		[8] = "Huit",
		[9] = "Neuf",

		[10] = "Dix",
		[11] = "Onze",
		[12] = "Douze",
		[13] = "Treize",
		[14] = "Quatorze",
		[15] = "Quinze",
		[16] = "Seize",
		[17] = "Dix-sept",
		[18] = "Dix-huit",
		[19] = "Dix-neuf",

		[20] = "Vingt",
		[21] = "Vingt et Un",
		[22] = "Vingt-Deux",
		[23] = "Vingt-Trois",
		[24] = "Vingt-Quatre",
		[25] = "Vingt-Cinq",
		[26] = "Vingt-Six",
		[27] = "Vingt-Sept",
		[28] = "Vingt-Huit",
		[29] = "Vingt-Neuf",

		[30] = "Trente",
		[31] = "Trente et Un",
		[32] = "Trente-Deux",
		[33] = "Trente-Trois",
		[34] = "Trente-Quatre",
		[35] = "Trente-Cinq",
		[36] = "Trente-Six",
		[37] = "Trente-Sept",
		[38] = "Trente-Huit",
		[39] = "Trente-Neuf",

		[40] = "Quarante",
		[41] = "Quarante et Un",
		[42] = "Quarante-Deux",
		[43] = "Quarante-Trois",
		[44] = "Quarante-Quatre",
		[45] = "Quarante-Cinq",
		[46] = "Quarante-Six",
		[47] = "Quarante-Sept",
		[48] = "Quarante-Huit",
		[49] = "Quarante-Neuf",

		[50] = "Cinquante",
		[51] = "Cinquante et Un",
		[52] = "Cinquante-Deux",
		[53] = "Cinquante-Trois",
		[54] = "Cinquante-Quatre",
		[55] = "Cinquante-Cinq",
		[56] = "Cinquante-Six",
		[57] = "Cinquante-Sept",
		[58] = "Cinquante-Huit",
		[59] = "Cinquante-Neuf",

		[60] = "Soixante",
		[61] = "Soixante et Un",
		[62] = "Soixante-Deux",
		[63] = "Soixante-Trois",
		[64] = "Soixante-Quatre",
		[65] = "Soixante-Cinq",
		[66] = "Soixante-Six",
		[67] = "Soixante-Sept",
		[68] = "Soixante-Huit",
		[69] = "Soixante-Neuf",

		[70] = "Soixante-Dix",
		[71] = "Soixante et Onze",
		[72] = "Soixante-Douze",
		[73] = "Soixante-Treize",
		[74] = "Soixante-Quatorze",
		[75] = "Soixante-Quinze",
		[76] = "Soixante-Seize",
		[77] = "Soixante-Dix-sept",
		[78] = "Soixante-Dix-huit",
		[79] = "Soixante-Dix-neuf",

		[80] = "Quatre-Vingts",
		[81] = "Quatre-Vingt-Un",
		[82] = "Quatre-Vingt-Deux",
		[83] = "Quatre-Vingt-Trois",
		[84] = "Quatre-Vingt-Quatre",
		[85] = "Quatre-Vingt-Cinq",
		[86] = "Quatre-Vingt-Six",
		[87] = "Quatre-Vingt-Sept",
		[88] = "Quatre-Vingt-Huit",
		[89] = "Quatre-Vingt-Neuf",

		[90] = "Quatre-Vingt-Dix",
		[91] = "Quatre-Vingt-Onze",
		[92] = "Quatre-Vingt-Douze",
		[93] = "Quatre-Vingt-Treize",
		[94] = "Quatre-Vingt-Quatorze",
		[95] = "Quatre-Vingt-Quinze",
		[96] = "Quatre-Vingt-Seize",
		[97] = "Quatre-Vingt-Dix-sept",
		[98] = "Quatre-Vingt-Dix-huit",
		[99] = "Quatre-Vingt-Dix-neuf",

		[100] = "Cent",
	};

	if (n < 0 || n > 100)
		return NULL;
	return tab[n];
}

int
main()
{
	int i;

	for (i = 0; i <= 100; i++)
		printf("%d: %s\n", i, french(i));
	return 0;
}
