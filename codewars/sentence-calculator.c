/*

Sentence Calculator

Calculate the total score (sum of the individual character scores) of a sentence given the following score rules for each allowed group of characters:

Lower case [a-z]: 'a'=1, 'b'=2, 'c'=3, ..., 'z'=26
Upper case [A-Z]: 'A'=2, 'B'=4, 'C'=6, ..., 'Z'=52
Digits [0-9] their numeric value: '0'=0, '1'=1, '2'=2, ..., '9'=9
Other characters: 0 value

Note: input will always be a string

*/

#include <assert.h>
#include <stdio.h>

int
score(const char *s)
{
	size_t i;
	int c, r;

	r = 0;
	for (i = 0; (c = s[i]); i++) {
		if ('a' <= c && c <= 'z')
			r += c - 'a' + 1;
		else if ('A' <= c && c <= 'Z')
			r += (c - 'A' + 1) * 2;
		else if ('0' <= c && c <= '9')
			r += c - '0';
	}
	return r;
}

int
main()
{
	assert(score("I Love You") == 170);
	assert(score("ILoveYou") == 170);
	assert(score("ARE YOU HUNGRY?") == 356);
	assert(score("oops, i did it again!") == 152);
	assert(score("Give me 5!") == 73);
	assert(score("Give me five!") == 110);
	return 0;
}
