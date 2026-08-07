/*

Your task is to display the below letter "E" shaped ASCII art, given five inputs.

Examples:

Input: 7,2,+,|,- (Note: You don't have to follow this exact input format, and if you don't use it, then you must explain how your own input format works)

Explanation:

7 total width, including the left and right edge characters.

2 Number of vertical characters.

+ The character that should display at the edges.

| The character that should display vertically between the edges.

- The character that should display horizontally.

Output of the above example:

+-----+
|
|
+-----+
|
|
+-----+
Other examples:

Input: 7,2,@,|,-

Output:

@-----@
|
|
@-----@
|
|
@-----@
Input: 7,2,+,|,#

Output:

+#####+
|
|
+#####+
|
|
+#####+
Input: 8,3,+,|,#

Output:

+######+
|
|
|
+######+
|
|
|
+######+
Input: 8,3,+,@,#

Output:

+######+
@
@
@
+######+
@
@
@
+######+
Input: 9,4,^,$,!

Output:

^!!!!!!!^
$
$
$
$
^!!!!!!!^
$
$
$
$
^!!!!!!!^
Cheating and standard loopholes are not allowed.

Your code must not print anything to STDERR.

Your code may accept any character encoding you choose as the input, but any character encoding you choose must, as a minimum, support all the 95 printable ASCII characters.

The shortest code, in bytes, that completes this challenge successfully, is the winning code.

*/

#include <stdio.h>

void
horizontal(int w, char c0, char c1)
{
	int i;

	for (i = 0; i < w; i++) {
		if (i == 0 || i == w - 1)
			putchar(c0);
		else
			putchar(c1);
	}
	puts("");
}

void
vertical(int v, char c)
{
	int i;

	for (i = 0; i < v; i++) {
		putchar(c);
		puts("");
	}
}

void
E(int w, int v, char c0, char c1, char c2)
{
	horizontal(w, c0, c2);
	vertical(v, c1);
	horizontal(w, c0, c2);
	vertical(v, c1);
	horizontal(w, c0, c2);
	puts("");
}

int
main(void)
{
	E(7, 2, '+', '|', '-');
	E(7, 2, '@', '|', '-');
	E(7, 2, '+', '|', '#');
	E(8, 3, '+', '|', '#');
	E(8, 3, '+', '@', '#');
	E(9, 4, '^', '$', '!');

	return 0;
}
