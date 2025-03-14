/*

Task
Let's call a string cool if it is formed only by Latin letters and no two lowercase and no two uppercase letters are in adjacent positions. Given a string, check if it is cool.

Input/Output
[input] string s

A string that contains uppercase letters, lowercase letters numbers and spaces.

1 ≤ s.length ≤ 20.

[output] a boolean value

true if s is cool, false otherwise.

Example
For s = "aQwFdA", the output should be true

For s = "aBC", the output should be false;

For s = "AaA", the output should be true;

For s = "q q", the output should be false.q

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

bool
cool(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (!isalpha(s[i]))
			return false;

		if (s[i + 1]) {
			if (isupper(s[i]) && isupper(s[i + 1]))
				return false;
			if (islower(s[i]) && islower(s[i + 1]))
				return false;
		}
	}
	return true;
}

int
main()
{
	assert(cool("aQwFdA") == true);
	assert(cool("aBC") == false);
	assert(cool("AaA") == true);
	assert(cool("q q") == false);
	assert(cool("wWw1") == false);
	assert(cool("2") == false);
	assert(cool("aAaAaAa") == true);
	assert(cool("    ") == false);

	return 0;
}
