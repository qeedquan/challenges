/*

Task
You are given a string s.

Let us call a substring of s with 2 or more adjacent identical letters a group (such as "aa", "bbb", "cccc"...).

Let us call a substring of s with 2 or more adjacent groups a big group (such as "aabb","bbccc"...).

Your task is to count the number of big groups in the given string.

Examples
"ccccoodeffffiiighhhhhhhhhhttttttts" => 3

The groups are "cccc", "oo", "ffff", "iii", "hhhhhhhhhh", "ttttttt".

The big groups are "ccccoo", "ffffiii", "hhhhhhhhhhttttttt".

"gztxxxxxggggggggggggsssssssbbbbbeeeeeeehhhmmmmmmmitttttttlllllhkppppp" => 2

The big groups are :

"xxxxxggggggggggggsssssssbbbbbeeeeeeehhhmmmmmmm" and "tttttttlllll"

"soooooldieeeeeer" => 0

There is no big group.

Input/Output
[input] string s

A string of lowercase Latin letters.

[output] an integer

The number of big groups.

*/

#include <assert.h>
#include <stdio.h>

size_t
repadj(const char *s)
{
	size_t c, r;
	size_t i, j;

	r = 0;
	for (c = i = j = 0; s[i]; i = j) {
		j = i + 1;
		while (s[i] == s[j])
			j++;

		switch (j - i) {
		case 1:
			r += (c > 1);
			c = 0;
			break;

		default:
			c += 1;
			break;
		}
	}
	r += (c > 1);
	return r;
}

int
main()
{
	assert(repadj("ccccoodeffffiiighhhhhhhhhhttttttts") == 3);
	assert(repadj("gztxxxxxggggggggggggsssssssbbbbbeeeeeeehhhmmmmmmmitttttttlllllhkppppp") == 2);
	assert(repadj("soooooldieeeeeer") == 0);

	return 0;
}
