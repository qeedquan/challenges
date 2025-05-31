/*

In this Kata you have to create a function,named insertMissingLetters,that takes in a string and outputs the same string processed in a particular way.

The function should insert only after the first occurrence of each character of the input string, all the alphabet letters that:

-are NOT in the original string
-come after the letter of the string you are processing

Each added letter should be in uppercase, the letters of the original string will always be in lowercase.

Example:

input: "holly"

missing letters: "a,b,c,d,e,f,g,i,j,k,m,n,p,q,r,s,t,u,v,w,x,z"

output: "hIJKMNPQRSTUVWXZoPQRSTUVWXZlMNPQRSTUVWXZlyZ"

You don't need to validate input, the input string will always contain a certain amount of lowercase letters (min 1 / max 50).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
insert(const char *input, char *output)
{
	bool seen[256];
	bool skip[256];
	const char *string;
	char *buffer;
	int symbol;
	int alphabet;

	memset(seen, 0, sizeof(seen));
	memset(skip, 0, sizeof(skip));

	for (string = input; *string; string++) {
		symbol = toupper(*string & 0xff);
		skip[symbol] = true;
	}

	buffer = output;
	for (string = input; *string; string++) {
		symbol = *string & 0xff;
		*buffer++ = symbol;
		if (seen[symbol])
			continue;

		alphabet = toupper(*string) + 1;
		for (; alphabet <= 'Z'; alphabet++) {
			if (!skip[alphabet])
				*buffer++ = alphabet;
		}
		seen[symbol] = true;
	}
	*buffer = '\0';

	return output;
}

void
test(const char *input, const char *expected)
{
	char output[256];

	insert(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("holly", "hIJKMNPQRSTUVWXZoPQRSTUVWXZlMNPQRSTUVWXZlyZ");
	test("hello", "hIJKMNPQRSTUVWXYZeFGIJKMNPQRSTUVWXYZlMNPQRSTUVWXYZloPQRSTUVWXYZ");
	test("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
	test("hellllllllllllooooo", "hIJKMNPQRSTUVWXYZeFGIJKMNPQRSTUVWXYZlMNPQRSTUVWXYZllllllllllloPQRSTUVWXYZoooo");
	test("pixxa", "pQRSTUVWYZiJKLMNOQRSTUVWYZxYZxaBCDEFGHJKLMNOQRSTUVWYZ");
	test("xpixax", "xYZpQRSTUVWYZiJKLMNOQRSTUVWYZxaBCDEFGHJKLMNOQRSTUVWYZx");
	test("z", "z");

	return 0;
}
