/*

Here is a relatively simple challenge for you.

Given a string of length N, output the string forwards, then backwards, then forwards, then backwards... etc. N times. For example, if your input was

Hello!
You should output:

Hello!!olleHHello!!olleHHello!!olleH
You may also optionally output one trailing newline.

Your submission may be either a full program or a function, and you may take input and output in any reasonable format.
For example, you may take IO from STDIN/STDOUT, function arguments and return value, from a file, etc.
You can safely assume that the input string will not be empty, and will only contain printable ASCII.
You must output the new string on a single line. So, for example, if the output to the last example was

Hello!
!olleH
Hello!
!olleH
Hello!
!olleH
This would not be a valid solution!

Here are some more test cases:

Input:
a
Output:
a

Input:
abcd
Output:
abcddcbaabcddcba

Input:
OK!
Output:
OK!!KOOK!

Input:
4815162342
Output:
4815162342243261518448151623422432615184481516234224326151844815162342243261518448151623422432615184

Input:
PPCG
Output:
PPCGGCPPPPCGGCPP

Input:
42
Output:
4224

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
strrev(char *b, const char *s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		b[i] = s[n - i - 1];
	b[n] = '\0';
	return i;
}

char *
strrts(const char *s, char *b)
{
	size_t i, l, n;

	l = 0;
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (!(i & 1))
			l += sprintf(b + l, "%s", s);
		else
			l += strrev(b + l, s, n);
	}
	b[l] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strrts(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Hello!", "Hello!!olleHHello!!olleHHello!!olleH");
	test("a", "a");
	test("abcd", "abcddcbaabcddcba");
	test("OK!", "OK!!KOOK!");
	test("4815162342", "4815162342243261518448151623422432615184481516234224326151844815162342243261518448151623422432615184");
	test("PPCG", "PPCGGCPPPPCGGCPP");
	test("42", "4224");

	return 0;
}
