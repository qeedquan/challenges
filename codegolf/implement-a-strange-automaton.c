/*

I was playing around with cellular automaton and I found one that had some interesting behavior. Here's how it works:

It reads a binary string from left to right, if it encounters a 1 followed by 2 other values it will append a 0 to the result and continue reading. If it encounters a 0 (or there are less than 3 values left) it will append the current value and a 1 and continue reading. At the end of the string it will append a single 1 to the result.

Here's a worked out example of one generation

01011111
^
We first encounter a 0 so we append 01 to our result

01011111
 ^
01
Now we encounter a 1 so we append a zero and skip the next two values

01011111
    ^
010
We encounter another 1 so we do the same

01011111
       ^
0100
We now have another 1 but not enough space to jump so we append the current cell and a 1 (in this case 11)

01011111
        ^
010011
We are at the end so we append a single 1 and terminate this generation

01011111
        ^
0100111
Task
Given input in any reasonable format you must create a function or program that computes one generation of the automaton.

This is a code-golf question so answers will be scored in bytes, with fewer bytes being better.

Sample implementation
Here is a sample implementation in Haskell (defines a function d, but the program prints a iterations indefinitely):

d('1':_:_:x) = "0" ++ d x
d(a:x) = a:'1':d x
d x = "1"
r x = x:map d(r x)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
update(const char *s, char *b)
{
	size_t i, l;

	for (i = l = 0; s[i]; i++) {
		if (s[i] == '0' || !s[i + 1] || !s[i + 2])
			l += sprintf(b + l, "%c1", s[i]);
		else if (s[i] == '1') {
			l += sprintf(b + l, "0");
			i += 2;
		}
	}
	sprintf(b + l, "1");
}

void
test(const char *s, const char *r)
{
	char b[128];

	update(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("01011111", "0100111");
	test("01001", "010111");
	test("1101", "0111");
	test("0", "011");

	return 0;
}
