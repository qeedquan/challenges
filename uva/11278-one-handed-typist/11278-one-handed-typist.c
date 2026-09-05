#include <stdio.h>

int
translate(const char *from, const char *to, int c)
{
	size_t i;

	for (i = 0; from[i]; i++) {
		if (from[i] == c) {
			putchar(to[i]);
			return 1;
		}
	}
	return 0;
}

void
solve(const char *str)
{
	static const char QWERTY[] = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	static const char DVORAK[] = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
	static const char M1[] = "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	static const char M2[] = "!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

	size_t i;

	for (i = 0; str[i]; i++) {
		if (translate(QWERTY, DVORAK, str[i]))
			continue;
		if (translate(M1, M2, str[i]))
			continue;
		putchar(str[i]);
	}
	puts("");
}

int
main()
{
	solve("Hg66t Mty6k!");
	solve("Jhg 4ibl; pytmn 8tc 5i79urrr");
	solve("t,gy jhg 6fxo kt.r");

	return 0;
}
