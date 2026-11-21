#include <assert.h>
#include <stdio.h>
#include <string.h>

void
decrypt(const char *cipher, size_t key, char *plain)
{
	size_t len;
	size_t i;
	int code;

	len = strlen(cipher);
	for (i = 0; i < len; i++) {
		if (cipher[i] == '.')
			code = 27;
		else if (cipher[i] == '_')
			code = 0;
		else
			code = cipher[i] - 'a' + 1;

		code = (code + i) % 28;
		if (code == 0)
			code = '_';
		else if (code == 27)
			code = '.';
		else
			code = code - 1 + 'a';

		plain[(key * i) % len] = code;
	}
	plain[len] = '\0';
}

void
test(const char *cipher, size_t key, const char *expected)
{
	char plain[128];

	decrypt(cipher, key, plain);
	puts(plain);
	assert(!strcmp(plain, expected));
}

int
main()
{
	test("cs.", 5, "cat");
	test("thqqxw.lui.qswer", 101, "this_is_a_secret");
	test("b_ylxmhzjsys.virpbkr", 3, "beware._dogs_barking");

	return 0;
}
