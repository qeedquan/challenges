/*

Your task
Given a string, output the range of ASCII values.

Example
Let's say we have the string Hello.

We get the ASCII values:

H = 72
e = 101
l = 108
l = 108
o = 111
Now, we get the range (max - min):

111 - 72 = 39
Our answer is 39.

Test cases
Input           Output
Hello, World!   82
aaaaa           0
Code Golf       79
Stack Exchange  88
ASCII           18
Scoring
For scoring, we will get the range of ASCII/Unicode values of your program source code, and add that to the length of your code in bytes.

For example, with the program abc, the score would be:

3 (the length of the program) + 2 (the ASCII range of the program) = 5
You can use this TIO link to get your score.

Clarifications
There will be no non-ASCII characters in the input (but your program source code may contain non-ASCII characters)
There will be no newline characters in the input (but your program source code may include newlines)
Lowest score wins

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
range(const char *s)
{
	size_t i;
	int r0, r1;

	if (!s[0])
		return 0;

	r0 = r1 = s[0];
	for (i = 1; s[i]; i++) {
		r0 = min(r0, s[i]);
		r1 = max(r1, s[i]);
	}
	return r1 - r0;
}

int
main(void)
{
	assert(range("Hello, World!") == 82);
	assert(range("aaaaa") == 0);
	assert(range("Code Golf") == 79);
	assert(range("Stack Exchange") == 88);
	assert(range("Code Golf") == 79);
	assert(range("ASCII") == 18);

	return 0;
}
