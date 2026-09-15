#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(int k1[], int k2[], size_t klen, char *buf)
{
	static const char sms[10][10] = {
		" ",
		".,?\"", "abc", "def",
		"ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz"
	};

	size_t i;

	for (i = 0; i < klen; i++)
		*buf++ = sms[k1[i]][k2[i] - 1];
	*buf = '\0';
}

void
test(int k1[], int k2[], size_t klen, const char *res)
{
	char buf[32];

	solve(k1, k2, klen, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	int k1_1[] = { 9, 3, 5, 2, 6, 6, 3, 0, 8, 6, 0, 4, 4, 8, 7, 2, 1 };
	int k2_1[] = { 1, 2, 3, 3, 3, 1, 2, 1, 1, 3, 1, 3, 3, 2, 1, 3, 1 };

	int k1_2[] = { 4, 6, 9, 0, 2, 7, 3, 0, 9, 6, 8, 1 };
	int k2_2[] = { 2, 3, 1, 1, 1, 3, 2, 1, 3, 3, 2, 3 };

	test(k1_1, k2_1, nelem(k1_1), "welcome to iiupc.");
	test(k1_2, k2_2, nelem(k1_2), "how are you?");

	return 0;
}
