/*

A comfortable word is a word which you can type always alternating the hand you type with (assuming you type using a QWERTY keyboard and use fingers as shown in the image below).

That being said, complete the function which receives a word and returns true if it's a comfortable word and false otherwise.

The word will always be a string consisting of only ascii letters from a to z.

https://i.imgur.com/1I7Uuc5.jpg

To avoid problems with image availability, here's the lists of letters for each hand:

Left: q, w, e, r, t, a, s, d, f, g, z, x, c, v, b
Right: y, u, i, o, p, h, j, k, l, n, m
Examples
"yams"  -->  true
"test"  -->  false

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
handedness(int c)
{
	if (strchr("qwertasdfgzxcvb", c))
		return 0;
	if (strchr("yuiophjklnm", c))
		return 1;
	return -1;
}

bool
comfortable(const char *s)
{
	int h0, h1;
	size_t i;

	if (!s[0])
		return true;

	h0 = handedness(s[0]);
	if (h0 < 0)
		return false;

	for (i = 1; s[i]; i++) {
		h1 = handedness(s[i]);
		if (h1 < 0 || !(h0 ^ h1))
			return false;
		h0 = h1;
	}
	return true;
}

int
main()
{
	assert(comfortable("yams") == true);
	assert(comfortable("odor") == true);
	assert(comfortable("their") == true);
	assert(comfortable("fiche") == true);
	assert(comfortable("leisure") == false);
	assert(comfortable("touts") == false);
	assert(comfortable("test") == false);
	assert(comfortable("jokin") == false);
	assert(comfortable("lol") == false);

	return 0;
}
