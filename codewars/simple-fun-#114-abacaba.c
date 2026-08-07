/*

Task
Consider the following algorithm for constructing 26 strings S(1) .. S(26):

S(1) = "a";
For i in [2, 3, ..., 26]:
S(i) = S(i - 1) + character(i) + S(i - 1).
For example:

S(1) = "a"
S(2) = S(1) + "b" + S(1) = "a" + "b" + "a" = "aba"
S(3) = S(2) + "c" + S(2) = "aba" + "c" +"aba" = "abacaba"
...
S(26) = S(25) + "z" + S(25)
Finally, we got a long string S(26). Your task is to find the kth symbol (indexing from 1) in the string S(26). All strings consist of lowercase letters only.

Input / Output
[input] integer k
1 ≤ k < 2^26

[output] a string(char in C#)
the kth symbol of S(26)

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>
#include <limits.h>

int
abacaba(unsigned k)
{
	int b, c;

	b = sizeof(k) * CHAR_BIT;
	c = b - stdc_leading_zeros_ui((k - 1) ^ k);
	return c + 'a' - 1;
}

int
main()
{
	assert(abacaba(1) == 'a');
	assert(abacaba(2) == 'b');
	assert(abacaba(3) == 'a');
	assert(abacaba(4) == 'c');
	assert(abacaba(5) == 'a');
	assert(abacaba(6) == 'b');
	assert(abacaba(7) == 'a');
	assert(abacaba(8) == 'd');
	assert(abacaba(12) == 'c');
	assert(abacaba(16) == 'e');

	return 0;
}
