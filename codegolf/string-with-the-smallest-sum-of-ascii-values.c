/*

Description
In this challenge, you need to write a function that takes in a list of strings and returns the smallest string based on their ASCII value. You should assume that the input list contains only lowercase alphabetical strings.

Test Cases
["a", "b", "c"] => "a"
["hello", "world", "code"] => "code"
["aaa", "aa", ""] => ""
["cat", "bat", "rat"] => "bat"
["zab", "xyz", "abcd"] => "zab"

Write the function in as few bytes as possible. The code itself can be a function, process or anything provided that it gives the desired output. Use of other ASCII characters like big or small letters, with space function must be supported.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
strsum(const char *s)
{
	int r;

	for (r = 0; *s; s++)
		r += *s;
	return r;
}

const char *
strsmall(const char **s, size_t n)
{
	const char *p;
	size_t i;
	int u, v;

	p = NULL;
	u = 0;
	for (i = 0; i < n; i++) {
		v = strsum(s[i]);
		if (!p || u > v) {
			p = s[i];
			u = v;
		}
	}
	return p;
}

void
test(const char **s, size_t n, const char *r)
{
	const char *p;

	p = strsmall(s, n);
	if (!p)
		assert(p == r);
	else {
		printf("%s\n", p);
		assert(!strcmp(p, r));
	}
}

int
main(void)
{
	const char *s1[] = {"a", "b", "c"};
	const char *s2[] = {"hello", "world", "code"};
	const char *s3[] = {"aaa", "aa", ""};
	const char *s4[] = {"cat", "bat", "rat"};
	const char *s5[] = {"zab", "xyz", "abcd"};

	test(s1, nelem(s1), "a");
	test(s2, nelem(s2), "code");
	test(s3, nelem(s3), "");
	test(s4, nelem(s4), "bat");
	test(s5, nelem(s5), "zab");

	return 0;
}
