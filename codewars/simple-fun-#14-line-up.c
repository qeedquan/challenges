/*

Task
To prepare his students for an upcoming game, the sports coach decides to try some new training drills. To begin with, he lines them up and starts with the following warm-up exercise:

when the coach says 'L', he instructs the students to turn to the left.
Alternatively, when he says 'R', they should turn to the right.
Finally, when the coach says 'A', the students should turn around.
Unfortunately some students (not all of them, but at least one) can't tell left from right, meaning they always turn right when they hear 'L' and left when they hear 'R'. The coach wants to know how many times the students end up facing the same direction.

Given the list of commands the coach has given, count the number of such commands after which the students will be facing the same direction.

Example
For commands = "LLARL", the output should be 3.

Let's say that there are 4 students, and the second one can't tell left from right. In this case, only after the second, third and fifth commands will the students face the same direction.

Input/Output
[input] string commands

String consisting of characters 'L', 'R' and 'A' only.

Constraints: 0 ≤ commands.length ≤ 35

[output] an integer

The number of commands after which students face the same direction.

*/

#include <assert.h>
#include <stdio.h>

int
move(int op, int p)
{
	switch (op) {
	case 'L':
		p = (p) ? (p - 1) : 3;
		break;
	case 'R':
		p = (p + 1) & 3;
		break;
	case 'A':
		p = (p + 2) & 3;
		break;
	}
	return p;
}

int
lineup(const char *s)
{
	size_t i;
	int c0, c1;
	int p0, p1;
	int r;

	r = 0;
	p0 = p1 = 0;
	for (i = 0; s[i]; i++) {
		c0 = s[i];
		c1 = s[i];
		if (c1 == 'L')
			c1 = 'R';
		else if (c1 == 'R')
			c1 = 'L';

		p0 = move(c0, p0);
		p1 = move(c1, p1);
		if (p0 == p1)
			r += 1;
	}
	return r;
}

int
main()
{
	assert(lineup("LLARL") == 3);
	assert(lineup("RLR") == 1);
	assert(lineup("") == 0);
	assert(lineup("L") == 0);
	assert(lineup("A") == 1);
	assert(lineup("AAAAAAAAAAAAAAA") == 15);
	assert(lineup("RRRRRRRRRRLLLLLLLLLRRRRLLLLLLLLLL") == 16);
	assert(lineup("AALAAALARAR") == 5);
	return 0;
}
