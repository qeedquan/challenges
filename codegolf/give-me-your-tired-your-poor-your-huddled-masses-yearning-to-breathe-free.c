/*

A bronze plaque in the pedestal of the Statue of Liberty displays the poem "The New Colossus" by Emma Lazarus, part of which reads:

Give me your tired, your poor,
Your huddled masses yearning to breathe free,
The wretched refuse of your teeming shore.
Send these, the homeless, tempest-tost to me,
I lift my lamp beside the golden door!

To simplify this section of the poem for this challenge, we'll make it all uppercase and replace the newlines with slashes (/), keeping commas and other punctuation as is:

GIVE ME YOUR TIRED, YOUR POOR,/YOUR HUDDLED MASSES YEARNING TO BREATHE FREE,/THE WRETCHED REFUSE OF YOUR TEEMING SHORE./SEND THESE, THE HOMELESS, TEMPEST-TOST TO ME,/I LIFT MY LAMP BESIDE THE GOLDEN DOOR!
We'll call this string S. It has md5 hash 8c66bbb9684f591c34751661ce9b5cea. You may optionally assume it has a trailing newline, in which case the md5 hash is 0928ff6581bc207d0938b193321f16e6.

Write a program or function that takes in a single string. When the string is S, output in order, one per line, the six phrases that describe the type of people the poem depicts Lady Liberty asking for:

TIRED
POOR
HUDDLED MASSES YEARNING TO BREATHE FREE
WRETCHED REFUSE OF YOUR TEEMING SHORE
HOMELESS
TEMPEST-TOST
(This precise string, optionally followed by a single trailing newline, must be your output for input S.)

For at least one input string that is not S, your output should be any string other than the six lines above. This could be as simple as outputting only TIRED if the input is only GIVE ME YOUR TIRED. This rule is to prevent pure hardcoding. Otherwise, when the input string is not S, your code may do anything.

This is essentially a constant-output challenge where you are given an input that is relatively close to the output. You could of course mostly ignore the input and hardcode the output, but it may be better to, say, strip out the substrings of the input needed for the output.

For reference, here are the zero-based indices and lengths of the six output lines in S:

13 5, 25 4, 36 39, 81 37, 136 8, 146 12
The shortest code in bytes wins.

*/

#include <stdio.h>
#include <string.h>

void
prophetic(const char *phrase)
{
	static const char words[] =
	    "GIVE ME YOUR TIRED, YOUR POOR,"
	    "/YOUR HUDDLED MASSES YEARNING TO BREATHE FREE,"
	    "/THE WRETCHED REFUSE OF YOUR TEEMING SHORE."
	    "/SEND THESE, THE HOMELESS, TEMPEST-TOST TO ME,"
	    "/I LIFT MY LAMP BESIDE THE GOLDEN DOOR!";

	if (!strcmp(phrase, words)) {
		puts("TIRED");
		puts("POOR");
		puts("HUDDLED MASSES YEARNING TO BREATHE FREE");
		puts("WRETCHED REFUSE OF YOUR TEEMING SHORE");
		puts("HOMELESS");
		puts("TEMPEST-TOST");
	}
}

int
main()
{
	prophetic("GIVE ME YOUR TIRED, YOUR POOR,/YOUR HUDDLED MASSES YEARNING TO BREATHE FREE,/THE WRETCHED REFUSE OF YOUR TEEMING SHORE./SEND THESE, THE HOMELESS, TEMPEST-TOST TO ME,/I LIFT MY LAMP BESIDE THE GOLDEN DOOR!");

	prophetic("CZX");

	return 0;
}
