/*

Task
Let's say that "g" is happy in the given string, if there is another "g" immediately to the right or to the left of it.

Find out if all "g"s in the given string are happy.

Example
For str = "gg0gg3gg0gg", the output should be true.

For str = "gog", the output should be false.

Input/Output

[input] string str
A random string of lower case letters, numbers and spaces.

[output] a boolean value
true if all "g"s are happy==false otherwise.

*/

#include <assert.h>
#include <stdio.h>

bool
ghappy(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == 'g') {
			if (i > 0 && s[i - 1] == 'g')
				continue;
			if (s[i + 1] == 'g')
				continue;
			return false;
		}
	}
	return true;
}

int
main()
{
	assert(ghappy("gg0gg3gg0gg") == true);
	assert(ghappy("gog") == false);
	assert(ghappy("") == true);
	assert(ghappy("gg0gg3gg0gg") == true);
	assert(ghappy("gog") == false);
	assert(ghappy("ggg ggg g ggg") == false);
	assert(ghappy("A half of a half is a quarter.") == true);
	assert(ghappy("good grief") == false);
	assert(ghappy("bigger is ggooder") == true);
	assert(ghappy("gggggggggg") == true);
	return 0;
}
