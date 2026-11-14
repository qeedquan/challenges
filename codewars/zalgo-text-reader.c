/*

Zalgo text is text that leaks into our plane of existence from a corrupted dimension of Unicode. For example:


H̗̪͇͓̙͎̣̄ͬa͚̯̦͉̖̥v͆ͩ̃͆̓̐ͥe̟͎͖͕͍̎ ̰͚̩͊̽̍ͯ̌͊ā̖̪͉͍̿ͩ̃ͅ ̬̥͎͑̿ͧg̰̳̺͔ͫ̀̐̓̐r̝̫͐͋ͯͭͭͭ͆e͙͕̖̗͙̰͌ͭä͓͚̝͓́̌͑ͪ͊ṱͥ ̱ͣd͎͔͎͇̫̪̃͐̇à͕̮̈͋ͪy̼̳̱ͮ!̳̥̰̭͇̔ͮ̽̓


Complete the function that converts a string of Zalgo text into a string interpretable by our mortal eyes. For example, the string above would be converted into:

Have a great day!

The converted string should only feature ASCII characters.

*/

#include <stdio.h>
#include <uchar.h>

char *
unzalgo(const char8_t *s, char *b)
{
	char *p;

	for (p = b; *s; s++) {
		if (!(*s & 0x80))
			*p++ = *s;
	}
	*p = '\0';
	return b;
}

int
main()
{
	char b[128];

	puts(unzalgo(u8"H̄ͬa͚̯v͆ͩe̟̎ ͊̽ā̿ ͑̿gͫ̀r͐͋e͌ͭä́̌ṱͥ ̱ͣd̃͐à̈y̼ͮ!̔ͮ", b));
	return 0;
}
