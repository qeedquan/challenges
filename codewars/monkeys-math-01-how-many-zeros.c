/*

Gigi is a clever monkey, living in the zoo, his teacher (animal keeper) recently taught him some knowledge of "0".

In Gigi's eyes, "0" is a character contains some circle(maybe one, maybe two).

So, a is a "0",b is a "0",6 is also a "0"，and 8 have two "0" ,etc...

Now, write some code to count how many "0"s in the text.

Let us see who is smarter? You ? or monkey?

Input always be a string(including words numbers and symbols)，You don't need to verify it, but pay attention to the difference between uppercase and lowercase letters.

Here is a table of characters：

one zero	abdegopq069DOPQR         () <-- A pair of braces as a zero
two zero	%&B8
Output will be a number of "0".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
zeros(const char *s)
{
	size_t i, c;

	for (c = i = 0; s[i]; i++) {
		if (strchr("abdegopq069DOPQR", s[i]))
			c += 1;
		else if (strchr("%&B8", s[i]))
			c += 2;
		else if (s[i] == '(' && s[i + 1] == ')') {
			c += 1;
			i += 1;
		}
	}
	return c;
}

int
main()
{
	assert(zeros("") == 0);
	assert(zeros("0") == 1);
	assert(zeros("()") == 1);
	assert(zeros("O()()") == 3);
	assert(zeros("1234567890") == 5);
	assert(zeros("abcdefghijklmnopqrstuvwxyz") == 8);
	return 0;
}
