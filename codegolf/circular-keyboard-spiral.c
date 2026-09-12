/*

This is a QWERTY keyboard.

Q W E R T Y U I O P
 A S D F G H J K L
  Z X C V B N M
We can "spiral out" on this keyboard, starting from G. The spiral will start at G, go to H, then to Y, then to T, then F, then V, then B, then N, then J, then U, then R, then D, then C,... etc. Your challenge is to, given a number 1 ≤ N ≤ 26, output the first N characters in this spiral. (If you are confused, refer to the pictures at the end of the post.)

The catch? Your program's score is proportional to the indices of characters found inside the spiral!

Scoring
For every letter (case-insensitive) in your code, add the index of that character in the spiral to your score (starting from 1).
For every character not in the spiral, add 10 to your score.
The lowest score wins.
For example, the program print("Hello, World!") has a score of 300.

For your convenience, I have written an automatic program grader.

Other rules
Your submission may be a program or function.
You may take N starting at 0 or 1 and ending at 25 or 26, respectively, but the outputs should still begin with "G" and end with "GHYTFVBNJURDCMKIESXLOWAZPQ".
You must output the characters in the spiral in order.
If a function, you may return a list of characters instead of a string.
You may have one trailing newline following the output.
You may use lowercase letters instead of uppercase letters, or a combination of both.

Test cases
number -> output
1 -> G
2 -> GH
5 -> GHYTF
12 -> GHYTFVBNJURD
15 -> GHYTFVBNJURDCMK
24 -> GHYTFVBNJURDCMKIESXLOWAZ
26 -> GHYTFVBNJURDCMKIESXLOWAZPQ

Pictures
https://i.stack.imgur.com/KUjwxm.png

The spiral superimposed:
https://i.stack.imgur.com/6Jcijm.png

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
keyspiral(int n, char *b)
{
	static const char keys[] = "GHYTFVBNJURDCMKIESXLOWAZPQ";

	if (n < 1 || n > 26)
		return NULL;

	memcpy(b, keys, n);
	b[n] = '\0';
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	keyspiral(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "G");
	test(2, "GH");
	test(5, "GHYTF");
	test(12, "GHYTFVBNJURD");
	test(15, "GHYTFVBNJURDCMK");
	test(24, "GHYTFVBNJURDCMKIESXLOWAZ");
	test(26, "GHYTFVBNJURDCMKIESXLOWAZPQ");

	return 0;
}
