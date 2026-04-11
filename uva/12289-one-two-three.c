/*

Your little brother has just learnt to write one, two and three, in English. He has written a lot of those
words in a paper, your task is to recognize them. Note that your little brother is only a child, so he
may make small mistakes: for each word, there might be at most one wrong letter. The word length is
always correct. It is guaranteed that each letter he wrote is in lower-case, and each word he wrote has
a unique interpretation.

Input
The first line contains the number of words that your little brother has written. Each of the following
lines contains a single word with all letters in lower-case. The words satisfy the constraints above: at
most one letter might be wrong, but the word length is always correct. There will be at most 10 words
in the input.

Output
For each test case, print the numerical value of the word.
Sample Input

3
owe
too
theee

Sample Output
1
2
3

*/

#include <assert.h>

int
detect(const char *s)
{
	if (s[0] && s[1] && s[2] && s[3])
		return 3;

	if (s[0] == 'o' && s[1] == 'n' && s[2] == 'e')
		return 1;
	if (s[0] == 'o' && s[1] == 'n')
		return 1;
	if (s[0] == 'o' && s[2] == 'e')
		return 1;
	if (s[1] == 'n' && s[2] == 'e')
		return 1;

	if (s[0] == 't' && s[1] == 'w' && s[2] == 'o')
		return 2;
	if (s[0] == 't' && s[1] == 'w')
		return 2;
	if (s[0] == 't' && s[2] == 'o')
		return 2;
	if (s[1] == 'w' && s[2] == 'o')
		return 2;

	return 0;
}

int
main()
{
	assert(detect("one") == 1);
	assert(detect("two") == 2);
	assert(detect("three") == 3);

	assert(detect("owe") == 1);
	assert(detect("too") == 2);
	assert(detect("theee") == 3);

	return 0;
}
