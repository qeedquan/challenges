/*

Background
I have a ladder leaning on a wall, and a remote-controlled robot that can climb it. I can send three different commands to the robot:

UP: the robot takes one step upwards. If it was on the highest step, it trips over, falls down and explodes.
DOWN: the robot takes one step downwards. If it was on the lowest step, nothing happens.
RESET: the robot returns to the lowest step.
I can also send a series of commands, and the robot will execute them one by one. Your task is to predict its movements.

Input
Your inputs are a positive integer N, representing the number of steps in the ladder, and a non-empty string C over UDR, representing the commands I have sent to the robot. You can assume that N < 1000. The robot is initialized on the lowest step of the ladder.

Output
It is guaranteed that at some point, the robot will climb over the highest step and explode. Your output is the number of commands it executes before this happens.

Example
Consider the inputs N = 4 and C = "UDDUURUUUUUUUDDDD" The robot, denoted by @, moves along the 4-step ladder as follows:

|-|   |-|   |-|   |-|   |-|   |-|   |-|   |-|   |-|   |@|   |-||
|-|   |-|   |-|   |-|   |-|   |@|   |-|   |-|   |@|   |-|   |-||
|-|   |@|   |-|   |-|   |@|   |-|   |-|   |@|   |-|   |-|   |-|v
|@| U |-| D |@| D |@| U |-| U |-| R |@| U |-| U |-| U |-| U |-|# Boom!
The remaining commands are not executed, since the robot has exploded. The explosion took place after 10 commands, so the correct output is 10.

Rules and scoring
You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

Test cases
  1 U -> 1
  1 DDRUDUU -> 4
  4 UDDUUUUURUUUUDDDD -> 7
  4 UDDUURUUUUUUUDDDD -> 10
  6 UUUUUDRUDDDDRDUUUUUUDRUUUUUUUDR -> 20
 10 UUUUUURUUUUUUURUUUUUUUURUUUUUUUUUUUUUU -> 34
  6 UUUDUUUUDDDDDDDDDDDDDDRRRRRRRRRRRUUUUUU -> 8
  6 UUUDUUUDURUDDDUUUUUDDRUUUUDDUUUUURRUUDDUUUUUUUU -> 32
 20 UUDDUDUUUDDUUDUDUUUDUDDUUUUUDUDUUDUUUUUUDUUDUDUDUUUUUDUUUDUDUUUUUUDUDUDUDUDUUUUUUUUUDUDUUDUDUUUUU -> 56
354 UUDDUUDUDUUDDUDUUUUDDDUDUUDUDUDUDDUUUUDUDUUDUDUUUDUDUDUUDUUUDUUUUUDUUDUDUUDUDUUUUUDUDUUDUDUDUDDUUUUUUUDUDUDUDUUUUUDUDUDUDUDUDUDUDUUDUUUUUURUUUDUUUUDDUUDUDUDURURURUDUDUUUUDUUUUUUDUDUDUDUDUUUUUUDUDUUUUUUUDUUUDUUDUDUDUUDUDUDUUUUUUUUUUDUUUDUDUUDUUDUUUDUUUUUUUUUUUUUDUUDUUDUDUDUUUDUDUUUUUUUDUUUDUUUDUUDUUDDUUUUUUUUDUDUDUDUDUUUUDUDUUUUUUUUDDUUDDUUDUUDUUDUDUDUDUUUUUUUUUDUUDUUDUUUDUUDUUUUUUUUUUUDUDUDUDUUUUUUUUUUUUDUUUDUUDUDDUUDUDUDUUUUUUUUUUUUDUDUDUUDUUUDUUUUUUUDUUUUUUUUUDUDUDUDUDUUUUUUDUDUDUUDUDUDUDUUUUUUUUUUUUUUUDUDUDUDDDUUUDDDDDUUUUUUUUUUUUUUDDUDUUDUUDUDUUUUUUDUDUDUDUDUUUUDUUUUDUDUDUUUDUUDDUUUUUUUUUUUUUUUUUUDUUDUUDUUUDUDUUUUUUUUUUUDUUUDUUUUDUDUDUUUUUUUUUDUUUDUUUDUUDUUUUUUUUUUUUDDUDUDUDUUUUUUUUUUUUUUUDUUUDUUUUDUUDUUDUUUUUUUUUUUDUDUUDUUUDUUUUUUDUDUDUUDUUUUUUUUUUUUDUUUDUUDUDUDUUUUDUDUDUDUDUUUUUUUUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUUU -> 872

*/

