/*

Definition
According to Wikipedia:

The Cooke and Wheatstone telegraph was an early electrical telegraph system dating from the 1830s invented by English inventor William Fothergill Cooke and English scientist Charles Wheatstone. It was the first telegraph system to be put into commercial service. The receiver consisted of a number of needles which could be moved by electromagnetic coils to point to letters on a board. This feature was liked by early users who were unwilling to learn codes, and employers who did not want to invest in staff training.

It works like this:

Scheme of Cooke and Wheatstone telegraph, five-needle
https://upload.wikimedia.org/wikipedia/commons/thumb/f/fc/Cooke_Wheatstone_Telegraph_2.jpg/220px-Cooke_Wheatstone_Telegraph_2.jpg

In the middle are five needles, which can be deflected clockwise (as is the case of the middle needle) or anti-clockwise (as is the case of the last needle).

In the picture above, the two deflected needles point to the letter G, which means that the letter being transmitted/received is the letter G.

Note that the letters C, J, Q, V, X, Z are missing and thus have to be substituted with other letters.

Task
You will receive a character in ABDEFGHIKLMNOPRSTUWY as input, and you will output the corresponding configuration of the five needles, with undeflected as |, deflected clockwise as /, and deflected anti-clockwise as \.

Testcases
This covers all the possible inputs

input output
A     /|||\
B     /||\|
D     |/||\
E     /|\||
F     |/|\|
G     ||/|\  (explanation: see above)
H     /\|||
I     |/\||
K     ||/\|
L     |||/\
M     \/|||
N     |\/||
O     ||\/|
P     |||\/
R     \|/||
S     |\|/|
T     ||\|/
U     \||/|
W     |\||/
Y     \|||/
Rules/Requirements
Each submission should be either a full program or function. If it is a function, it must be runnable by only needing to add the function call to the bottom of the program. Anything else (e.g. headers in C), must be included.
If it is possible, provide a link to a site where your program can be tested.
Your program must not write anything to STDERR.
Standard Loopholes are forbidden.
Your program can output in any case, but it must be printed (not an array or similar).
Scoring
Programs are scored according to bytes, in UTF-8 by default or a different character set of your choice.

Eventually, the answer with the least bytes will win.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
needle(int c)
{
	static const char *tab[] = {
	    ['A'] = "/|||\\",
	    ['B'] = "/||\\|",
	    ['D'] = "|/||\\",
	    ['E'] = "/|\\||",
	    ['F'] = "|/|\\|",
	    ['G'] = "||/|\\",
	    ['H'] = "/\\|||",
	    ['I'] = "|/\\||",
	    ['K'] = "||/\\|",
	    ['L'] = "|||/\\",
	    ['M'] = "\\/|||",
	    ['N'] = "|\\/||",
	    ['O'] = "||\\/|",
	    ['P'] = "|||\\/",
	    ['R'] = "\\|/||",
	    ['S'] = "|\\|/|",
	    ['T'] = "||\\|/",
	    ['U'] = "\\||/|",
	    ['W'] = "|\\||/",
	    ['Y'] = "\\|||/",
	};

	if (c < 0 || c >= (int)nelem(tab))
		return NULL;
	return tab[c];
}

int
main(void)
{
	int i;

	for (i = 'A'; i <= 'Z'; i++)
		printf("%c %s\n", i, needle(i));

	return 0;
}
