#include <assert.h>
#include <stdio.h>
#include <string.h>

void
solve(int shift, const char *src, char *dst)
{
	size_t i;

	shift = (shift % 26 + 26) % 26;
	for (i = 0; src[i]; i++) {
		if (src[i] >= 'A' && src[i] <= 'Z')
			dst[i] = (src[i] - 'A' + shift) % 26 + 'A';
		else if (src[i] >= 'a' && src[i] <= 'z')
			dst[i] = (src[i] - 'a' + shift) % 26 + 'a';
		else
			dst[i] = src[i];
	}
	dst[i] = '\0';
}

void
test(int shift, const char *src, const char *res)
{
	char dst[64];

	solve(shift, src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test(14, "Nbcm cm hin u pyls aiix gynbix...", "Bpqa qa vwb i dmzg owwl umbpwl...");
	test(8, "Von cn qum nby 1mn ihy ch Bcmnils.", "Dwv kv ycu vjg 1uv qpg kp Jkuvqta.");
	test(-100, "Hiq, ch 2016, nbyly uly vynnyl nywbhckoym, il hin?", "Lmu, gl 2016, rfcpc ypc zcrrcp rcaflgoscq, mp lmr?");

	return 0;
}
