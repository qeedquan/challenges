/*

Your task is to add up letters to one letter.

The function will be given a variable amount of arguments, each one being a letter to add.

Notes:
Letters will always be lowercase.
Letters can overflow (see second to last example of the description)
If no letters are given, the function should return 'z'

Examples:
addLetters('a', 'b', 'c') = 'f'
addLetters('a', 'b') = 'c'
addLetters('z') = 'z'
addLetters('z', 'a') = 'a'
addLetters('y', 'c', 'b') = 'd' // notice the letters overflowing
addLetters() = 'z'

*/

#include <assert.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
add(const char *s)
{
	int r;

	for (r = 25; *s; s++)
		r = mod(r + *s - 'a' + 1, 26);
	return r + 'a';
}

int
main()
{
	assert(add("abc") == 'f');
	assert(add("ab") == 'c');
	assert(add("z") == 'z');
	assert(add("za") == 'a');
	assert(add("ycb") == 'd');
	assert(add("") == 'z');

	return 0;
}
