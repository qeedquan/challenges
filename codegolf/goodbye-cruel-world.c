/*

Background
Hello golfers! I would like to learn all the programming languages! But I kinda have a short attention span... and copying all the Hello World examples gets boring... but I like fire! ^w^

Challenge
So here is the plan! I want you all to write the smallest code that will compile, print Goodbye Cruel World!, and then crash. Or, as a bonus twist challenge, print Hello World! and crash with Goodbye Cruel World!

Rules
Your score will be total character count used. The answer must be a whole executable program.
Your program must print Goodbye Cruel World! to output, and then crash (unexpected error).
For a score bonus, you must print Hello World! to output instead, but the error message must also contain Goodbye Cruel World!. If you complete the bonus challenge, you may divide your score by 2. (Include a ! at the end of your score if you are claiming the bonus!)
As long as the standard output still prints, and standard error still prints, the order doesn't matter. Just as long as neither can block the other from happening.
The output must contain the contents of the above; " shouldn't appear in the output.
The output should contain the specified string, and nothing else.
The crash report can contain anything, but to claim the bonus, the following regex should match /Goodbye Cruel World!/mi (aka, contains, ignore case/surrounding text))
The strings Hello World! and Goodbye Cruel World! are case insensitive, but otherwise should appear exactly as above.
If the language is capable of crashing (it cannot change its exit code), it needs to crash. Otherwise use the standard "error report" (i.e., STDERR) for the language.
I can crash Python 3, so I have included an example Python 3 answer! Now lets all set the world on fire! ^W^

*/

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	puts("Goodbye Cruel World!");
	abort();
	return 0;
}
