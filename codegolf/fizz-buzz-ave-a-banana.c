/*

Here's one for fans of Cabin Pressure. There is an episode in which the characters devise a new version of Fizz Buzz, which is simplified to contain absolutely no mathematics.

It has these rules:

If someone says "fizz", you say "buzz".
If someone says "buzz", you sing "'ave a banana"
If someone says your name, you say "fizz".
The result is that whenever a name is uttered, that person says "fizz" and the sequence has to run to completion.

Let's write some code.

I'd like you to write a program/function/whatever which works thus:

It accepts one single string of text as input.
If the string equals the name of the language your code is written in, it outputs "fizz".
If the string equals "fizz", it outputs "buzz".
If the string equals "buzz", it outputs "'ave a banana" (note the apostrophe at the start).
If the input is not one of these things, it should terminate.
Here's the kicker: The output string must go to two places.
Output to be seen by the user
Back into your code as input
I don't really care if they are output in each iteration, or build a string for eventual output.
Outputs must be separated by new lines (in console or result string)
Rules
This is code golf, write in any language you like and attempt to make your code as small as possible.
Standard loopholes apply.
I'd like to see links to an online interpreter.
The language name can be a full name or common short-form of the language the answer is written in. E.g. JS is acceptable, but shortening Ruby to R is not).
Test Cases
Input

'buzz'
Output

'ave a banana
Input

'fizz'
Output

buzz
'ave a banana
Input

ruby # or the name of the language your answer is written in
Output

fizz
buzz
'ave a banana
Input

something else
No output

*/

#include <stdio.h>
#include <string.h>

void
play(const char *input)
{
	const char *output;

	for (;;) {
		if (!strcmp(input, "C"))
			output = "fizz";
		else if (!strcmp(input, "fizz"))
			output = "buzz";
		else if (!strcmp(input, "buzz"))
			output = "ave a banana";
		else
			break;

		puts(output);
		input = output;
	}
}

int
main()
{
	play("buzz");
	play("fizz");
	play("C");
	play("done");

	return 0;
}
