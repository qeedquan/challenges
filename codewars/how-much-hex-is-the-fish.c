/*

How much is the fish! (- Scooter )
The ocean is full of colorful fishes. We as programmers want to know the hexadecimal value of these fishes.

Task
Take all hexadecimal valid characters (a,b,c,d,e,f) of the given name and XOR them. Return the result as an integer.

Input
The input is always a string, which can contain spaces, upper and lower case letters but no digits.

Example
fisHex("redlionfish") -> e,d,f -> XOR -> 12

*/

#include <assert.h>

int
fishex(const char *s)
{
	int r;

	for (r = 0; *s; s++) {
		if ('a' <= *s && *s <= 'f')
			r ^= *s - 'a' + 10;
		else if ('A' <= *s && *s <= 'F')
			r ^= *s - 'A' + 10;
	}
	return r;
}

int
main()
{
	assert(fishex("redlionfish") == 12);
	assert(fishex("pufferfish") == 1);
	assert(fishex("puffers") == 14);
	assert(fishex("balloonfish") == 14);
	assert(fishex("blowfish") == 4);
	assert(fishex("bubblefish") == 10);
	assert(fishex("globefish") == 10);
	assert(fishex("swellfish") == 1);
	assert(fishex("toadfish") == 8);
	assert(fishex("toadies") == 9);
	assert(fishex("honey toads") == 9);
	assert(fishex("sugar toads") == 13);
	assert(fishex("sea squab") == 5);

	return 0;
}
