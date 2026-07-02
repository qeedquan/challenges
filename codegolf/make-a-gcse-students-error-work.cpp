/*

A GCSE computer science student recently made this hilarious blunder on their exam and posted it online. Now, you must make it work:

day = "Monday"
x = day.length
print(x)
To which they said the output was: 24 hours. Now, we all know that this is incorrect, but to validate this random student, try to golf a program that can take the code above and return the output of 24 hours.

Details
The primary constraint is that the code above must be included, in its entirety, in your program, and it must output the string "24 hours"

This program takes no input, but it must provide its output (to stdout, the screen, or anything) by utilizing a function called print. If this is built in to your language, then use it. If not, then you will need to write your own. A trailing newline may or may not be included, that's up to you.

Rules
The provided code segment must not be in a comment or an unreachable section; it must be executed.
The provided code segment must be used as-is and cannot be golfed in any way.
Semicolons (or the equivalent to the end of a line for your chosen language) are the only allowed modification to the provided code segment.
Pseudocode Example
modify class String {
    let length = "24 hours"
}

day = "Monday"
x = day.length
print(x)
This is a Code Golf challenge, so do still try to make the code with the fewest bytes possible!

*/

#include <iostream>

using namespace std;

#define Monday String()

struct String
{
	const char *length = "24 hours";
};

int main()
{
	auto day = Monday;
	auto x = day.length;
	cout << x << endl;
	return 0;
}
