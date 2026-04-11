/*

Ocean deep
I’m so afraid to show my feelings,
I have sailed a million ceilings
In my solitary room
Ocean deep
The lines above are from a very popular song of Cliff Richard. In this problem we will be dealing
with a similar type of person. His name is Rampell-Stilt-Skin and another important thing is that he
is a dead man. Someone has killed him a few days ago and you are the detective to solve the mystery.
The problem with this guy is that he always tried to hide his information and feelings under the sea
(I mean out of reach). He wrote a diary, which contained some statements and then a large binary
number (May have as many as 10000 digits). If the number is divisible by a large prime number 131071
then the statement is true, otherwise the statement is false. In this problem you will be given large
binary numbers as input and you will have to verify if that number is divisible by 131071 or not. Your
algorithm needs to be very efficient.

Input
The input file contains several binary numbers. Each binary number starts in a new line but may
expand in several lines. Each number is terminated by a ‘#’ symbol. No line contains more than 100
digits.

Output
For every binary number print ‘YES’ if the number is divisible by the given prime number, print ‘NO’ if
the binary number is not divisible by the given prime number.

Sample Input
0#
1010101#

Sample Output
YES
NO

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

bool
solve(const char *s)
{
	vlong r;

	for (r = 0; *s && *s != '#'; s++) {
		r <<= 1;
		if (*s == '1')
			r += 1;
		r %= 131071;
	}
	return r == 0;
}

int
main()
{
	assert(solve("0#") == true);
	assert(solve("1010101#") == false);

	return 0;
}
