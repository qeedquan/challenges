/*

Context
We're at war! You need to transfer an important message to your general to inform them from an imminent assault. The thing is, your enemy knows a lot about cryptography : you will need to be more creative in order to encode your message...

Task
Create a program that accepts an ascii message as input, and outputs the encoded message. The message should be encoded this way : each character should get its ascii value shifted by its position in the message.

For example, let's encode the message "Hello, world!"

H   e   l   l   o   ,       w   o   r   l   d   !     Original message

72  101 108 108 111 44  32  119 111 114 108 100 33    ASCII value

0   1   2   3   4   5   6   7   8   9   10  11  12    Place in the message

72  102 110 111 115 49  38  126 119 123 118 111 45    Encoded ascii (line 1 + line 2)

H   f   n   o   s   1   &   ~   w   {   v   o   -     Encoded message
The message Hello, world! should be encoded as Hfnos1&~w{vo-.

Sometimes the encoded ascii can go beyond printable character. In that case, the value loop back to 32 (read the rules for additionnal informations)

T   h   e       r   a   n   d   o   m       g   u   y      Original message

84  104 101 32  114 97  110 100 111 109 32  103 117 121    ASCII value

0   1   2   3   4   5   6   7   8   9   10  11  12  13     Place in the message

84  105 103 35  118 102 116 107 119 118 42  114 129 134    Encoded ascii (line 1 + line 2)

84  105 103 35  118 102 116 107 119 118 42  114 34  39    Corrected encoded ascii (looped back to 32)

T   i   g   #   v   f   t   k   w   v   *   r   "   '
The random guy is then converted into Tig#vftkwv*r"'

Using the same strat, zzzzzzzzz will be converted into z{|}~ !"# (ascii values converted into 122 - 123 - 124 - 125 - 126 - 32 - 33 - 34 - 35)

Rules
The input message will be composed of printable ascii character (between 32 and 126)

The message should be encoded as described before.

The ascii values of the encoded message should be set between 32 and 126.

The first character of the message should be at position 0.

If the new ascii value goes beyond the limit, it should loop back to 32.

Every character should be encoded. This includes punctuation, spaces etc.

No standard loopholes allowed.

This is codegolf, so the shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void
shift(const char *src, char *dst)
{
	int chr;

	for (chr = 32; *src; src++)
		*dst++ = mod(*src - chr--, 95) + 32;
}

void
test(const char *src, const char *res)
{
	char dst[128];

	shift(src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test("The random guy", "Tig#vftkwv*r\"'");
	test("zzzzzzzzz", "z{|}~ !\"#");

	return 0;
}
