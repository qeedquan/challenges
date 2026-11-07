/*

Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
read4(FILE *fp, char *b)
{
	return fread(b, 1, 4, fp);
}

int
readn(FILE *fp, char *b, int n)
{
	char p[4];
	int c, i, r;

	for (i = 0; i < n; i += c) {
		r = read4(fp, p);
		if (r == 0)
			break;

		c = min(r, n - i);
		memcpy(b + i, p, c);
	}
	return i;
}

void
test(char *s)
{
	FILE *fp;
	char b[1024];

	fp = fmemopen(s, strlen(s) + 1, "rb");
	assert(fp);
	readn(fp, b, sizeof(b));
	printf("%s\n", b);
	assert(!strcmp(b, s));
	fclose(fp);
}

int
main(void)
{
	char s1[] = "abc";
	char s2[] = "abcde";
	char s3[] = "abcdABCD1234";
	char s4[] = "leetcode";

	test(s1);
	test(s2);
	test(s3);
	test(s4);

	return 0;
}
