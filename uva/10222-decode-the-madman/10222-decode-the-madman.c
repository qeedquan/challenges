#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
decode(const char *src, char *dst)
{
	static const char enc[] = " abcdefghijklmnopqrstuvwxyz`1234567890-=[];',./\\";
	static const char dec[] = "  czaqsdfyghjbvui w etx  r   `1234567890opklnm,[";

	char *ptr;
	int ch;

	for (; *src; src++) {
		ch = tolower(*src);
		ptr = strchr(enc, ch);
		if (!ptr)
			ch = ' ';
		else
			ch = dec[ptr - enc];

		*dst++ = ch;
	}
	*dst = '\0';
}

void
test(const char *src, const char *res)
{
	char buf[128];

	decode(src, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test("k[r dyt I[o", "how are you");
	return 0;
}
