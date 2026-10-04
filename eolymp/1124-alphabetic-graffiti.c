/*

https://static.e-olymp.com/content/ac/ac63adb176fb0adeb0329a89cf01f466bf000b30.gif

Graffiti is a form of modern street art. Vasyl, passionate about creativity,
decided to take up this interesting activity and create artistic inscriptions using English letters.

Since Vasyl had just started learning English, after mastering the third letter of the English alphabet,
he decided to commemorate each stage of learning a new letter by creating a corresponding pattern.

Vasyl's artistic works after studying the 3-rd and 7-th letters are shown in the example output.

Since with each step it became harder for Vasyl to create the correct pattern, write a program that will help him generate a template for the next drawing.

Input
The only number N (3≤N≤26) — the number of English letters studied.

Output
The pattern created by Vasyl after studying N letters of the English alphabet.

Examples

Input #1
3

Answer #1
a  a
a ab
aabc

*/

#include <stdio.h>

void
solve(int n)
{
	int i, j;

	printf("n=%d\n", n);
	for (i = 0; i < n; i++) {
		printf("a");
		for (j = n - 1; j >= 0; j--) {
			if (j > i)
				printf(" ");
			else
				printf("%c", 'a' + i - j);
		}
		puts("");
	}
	puts("");
}

int
main()
{
	solve(3);
	solve(26);

	return 0;
}