#include <assert.h>
#include <stdio.h>

size_t
movements(unsigned n, const char *s)
{
	unsigned p;
	size_t i;

	p = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'U':
			if (++p >= n)
				return i + 1;
			break;

		case 'D':
			if (p > 0)
				p--;
			break;

		case 'R':
			p = 0;
			break;
		}
	}
	return i;
}

int
main(void)
{
	assert(movements(1, "U") == 1);
	assert(movements(1, "DDRUDUU") == 4);
	assert(movements(4, "UDDUUUUURUUUUDDDD") == 7);
	assert(movements(4, "UDDUURUUUUUUUDDDD") == 10);
	assert(movements(6, "UUUUUDRUDDDDRDUUUUUUDRUUUUUUUDR") == 20);
	assert(movements(10, "UUUUUURUUUUUUURUUUUUUUURUUUUUUUUUUUUUU") == 34);
	assert(movements(6, "UUUDUUUUDDDDDDDDDDDDDDRRRRRRRRRRRUUUUUU") == 8);
	assert(movements(6, "UUUDUUUDURUDDDUUUUUDDRUUUUDDUUUUURRUUDDUUUUUUUU") == 32);
	assert(movements(20, "UUDDUDUUUDDUUDUDUUUDUDDUUUUUDUDUUDUUUUUUDUUDUDUDUUUUUDUUUDUDUUUUUUDUDUDUDUDUUUUUUUUUDUDUUDUDUUUUU") == 56);
	assert(movements(354, "UUDDUUDUDUUDDUDUUUUDDDUDUUDUDUDUDDUUUUDUDUUDUDUUUDUDUDUUDUUUDUUUUUDUUDUDUUDUDUUUUUDUDUUDUDUDUDDUUUUUUUDUDUDUDUUUUUDUDUDUDUDUDUDUDUUDUUUUUURUUUDUUUUDDUUDUDUDURURURUDUDUUUUDUUUUUUDUDUDUDUDUUUUUUDUDUUUUUUUDUUUDUUDUDUDUUDUDUDUUUUUUUUUUDUUUDUDUUDUUDUUUDUUUUUUUUUUUUUDUUDUUDUDUDUUUDUDUUUUUUUDUUUDUUUDUUDUUDDUUUUUUUUDUDUDUDUDUUUUDUDUUUUUUUUDDUUDDUUDUUDUUDUDUDUDUUUUUUUUUDUUDUUDUUUDUUDUUUUUUUUUUUDUDUDUDUUUUUUUUUUUUDUUUDUUDUDDUUDUDUDUUUUUUUUUUUUDUDUDUUDUUUDUUUUUUUDUUUUUUUUUDUDUDUDUDUUUUUUDUDUDUUDUDUDUDUUUUUUUUUUUUUUUDUDUDUDDDUUUDDDDDUUUUUUUUUUUUUUDDUDUUDUUDUDUUUUUUDUDUDUDUDUUUUDUUUUDUDUDUUUDUUDDUUUUUUUUUUUUUUUUUUDUUDUUDUUUDUDUUUUUUUUUUUDUUUDUUUUDUDUDUUUUUUUUUDUUUDUUUDUUDUUUUUUUUUUUUDDUDUDUDUUUUUUUUUUUUUUUDUUUDUUUUDUUDUUDUUUUUUUUUUUDUDUUDUUUDUUUUUUDUDUDUUDUUUUUUUUUUUUDUUUDUUDUDUDUUUUDUDUDUDUDUUUUUUUUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUDUUUUDUDUUUUUU") == 872);

	return 0;
}