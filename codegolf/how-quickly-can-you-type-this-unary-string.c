/*

If I want to type the string aaa, the least keystrokes I can type it in is 3: a a a. But if I want to type the string aaaaaa, I can do it in 5: a a a ctrl-c ctrl-v, where the ctrl-c refers to copying aaa and the ctrl-v refers to pasting it.

Specifically, starting with an empty "buffer" and an empty "clipboard":

The keystroke a appends an a to the buffer.
ctrl-c takes some substring of the buffer and stores it into the clipboard. I'll notate it as ctrl-c(5) or similar to refer to 5 characters being stored. Only one string can be stored into the clipboard, and storing overwrites previous content.
ctrl-v appends the clipboard to the buffer.
Each of these counts as one keystroke.

With a larger example, the least keystrokes 17 as can be typed in is 8:

a a a ctrl-c(3) ctrl-v ctrl-v ctrl-c(8) ctrl-v
Your challenge is to, given a number n, return the number of keystrokes required to type n as. This is code-golf, shortest wins!

Testcases
These are done by hand, so tell me if any of these are wrong. Also, this doesn't appear to be on OEIS. I've written some not-quite-functional python code to find all possible outputs for a given length.

The first 30 terms of the sequence are:

1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 10, 9, 10, 10, 10

And some more specific ones, with examples:

11 -> 7 (a a a ctrl-c(3) ctrl-v ctrl-c(5) ctrl-v)
17 -> 8 (a a a ctrl-c(3) ctrl-v ctrl-v ctrl-c(8) ctrl-v)
25 -> 9 (a a a ctrl-c(3) ctrl-v ctrl-v ctrl-c(8) ctrl-v ctrl-v, the python code doesn't find this one)
75 -> 12 (a a a ctrl-c(3) ctrl-v ctrl-v ctrl-c(9) ctrl-v ctrl-v ctrl-c(24) ctrl-v ctrl-v, python code also misses this one)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// https://math.stackexchange.com/questions/4881219/prove-or-reject-my-solution-to-how-quickly-can-you-type-this-unary-string/4881417#4881417
int
speed(int n)
{
	int x, y;

	if (n < 6)
		return max(n, 0);

	x = speed(n - (n / 2)) + 2;
	y = speed(n - (2 * (n / 3))) + 3;
	return min(x, y);
}

int
main(void)
{
	static const int tab[] = {1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 10, 9, 10, 10, 10};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(speed(i + 1) == tab[i]);

	assert(speed(11) == 7);
	assert(speed(17) == 8);
	assert(speed(25) == 9);
	assert(speed(75) == 12);

	return 0;
}
