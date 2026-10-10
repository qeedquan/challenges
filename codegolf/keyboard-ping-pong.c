/*

Keyboard Ping Pong
This question was inspired by this post from CaucasianJames on X.

https://i.sstatic.net/rUqAIY3k.png

Challenge
Given a string of letters, determine if the word "ping-pongs" across the keyboard. (Letters alternating between sides of the keyboard)

Use any established Latin-script keyboard layout that you would like (QWERTY, AZERTY, etc.) but please specify your choice in your answer.

Here is a graphic of the ping pong sides with QWERTY layout. The left hand side consists of the leftmost 5 letters, with the right hand side consisting of the remaining letters.

Test Cases (QWERTY)

skepticism      -      true
ENDOWMENT       -      true
quantity        -      true
dispel          -      true
kayaks          -      true
a               -      true
aa              -      false
test            -      false
WRONG           -      false
thiswillfail    -      false
ε               -      false

Comments:

Strings of length 1 should return true. Represents an ace!
Strings of length 0 should return false. A point would not be scored in a real ping pong game.
Should be case-insensitive
This question is tagged code-golf, so the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
classify(int c)
{
	static const char left[] = "~!@#$%`12345QWERTASDFGZXCVBqwertasdfgzxcvb";
	static const char right[] = "^&*()_+{}:\"|<>?[];',./YUIOPHJKLNMyuiophjklnm";

	if (strchr(left, c))
		return 0;
	if (strchr(right, c))
		return 1;
	return -1;
}

bool
pingpong(const char *s)
{
	size_t i;
	int x, y;

	if (!s[0])
		return true;

	x = classify(s[0]);
	for (i = 1; s[i]; i++) {
		y = classify(s[i]);
		if (x < 0 || y < 0 || (x ^ 1) != y)
			return false;
		x = y;
	}
	return x >= 0;
}

int
main()
{
	assert(pingpong("skepticism") == true);
	assert(pingpong("ENDOWMENT") == true);
	assert(pingpong("quantity") == true);
	assert(pingpong("dispel") == true);
	assert(pingpong("kayaks") == true);
	assert(pingpong("a") == true);
	assert(pingpong("aa") == false);
	assert(pingpong("test") == false);
	assert(pingpong("WRONG") == false);
	assert(pingpong("thiswillfail") == false);
	assert(pingpong("ε") == false);

	return 0;
}
