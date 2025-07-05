/*

Let's play Russian Roulette!

Normally, this would be a race to write the shortest MOD 6 program, but that's not very realistic, as the chance of winning decreases with each click. Here are the rules:

Emulate a real six-shooter:
A single bullet is placed into one of the six chambers, and the barrel is spun once, only before playing.
The chance of losing on the nth try is 1/6.
The chance of losing after n tries is 1/(6-n)
You are guaranteed to lose in, at most, 6 tries.
Losing:
Display the text *BANG!*
Terminate the program.
Winning:
"Winning" means the gun does not fire, but the bullet is one chamber closer to the hammer.
Display the text *click*
Present a "trigger" to the user, along with the ability to terminate the program (e.g. "ctrl+c", see below).
Program specific:
Pulling the trigger is some form of user input, including the first try. (This can be a keystroke, a mouse click, whatever; text prompts are not required.)
Only one instance of the program is allowed until it is terminated. (Running a new instance of the program is akin to giving the barrel a good spin, i.e. the probability of losing on the next click is reset to 1/6.)
Shortest code wins!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

void
play()
{
	int i, r;

	r = randn(6);
	for (i = 1; i <= 6; i++) {
		if (i == r) {
			puts("*BANG!*");
			break;
		} else
			puts("*click*");
	}
}

int
main()
{
	srand(time(NULL));
	play();
	return 0;
}
