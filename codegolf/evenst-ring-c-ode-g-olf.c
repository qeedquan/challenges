/*

An 'Even string' is any string where the parity of the ASCII values of the characters is always alternating. For example, the string EvenSt-ring$! is an even-string because the ASCII values of the characters are:

69 118 101 110 83 116 45 114 105 110 103 36 33
And the parities of these numbers are:

Odd Even Odd Even Odd Even Odd Even Odd Even Odd Even Odd
Which is alternating the whole way. However, a string like Hello world! is not an even string because the ASCII values are:

72 101 108 108 111 32 87 111 114 108 100 33
And the parities are:

Even Odd Even Even Odd Even Odd Odd Even Even Even Odd
Which is clearly not always alternating.

The challenge
You must write either a full program or a function that accepts a string for input and outputs a truthy value if the string is even, and a falsy value otherwise. You can take your input and output in any reasonable format, and you can assume that the input will only have printable ASCII (the 32-127 range). You do not have to handle empty input.

Examples
Here are some examples of even strings:

#define
EvenSt-ring$!
long
abcdABCD
3.141
~
0123456789
C ode - g ol!f
HatchingLobstersVexinglyPopulateJuvenileFoxglove

And all of these examples are not even strings:

Hello World
PPCG
3.1415
babbage
Code-golf
Standard loopholes apply
Shortest answer in bytes wins

Happy golfing!
You may also use this ungolfed solution to test any strings if you're curious about a certain test-case.

str = readline(STDIN)
even = true
parity = Int(str[1]) % 2
for c in str[2:end]
  newParity = Int(c) % 2
  if newParity == parity
    even = false
  end
  parity = newParity
end
print(even)

*/

#include <assert.h>
#include <stdio.h>

bool
streven(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i++) {
		if ((s[i] & 1) != !(s[i + 1] & 1))
			return false;
	}
	return true;
}

int
main(void)
{
	assert(streven("#define") == true);
	assert(streven("EvenSt-ring$!") == true);
	assert(streven("long") == true);
	assert(streven("abcdABCD") == true);
	assert(streven("3.141") == true);
	assert(streven("~") == true);
	assert(streven("0123456789") == true);
	assert(streven("C ode - g ol!f") == true);
	assert(streven("HatchingLobstersVexinglyPopulateJuvenileFoxglove") == true);

	assert(streven("Hello World") == false);
	assert(streven("PPCG") == false);
	assert(streven("3.1415") == false);
	assert(streven("babbage") == false);
	assert(streven("Code-golf") == false);
	assert(streven("Standard loopholes apply") == false);
	assert(streven("Shortest answer in bytes wins") == false);
	assert(streven("Happy golfing!") == false);

	return 0;
}
