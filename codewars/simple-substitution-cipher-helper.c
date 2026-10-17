/*

A simple substitution cipher replaces one character from an alphabet with a character from an alternate alphabet, where each character's position in an alphabet is mapped to the alternate alphabet for encoding or decoding.

E.g.

var abc1 = "abcdefghijklmnopqrstuvwxyz";
var abc2 = "etaoinshrdlucmfwypvbgkjqxz";

var sub = new SubstitutionCipher(abc1, abc2);
sub.encode("abc") // => "eta"
sub.encode("xyz") // => "qxz"
sub.encode("aeiou") // => "eirfg"

sub.decode("eta") // => "abc"
sub.decode("qxz") // => "xyz"
sub.decode("eirfg") // => "aeiou"
If a character provided is not in the opposing alphabet, simply leave it as be.

*/

#include <stdio.h>

typedef struct {
	int map0[256];
	int map1[256];
} Sub;

void
subinit(Sub *s, const char *from, const char *to)
{
	size_t i;

	for (i = 0; i < 256; i++)
		s->map0[i] = s->map1[i] = i;

	while (*from) {
		s->map0[*from & 0xff] = *to & 0xff;
		s->map1[*to & 0xff] = *from & 0xff;
		from++;
		to++;
	}
}

char *
submap(const char *src, char *dst, int map[256])
{
	char *ptr;

	for (ptr = dst; *src;)
		*ptr++ = map[*src++ & 0xff];
	*ptr = '\0';
	return dst;
}

char *
subencode(Sub *s, const char *src, char *dst)
{
	return submap(src, dst, s->map0);
}

char *
subdecode(Sub *s, const char *src, char *dst)
{
	return submap(src, dst, s->map1);
}

int
main()
{
	char abc1[] = "abcdefghijklmnopqrstuvwxyz";
	char abc2[] = "etaoinshrdlucmfwypvbgkjqxz";
	char buf[128];

	Sub sub;
	subinit(&sub, abc1, abc2);
	puts(subencode(&sub, "abc", buf));
	puts(subencode(&sub, "xyz", buf));
	puts(subencode(&sub, "aeiou", buf));

	puts(subdecode(&sub, "eta", buf));
	puts(subdecode(&sub, "qxz", buf));
	puts(subdecode(&sub, "eifrg", buf));

	return 0;
}
