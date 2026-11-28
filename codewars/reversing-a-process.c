/*

Suppose we know the process by which a string s was encoded to a string r (see explanation below). The aim of the kata is to decode this string r to get back the original string s.

Explanation of the encoding process:
input: a string s composed of lowercase letters from "a" to "z", and a positive integer num
we know there is a correspondence between abcde...uvwxyzand 0, 1, 2 ..., 23, 24, 25 : 0 <-> a, 1 <-> b ...
if c is a character of s whose corresponding number is x, apply to x the function f: x-> f(x) = num * x % 26, then find ch the corresponding character of f(x)
Accumulate all these ch in a string r
concatenate num and r and return the result
For example:

encode("mer", 6015)  -->  "6015ekx"

m --> 12,   12 * 6015 % 26 = 4,    4  --> e
e --> 4,     4 * 6015 % 26 = 10,   10 --> k
r --> 17,   17 * 6015 % 26 = 23,   23 --> x

So we get "ekx", hence the output is "6015ekx"
Task
A string s was encoded to string r by the above process. complete the function to get back s whenever it is possible.

Indeed it can happen that the decoding is impossible for strings composed of whatever letters from "a" to "z" when positive integer num has not been correctly chosen. In that case return "Impossible to decode".

Examples
decode "6015ekx" -> "mer"
decode "5057aan" -> "Impossible to decode"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long vlong;

char *
decode(const char *input, char *output)
{
	vlong symbol, number;
	vlong value0, value1;
	size_t index0, index1;
	char *endptr;

	number = strtoll(input, &endptr, 10);
	input = endptr;
	for (index0 = index1 = 0; input[index0]; index0++) {
		for (symbol = 0; symbol < 26; symbol++) {
			value0 = (symbol * number) % 26;
			value1 = input[index0] - 'a';
			if (value0 == value1)
				output[index1++] = 'a' + symbol;
		}
	}
	output[index1] = '\0';

	if (index0 != index1)
		sprintf(output, "Impossible to decode");
	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	decode(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("6015ekx", "mer");
	test("5057aan", "Impossible to decode");
	test("1273409kuqhkoynvvknsdwljantzkpnmfgf", "uogbucwnddunktsjfanzlurnyxmx");
	test("1544749cdcizljymhdmvvypyjamowl", "mfmwhbpoudfujjozopaugcb");
	test("105860ymmgegeeiwaigsqkcaeguicc", "Impossible to decode");
	test("1122305vvkhrrcsyfkvejxjfvafzwpsdqgp", "rrsxppowmjsrclfljrajtybwviqb");
	test("7235897srigyvazffyrtxizwgpmvpts", "qfkoexapddefbtkpiojcxjbq");

	return 0;
}
