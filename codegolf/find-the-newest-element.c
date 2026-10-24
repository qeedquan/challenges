/*

Given a finite sequence, each of its elements has a first occurrence. Your task is to output the symbol whose first occurrence is last in the sequence. If the elements represent posts and reposts of memes over time, we want to see the newest meme!

Example
Input: A-BANAL-BANANA-LAB

A first occurs at position 0 (it occurs at positions 0,3,5,9,11,13,16)
- first occurs at position 1
B first occurs at position 2
N first occurs at position 4
L first occurs at position 6
max(0,1,2,4,6) = 6, so

Output: L

Input/output format
You can assume that the input sequence is nonempty, and is either a string of printable non-whitespace ASCII characters or a list of nonnegative integers in any reasonable form (your choice). You will output one element of the input sequence.

And of course
This is code-golf, so the shortest solution in each language wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
newest(const char *s)
{
	char h[256];
	size_t i;
	int c, r;

	memset(h, 0, sizeof(h));
	r = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (!h[c]) {
			r = c;
			h[c] = 1;
		}
	}
	return r;
}

int
main()
{
	assert(newest("A-BANAL-BANANA-LAB") == 'L');
	return 0;
}
